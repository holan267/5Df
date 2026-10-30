"""Grain and halation, reimplemented from the AUTOEXEC.BIN payload.

Grain  (FUN_009912ec noise, FUN_00994378 LTGRAIN4, FUN_009928e8 apply)
  seed  = FNV-1a("A:/DCIM/100EOS5D/IMG_0002.CR2") | 1
  noise = per row: murmur3 fmix32 + xorshift32 -> bytes -> inverse-CDF Gauss
          table (0x9A8F7C), filtered [1,4,1] horizontally and vertically
  apply = 17^3 lattice of lower-triangular 3x3 matrices on the 16-bit cube
          output (colour grain), or a 3x256 amplitude table on the 8-bit
          output (mono grain).
Halation (FUN_00994db0/FUN_00996450 collect, FUN_00994f70 blur, FUN_00995d5c apply)
  only for the films listed at 0x9A90F0 (D250, T500, D050, T200, F250, EV16).
"""
import struct

import numpy as np

PAYLOAD_BASE = 0x982000
GAUSS_TABLE = 0x9A8F7C
KNEE_TABLE = 0x9A8D68
HALO_PROFILES = 0x9A90F0
HALO_KERNELS = {"h_narrow": 0x9A9274, "v_narrow": 0x9A92BA, "h_wide": 0x9A9300, "v_wide": 0x9A9346}
HALO_WEIGHTS = 0x9A9418          # (-7282, 25486), plus 0x38E4 for the half-resolution pass
HALO_LEVELS = (0x55, 0xAB, 0x100)  # 0x9B1D74, indexed by the halation setting 0..2
# Fitted against a camera JPEG (0004D250.JPG: D250, 2383, Full, 5700 K). The
# firmware reads as 7 (FUN_009919e0) and 1, but with those the halo around a
# blown source comes out ~3x too weak and the far-field red lift ~25% short.
HALO_HIGHLIGHT_GAIN = 80.0
HALO_MEAN_GAIN = 1.35
MAP_W, MAP_H = 360, 213
GRAIN_BLOCK = 0xFE58
M32 = np.uint32(0xFFFFFFFF)


def _u(p, addr, fmt):
    return struct.unpack_from(fmt, p, addr - PAYLOAD_BASE)


# ---------------------------------------------------------------- grain

def fnv1a_seed(text):
    h = 0x811C9DC5
    for c in text.encode("ascii"):
        h = ((h ^ c) * 0x01000193) & 0xFFFFFFFF
    return h | 1


def _xorshift(x):
    x = x ^ (x << np.uint32(13))
    x = x ^ (x >> np.uint32(17))
    return x ^ (x << np.uint32(5))


def grain_noise(payload, seed, height, width, streams):
    """int32 noise planes (streams x height x width), as FUN_009912ec builds them
    row by row (rows -2 and -1 only prime the vertical filter)."""
    gauss = np.array(_u(payload, GAUSS_TABLE, "<256b"), dtype=np.int32)
    rows = (np.arange(-2, height, dtype=np.int64) & 0xFFFFFFFF).astype(np.uint32)
    groups = (width + 3) // 4
    planes = []
    with np.errstate(over="ignore"):
        for k in range(streams):
            x = rows * np.uint32(0x9E3779B9) ^ np.uint32(seed) ^ np.uint32((k * 0x2545F491) & 0xFFFFFFFF)
            x = x ^ (x >> np.uint32(16))
            x = x * np.uint32(0x85EBCA6B)
            x = x ^ (x >> np.uint32(13))
            x = x * np.uint32(0xC2B2AE35)
            degenerate = x == 0
            x = _xorshift(x ^ (x >> np.uint32(16)))
            a, b = gauss[x & 0xFF], gauss[(x >> 8) & 0xFF]
            x[degenerate], a[degenerate], b[degenerate] = 0x40AEC71F, -8, 5
            s = np.empty((len(rows), 4 * groups + 2), np.int32)
            s[:, 0], s[:, 1] = a, b
            for g in range(groups):
                x = _xorshift(x)
                for j in range(4):
                    s[:, 2 + 4 * g + j] = gauss[(x >> np.uint32(8 * j)) & 0xFF]
            h = s[:, :-2] + 4 * s[:, 1:-1] + s[:, 2:]
            v = h[:-2] + 4 * h[1:-1] + h[2:]
            planes.append(v[:, :width])
    return np.stack(planes)


