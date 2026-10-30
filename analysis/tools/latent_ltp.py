#!/usr/bin/env python3
"""Read Latent film packs (LTPACK2 inside *.LTP) and their LTZ1-coded 3D LUTs.

Container (decrypted, see latent_crypt.py), parsed as in FUN_0098533c:
  0x00 "LTPACK2\\0"
  0x08 u32 index_end        end of header+index; cube data follows
  0x0C u32 0x41             must be 65
  0x10 u32 8000             must be 8000
  0x14 u32 31250            must be 31250 (0x7A12)
  0x18 char[8] film code    e.g. "P400"
  0x20 u16 n_light, u16 n_push, u16 n_grade, u16 n_extra
  0x28 u32 n_cubes          n_light * n_push * n_grade
  0x2C u32 n_extra_words    n_extra * n_grade * n_push
  0x30 u32 sum, 0x34 u32 sum_of_sums   over all u32 words after 0x40
  0x38 u32 (unknown)
  0x3C u32 0x13002          format id
  0x40 i32[n_light]  light axis, Q16 mired (light_mired_q16 in the log)
       i8[n_push]    push/pull axis (stops)          padded to 4
       u8[n_grade]   third axis (paper/grade index)   padded to 4
       u8[n_extra]   optional fourth axis             padded to 4
       (u32 offset, u32 size)[n_cubes]   each points to an LTZ1 blob
       u32[n_extra_words]

LTZ1 blob (FUN_00998f98 header, FUN_00999358 slice decoder):
  0x00 "LTZ1", u8 N (2..65), u8 flags, u8 10, u8 10
  0x08 u32 expected sum, 0x0C u32 expected sum_of_sums of the decoded words
  0x10 u32 stream length
  0x14 3 channels x 10 contexts of: u8 k, u16 freq[k] (sum 1024)
  then u32 rANS state followed by little-endian u16 renormalisation words.
  Output: N slices of N x N u32, each word = c0 | c1 << 11 | c2 << 22
  (11, 11 and 10 bits).
"""
import argparse
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import latent_crypt  # noqa: E402

MASKS = (0x7FF, 0x7FF, 0x3FF)
SHIFTS = (0, 11, 22)
CTX_THRESHOLDS = (1, 2, 3, 5, 7, 10, 15, 22, 34)
ESCAPE = 40


def _ctx_map():
    out, c = [], 0
    for i in range(64):
        while c < 9 and CTX_THRESHOLDS[c] <= i:
            c += 1
        out.append(c)
    return out


CTX_MAP = _ctx_map()


class LTZ1Error(ValueError):
    pass


class _Stream:
    def __init__(self, blob, pos, state):
        self.blob, self.pos, self.x = blob, pos, state

    def renorm(self):
        if self.x < 0x10000:
            self.x = ((self.x << 16) | struct.unpack_from("<H", self.blob, self.pos)[0]) & 0xFFFFFFFF
            self.pos += 2

    def symbol(self, cum):
        slot = self.x & 0x3FF
        s = 0
        while cum[s + 1] <= slot:
            s += 1
        self.x = (self.x >> 10) * (cum[s + 1] - cum[s]) + slot - cum[s]
        self.renorm()
        if s == ESCAPE:
            e = self.x & 0xF
            self.x >>= 4
            self.renorm()
            if e:
                s = (self.x & ((1 << e) - 1)) + (1 << e) + 39
                self.x >>= e
                self.renorm()
        return (s >> 1) ^ -(s & 1)    # zigzag


def _div3(v):
    """(v * 0x5556) >> 16 on a signed 32-bit value, as the ARM code does."""
    return (v * 0x5556) >> 16


