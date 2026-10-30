"""rawpy stand-in for the browser build, on LibRaw-Wasm (LibRaw 0.22.1, as in rawpy 0.27).

Only what latent_develop.py and latent_app.py use: imread() as a context manager,
postprocess() with the keywords below, extract_thumb(), and the colour / level /
size attributes open_raw() reads for cameras other than the 5D.

worker.js registers the decoder as the JS module _libraw; its calls are synchronous
inside the worker. The wrapper does not expose LibRaw's per-channel black (cblack) or
linear_max, so they are read here the way LibRaw reads them: for Sony from the encrypted
SR2 block (tags 0x7310, 0x787f), for Canon from SpecularWhiteLevel. Other makes get the
common black and no per-channel white (open_raw() then uses white_level).
"""
import collections
import enum
import struct

import js
import numpy as np
from pyodide.ffi import to_js

import _libraw


class ColorSpace(enum.IntEnum):
    raw, sRGB, Adobe, Wide, ProPhoto, XYZ, ACES, P3D65, Rec2020 = range(9)


class HighlightMode(enum.IntEnum):
    Clip, Ignore, Blend, ReconstructDefault = 0, 1, 2, 5


class ThumbFormat(enum.Enum):
    JPEG, BITMAP = 1, 2


class LibRawError(Exception):
    pass


Thumbnail = collections.namedtuple("Thumbnail", "format data")
ImageSizes = collections.namedtuple(
    "ImageSizes", "raw_height raw_width height width top_margin left_margin iheight iwidth flip "
                  "crop_left_margin crop_top_margin crop_width crop_height")

# rawpy.postprocess() keyword -> (LibRaw-Wasm setting, value for it, rawpy's default).
# Every call sends all of them: the wrapper keeps settings from the previous open().
POSTPROCESS = {
    "output_color": ("outputColor", int, ColorSpace.sRGB),
    "gamma": ("gamm", lambda g: [1 / g[0], g[1], 0, 0, 0, 0], (2.222, 4.5)),
    "no_auto_bright": ("noAutoBright", bool, False),
    "use_camera_wb": ("useCameraWb", bool, False),
    "use_auto_wb": ("useAutoWb", bool, False),
    "user_wb": ("userMul", lambda w: [float(v) for v in w], [0, 0, 0, 0]),
    "user_black": ("userBlack", int, -1),
    "user_sat": ("userSat", int, -1),
    "output_bps": ("outputBps", int, 8),
    "half_size": ("halfSize", bool, False),
    "highlight_mode": ("highlight", int, HighlightMode.Clip),
    "user_flip": ("userFlip", int, -1),
}


def imread(path):
    return RawPy(path)


# ---------------------------------------------------------------- Sony SR2 block

def _sony_pad(key):
    """LibRaw::sony_decrypt key schedule (the pad words before htonl())."""
    pad = [0] * 128
    for p in range(4):
        key = (key * 48828125 + 1) & 0xFFFFFFFF
        pad[p] = key
    pad[3] = (pad[3] << 1 | (pad[0] ^ pad[2]) >> 31) & 0xFFFFFFFF
    for p in range(4, 127):
        pad[p] = ((pad[p - 4] ^ pad[p - 2]) << 1 | (pad[p - 3] ^ pad[p - 1]) >> 31) & 0xFFFFFFFF
    return pad


def sony_sr2(data):
    """{tag: [values]} of the SR2SubIFD of a Sony ARW (LibRaw parse_tiff_ifd 0xc634 /
    0x7200-0x7221, then parseSonySR2), or {} when the file has none."""
    e = {b"II": "<", b"MM": ">"}.get(bytes(data[:2]))
    if e is None:
        return {}

    def entries(buf, off, base=0):
        """{tag: values} of the IFD at buf[off]; out-of-line values sit at offset - base."""
        out = {}
        for i in range(struct.unpack_from(e + "H", buf, off)[0]):
            p = off + 2 + 12 * i
            tag, typ, cnt = struct.unpack_from(e + "HHI", buf, p)
            size = {1: 1, 3: 2, 4: 4, 7: 1, 8: 2, 9: 4}.get(typ)
            if size is None:
                continue
            at = p + 8 if cnt * size <= 4 else struct.unpack_from(e + "I", buf, p + 8)[0] - base
            if not 0 <= at <= len(buf) - cnt * size:
                continue
            fmt = {1: "B", 3: "H", 4: "I", 7: "B", 8: "h", 9: "i"}[typ]
            out[tag] = list(struct.unpack_from(e + fmt * cnt, buf, at))
        return out

    try:
        ifd0 = entries(data, struct.unpack_from(e + "I", data, 4)[0])
        if 0xC634 not in ifd0:
            return {}
        # LibRaw get4()s these whatever their type: DNGPrivateData and the key are 4 bytes.
        get4 = lambda v: struct.unpack(e + "I", bytes(v))[0] if len(v) == 4 else v[0]
        private = entries(data, get4(ifd0[0xC634]))
        off, length, key = (get4(private.get(t, [0])) for t in (0x7200, 0x7201, 0x7221))
        if not length or off + length > len(data):
            return {}
        n = length // 4
        words = list(struct.unpack_from(">%dI" % n, data, off))
        pad, p = _sony_pad(key), 127
        for i in range(n):
            pad[p & 127] = pad[(p + 1) & 127] ^ pad[(p + 65) & 127]
            words[i] ^= pad[p & 127]
            p += 1
        return entries(struct.pack(">%dI" % n, *words), 0, off)
    except (struct.error, IndexError):
        return {}


