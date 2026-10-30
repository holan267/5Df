#!/usr/bin/env python3
"""Decrypt Latent film packs (*.LTP) and grain files (GRAIN.LTG).

Reimplements the AUTOEXEC.BIN payload routines:
  FUN_00983d0c  open + detect encryption (compare first 8 bytes to the magic)
  FUN_0098943c  nonce = {label, first 4 chars of the film code, 0x4C54}
  FUN_0098912c  ChaCha20 block (IETF layout: 32-bit counter, 96-bit nonce)
  FUN_0098948c  XOR keystream at an arbitrary file offset (counter = offset >> 6)

The 256-bit key is not stored in the clear: it is the XOR of two 32-byte
tables at payload addresses 0x9A8B54 and 0x9A8B74. It is read from
AUTOEXEC.BIN at run time.
"""
import argparse
import os
import struct
import sys

AUTOEXEC_PAYLOAD_OFFSET = 0x7E0    # loader copies file[0x7E0:] to 0x982000
PAYLOAD_BASE = 0x982000
KEY_A = 0x9A8B54
KEY_B = 0x9A8B74

# (label, file-name tail length used for the nonce, plaintext magic)
KINDS = {
    "ltp": (b"LTPK", 8, b"LTPACK2\0"),    # "P400.LTP"
    "ltg": (b"LTGR", 14, b"LTGPACK1"),    # "P400/GRAIN.LTG"
}
NONCE_TAIL = struct.pack("<I", 0x4C54)


def load_key(autoexec_path):
    with open(autoexec_path, "rb") as f:
        data = f.read()
    # Accept either the full AUTOEXEC.BIN or the extracted payload.
    off = AUTOEXEC_PAYLOAD_OFFSET if data[:4] == b"\x00\x00\x0f\xe1" else 0
    a = data[off + KEY_A - PAYLOAD_BASE: off + KEY_A - PAYLOAD_BASE + 32]
    b = data[off + KEY_B - PAYLOAD_BASE: off + KEY_B - PAYLOAD_BASE + 32]
    return bytes(x ^ y for x, y in zip(a, b))


def make_nonce(kind, path):
    label, tail_len, _ = KINDS[kind]
    # The firmware takes the tail of "A:/LATENT/<CODE>.LTP" or
    # "A:/LATENT/<CODE>/GRAIN.LTG"; rebuild that tail from the local path.
    code = os.path.basename(path)[:4] if kind == "ltp" else os.path.basename(os.path.dirname(os.path.abspath(path)))[:4]
    return label + code.upper().encode("ascii") + NONCE_TAIL


def _rotl(v, n):
    return ((v << n) & 0xFFFFFFFF) | (v >> (32 - n))


def _chacha_block(key, counter, nonce):
    s = [0x61707865, 0x3320646E, 0x79622D32, 0x6B206574]
    s += list(struct.unpack("<8I", key)) + [counter & 0xFFFFFFFF] + list(struct.unpack("<3I", nonce))
    x = s[:]

    def qr(a, b, c, d):
        x[a] = (x[a] + x[b]) & 0xFFFFFFFF; x[d] = _rotl(x[d] ^ x[a], 16)
        x[c] = (x[c] + x[d]) & 0xFFFFFFFF; x[b] = _rotl(x[b] ^ x[c], 12)
        x[a] = (x[a] + x[b]) & 0xFFFFFFFF; x[d] = _rotl(x[d] ^ x[a], 8)
        x[c] = (x[c] + x[d]) & 0xFFFFFFFF; x[b] = _rotl(x[b] ^ x[c], 7)

    for _ in range(10):
        qr(0, 4, 8, 12); qr(1, 5, 9, 13); qr(2, 6, 10, 14); qr(3, 7, 11, 15)
        qr(0, 5, 10, 15); qr(1, 6, 11, 12); qr(2, 7, 8, 13); qr(3, 4, 9, 14)
    return struct.pack("<16I", *((x[i] + s[i]) & 0xFFFFFFFF for i in range(16)))


def keystream_xor(key, nonce, offset, data):
    """XOR data located at file offset `offset` with the keystream."""
    try:
        from cryptography.hazmat.primitives.ciphers import Cipher, algorithms
        block, skip = offset >> 6, offset & 63
        dec = Cipher(algorithms.ChaCha20(key, struct.pack("<I", block) + nonce), mode=None).decryptor()
        return dec.update(bytes(skip) + bytes(data))[skip:]
    except ImportError:
        out = bytearray(data)
        pos = 0
        while pos < len(out):
            block, skip = (offset + pos) >> 6, (offset + pos) & 63
            ks = _chacha_block(key, block, nonce)[skip:]
            n = min(len(ks), len(out) - pos)
            for i in range(n):
                out[pos + i] ^= ks[i]
            pos += n
        return bytes(out)


def detect_kind(path):
    ext = os.path.splitext(path)[1].lower()
    return {".ltp": "ltp", ".ltg": "ltg"}.get(ext)


def decrypt_file(key, path, out_path=None, length=None, kind=None):
    kind = kind or detect_kind(path)
    magic = KINDS[kind][2]
    nonce = make_nonce(kind, path)
    with open(path, "rb") as f:
        head = f.read(8)
        encrypted = head != magic
        if encrypted and keystream_xor(key, nonce, 0, head) != magic:
            raise ValueError(f"{path}: magic {magic!r} not found after decryption (nonce {nonce!r})")
        f.seek(0)
        total = os.path.getsize(path) if length is None else min(length, os.path.getsize(path))
        chunks, off = [], 0
        sink = open(out_path, "wb") if out_path else None
        try:
            while off < total:
                buf = f.read(min(1 << 22, total - off))
                plain = keystream_xor(key, nonce, off, buf) if encrypted else buf
                if sink:
                    sink.write(plain)
                else:
                    chunks.append(plain)
                off += len(buf)
        finally:
            if sink:
                sink.close()
    return None if out_path else b"".join(chunks)


def main():
    p = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    p.add_argument("--autoexec", required=True, help="AUTOEXEC.BIN or the extracted payload")
    p.add_argument("--length", type=lambda s: int(s, 0), help="only decrypt this many leading bytes")
    p.add_argument("input")
    p.add_argument("output")
    a = p.parse_args()
    decrypt_file(load_key(a.autoexec), a.input, a.output, a.length)


if __name__ == "__main__":
    sys.exit(main())