def decode_ltz1(blob):
    if blob[:4] != b"LTZ1":
        raise LTZ1Error("bad magic")
    n, flags_raw, b6, b7 = blob[4], blob[5], blob[6], blob[7]
    if flags_raw & 0xEA or not 2 <= n <= 65 or (b6, b7) != (10, 10):
        raise LTZ1Error("bad header")
    flags = (flags_raw & 1) | ((flags_raw >> 4) << 2) | ((flags_raw >> 1) & 2)
    want_sum, want_sum2, stream_len = struct.unpack_from("<3I", blob, 8)

    pos = 0x14
    cums = []                                  # cums[channel][ctx] -> 42 cumulative freqs
    for _ in range(3):
        tables = []
        for _ in range(10):
            k = blob[pos]
            if not 1 <= k <= 41:
                raise LTZ1Error("bad table size")
            freqs = struct.unpack_from("<%dH" % k, blob, pos + 1)
            pos += 1 + 2 * k
            cum = [0]
            for f in freqs[:-1]:
                cum.append(cum[-1] + f)
            if cum[-1] + freqs[-1] != 0x400:
                raise LTZ1Error("frequencies do not sum to 1024")
            cum += [0x400] * (42 - len(cum))
            tables.append(cum)
        cums.append(tables)
    if pos + stream_len != len(blob):
        raise LTZ1Error("stream length mismatch")
    st = _Stream(blob, pos + 4, struct.unpack_from("<I", blob, pos)[0])

    out = [0] * (n * n * n)
    total = total2 = 0
    for z in range(n):
        base = z * n * n
        prev_slice = base - n * n if z else None
        act_prev = [[0] * (n + 2) for _ in range(3)]
        for y in range(n):
            act_cur = [[0] * (n + 2) for _ in range(3)]
            row = base + y * n
            for x in range(n):
                up = out[row - n + x] if y else 0
                left = out[row + x - 1] if x else 0
                upleft = out[row - n + x - 1] if (x and y) else 0
                if prev_slice is not None:
                    p0 = out[prev_slice + y * n + x]
                    p0left = out[prev_slice + y * n + x - 1] if x else 0
                    p0up = out[prev_slice + (y - 1) * n + x] if y else 0
                word = 0
                for c in range(3):
                    m, sh = MASKS[c], SHIFTS[c]
                    a, b, d = (left >> sh) & m, (up >> sh) & m, (upleft >> sh) & m
                    if prev_slice is None:
                        pred = a + b - d
                        if flags >> c & 1:
                            pred = _div3(a + pred + b)
                    elif flags >> c & 1:
                        q, ql, qu = (p0 >> sh) & m, (p0left >> sh) & m, (p0up >> sh) & m
                        pred = _div3((b + q + a) * 2 - d - ql - qu)
                    else:
                        pred = b + a - d
                    act = act_cur[c][x] + act_prev[c][x] + act_prev[c][x + 1] + act_prev[c][x + 2]
                    res = st.symbol(cums[c][CTX_MAP[min(act, 63)]])
                    word |= ((pred + res) & m) << sh
                    act_cur[c][x + 1] = min(abs(res), 255)
                out[row + x] = word
                total = (total + word) & 0xFFFFFFFF
                total2 = (total2 + total) & 0xFFFFFFFF
            act_prev = act_cur
    if (total, total2) != (want_sum, want_sum2):
        raise LTZ1Error("checksum mismatch: got %08x/%08x want %08x/%08x" % (total, total2, want_sum, want_sum2))
    return n, out


