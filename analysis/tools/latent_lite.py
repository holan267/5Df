#!/usr/bin/env python3
"""Read lite film packs: a compact, unencrypted form of the .LTP cubes (built by latent_lite_build.py).

Layout of LATENT_LITE/:
  firmware.bin   the payload of AUTOEXEC.BIN with everything but the tables the darkroom
                 reads zeroed: no code, no key. Stands in for AUTOEXEC.BIN in latent_color.
  traits.json    film descriptions, latent_traits.traits() of these packs
  index.json     {"files": {path: [size, crc32]}}, for the page to fetch packs over HTTP
  <CODE>/film.json     axes of the pack, per-paper weights, curve map. Plain text.
  <CODE>/tables.bin    zlib of the pack's u16 tables, as LTPack.tables()
  <CODE>/curves.bin    zlib of the LTVC tables (3 x 4096 bytes each), only on packs with B&W papers
  <CODE>/paper<i>.bin  zlib of the basis cubes of paper i
  <CODE>/grain<i>.bin  the GRAIN.LTG blocks of paper i, one per push, losslessly

A pack's cubes are close to a low-rank function of push and light, so each paper keeps
k = rp * rl basis cubes and one cube is a weighted sum of them:
  y[node] = sum over (b, c) of push_w[row][b] * light_w[l][c] * basis[b, c][node]
y is in 8-bit output levels (output_curve), which spends precision where the output
table does; cube16 maps it back to the 0..65535 scale of latent_develop.load_cube16.

paper<i>.bin, after inflating:
  u32 n_over, u32 over[n_over], u8 zz[k * 3 * n * n * n]
zz is ordered [basis][channel][z][y][x]. Each channel is q = round(y / delta), stored as
its 3D Lorenzo residual (first difference along each axis) in zigzag form; zz == 255
takes the next value of over instead. Decoding is three cumsums, so it needs no
per-node Python and is fast in Pyodide.

grain<i>.bin: one byte, 1 for 8-bit table blocks and 0 for lattice blocks, then zlib.
  Table blocks: u8 [push][byte], first difference along push.
  Lattice blocks: i16 [push][word], with the 3 x 1024 input table differenced along its
  last axis and the 17^3 lattice along its three, then all of it along push (all wrapping
  at 16 bits), then the low bytes of every word followed by the high bytes.
"""
import json
import os
import struct
import zlib

import numpy as np

INDEX = "film.json"
FIRMWARE = "firmware.bin"
TRAITS = "traits.json"
MANIFEST = "index.json"
GRID = 65
GRAIN_PRE, GRAIN_LATTICE = 6, 6 + 3 * 1024      # word offsets in a grain block
_decoded = {}       # (folder, paper): basis cubes. A paper takes up to 330 MB, so one, over all packs


def output_curve(tables):
    """Smooth, strictly increasing form of the 12-bit -> 8-bit output table."""
    out8 = np.frombuffer(struct.pack("<2048H", *tables[0x8001:0x8801]), dtype=np.uint8).astype(np.float64)
    k = 9
    smooth = np.convolve(np.pad(out8, k, mode="edge"), np.ones(2 * k + 1) / (2 * k + 1), mode="valid")
    return np.maximum.accumulate(smooth + np.arange(4096) * 1e-6)


def to_levels(c16, curve):
    return np.interp(c16 / 65535 * 4095, np.arange(4096.0), curve)


def from_levels(y, curve):
    return np.interp(y, curve, np.arange(4096.0)) / 4095 * 65535


def encode_basis(y, delta):
    """y: float array [k][3][n][n][n] -> bytes of a paper<i>.bin."""
    over, body = [], []
    for basis in y:
        r = np.rint(basis / delta).astype(np.int32)
        for axis in (-1, -2, -3):
            r = np.diff(r, axis=axis, prepend=np.int32(0))
        zz = ((r << 1) ^ (r >> 31)).ravel()
        over.append(zz[zz >= 255])
        body.append(np.minimum(zz, 255).astype(np.uint8).tobytes())
    over = np.concatenate(over)
    head = struct.pack("<I", len(over)) + over.astype("<u4").tobytes()
    return zlib.compress(head + b"".join(body), 9)


def decode_basis(blob, delta, k):
    raw = zlib.decompress(blob)
    n_over = struct.unpack_from("<I", raw)[0]
    over = np.frombuffer(raw, "<u4", n_over, 4).astype(np.int32)
    size, used = 3 * GRID ** 3, 0
    out = np.empty((k, size), np.float32)
    for b in range(k):
        zz = np.frombuffer(raw, np.uint8, size, 4 + 4 * n_over + b * size).astype(np.int32)
        hits = zz == 255
        n_hits = np.count_nonzero(hits)
        zz[hits] = over[used:used + n_hits]
        used += n_hits
        q = ((zz >> 1) ^ -(zz & 1)).reshape(3, GRID, GRID, GRID)
        for axis in (-1, -2, -3):
            np.cumsum(q, axis=axis, out=q)
        out[b] = q.ravel() * delta
    return out


