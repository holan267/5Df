#!/usr/bin/env python3
# /// script
# requires-python = ">=3.9"
# dependencies = ["numpy", "numba", "cryptography", "rawpy", "pillow"]
# ///
"""Build lite film packs (see latent_lite.py) from the .LTP packs and their GRAIN.LTG.

    uv run analysis/tools/latent_lite_build.py [P400 V050 ...] [--out LATENT_LITE] [--jobs 2]

The rank of each paper is the smallest step of RANKS whose 99th percentile error, over
every cube of the paper at a 17^3 subset of the nodes, stays under --max-error 8-bit levels,
or the last step within MAX_BASIS if none does.
--keep-cubes keeps the paper<i>.bin already built and redoes everything else.
The output is decrypted film data: keep it as private as the packs themselves.
"""
import argparse
import json
import os
import struct
import sys
import time
import zlib
from concurrent.futures import ProcessPoolExecutor, ThreadPoolExecutor

os.environ.setdefault("OPENBLAS_NUM_THREADS", "4")      # each BLAS thread commits its own buffer
import numpy as np  # noqa: E402
from numba import njit  # noqa: E402

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import latent_color  # noqa: E402
import latent_crypt  # noqa: E402
import latent_effects  # noqa: E402
import latent_lite  # noqa: E402
import latent_ltp  # noqa: E402

RANKS = ((2, 2), (3, 2), (3, 3), (4, 3), (5, 3), (5, 4), (6, 4), (6, 5), (8, 6), (8, 8), (10, 10), (13, 13), (13, 23))
MAX_BASIS = 100 # past this a paper is hardly smaller than its cubes, so the error target gives way
SUBSET = 4      # node step of the subset used for the factors and the rank choice


@njit(nogil=True)
def _decode_ltz1(blob):
    """latent_ltp.decode_ltz1 without the per-node Python; about 200x faster."""
    masks, shifts = (0x7FF, 0x7FF, 0x3FF), (0, 11, 22)
    thresholds = (1, 2, 3, 5, 7, 10, 15, 22, 34)
    ctx_map = np.zeros(64, np.int64)
    k = 0
    for i in range(64):
        while k < 9 and thresholds[k] <= i:
            k += 1
        ctx_map[i] = k

    def u32(p):
        return blob[p] | blob[p + 1] << 8 | blob[p + 2] << 16 | blob[p + 3] << 24

    n, raw = blob[4], blob[5]
    flags = (raw & 1) | ((raw >> 4) << 2) | ((raw >> 1) & 2)
    want, want2 = u32(8), u32(12)
    pos = 0x14
    cums = np.full((3, 10, 42), 0x400, np.int64)
    for c in range(3):
        for t in range(10):
            size = blob[pos]
            total = 0
            for j in range(size):
                cums[c, t, j] = total
                total += blob[pos + 1 + 2 * j] | blob[pos + 2 + 2 * j] << 8
            pos += 1 + 2 * size
    x = u32(pos)
    pos += 4
    out = np.zeros(n * n * n, np.int64)
    total = total2 = 0
    act_prev = np.zeros((3, n + 2), np.int64)
    act_cur = np.zeros((3, n + 2), np.int64)
    for z in range(n):
        base = z * n * n
        act_prev[:] = 0
        for y in range(n):
            act_cur[:] = 0
            row = base + y * n
            for xx in range(n):
                up = out[row - n + xx] if y else 0
                left = out[row + xx - 1] if xx else 0
                upleft = out[row - n + xx - 1] if (xx and y) else 0
                p0 = p0left = p0up = 0
                if z:
                    prev = base - n * n
                    p0 = out[prev + y * n + xx]
                    p0left = out[prev + y * n + xx - 1] if xx else 0
                    p0up = out[prev + (y - 1) * n + xx] if y else 0
                word = 0
                for c in range(3):
                    m, sh = masks[c], shifts[c]
                    a, b, d = (left >> sh) & m, (up >> sh) & m, (upleft >> sh) & m
                    if z == 0:
                        pred = a + b - d
                        if flags >> c & 1:
                            pred = ((a + pred + b) * 0x5556) >> 16
                    elif flags >> c & 1:
                        q, ql, qu = (p0 >> sh) & m, (p0left >> sh) & m, (p0up >> sh) & m
                        pred = (((b + q + a) * 2 - d - ql - qu) * 0x5556) >> 16
                    else:
                        pred = b + a - d
                    cum = cums[c, ctx_map[min(act_cur[c, xx] + act_prev[c, xx] + act_prev[c, xx + 1] + act_prev[c, xx + 2], 63)]]
                    slot = x & 0x3FF
                    s = 0
                    while cum[s + 1] <= slot:
                        s += 1
                    x = (x >> 10) * (cum[s + 1] - cum[s]) + slot - cum[s]
                    if x < 0x10000:
                        x = ((x << 16) | blob[pos] | blob[pos + 1] << 8) & 0xFFFFFFFF
                        pos += 2
                    if s == 40:
                        e = x & 0xF
                        x >>= 4
                        if x < 0x10000:
                            x = ((x << 16) | blob[pos] | blob[pos + 1] << 8) & 0xFFFFFFFF
                            pos += 2
                        if e:
                            s = (x & ((1 << e) - 1)) + (1 << e) + 39
                            x >>= e
                            if x < 0x10000:
                                x = ((x << 16) | blob[pos] | blob[pos + 1] << 8) & 0xFFFFFFFF
                                pos += 2
                    res = (s >> 1) ^ -(s & 1)
                    word |= ((pred + res) & m) << sh
                    act_cur[c, xx + 1] = min(abs(res), 255)
                out[row + xx] = word
                total = (total + word) & 0xFFFFFFFF
                total2 = (total2 + total) & 0xFFFFFFFF
            act_prev, act_cur = act_cur, act_prev
    return out, total == want and total2 == want2


