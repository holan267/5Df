#!/usr/bin/env python3
# /// script
# requires-python = ">=3.9"
# dependencies = ["numpy", "rawpy", "pillow"]
# ///
"""Describe each Latent film by probing its cubes with synthetic targets.

    uv run analysis/tools/latent_traits.py [P400 V050 ...] [--json out.json]

Every film is measured the same way, at its default print (paper #0, push 0,
grade index 5) under the light it is balanced for (5500 K, or 3200 K for the
tungsten "...T" stocks):
  - a grey ramp from -10 to +7 stops around scene grey 0.18 (linear Rec.709,
    the cube input, README section 5.1) gives the tone curve: black and white
    levels, mid-grey, mid-tone contrast, where the toe and shoulder start;
  - the grey ramp's OKLab a/b in shadows, mid-tones and highlights gives the
    neutral balance (warm/cool, green/magenta);
  - the 18 colour patches of a ColorChecker (BabelColor sRGB values) give
    saturation and hue shifts per colour group, against a plain sRGB rendering
    of the same patches.
Same pipeline as latent_develop.develop() minus grain/halation: gamut
compression, shaper, tetrahedral cube, 8-bit output table (or LTVC curves).
The words are relative to the films in LATENT/ as well as absolute, so they
read as "compared with the rest of this set".
"""
import argparse
import json
import os
import struct
import sys

import numpy as np

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import latent_color  # noqa: E402
import latent_crypt  # noqa: E402
import latent_develop as ld  # noqa: E402
import latent_ltp  # noqa: E402

# Film catalogue at 0x9B2254: 81 x {char *name, char code[4], u16 ISO, u8 brand, u8 family}.
CATALOGUE, CATALOGUE_N = 0x9B2254, 81
FAMILY_NAMES, BRAND_NAMES = 0x9B2620, 0x9B2634     # 5 and 5 char * pointers

GREY = 0.18
RAMP = np.arange(-10, 7.001, 0.25)                 # stops around GREY
CURVE = np.arange(-8, 6.001, 0.5)                  # points sent to the UI

# ColorChecker 24, sRGB 8-bit (BabelColor, D65). Neutrals are the last row.
CHECKER = {
    "dark skin": (115, 82, 68), "light skin": (194, 150, 130), "blue sky": (98, 122, 157),
    "foliage": (87, 108, 67), "blue flower": (133, 128, 177), "bluish green": (103, 189, 170),
    "orange": (214, 126, 44), "purplish blue": (80, 91, 166), "moderate red": (193, 90, 99),
    "purple": (94, 60, 108), "yellow green": (157, 188, 64), "orange yellow": (224, 163, 46),
    "blue": (56, 61, 150), "green": (70, 148, 73), "red": (175, 54, 60),
    "yellow": (231, 199, 31), "magenta": (187, 86, 149), "cyan": (8, 133, 161),
}
GROUPS = {
    "skin": ("dark skin", "light skin"),
    "reds": ("red", "moderate red", "magenta"),
    "oranges": ("orange", "orange yellow"),
    "yellows": ("yellow", "yellow green"),
    "greens": ("green", "foliage", "bluish green"),
    "blues": ("blue", "blue sky", "purplish blue", "cyan"),
}


# ---------------------------------------------------------------- colour maths

def srgb_to_linear(v):
    v = np.asarray(v, np.float64) / 255.0
    return np.where(v <= 0.04045, v / 12.92, ((v + 0.055) / 1.055) ** 2.4)


def linear_to_srgb8(v):
    v = np.clip(v, 0, 1)
    return np.round(255 * np.where(v <= 0.0031308, 12.92 * v, 1.055 * v ** (1 / 2.4) - 0.055))


def oklab(srgb8):
    """sRGB 8-bit -> OKLab (L 0..1, a, b)."""
    lin = srgb_to_linear(srgb8)
    lms = lin @ np.array([[0.4122214708, 0.5363325363, 0.0514459929],
                          [0.2119034982, 0.6806995451, 0.1073969566],
                          [0.0883024619, 0.2817188376, 0.6299787005]]).T
    lms = np.cbrt(lms)
    return lms @ np.array([[0.2104542553, 0.7936177850, -0.0040720468],
                           [1.9779984951, -2.4285922050, 0.4505937099],
                           [0.0259040371, 0.7827717662, -0.8086757660]]).T


def hue_delta(a, b):
    """Signed hue difference a - b in degrees, -180..180."""
    return (a - b + 180) % 360 - 180


# ---------------------------------------------------------------- catalogue

