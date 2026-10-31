#!/usr/bin/env python3
# /// script
# requires-python = ">=3.9"
# dependencies = ["numpy", "rawpy==0.27.*", "pillow"]
# ///
"""Dump the Python pipeline's numbers, the reference for analysis/engine.

    uv run analysis/tools/latent_golden.py [--out analysis/engine/golden] [--only CASE ...]

Runs the real functions of latent_develop / latent_effects on the raws at the repo root and
the packs in analysis/app/public/LATENT_LITE, capturing each stage by wrapping them, so
nothing here restates the pipeline except the few lines of Studio.render that call it.
Each case gets a folder: manifest.json, and .bin files in little-endian, array order:
  rgb.bin        u2 [h][w][3]         decoded camera RGB
  cube.bin       f4 [b][g][r][3]      blended cube
  noise.bin      i4 [streams][h][w]
  offsets.bin    f8 [h][w][3]         halation offsets; maps.bin f8 [2][213][360]
  lin_in.bin     f4/f8 [h][w][3]      input of gamut_compress
  lin.bin        same                 its output
  g.bin          f8 [h][w][3]         shaper output, grid coordinates
  tetra.bin      f4 [h][w][3]         tetrahedral output
  o16.bin        f4 [h][w][3]         after apply16
  out.bin        u1 [h][w][3]         final, before rotation and JPEG
Cases with "full" keep only rgb, noise and out.
"""
import argparse
import json
import os
import sys

import numpy as np
import rawpy

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", ".."))
sys.path.insert(0, HERE)
import latent_color  # noqa: E402
import latent_develop as ld  # noqa: E402
import latent_effects  # noqa: E402
import latent_lite  # noqa: E402

LITE = os.path.join(REPO, "analysis", "app", "public", "LATENT_LITE")
FIRMWARE = os.path.join(LITE, latent_lite.FIRMWARE)
CR2, CR1DX, ARW = "IMG_0002.CR2", "IMGL6133.CR2", "DSC01209.ARW"

CASES = {
    "p400":          dict(file=CR2, film="P400"),
    "p400_3200_ev1": dict(file=CR2, film="P400", kelvin=3200, exposure=1.0),
    "p400_nograin":  dict(file=CR2, film="P400", grain=False),
    "p400_nogamut":  dict(file=CR2, film="P400", gamut=False, push=2, paper=3),
    "hp5p_bw":       dict(file=CR2, film="HP5P", paper=0, grade=5),
    "hp5p_push":     dict(file=CR2, film="HP5P", paper=1, push=2, grade=3, kelvin=5000),
    "d250_halo":     dict(file=CR2, film="D250", halation=2),
    "d250_halo_ev":  dict(file=CR2, film="D250", halation=1, exposure=-1.0),
    "t500_1dx":      dict(file=CR1DX, film="T500", halation=0),
    "p400_arw":      dict(file=ARW, film="P400", scale=2),
    "pbw4_arw":      dict(file=ARW, film="PBW4", paper=0, grade=5),
    "p400_full":     dict(file=CR2, film="P400", scale=1, full=True),
}
DEFAULT = dict(paper=0, push=0, grade=5, kelvin=None, exposure=0.0, grain=True, gamut=True, halation=2, scale=4, full=False)