def load_levels(pack, i, curve):
    """Cube i as [3][z][y][x] floats in 8-bit output levels."""
    words, ok = _decode_ltz1(np.frombuffer(pack.blob(i), np.uint8).astype(np.int64))
    if not ok:
        raise latent_ltp.LTZ1Error("checksum mismatch in %s cube %d" % (pack.code, i))
    r, g, b = words & 0x7FF, words >> 11 & 0x7FF, words >> 22
    c16 = np.stack(((r << 5) | (r >> 6), (g << 5) | (g >> 6), (b << 6) | (b >> 4)))
    return latent_lite.to_levels(c16, curve).astype(np.float32).reshape(3, latent_lite.GRID, latent_lite.GRID, -1)


def choose_rank(sample, max_error):
    """sample: [push row][light][node]. Returns orthonormal factors (A, B) and the p99 error."""
    rows, lights = sample.shape[:2]
    flat = sample.reshape(rows, -1)
    Up = np.linalg.svd(flat @ flat.T)[0]
    flat = sample.transpose(1, 0, 2).reshape(lights, -1)
    Ul = np.linalg.svd(flat @ flat.T)[0]
    seen = set()
    for rp, rl in RANKS:
        rp, rl = min(rp, rows), min(rl, lights)
        if (rp, rl) in seen or rp * rl > MAX_BASIS:
            continue
        seen.add((rp, rl))
        A, B = Up[:, :rp], Ul[:, :rl]
        fit = (A @ A.T) @ np.moveaxis(np.moveaxis(sample, 1, 2) @ (B @ B.T), 2, 1).reshape(rows, -1)
        err = float(np.percentile(np.abs(fit - sample.reshape(rows, -1)), 99))
        if err <= max_error:
            break
    return A, B, err


def build_paper(pack, grade_i, rows, curve, a, threads):
    n_light, grid = len(pack.light_mired), latent_lite.GRID
    ids = [latent_ltp.cube_index(pack, l, p, grade_i) for p in rows for l in range(n_light)]
    with ThreadPoolExecutor(threads) as ex:
        cubes = list(ex.map(lambda i: load_levels(pack, i, curve).ravel(), ids))
    Y = np.stack(cubes)                                         # [cube][node]
    del cubes
    mask = np.zeros((3, grid, grid, grid), bool)
    mask[:, ::SUBSET, ::SUBSET, ::SUBSET] = True
    sample = Y[:, mask.ravel()].reshape(len(rows), n_light, -1).astype(np.float64)
    A, B, err = choose_rank(sample, a.max_error)
    # Weights peak at 1, so a basis cube's values are its largest contribution, in levels.
    A, B = A / np.abs(A).max(0), B / np.abs(B).max(0)
    W = np.linalg.pinv(np.kron(A, B)).astype(np.float32)        # [basis][cube]
    basis = (W @ Y).reshape(-1, 3, grid, grid, grid)
    blob = latent_lite.encode_basis(basis, a.delta)
    meta = {
        "file": "paper%d.bin" % grade_i, "delta": a.delta, "push_rows": rows,
        "push_w": np.round(A, 6).tolist(), "light_w": np.round(B, 6).tolist(),
    }
    return meta, blob, err, sum(pack.entries[i][1] for i in ids)