def catalogue(payload):
    """Film code -> {name, iso, brand, family} from the firmware's own table."""
    def cstr(addr):
        o = addr - latent_color.PAYLOAD_BASE
        return payload[o:payload.index(b"\0", o)].decode("utf-8", "replace")
    ptrs = lambda addr, n: struct.unpack_from("<%dI" % n, payload, addr - latent_color.PAYLOAD_BASE)
    families, brands = [cstr(a) for a in ptrs(FAMILY_NAMES, 5)], [cstr(a) for a in ptrs(BRAND_NAMES, 5)]
    out = {}
    for i in range(CATALOGUE_N):
        name, code, iso, brand, family = struct.unpack_from(
            "<I4sHBB", payload, CATALOGUE + 12 * i - latent_color.PAYLOAD_BASE)
        out[code.decode("ascii")] = {"name": cstr(name), "iso": iso,
                                     "brand": brands[brand], "family": families[family]}
    return out


def native_kelvin(pack, name):
    k = 3200 if name.rstrip().endswith("T") else 5500
    lo, hi = 1e6 / pack.light_mired[-1], 1e6 / pack.light_mired[0]
    return min(max(k, lo), hi)


# ---------------------------------------------------------------- probe

def render(pack, lin, kelvin, paper=0, push=0, grade=5):
    """Linear Rec.709 (N, 3) -> output sRGB 8-bit (N, 3), as develop() without grain/halation."""
    i0, i1, w, curves = ld.select_cubes(pack, paper, push, grade, 1e6 / kelvin)
    cube = ld.load_cube16(pack, i0)
    if i1 != i0 and w > 0:
        cube = (1 - w) * cube + w * ld.load_cube16(pack, i1)
    t = pack.tables()
    gamut_t = [np.asarray(t[s:s + 0x400], np.float32) for s in (0x8C01, 0x9001, 0x9401)]
    if curves:
        out8 = [np.frombuffer(c, np.uint8) for c in curves]
    else:
        out8 = [np.frombuffer(struct.pack("<2048H", *t[0x8001:0x8801]), np.uint8)] * 3
    lin = ld.gamut_compress(np.asarray(lin, np.float32), gamut_t)
    g = ld.shaper(lin, np.asarray(t[:0x8001], np.float32))
    o16 = np.clip(ld.tetrahedral(cube, g[..., 0], g[..., 1], g[..., 2]), 0, 65535)
    i12 = (o16.astype(np.uint32) * 0xFFF + 0x8000) >> 16
    return np.stack([out8[c][i12[..., c]] for c in range(3)], axis=-1).astype(np.float64)


def _at(stops, values, s):
    return float(np.interp(s, stops, values))


def _crossing(stops, values, level):
    """First stop where a rising curve reaches level."""
    i = int(np.argmax(values >= level))
    if i == 0:
        return float(stops[0])
    s0, s1, v0, v1 = stops[i - 1], stops[i], values[i - 1], values[i]
    return float(s0 + (level - v0) / (v1 - v0) * (s1 - s0)) if v1 > v0 else float(s1)


def measure(pack, kelvin):
    names = list(CHECKER)
    patches = srgb_to_linear([CHECKER[n] for n in names])
    ramp = GREY * 2 ** RAMP
    lin = np.concatenate([np.repeat(ramp[:, None], 3, 1), patches])
    out = oklab(render(pack, lin, kelvin))
    grey, col = out[:len(RAMP)], out[len(RAMP):]
    L = np.maximum.accumulate(grey[:, 0])            # tone curve, forced monotonic

    black, white, mid = float(L[0]), float(L[-1]), _at(RAMP, L, 0)
    span = white - black
    toe = _crossing(RAMP, L, black + 0.1 * span)
    shoulder = _crossing(RAMP, L, black + 0.9 * span)
    contrast = (_at(RAMP, L, 1) - _at(RAMP, L, -1)) / 2

    def zone(s0, s1):
        m = (RAMP >= s0) & (RAMP <= s1)
        return [round(float(v), 4) for v in grey[m, 1:].mean(axis=0)]

    # Saturation as OKLab chroma / lightness, so a darker or lighter print of the
    # same colour does not count as more or less saturated.
    ref = oklab(linear_to_srgb8(patches))
    sat = np.hypot(col[:, 1], col[:, 2]) / np.maximum(col[:, 0], 1e-3)
    ref_sat = np.hypot(ref[:, 1], ref[:, 2]) / ref[:, 0]
    hue = np.degrees(np.arctan2(col[:, 2], col[:, 1]))
    ref_hue = np.degrees(np.arctan2(ref[:, 2], ref[:, 1]))
    groups = {}
    for g, members in GROUPS.items():
        idx = [names.index(n) for n in members]
        groups[g] = {
            "saturation": round(float(sat[idx].sum() / ref_sat[idx].sum()), 3),
            "hue_shift": round(float(np.mean(hue_delta(hue[idx], ref_hue[idx]))), 1),
        }
    return {
        "kelvin": round(kelvin),
        "black": round(black, 4), "white": round(white, 4), "mid": round(mid, 4),
        "contrast": round(contrast, 4), "toe": round(toe, 2), "shoulder": round(shoulder, 2),
        "neutral": {"shadows": zone(-4, -2), "mids": zone(-0.5, 0.5), "highlights": zone(1.5, 3)},
        "saturation": round(float(sat.sum() / ref_sat.sum()), 3),
        "mono": bool(np.hypot(col[:, 1], col[:, 2]).mean() < 0.015),
        "groups": groups,
        "curve": [round(_at(RAMP, L, s), 4) for s in CURVE],
        "curve_stops": [float(s) for s in CURVE],
    }