class Grain:
    def __init__(self, pack_path, key, grade_i, push_i, level):
        import latent_crypt
        nonce = latent_crypt.make_nonce("ltg", pack_path)
        with open(pack_path, "rb") as f:
            head = latent_crypt.keystream_xor(key, nonce, 0, f.read(0x30))
            if head[:8] != b"LTGPACK1":
                raise ValueError("not an LTGPACK1 file")
            n_grade, n_push = struct.unpack_from("<2I", head, 8)
            off = 0x30 + (grade_i * n_push + push_i) * GRAIN_BLOCK
            f.seek(off)
            blk = latent_crypt.keystream_xor(key, nonce, off, f.read(GRAIN_BLOCK))
        if blk[:8] != b"LTGRAIN4":
            raise ValueError("bad LTGRAIN4 block")
        flags = blk[8]
        self.mono = bool(flags & 1)
        self.simple = bool(flags & 2)
        if self.simple:
            lvl = level if 0 <= level < 12 else 5
            amp = np.frombuffer(blk, np.uint8, 0x300, 0xC + lvl * 0x300)
            self.amp = amp.reshape(3, 256).astype(np.int32)
        else:
            self.pre = np.frombuffer(blk, "<u2", 3 * 1024, 0xC).reshape(3, 1024).astype(np.int32)
            self.lattice = np.frombuffer(blk, "<i2", 17 ** 3 * 6, 0x180C).reshape(17, 17, 17, 6).astype(np.float32)

    def streams(self):
        return 1 if self.mono else 3

    def apply16(self, o16, noise, tetrahedral):
        """Colour-dependent grain on the 16-bit cube output (lattice mode)."""
        if self.simple:
            return o16
        v = o16.astype(np.int32)
        coords = []
        for c in range(3):
            idx = np.where(v[..., c] < 0x400, v[..., c] >> 1, (v[..., c] >> 7) + 0x1F8)
            e = self.pre[c][np.minimum(idx, 1023)]
            coords.append((e >> 11) + (e & 0x7FF) / 2048.0)
        lm = np.floor(tetrahedral(self.lattice, *coords)).astype(np.int32)
        n0 = noise[0]
        d = np.empty(v.shape, np.int32)
        d[..., 0] = (lm[..., 0] * n0) >> 7
        if self.mono:
            d[..., 1] = (lm[..., 1] * n0) >> 7
            d[..., 2] = (lm[..., 3] * n0) >> 7
        else:
            n1, n2 = noise[1], noise[2]
            d[..., 1] = (lm[..., 1] * n0 + lm[..., 2] * n1) >> 7
            d[..., 2] = (lm[..., 3] * n0 + lm[..., 4] * n1 + lm[..., 5] * n2) >> 7
        return np.clip(v + d, 0, 0xFFFF)

    def apply8(self, out8, noise):
        """Mono grain on the 8-bit output (simple mode)."""
        if not self.simple:
            return out8
        v = out8.astype(np.int32)
        n0 = noise[0][..., None]
        amp = np.stack([self.amp[c][v[..., c]] for c in range(3)], axis=-1)
        return np.clip(v + ((n0 * amp + 0x400) >> 11), 0, 255).astype(np.uint8)


# ---------------------------------------------------------------- halation

def halation_profile(payload, code):
    """0x34-byte records: char code[4], i32 p0[3], i32 p1[3], i32 c[6] (c0/c1 interleaved)."""
    addr = HALO_PROFILES
    while payload[addr - PAYLOAD_BASE] != 0x11:
        rec = payload[addr - PAYLOAD_BASE: addr - PAYLOAD_BASE + 0x34]
        if rec[:4] == code.encode("ascii"):
            v = struct.unpack_from("<12i", rec, 4)
            return {"p": np.array([v[0:3], v[3:6]], np.float64) / 32768.0,
                    "c": np.array([[v[6], v[8], v[10]], [v[7], v[9], v[11]]], np.float64) / 65536.0}
        addr += 0x34
    return None


def _kernel(payload, addr, n=35):
    k = np.array(_u(payload, addr, "<%dH" % n), np.float64)
    nz = np.nonzero(k)[0]
    return k[nz[0]:nz[-1] + 1]


def _conv_norm(a, k, axis):
    """Symmetric convolution, renormalised by the taps that fall inside (firmware edge rule)."""
    r = len(k) // 2
    a = np.moveaxis(a, axis, -1)
    n = a.shape[-1]
    out = np.zeros_like(a)
    wsum = np.zeros(n)
    for j, w in enumerate(k):
        s = j - r
        lo, hi = max(0, -s), min(n, n - s)
        out[..., lo:hi] += w * a[..., lo + s:hi + s]
        wsum[lo:hi] += w
    return np.moveaxis(out / wsum, -1, axis)


def _resize_bilinear(a, new_h, new_w):
    def axis_weights(n_src, n_dst):
        pos = np.clip((np.arange(n_dst) + 0.5) * n_src / n_dst - 0.5, 0, n_src - 1)
        i0 = np.minimum(np.floor(pos).astype(int), n_src - 2) if n_src > 1 else np.zeros(n_dst, int)
        return i0, pos - i0
    r0, rf = axis_weights(a.shape[0], new_h)
    c0, cf = axis_weights(a.shape[1], new_w)
    rows = a[r0] * (1 - rf)[:, None] + a[np.minimum(r0 + 1, a.shape[0] - 1)] * rf[:, None]
    return rows[:, c0] * (1 - cf) + rows[:, np.minimum(c0 + 1, a.shape[1] - 1)] * cf