def build_grain(pack, folder, a, key):
    path = os.path.join(a.latent_dir, pack.code, "GRAIN.LTG")
    for g in range(len(pack.grade)):
        blocks = [latent_effects.read_grain_block(path, key, g, p) for p in range(len(pack.push))]
        with open(os.path.join(folder, "grain%d.bin" % g), "wb") as f:
            f.write(latent_lite.encode_grain(np.frombuffer(b"".join(blocks), np.uint8).reshape(len(blocks), -1)))


def build_film(ltp, a):
    t0 = time.time()
    key = latent_crypt.load_key(a.autoexec)
    pack = latent_ltp.LTPack(ltp, key)
    folder = os.path.join(a.out, pack.code)
    os.makedirs(folder, exist_ok=True)
    build_grain(pack, folder, a, key)
    log = []
    if not a.keep_cubes:
        build_cubes(pack, folder, a, log)
    total = sum(os.path.getsize(os.path.join(folder, n)) for n in os.listdir(folder))
    log.append("%s: %.1f -> %.1f MB in %.0f s" % (pack.code, os.path.getsize(ltp) / 1e6, total / 1e6, time.time() - t0))
    return "\n".join(log)


def build_cubes(pack, folder, a, log):
    tables = pack.tables()
    curve = latent_lite.output_curve(tables)
    n_push = len(pack.push)
    papers = []
    for g in range(len(pack.grade)):
        rows = [p for p in range(n_push) if pack.entries[latent_ltp.cube_index(pack, 0, p, g)][1]]
        if not rows:        # a B&W paper whose cubes live on the first B&W row
            papers.append({"push_rows": []})
            continue
        meta, blob, err, size = build_paper(pack, g, rows, curve, a, a.threads)
        with open(os.path.join(folder, meta["file"]), "wb") as f:
            f.write(blob)
        papers.append(meta)
        log.append("  %s paper %d: rank %dx%d, p99 %.2f levels, %.1f -> %.2f MB" % (
            pack.code, g, len(meta["push_w"][0]), len(meta["light_w"][0]), err, size / 1e6, len(blob) / 1e6))

    offsets = sorted({w for w in pack.extra_words if w})
    curve_map = [offsets.index(w) + 1 if w else 0 for w in pack.extra_words]
    if offsets:
        raw = b"".join(pack.read(o, 0x3004)[4:] for o in offsets)
        with open(os.path.join(folder, "curves.bin"), "wb") as f:
            f.write(zlib.compress(raw, 9))
    with open(os.path.join(folder, "tables.bin"), "wb") as f:
        f.write(zlib.compress(struct.pack("<%dH" % len(tables), *tables), 9))
    with open(os.path.join(folder, latent_lite.INDEX), "w") as f:
        json.dump({
            "code": pack.code, "light_mired": pack.light_mired, "push": pack.push,
            "grade": pack.grade, "extra": pack.extra, "papers": papers, "curve_map": curve_map,
        }, f, separators=(",", ":"))