# ---------------------------------------------------------------- words

def _cast(ab, strength=0.006):
    """OKLab a/b -> words like 'warm', 'cool-green', or '' for neutral."""
    a, b = ab
    words = []
    if b > strength:
        words.append("warm")
    elif b < -strength:
        words.append("cool")
    if a > strength:
        words.append("magenta")
    elif a < -strength:
        words.append("green")
    return "-".join(words)


def _pick(z, words):
    """One of 5 words for a score of -2..2 (0 = the set median)."""
    return words[0 if z <= -1.5 else 1 if z <= -0.5 else 2 if z < 0.5 else 3 if z < 1.5 else 4]


HUE_WORDS = {   # positive OKLab hue shift = counter-clockwise: red -> yellow -> green -> blue -> purple
    "skin": ("pinker", "more golden"), "reds": ("more magenta", "more orange"),
    "oranges": ("redder", "more yellow"), "yellows": ("more orange", "more lime"),
    "greens": ("more yellow", "more teal"), "blues": ("more cyan", "more violet"),
}
# One score unit is the set's spread (1.4826 x median absolute deviation), but at least this.
MIN_SCALES = {"contrast": 0.02, "saturation": 0.08, "black": 0.04, "shoulder": 0.3}


def scores(m, med):
    """-2..2 per trait, 0 = the median film of the set; warmth is absolute (OKLab b of mid-grey)."""
    clip = lambda v: round(max(-2.0, min(2.0, v)), 2)
    out = {k: clip((m[k] - med[k]) / med["scale"][k]) for k in MIN_SCALES}
    out["warmth"] = clip(m["neutral"]["mids"][1] / 0.01)
    if m["mono"]:
        out["saturation"] = None
    return out


def describe(m, med):
    """Tags, a short summary and -2..2 scores for one film, relative to the set medians."""
    sc = scores(m, med)
    tags, parts = [], []

    contrast = _pick(sc["contrast"], ("very soft", "soft", "medium", "punchy", "very punchy"))
    tags.append(contrast + " contrast")

    if m["black"] > 0.2:
        shadows = "matte, lifted blacks"
    elif m["black"] > 0.13:
        shadows = "slightly lifted blacks"
    else:
        shadows = "deep blacks"
    tags.append(shadows.split(", ")[0] if "," in shadows else shadows)
    if m["toe"] < med["toe"] - 0.4:
        shadows += " with long shadow detail"
    elif m["toe"] > med["toe"] + 0.4:
        shadows += " that close up quickly"

    if sc["shoulder"] >= 0.75:
        highlights = "a long highlight roll-off"
        tags.append("highlight latitude")
    elif sc["shoulder"] <= -0.75:
        highlights = "highlights that clip early"
    else:
        highlights = "average highlight room"
    highlights += " (white ≈%+.1f stops over grey)" % m["shoulder"]
    if m["white"] < 0.88:
        highlights += " and dim, creamy whites"
    parts.append("%s%s mid-tone contrast, %s, %s" % (contrast[0].upper(), contrast[1:], shadows, highlights))

    if m["mid"] < med["mid"] - 0.03:
        parts.append("Prints dense: mid-grey sits darker than most")
    elif m["mid"] > med["mid"] + 0.03:
        parts.append("Prints light: mid-grey sits brighter than most")

    if m["mono"]:
        tone = _cast(m["neutral"]["mids"], 0.009)
        parts.append("Monochrome with a %s image tone" % tone if tone else "Neutral monochrome")
        return {"tags": tags, "summary": ". ".join(parts) + ".", "scores": sc}

    sat = _pick(sc["saturation"], ("very muted", "muted", "natural", "rich", "very saturated"))
    tags.insert(0, sat + " colour")
    colour = "%s%s colour" % (sat[0].upper(), sat[1:])
    overall = m["saturation"] / med["saturation"]
    strong, quiet, shifts = [], [], []
    for g, v in m["groups"].items():
        rel = v["saturation"] / med["groups"][g]["saturation"] / overall
        if rel > 1.1:
            strong.append((-rel, g))
        elif rel < 0.9:
            quiet.append((rel, g))
        dh = v["hue_shift"] - med["groups"][g]["hue_shift"]
        if abs(dh) >= 5:
            shifts.append((-abs(dh), "%s %s" % ("skin tones" if g == "skin" else g, HUE_WORDS[g][dh > 0])))
    top = lambda items, n=2: ", ".join(w for _, w in sorted(items)[:n])
    strong, quiet, shifts = top(strong), top(quiet), top(shifts, 3)
    extra = (["especially " + strong] if strong else []) + (["quieter " + quiet] if quiet else [])
    if extra:
        colour += " (%s)" % "; ".join(extra)
    parts.append(colour)
    if shifts:
        parts.append(("%s than most" % shifts).capitalize())

    casts = {z: _cast(m["neutral"][z]) for z in ("shadows", "mids", "highlights")}
    zones = {"shadows": "shadows", "mids": "mid-tones", "highlights": "highlights"}
    if len(set(casts.values())) == 1:
        parts.append("Overall %s grey balance" % casts["mids"] if casts["mids"] else "Neutral grey balance")
    else:
        parts.append(", ".join("%s %s" % (c, zones[z]) for z, c in casts.items() if c).capitalize())
    if casts["mids"]:
        tags.append(casts["mids"])
    return {"tags": tags, "summary": ". ".join(parts) + ".", "scores": sc}


