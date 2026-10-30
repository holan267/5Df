#!/usr/bin/env python3
"""Rebuild Latent's camera -> cube-input colour matrix (FUN_009944b0).

Firmware steps, all in double precision:
  n      = (G/R, 1, G/B) from the CR2 WB_RGGBLevelsAsShot words (+0x38/+0x3A/+0x3E)
  Minv   = inverse of the camera table's XYZ->camera ColorMatrix (FUN_00993bd4)
  white  = Minv . n, normalised to Y = 1                         (FUN_00992700)
  A      = Bradford(white -> D50)                                 (FUN_00993fe0)
  B      = Bradford(D50 -> D65)
  C      = 2^(BaselineExposure + 0.943) * T . B . A . Minv        T = XYZ(D65)->linear sRGB
  stored = round(C * 4096)   (Q12, applied to raw normalised so 1.0 = white - black)

The result is the linear input of the shaper/cube: Rec.709/sRGB primaries,
D65 white, scene-referred, 1.0 = 0x10000 in Q16.
"""
import argparse
import os
import struct
import sys

PAYLOAD_BASE = 0x982000
AUTOEXEC_PAYLOAD_OFFSET = 0x7E0
CAMERA_TABLE = 0x9A9080      # {char *model, 0, double ColorMatrix[9], u32 black, u32 white, ...}
BRADFORD = 0x9A8CD0
XYZ_TO_RGB = 0x9A8D18
D50 = (0.9642956764295677, 1.0, 0.8251046025104602)   # constants in FUN_009944b0
D65 = (0.9504559270516716, 1.0, 1.0890577507598784)
LATENT_EXPOSURE_OFFSET = 0.943


def _payload(path):
    data = open(path, "rb").read()
    return data[AUTOEXEC_PAYLOAD_OFFSET:] if data[:4] == b"\x00\x00\x0f\xe1" else data


def _doubles(p, addr, n):
    return list(struct.unpack_from("<%dd" % n, p, addr - PAYLOAD_BASE))


def _m3(flat):
    return [flat[0:3], flat[3:6], flat[6:9]]


def mul(a, b):
    return [[sum(a[i][k] * b[k][j] for k in range(3)) for j in range(3)] for i in range(3)]


def mv(a, v):
    return [sum(a[i][k] * v[k] for k in range(3)) for i in range(3)]


def inv(m):
    (a, b, c), (d, e, f), (g, h, i) = m
    det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g)
    return [[(e * i - f * h) / det, (c * h - b * i) / det, (b * f - c * e) / det],
            [(f * g - d * i) / det, (a * i - c * g) / det, (c * d - a * f) / det],
            [(d * h - e * g) / det, (b * g - a * h) / det, (a * e - b * d) / det]]


def bradford(mb, src, dst):
    s, d = mv(mb, src), mv(mb, dst)
    diag = [[d[0] / s[0], 0, 0], [0, d[1] / s[1], 0], [0, 0, d[2] / s[2]]]
    return mul(inv(mb), mul(diag, mb))


def camera_table(p):
    model_ptr = struct.unpack_from("<I", p, CAMERA_TABLE - PAYLOAD_BASE)[0]
    end = p.index(b"\0", model_ptr - PAYLOAD_BASE)
    model = p[model_ptr - PAYLOAD_BASE:end].decode("ascii")
    color_matrix = _m3(_doubles(p, CAMERA_TABLE + 8, 9))
    black, white = struct.unpack_from("<2I", p, CAMERA_TABLE + 0x50 - PAYLOAD_BASE)
    baseline = _doubles(p, CAMERA_TABLE + 0x68, 1)[0]
    return model, color_matrix, black, white, baseline


def colour_matrix(payload_path, cm, baseline, wb_r, wb_g, wb_b):
    """FUN_009944b0 for any XYZ->camera ColorMatrix (the 5D's comes from the
    firmware table; other cameras pass Adobe's, e.g. LibRaw's rgb_xyz_matrix)."""
    p = _payload(payload_path)
    mb = _m3(_doubles(p, BRADFORD, 9))
    t = _m3(_doubles(p, XYZ_TO_RGB, 9))
    minv = inv(cm)
    x, y, z = mv(minv, [wb_g / wb_r, 1.0, wb_g / wb_b])
    white_xyz = [x / y, 1.0, z / y]
    m = mul(t, mul(bradford(mb, D50, D65), mul(bradford(mb, white_xyz, D50), minv)))
    scale = 2 ** (baseline + LATENT_EXPOSURE_OFFSET)
    m = [[v * scale for v in row] for row in m]
    return {
        "baseline_exposure": baseline, "scale": scale, "matrix": m,
        "matrix_q12": [[int(v * 4096 + (0.5 if v >= 0 else -0.5)) for v in row] for row in m],
        "neutral_at_clip": y * scale,
    }


def latent_matrix(payload_path, wb_r, wb_g, wb_b):
    model, cm, black, white, baseline = camera_table(_payload(payload_path))
    r = colour_matrix(payload_path, cm, baseline, wb_r, wb_g, wb_b)
    r.update(model=model, black=black, white=white)
    return r


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--autoexec", required=True)
    ap.add_argument("--wb", nargs=3, type=float, metavar=("R", "G", "B"), default=(1966, 1024, 1491),
                    help="CR2 WB_RGGBLevelsAsShot R, G, B (default: a typical 5D daylight value)")
    a = ap.parse_args()
    r = latent_matrix(a.autoexec, *a.wb)
    print("camera: %s  black %d  white %d  BaselineExposure %+g  scale 2^(%g)=%.4f"
          % (r["model"], r["black"], r["white"], r["baseline_exposure"],
             r["baseline_exposure"] + LATENT_EXPOSURE_OFFSET, r["scale"]))
    print("camera raw (1.0 = white-black) -> linear Rec.709/sRGB D65:")
    for row, q in zip(r["matrix"], r["matrix_q12"]):
        print("  % .5f % .5f % .5f    Q12 %6d %6d %6d" % (*row, *q))
    print("neutral that just clips the green photosites -> %.3f linear" % r["neutral_at_clip"])


if __name__ == "__main__":
    sys.exit(main())