def firmware_ranges(p):
    """(address, length) of what the darkroom reads from the payload."""
    sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "app"))
    import latent_app
    import latent_traits
    base = latent_color.PAYLOAD_BASE
    ptrs = lambda addr, n: struct.unpack_from("<%dI" % n, p, addr - base)
    cstr = lambda addr: (addr, p.index(b"\0", addr - base) - (addr - base) + 1)
    keep = [(latent_color.CAMERA_TABLE, 0x70), cstr(ptrs(latent_color.CAMERA_TABLE, 1)[0]),
            (latent_color.BRADFORD, 72), (latent_color.XYZ_TO_RGB, 72),
            (latent_effects.GAUSS_TABLE, 256), (latent_effects.KNEE_TABLE, 514), (latent_effects.HALO_WEIGHTS, 8)]
    keep += [(addr, 70) for addr in latent_effects.HALO_KERNELS.values()]
    addr = latent_effects.HALO_PROFILES
    while p[addr - base] != 0x11:
        addr += 0x34
    keep.append((latent_effects.HALO_PROFILES, addr + 1 - latent_effects.HALO_PROFILES))
    for table, n in ((latent_app.PAPER_NAMES, 19), (latent_traits.FAMILY_NAMES, 5), (latent_traits.BRAND_NAMES, 5)):
        keep.append((table, 4 * n))
        keep += [cstr(s) for s in ptrs(table, n)]
    keep.append((latent_traits.CATALOGUE, 12 * latent_traits.CATALOGUE_N))
    for i in range(latent_traits.CATALOGUE_N):
        keep.append(cstr(ptrs(latent_traits.CATALOGUE + 12 * i, 1)[0]))
    return keep


def write_firmware(a):
    """A payload that holds only the tables, so the packs work without AUTOEXEC.BIN and its key."""
    p, base = latent_color._payload(a.autoexec), latent_color.PAYLOAD_BASE
    keep = firmware_ranges(p)
    key_lo, key_hi = latent_crypt.KEY_A, latent_crypt.KEY_B + 32
    if any(addr < key_hi and addr + n > key_lo for addr, n in keep):
        raise ValueError("a firmware table overlaps the key")
    out = bytearray(len(p))
    for addr, n in keep:
        out[addr - base:addr - base + n] = p[addr - base:addr - base + n]
    path = os.path.join(a.out, latent_lite.FIRMWARE)
    with open(path, "wb") as f:
        f.write(out)
    return path


def write_shared(a):
    import latent_traits        # needs rawpy and Pillow, which the film workers do not
    firmware = write_firmware(a)
    packs = {}
    for f in sorted(os.listdir(a.out)):
        if os.path.isfile(os.path.join(a.out, f, latent_lite.INDEX)):
            packs[f] = latent_lite.LitePack(os.path.join(a.out, f))
    traits = latent_traits.traits(packs, latent_color._payload(firmware))
    with open(os.path.join(a.out, latent_lite.TRAITS), "w", encoding="utf-8") as f:
        json.dump(traits, f, ensure_ascii=False, separators=(",", ":"))
    files = {}
    for folder, _, names in os.walk(a.out):
        for n in names:
            path = os.path.join(folder, n)
            if n != latent_lite.MANIFEST:
                with open(path, "rb") as f:
                    data = f.read()
                files[os.path.relpath(path, a.out).replace(os.sep, "/")] = [len(data), "%08x" % zlib.crc32(data)]
    with open(os.path.join(a.out, latent_lite.MANIFEST), "w") as f:
        json.dump({"files": dict(sorted(files.items()))}, f, separators=(",", ":"))
    return sum(v[0] for v in files.values())


def main():
    repo = os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("films", nargs="*", help="film codes (default: every pack)")
    p.add_argument("--autoexec", default=os.path.join(repo, "AUTOEXEC.BIN"))
    p.add_argument("--latent-dir", default=os.path.join(repo, "LATENT"))
    p.add_argument("--out", default=os.path.join(repo, "LATENT_LITE"))
    p.add_argument("--delta", type=float, default=0.5, help="basis quantisation step, in 8-bit levels (default 0.5)")
    p.add_argument("--max-error", type=float, default=0.75, help="p99 target for the rank choice, in 8-bit levels (default 0.75)")
    p.add_argument("--jobs", type=int, default=2, help="films built at once, about 1.5 GB each (default 2)")
    p.add_argument("--threads", type=int, default=4, help="LTZ1 decode threads per film (default 4)")
    p.add_argument("--keep-cubes", action="store_true", help="keep the paper<i>.bin already in --out")
    a = p.parse_args()
    films = [f.upper() for f in a.films] or sorted(f[:-4].upper() for f in os.listdir(a.latent_dir) if f.upper().endswith(".LTP"))
    paths = [os.path.join(a.latent_dir, f + ".LTP") for f in films]
    with ProcessPoolExecutor(a.jobs) as ex:
        for line in ex.map(build_film, paths, [a] * len(paths)):
            print(line, flush=True)
    print("total %.1f MB" % (write_shared(a) / 1e6))


if __name__ == "__main__":
    sys.exit(main())