def medians_of(measures):
    colour = [m for m in measures if not m["mono"]] or measures
    med = {k: float(np.median([m[k] for m in measures])) for k in ("contrast", "toe", "shoulder", "mid", "black")}
    med["saturation"] = float(np.median([m["saturation"] for m in colour]))
    spread = lambda k, ms: 1.4826 * float(np.median([abs(m[k] - med[k]) for m in ms]))
    med["scale"] = {k: max(MIN_SCALES[k], spread(k, colour if k == "saturation" else measures))
                    for k in MIN_SCALES}
    med["groups"] = {g: {k: float(np.median([m["groups"][g][k] for m in colour]))
                         for k in ("saturation", "hue_shift")} for g in GROUPS}
    return med


def traits(packs, payload, progress=None):
    """{code: {catalogue entry, measures, tags, summary, scores}} for a dict of LTPack by code."""
    cat = catalogue(payload)
    unknown = lambda code: {"name": code, "iso": None, "brand": "", "family": ""}
    measures = {}
    for code, pack in packs.items():
        measures[code] = measure(pack, native_kelvin(pack, cat.get(code, unknown(code))["name"]))
        if progress:
            progress(code)
    med = medians_of(list(measures.values()))
    out = {}
    for code, m in measures.items():
        out[code] = dict(cat.get(code, unknown(code)), measures=m, **describe(m, med))
    return out


def main():
    here = os.path.dirname(os.path.abspath(__file__))
    repo = os.path.abspath(os.path.join(here, "..", ".."))
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("films", nargs="*", help="film codes (default: every pack in --latent-dir)")
    ap.add_argument("--json", help="write the full measurements to this file")
    ap.add_argument("--autoexec", default=os.path.join(repo, "AUTOEXEC.BIN"))
    ap.add_argument("--latent-dir", default=os.path.join(repo, "LATENT"))
    a = ap.parse_args()

    key = latent_crypt.load_key(a.autoexec)
    payload = latent_color._payload(a.autoexec)
    packs = {}
    for f in sorted(os.listdir(a.latent_dir)):
        if f.upper().endswith(".LTP"):
            pack = latent_ltp.LTPack(os.path.join(a.latent_dir, f), key)
            if pack.index_checksum_ok:
                packs[pack.code] = pack
    # Medians come from the whole set, so measure everything and print what was asked for.
    result = traits(packs, payload, progress=lambda c: print("measured", c, file=sys.stderr))
    for code in [c.upper() for c in a.films] or sorted(result):
        t = result[code]
        m = t["measures"]
        print("%s  %s %s (ISO %s, %s, %d K)" % (code, t["brand"], t["name"], t["iso"], t["family"], m["kelvin"]))
        print("  black %.3f  mid %.3f  white %.3f  contrast %.4f  toe %+.1f  shoulder %+.1f  sat %.2f%s" % (
            m["black"], m["mid"], m["white"], m["contrast"], m["toe"], m["shoulder"], m["saturation"],
            "  mono" if m["mono"] else ""))
        print("  " + "  ".join("%s %.2f/%+.0f°" % (g, v["saturation"], v["hue_shift"]) for g, v in m["groups"].items()))
        print("  neutral " + "  ".join("%s %+.3f/%+.3f" % (z, *ab) for z, ab in m["neutral"].items()))
        print("  [%s]  %s" % (", ".join(t["tags"]), "  ".join("%s %+.1f" % (k, v) for k, v in t["scores"].items() if v is not None)))
        print("  " + t["summary"])
    if a.json:
        with open(a.json, "w") as f:
            json.dump(result, f, indent=1, ensure_ascii=False)


if __name__ == "__main__":
    sys.exit(main())