class LTPack:
    def __init__(self, path, key):
        self.path, self.key = path, key
        head = latent_crypt.decrypt_file(key, path, length=0x40)
        if head[:8] != b"LTPACK2\0":
            raise ValueError("not an LTPACK2 file")
        self.index_end = struct.unpack_from("<I", head, 8)[0]
        hdr = latent_crypt.decrypt_file(key, path, length=self.index_end)
        u = lambda o: struct.unpack_from("<I", hdr, o)[0]
        if (u(0x0C), u(0x10), u(0x14), u(0x3C)) != (0x41, 8000, 31250, 0x13002):
            raise ValueError("unexpected LTPACK2 constants")
        self.code = hdr[0x18:0x20].rstrip(b"\0").decode("ascii")
        n_light, n_push, n_grade, n_extra = struct.unpack_from("<4H", hdr, 0x20)
        self.n_cubes, self.n_extra_words = u(0x28), u(0x2C)
        o = 0x40
        self.light_mired = [v / 65536 for v in struct.unpack_from("<%di" % n_light, hdr, o)]
        o += 4 * n_light
        self.push = list(struct.unpack_from("<%db" % n_push, hdr, o))
        o += (n_push + 3) & ~3
        self.grade = list(hdr[o:o + n_grade])
        o += (n_grade + 3) & ~3
        self.extra = list(hdr[o:o + n_extra])
        o += (n_extra + 3) & ~3
        self.entries = [struct.unpack_from("<2I", hdr, o + 8 * i) for i in range(self.n_cubes)]
        o += 8 * self.n_cubes
        self.extra_words = list(struct.unpack_from("<%dI" % self.n_extra_words, hdr, o))
        words = struct.unpack_from("<%dI" % ((self.index_end - 0x40) // 4), hdr, 0x40)
        s = s2 = 0
        for w in words:
            s = (s + w) & 0xFFFFFFFF
            s2 = (s2 + s) & 0xFFFFFFFF
        self.index_checksum_ok = (s, s2) == (u(0x30), u(0x34))

    def read(self, off, size):
        """Decrypted bytes [off, off+size) of the pack."""
        nonce = latent_crypt.make_nonce("ltp", self.path)
        with open(self.path, "rb") as f:
            f.seek(off)
            raw = f.read(size)
        return latent_crypt.keystream_xor(self.key, nonce, off, raw)

    def blob(self, i):
        return self.read(*self.entries[i])

    def cube(self, i):
        return decode_ltz1(self.blob(i))

    def tables(self):
        """u16 table block at header 0x38 (offset) / 0x3C (size, 0x13002):
        [0x0000..0x8000] shaper: linear Q16 (step 16, 0..8.0) -> grid * 512
        [0x8001..0x8800] 4096-byte output table (12-bit index -> 8-bit, sRGB-like)
        [0x8801..]       four 1024-entry tables (fine shaper and per-channel curves)"""
        off, size = struct.unpack_from("<2I", self.read(0, 0x40), 0x38)
        return struct.unpack("<%dH" % (size // 2), self.read(off, size))

    def paper_curves(self, grade_i, push_i, extra_i):
        """B&W paper/grade output curves (FUN_009865ac): the extra word is the
        offset of an "LTVC" block = 3 x 4096-byte tables (R, G, B) that replace
        the default 8-bit output table."""
        n_push, n_extra = len(self.push), len(self.extra)
        off = self.extra_words[(grade_i * n_push + push_i) * n_extra + extra_i]
        if not off:
            raise ValueError("no paper curve for this paper/push/grade")
        blk = self.read(off, 0x3004)
        if blk[:4] != b"LTVC":
            raise ValueError("bad LTVC block at 0x%x" % off)
        return [blk[4 + 0x1000 * c: 4 + 0x1000 * (c + 1)] for c in range(3)]

    def summary(self):
        return {
            "code": self.code,
            "light_mired": self.light_mired,
            "push": self.push,
            "grade": self.grade,
            "extra": self.extra,
            "n_cubes": self.n_cubes,
            "index_checksum_ok": self.index_checksum_ok,
        }


def write_cube_text(path, n, words, title):
    """Dump channels as normalised floats in the stored order (c0 c1 c2),
    first index fastest. Axis/colour meaning is not yet confirmed."""
    with open(path, "w") as f:
        f.write('TITLE "%s"\nLUT_3D_SIZE %d\n' % (title, n))
        for w in words:
            f.write("%.6f %.6f %.6f\n" % ((w & 0x7FF) / 2047, (w >> 11 & 0x7FF) / 2047, (w >> 22) / 1023))


def _expand16(w):
    """Cube word -> three 16-bit values, as FUN_0098c00c widens them."""
    r, g, b = w & 0x7FF, w >> 11 & 0x7FF, w >> 22
    return (r << 5 | r >> 6, g << 5 | g >> 6, b << 6 | b >> 4)


def write_display_cube(path, n, words, tables, title):
    """3D LUT whose input is the shaper-encoded value (grid / (N-1)) and whose
    output is the firmware's 8-bit display value / 255."""
    out8 = bytes(struct.pack("<2048H", *tables[0x8001:0x8801]))
    with open(path, "w") as f:
        f.write('TITLE "%s"\nLUT_3D_SIZE %d\n' % (title, n))
        for w in words:
            f.write("%.6f %.6f %.6f\n" % tuple(out8[(v * 0xFFF + 0x8000) >> 16] / 255 for v in _expand16(w)))


def write_shaper(path, tables, size=4096, max_linear=8.0):
    """1D LUT: scene-linear 0..max_linear -> cube input 0..1."""
    sh = tables[:0x8001]
    with open(path, "w") as f:
        f.write('TITLE "Latent shaper"\nLUT_1D_SIZE %d\nDOMAIN_MIN 0 0 0\nDOMAIN_MAX %g %g %g\n' % (size, max_linear, max_linear, max_linear))
        for i in range(size):
            v = int(round(i / (size - 1) * max_linear * 65536))
            j, frac = min(v >> 4, 0x7FFF), v & 0xF
            g = sh[j] + ((frac * (sh[j + 1] - sh[j]) + 8) >> 4)
            y = g / (64 * 512)
            f.write("%.6f %.6f %.6f\n" % (y, y, y))


def cube_index(pack, light_i, push_i, grade_i):
    """Index order used by FUN_0098533c: light fastest, then push, then grade."""
    return (grade_i * len(pack.push) + push_i) * len(pack.light_mired) + light_i


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--autoexec", required=True)
    p.add_argument("ltp")
    p.add_argument("--cube", type=int, help="decode this cube index")
    p.add_argument("--at", nargs=3, type=int, metavar=("LIGHT", "PUSH", "GRADE"),
                   help="select the cube by axis indices instead of --cube")
    p.add_argument("--out", help="write the decoded cube as raw normalised channels")
    p.add_argument("--export", help="write <prefix>.cube (display output) and <prefix>_shaper.cube")
    a = p.parse_args()
    pack = LTPack(a.ltp, latent_crypt.load_key(a.autoexec))
    for k, v in pack.summary().items():
        print("%s: %s" % (k, v))
    idx = cube_index(pack, *a.at) if a.at else a.cube
    if idx is not None:
        n, words = pack.cube(idx)
        print("cube %d: N=%d, checksum ok" % (idx, n))
        title = "%s #%d" % (pack.code, idx)
        if a.out:
            write_cube_text(a.out, n, words, title)
        if a.export:
            t = pack.tables()
            write_display_cube(a.export + ".cube", n, words, t, title)
            write_shaper(a.export + "_shaper.cube", t)


if __name__ == "__main__":
    sys.exit(main())