class RawPy:
    def __init__(self, path):
        self.path = path
        self._meta = self._sr2 = None

    def __enter__(self):
        return self

    def __exit__(self, *exc):
        self.close()

    def close(self):
        pass

    def _open(self, settings=None):
        with open(self.path, "rb") as f:
            data = f.read()
        try:
            _libraw.open(to_js(data), to_js(settings or {}, dict_converter=js.Object.fromEntries))
        except Exception as e:
            raise LibRawError("%s: %s" % (self.path, e)) from None

    # ------------------------------------------------------------ processing

    def postprocess(self, **kw):
        unknown = set(kw) - set(POSTPROCESS)
        if unknown:
            raise TypeError("postprocess() keywords not supported in the browser: %s" % ", ".join(sorted(unknown)))
        settings = {}
        for name, (key, conv, default) in POSTPROCESS.items():
            v = kw.get(name)
            settings[key] = conv(default if v is None else v)
        self._open(settings)
        try:
            img = _libraw.imageData().to_py()
        except Exception as e:
            raise LibRawError("%s: %s" % (self.path, e)) from None
        dtype = np.uint16 if img["bits"] == 16 else np.uint8
        return np.asarray(img["data"], dtype=dtype).reshape(img["height"], img["width"], img["colors"])

    def extract_thumb(self):
        self._open()
        t = _libraw.thumbnailData()
        if t is None:
            raise LibRawError("%s: no thumbnail" % self.path)
        t = t.to_py()
        data = bytes(t["data"])
        if t["format"] == "jpeg":
            return Thumbnail(ThumbFormat.JPEG, data)
        if t["format"] == "bitmap":
            return Thumbnail(ThumbFormat.BITMAP,
                             np.frombuffer(data, np.uint8).reshape(t["height"], t["width"], 3))
        raise LibRawError("%s: unsupported thumbnail format %s" % (self.path, t["format"]))

    # ------------------------------------------------------------ metadata

    @property
    def meta(self):
        if self._meta is None:
            self._open()
            self._meta = _libraw.metadata().to_py()
        return self._meta

    @property
    def rgb_xyz_matrix(self):
        return np.asarray(self.meta["color_data"]["cam_xyz"], np.float32).reshape(4, 3)

    @property
    def num_colors(self):
        return self.meta["colors"]

    @property
    def raw_pattern(self):
        f = self.meta["filters"] & 0xFFFFFFFF
        if f < 1000:
            return None
        # LibRaw's FC(row, col) over one 2x2 Bayer cell.
        return np.array([[f >> (((r << 1 & 14) | (c & 1)) << 1) & 3 for c in range(2)] for r in range(2)], np.uint8)

    @property
    def sr2(self):
        if self._sr2 is None:
            with open(self.path, "rb") as f:
                self._sr2 = sony_sr2(f.read()) if self.meta["camera_make"] == "Sony" else {}
        return self._sr2

    @property
    def black_level_per_channel(self):
        # LibRaw black + cblack[c]; 0x7310 is the Sony per-channel black, in RGGB order.
        bl = self.sr2.get(0x7310)
        if bl and len(bl) == 4:
            return [bl[0], bl[1], bl[3], bl[2]]
        return [int(self.meta["color_data"]["black"])] * 4

    @property
    def camera_white_level_per_channel(self):
        # LibRaw linear_max: Sony SR2 0x787f, Canon SpecularWhiteLevel; None when unknown, as rawpy.
        wl = self.sr2.get(0x787F)
        if wl and len(wl) in (1, 3):
            wl = [wl[0]] * 4 if len(wl) == 1 else [wl[0], wl[1], wl[2], wl[1]]
            if self.white_level < wl[0] <= self.white_level * 4:   # 14-bit levels on 12-bit data (open.cpp)
                wl = [v // 4 for v in wl]
            return wl
        spec = (self.meta.get("canon") or {}).get("SpecularWhiteLevel")
        return [spec] * 4 if spec else None

    @property
    def white_level(self):
        return int(self.meta["color_data"]["maximum"])

    @property
    def camera_whitebalance(self):
        return [float(v) for v in self.meta["color_data"]["cam_mul"]]

    @property
    def daylight_whitebalance(self):
        return [float(v) for v in self.meta["color_data"]["pre_mul"]]

    @property
    def sizes(self):
        m = self.meta
        crops = m.get("raw_inset_crops") or []
        c = crops[0] if crops and crops[0]["cwidth"] else {"cleft": 0, "ctop": 0, "cwidth": 0, "cheight": 0}
        # The wrapper swaps width / height for rotated shots; rawpy reports the sensor's.
        w, h = (m["height"], m["width"]) if m["flip"] in (5, 6, 7) else (m["width"], m["height"])
        return ImageSizes(m["raw_height"], m["raw_width"], h, w, m["top_margin"], m["left_margin"], h, w,
                          m["flip"], c["cleft"], c["ctop"], c["cwidth"], c["cheight"])