def _grain_fields(words):
    """Views of the input tables and lattices in [push][word] i16."""
    return (words[:, GRAIN_PRE:GRAIN_LATTICE].reshape(-1, 3, 1024),
            words[:, GRAIN_LATTICE:].reshape(-1, 17, 17, 17, 6))


def encode_grain(blocks):
    """blocks: u8 array [push][byte] -> bytes of a grain<i>.bin."""
    if blocks[0, 8] & 2:
        return b"\1" + zlib.compress(np.diff(blocks, axis=0, prepend=np.uint8(0)).tobytes(), 9)
    w = blocks.reshape(len(blocks), -1, 2).view("<i2")[..., 0].copy()
    pre, lattice = _grain_fields(w)
    pre[:] = np.diff(pre, axis=-1, prepend=np.int16(0))
    for axis in (1, 2, 3):
        lattice[:] = np.diff(lattice, axis=axis, prepend=np.int16(0))
    planes = np.diff(w, axis=0, prepend=np.int16(0)).astype("<i2").view(np.uint8).reshape(-1, 2)
    return b"\0" + zlib.compress(planes[:, 0].tobytes() + planes[:, 1].tobytes(), 9)


def decode_grain(blob, n_push):
    raw = np.frombuffer(zlib.decompress(blob[1:]), np.uint8)
    if blob[0]:
        return np.cumsum(raw.reshape(n_push, -1), axis=0, dtype=np.uint8)
    n = len(raw) // 2
    w = (raw[:n] | raw[n:].astype(np.uint16) << 8).astype(np.int16).reshape(n_push, -1)
    w = np.cumsum(w, axis=0, dtype=np.int16)
    pre, lattice = _grain_fields(w)
    pre[:] = np.cumsum(pre, axis=-1, dtype=np.int16)
    for axis in (1, 2, 3):
        lattice[:] = np.cumsum(lattice, axis=axis, dtype=np.int16)
    return w.astype("<i2").view(np.uint8).reshape(n_push, -1)


class LitePack:
    """Same surface as latent_ltp.LTPack for what the darkroom uses."""

    def __init__(self, folder):
        self.folder = folder
        self.path = os.path.join(folder, INDEX)
        with open(self.path) as f:
            meta = json.load(f)
        self.code = meta["code"]
        self.light_mired, self.push = meta["light_mired"], meta["push"]
        self.grade, self.extra = meta["grade"], meta["extra"]
        self.papers = meta["papers"]
        self.curve_map = meta["curve_map"]
        self.index_checksum_ok = True
        self._tables = self._curve = self._curves = self._grain = None

    def _read(self, name):
        with open(os.path.join(self.folder, name), "rb") as f:
            return f.read()

    def tables(self):
        if self._tables is None:
            raw = zlib.decompress(self._read("tables.bin"))
            self._tables = struct.unpack("<%dH" % (len(raw) // 2), raw)
        return self._tables

    def paper_curves(self, grade_i, push_i, extra_i):
        n_push, n_extra = len(self.push), len(self.extra)
        i = self.curve_map[(grade_i * n_push + push_i) * n_extra + extra_i]
        if not i:
            raise ValueError("no paper curve for this paper/push/grade")
        if self._curves is None:
            self._curves = zlib.decompress(self._read("curves.bin"))
        base = (i - 1) * 0x3000
        return [self._curves[base + 0x1000 * c: base + 0x1000 * (c + 1)] for c in range(3)]

    def grain_block(self, grade_i, push_i):
        if self._grain is None or self._grain[0] != grade_i:
            self._grain = grade_i, decode_grain(self._read("grain%d.bin" % grade_i), len(self.push))
        return self._grain[1][push_i].tobytes()

    def cube16(self, idx):
        """[b][g][r][channel] float32 0..65535, as latent_develop.load_cube16."""
        n_light, n_push = len(self.light_mired), len(self.push)
        grade_i, push_i, light_i = idx // (n_push * n_light), (idx // n_light) % n_push, idx % n_light
        paper = self.papers[grade_i]
        if push_i not in paper["push_rows"]:
            raise ValueError("no cube at index %d" % idx)
        key = self.folder, grade_i
        if key not in _decoded:
            k = len(paper["push_w"][0]) * len(paper["light_w"][0])
            blob = self._read(paper["file"])
            _decoded.clear()
            _decoded[key] = decode_basis(blob, paper["delta"], k)
        w = np.outer(paper["push_w"][paper["push_rows"].index(push_i)], paper["light_w"][light_i])
        y = w.ravel().astype(np.float32) @ _decoded[key]
        if self._curve is None:
            self._curve = output_curve(self.tables())
        return from_levels(y, self._curve).astype(np.float32).reshape(3, GRID, GRID, GRID).transpose(1, 2, 3, 0)