class Halation:
    def __init__(self, payload, profile, matrix, clip, strength,
                 highlight_gain=HALO_HIGHLIGHT_GAIN, mean_gain=HALO_MEAN_GAIN):
        self.payload, self.profile, self.strength = payload, profile, strength / 256.0
        self.clip = np.asarray(clip, np.float32)
        self.highlight_gain, self.mean_gain = highlight_gain, mean_gain
        self.knee = np.array(_u(payload, KNEE_TABLE, "<257H"), np.float32) / 256.0
        # Collection weights: film layer sensitivities (p, Q15) times the camera
        # matrix (Q12 in firmware), i.e. FUN_00994db0's param_1[0x2079..0x207e].
        self.vec = (profile["p"] @ np.asarray(matrix, np.float64)).astype(np.float32)

    def build_map(self, cam):
        """cam: camera RGB, 1.0 = sensor saturation. Returns 2 x 213 x 360 maps in linear units."""
        h, w, _ = cam.shape
        col_edges = (np.arange(MAP_W) * w) // MAP_W
        row_cell = (np.arange(h) * MAP_H) // h
        sums = np.zeros((MAP_H, MAP_W, 3), np.float64)
        for y in range(0, h, 256):
            # Each photosite is clipped at its channel's WB white (FUN_00996450),
            # so a blown source collects as neutral rather than deep red.
            v = np.minimum(cam[y:y + 256].astype(np.float32), self.clip)
            # Only G photosites pass the 0.97 threshold (FUN_00994db0 sets the R
            # and B thresholds to -1). The excess is spread as a neutral (clip-
            # shaped) highlight: putting it in G alone drives the red plane
            # negative and does not match the camera.
            g = v[..., 1]
            t = np.clip((g - 0.97) / 0.03 * 256, 0, 256)
            ti = np.minimum(t.astype(np.int32), 255)
            knee = self.knee[ti] + (t - ti) * (self.knee[ti + 1] - self.knee[ti])
            total = self.mean_gain * v + (self.highlight_gain * g * knee)[..., None] * self.clip
            colsum = np.add.reduceat(total, col_edges, axis=1)
            np.add.at(sums, row_cell[y:y + 256], colsum)
        counts = np.outer(np.bincount(row_cell, minlength=MAP_H),
                          np.diff(np.append(col_edges, w)))[..., None]
        mean = sums / counts
        # Two 720-wide collection cells land in each map column and are summed.
        planes = 2.0 * np.einsum("pc,yxc->pyx", self.vec, mean)
        maps = np.clip(planes, 0, 65535 / 512.0)
        return np.stack([self._blur(m) for m in maps])

    def _blur(self, m):
        p = self.payload
        kh_n, kv_n = _kernel(p, HALO_KERNELS["h_narrow"]), _kernel(p, HALO_KERNELS["v_narrow"])
        kh_w, kv_w = _kernel(p, HALO_KERNELS["h_wide"]), _kernel(p, HALO_KERNELS["v_wide"])
        w_n, w_w = _u(p, HALO_WEIGHTS, "<2i")
        # Half resolution (2x2 mean, last row repeated), wide kernels, back up.
        mm = np.vstack([m, m[-1:]]) if m.shape[0] % 2 else m
        half = mm.reshape(mm.shape[0] // 2, 2, MAP_W // 2, 2).mean(axis=(1, 3))
        half = _conv_norm(_conv_norm(half, kh_w, 1), kv_w, 0)
        very_wide = _resize_bilinear(half, MAP_H, MAP_W)
        narrow = _conv_norm(_conv_norm(m, kh_n, 1), kv_n, 0)
        wide = _conv_norm(_conv_norm(m, kh_w, 1), kv_w, 0)
        out = (0x38E4 * very_wide + w_n * narrow + w_w * wide) / 32768.0
        # Stored as u16 Q9; FUN_00995d5c clamps the interpolated value to 0x7FFF.
        return np.clip(out, 0, 0x7FFF / 512.0)

    def offsets(self, maps, height, width):
        """Per-pixel linear RGB offsets as a generator over 256-row chunks."""
        planes = [_resize_bilinear(m, MAP_H, width) for m in maps]     # columns first
        pos = np.clip((np.arange(height) + 0.5) * MAP_H / height - 0.5, 0, MAP_H - 1)
        r0 = np.minimum(np.floor(pos).astype(int), MAP_H - 2)
        rf = (pos - r0)[:, None]
        c = self.profile["c"].astype(np.float32)
        for y in range(0, height, 256):
            sl = slice(y, y + 256)
            m = [pl[r0[sl]] * (1 - rf[sl]) + pl[r0[sl] + 1] * rf[sl] for pl in planes]
            yield self.strength * (m[0][..., None] * c[0] + m[1][..., None] * c[1])