def source(path, scale):
    src = ld.open_raw(path, FIRMWARE)
    load = src.pop("load")
    src["levels"] = dict(zip(load.__code__.co_freevars, (c.cell_contents for c in load.__closure__)))
    rgb = load(scale > 1)
    if scale == 4:
        h, w = rgb.shape[0] // 2 * 2, rgb.shape[1] // 2 * 2
        rgb = rgb[:h, :w].reshape(h // 2, 2, w // 2, 2, 3).mean(axis=(1, 3)).astype(np.uint16)
    src["rgb"] = rgb
    return src


def cube(pack, i0, i1, w):
    c = ld.load_cube16(pack, i0)
    if i1 != i0 and w > 0:
        c = (1 - w) * c + w * ld.load_cube16(pack, i1)
    return c


class Capture:
    """Swaps the pipeline's stages for wrappers that keep what goes through them."""

    def __init__(self):
        self.arrays = {k: [] for k in ("lin_in", "lin", "g", "tetra", "o16", "offsets")}
        self.saved = ld.gamut_compress, ld.shaper, ld.tetrahedral

    def __enter__(self):
        gamut, shaper, tetrahedral = self.saved

        def gamut_compress(lin, curves):
            out = gamut(lin, curves)
            self.arrays["lin_in"].append(lin.copy())
            self.arrays["lin"].append(out.copy())
            return out

        def shaper_w(lin, table):
            if not self.gamut_on:
                self.arrays["lin_in"].append(lin.copy())
                self.arrays["lin"].append(lin.copy())
            g = shaper(lin, table)
            self.arrays["g"].append(g.copy())
            return g

        def tetrahedral_w(c, r, g, b):
            out = tetrahedral(c, r, g, b)
            if c.shape[-1] == 3:
                self.arrays["tetra"].append(np.clip(out, 0, 65535))
            return out
        ld.gamut_compress, ld.shaper, ld.tetrahedral = gamut_compress, shaper_w, tetrahedral_w
        return self

    def __exit__(self, *exc):
        ld.gamut_compress, ld.shaper, ld.tetrahedral = self.saved

    def grain(self, grain):
        if grain is None:
            return
        apply16 = grain.apply16

        def wrapped(o16, n, tet):
            out = apply16(o16, n, tet)
            self.arrays["o16"].append(np.asarray(out, np.float32).copy())
            return out
        grain.apply16 = wrapped

    def offsets(self, gen):
        for chunk in gen:
            self.arrays["offsets"].append(chunk.copy())
            yield chunk


def save(folder, name, a):
    a.astype(a.dtype.newbyteorder("<")).tofile(os.path.join(folder, name + ".bin"))


def run(name, case, out):
    p = {**DEFAULT, **case}
    folder = os.path.join(out, name)
    os.makedirs(folder, exist_ok=True)
    path = os.path.join(REPO, p["file"])
    pack = latent_lite.LitePack(os.path.join(LITE, p["film"]))
    payload = latent_color._payload(FIRMWARE)

    # Studio.render, up to develop().
    src = source(path, p["scale"])
    meta, clip, rgb = src["meta"], src["clip"], src["rgb"]
    mired = 1e6 / p["kelvin"] if p["kelvin"] else src["mired"]
    i0, i1, w, paper_curves = ld.select_cubes(pack, p["paper"], p["push"], p["grade"], mired)
    c = cube(pack, i0, i1, w)
    tables = pack.tables()
    height, width = rgb.shape[:2]
    matrix = (np.asarray(src["matrix"]) * 2 ** p["exposure"]).tolist()

    halo, maps, offsets = None, None, None
    profile = latent_effects.halation_profile(payload, pack.code)
    if profile is not None and p["halation"] >= 0:
        halo = latent_effects.Halation(payload, profile, matrix, clip, latent_effects.HALO_LEVELS[p["halation"]])
        maps = halo.build_map(rgb.astype(np.float32) / 65535.0)
        offsets = halo.offsets(maps, height, width)

    grain, noise, seed, card_path = None, None, None, None
    if p["grain"]:
        push_i = pack.push.index(p["push"])
        grain = ld.load_grain(pack, None, None, p["paper"], push_i, p["grade"])
        card_path = "A:/DCIM/%s/" % src["card_dir"] + os.path.basename(path).upper()
        seed = latent_effects.fnv1a_seed(card_path)
        noise = latent_effects.grain_noise(payload, seed, height, width, grain.streams())

    save(folder, "rgb", rgb)
    if noise is not None:
        save(folder, "noise", noise.astype(np.int32))
    if p["full"]:
        img = ld.develop(rgb, clip, matrix, tables, c, paper_curves, gamut=p["gamut"], halo_offsets=offsets,
                         grain=grain, noise=noise)
    else:
        save(folder, "cube", c)
        if maps is not None:
            save(folder, "maps", maps)
        with Capture() as cap:
            cap.gamut_on = p["gamut"]
            cap.grain(grain)
            img = ld.develop(rgb, clip, matrix, tables, c, paper_curves, gamut=p["gamut"],
                             halo_offsets=cap.offsets(offsets) if offsets is not None else None,
                             grain=grain, noise=noise)
        for k, chunks in cap.arrays.items():
            if chunks:
                save(folder, k, np.concatenate(chunks))
    save(folder, "out", img)

    with rawpy.imread(path) as raw:
        s = raw.sizes
        cw = raw.camera_white_level_per_channel
        raw_info = {
            "colors": raw.num_colors, "pattern": np.asarray(raw.raw_pattern).ravel().tolist(),
            "black": [int(v) for v in raw.black_level_per_channel],
            "linear_max": [0] * 4 if cw is None else [int(v) for v in cw],
            "maximum": int(raw.white_level), "cam_mul": [float(v) for v in raw.camera_whitebalance],
            "pre_mul": [float(v) for v in raw.daylight_whitebalance],
            "cam_xyz": np.asarray(raw.rgb_xyz_matrix[:3], np.float64).tolist(),
            "size": [s.width, s.height, s.top_margin, s.left_margin],
            "crop": [s.crop_left_margin, s.crop_top_margin, s.crop_width, s.crop_height],
        }
    with open(os.path.join(folder, "manifest.json"), "w") as f:
        json.dump({
            "case": p, "raw": raw_info, "crop_used": [int(v) for v in src["levels"]["crop"]],
            "black": src["levels"]["black"], "white": src["levels"]["white"], "model": meta["model"], "make": meta["make"], "wb": [float(v) for v in meta["wb"]],
            "orientation": meta["orientation"], "width": width, "height": height,
            "matrix": src["matrix"], "matrix_ev": matrix, "clip": [float(v) for v in clip], "mired": mired,
            "scene_mired": src["mired"], "baseline_exposure": src["baseline_exposure"], "card_dir": src["card_dir"],
            "cubes": [i0, i1], "weight": w, "bw_curves": bool(paper_curves), "seed": seed, "card_path": card_path,
            "grain": None if grain is None else {"mono": grain.mono, "simple": grain.simple, "streams": grain.streams()},
            "halation": None if halo is None else latent_effects.HALO_LEVELS[p["halation"]],
            "lin_dtype": "f8" if offsets is not None else "f4",
            "out_mean": float(img.mean()),
        }, f, indent=1)
    print("%-14s %dx%d cubes %s w=%.3f mean=%.2f" % (name, width, height, [i0, i1], w, img.mean()))


def ramp(out):
    """Edge cases of gamut + shaper + cube, without a raw."""
    folder = os.path.join(out, "ramp")
    os.makedirs(folder, exist_ok=True)
    pack = latent_lite.LitePack(os.path.join(LITE, "P400"))
    tables = pack.tables()
    rng = np.random.default_rng(7)
    edge = np.array([v for v in np.ndindex(5, 5, 5)], np.float32) / 4
    lin = np.concatenate([
        edge, edge * 8, edge * 16, edge - 0.25, np.zeros((4, 3), np.float32),
        np.array([[0, 0, -1], [-1, -1, -1], [8, 0, 0], [7.999, 7.999, 7.999], [1e-6, 0, 0], [16, 16, 16]], np.float32),
        rng.random((20000, 3), np.float32) * np.array([[1, 1, 1]], np.float32),
        (rng.random((20000, 3), np.float32) ** 3) * 10 - 0.5,
    ]).astype(np.float32)
    gamut_t = [np.asarray(tables[s:s + 0x400], dtype=np.float32) for s in (0x8C01, 0x9001, 0x9401)]
    shaper_t = np.asarray(tables[:0x8001], dtype=np.float32)
    c = ld.load_cube16(pack, 63)
    out_lin = ld.gamut_compress(lin, gamut_t)
    g = ld.shaper(out_lin, shaper_t)
    tetra = np.clip(ld.tetrahedral(c, g[..., 0], g[..., 1], g[..., 2]), 0, 65535)
    # f8 input takes the promotions of the halation path.
    lin64 = lin.astype(np.float64)
    out64 = ld.gamut_compress(lin64, gamut_t)
    save(folder, "lin_in", lin)
    save(folder, "lin", out_lin)
    save(folder, "g", g)
    save(folder, "tetra", tetra)
    save(folder, "lin64", out64)
    save(folder, "g64", ld.shaper(out64, shaper_t))
    with open(os.path.join(folder, "manifest.json"), "w") as f:
        json.dump({"n": len(lin), "film": "P400", "cube": 63}, f)
    print("ramp           %d points" % len(lin))


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--out", default=os.path.join(REPO, "analysis", "engine", "golden"))
    ap.add_argument("--only", nargs="*")
    a = ap.parse_args()
    for name, case in CASES.items():
        if not a.only or name in a.only:
            run(name, case, a.out)
    if not a.only or "ramp" in a.only:
        ramp(a.out)


if __name__ == "__main__":
    sys.exit(main())
