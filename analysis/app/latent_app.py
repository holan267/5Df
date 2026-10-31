#!/usr/bin/env python3
# /// script
# requires-python = ">=3.9"
# dependencies = ["numpy", "rawpy", "pillow"]
# ///
"""Browser UI over latent_develop.py: preview Canon EOS 5D .CR2 (and Sony .ARW) files through
the Latent film profiles, tune the parameters, export full-size JPEGs.

    uv run analysis/app/latent_app.py [--dir FOLDER] [--port 8765] [--host 127.0.0.1]

Then open http://127.0.0.1:8765 (opened automatically unless --no-browser).
Raw files are listed from --dir (default: the repo root); more can be dropped
onto the page. Previews run at 1/4 size by default; Export always renders at
full size and gives the same pixels as the CLI with the same settings.

Every stage that does not depend on the sliders is cached: the demosaiced raw
per file and size, decoded cubes, grain packs and noise planes, halation maps.
Film descriptions (latent_traits.py) are measured in the background at start-up
and kept in a JSON file in the system temp folder until a pack changes.
The server only needs the standard library on top of the CLI's dependencies. The page is
the React app in this folder: build it once with npm install && npm run build.
The same page also runs without Python, entirely in the browser: see web/README.md.
Lite packs work here too: --latent-dir analysis/app/public/LATENT_LITE
--autoexec analysis/app/public/LATENT_LITE/firmware.bin.

AUTOEXEC.BIN and LATENT/ hold Latent Studios' key and film packs: keep the
server on localhost or behind your own access control, do not host it publicly.
"""
import argparse
import collections
import hashlib
import io
import json
import os
import re
import struct
import sys
import tempfile
import threading
import time
import webbrowser
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from urllib.parse import parse_qs, unquote, urlparse

import numpy as np
import rawpy
from PIL import Image

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.abspath(os.path.join(HERE, "..", ".."))
sys.path.insert(0, os.path.join(HERE, "..", "tools"))
import latent_color  # noqa: E402
import latent_crypt  # noqa: E402
import latent_develop as ld  # noqa: E402
import latent_effects  # noqa: E402
import latent_lite  # noqa: E402
import latent_ltp  # noqa: E402
import latent_traits  # noqa: E402

PAPER_NAMES = 0x9B1D90            # 19 pointers: 10 colour, 2 reversal, 4 print, 3 B&W
PAPER_GROUPS = {10: (0, 10), 2: (10, 12), 4: (12, 16)}   # colour papers in a pack -> slice
BW_PAPERS = (16, 19)
FAMILIES = {10: "colour negative", 2: "colour reversal", 4: "motion picture"}
SCALES = (1, 2, 4)
EXPOSURE_RANGE = 5.0              # +/- EV on top of the camera's BaselineExposure
RAW_EXTS = (".CR2", ".ARW")
MAX_UPLOAD = 64 << 20
ORIENT = {3: Image.ROTATE_180, 6: Image.ROTATE_270, 8: Image.ROTATE_90}


class LRU:
    def __init__(self, size):
        self.size, self.items = size, collections.OrderedDict()

    def get(self, key, make):
        if key in self.items:
            self.items.move_to_end(key)
            return self.items[key]
        value = self.items[key] = make()
        while len(self.items) > self.size:
            self.items.popitem(last=False)
        return value


class BadRequest(ValueError):
    pass


def _cstr(payload, addr):
    o = addr - latent_effects.PAYLOAD_BASE
    return payload[o:payload.index(b"\0", o)].decode("latin-1")


def _arg(q, name, conv, default):
    v = q.get(name, [""])[0]
    if v == "":
        return default
    try:
        return conv(v)
    except ValueError:
        raise BadRequest("bad value for %s: %r" % (name, v))


class Studio:
    def __init__(self, autoexec, latent_dir, folder, upload_dir, background_traits=True):
        self.autoexec, self.latent_dir = autoexec, latent_dir
        self.folder, self.upload_dir = folder, upload_dir
        self.key = latent_crypt.load_key(autoexec)
        self.payload = latent_color._payload(autoexec)
        names = struct.unpack_from("<19I", self.payload, PAPER_NAMES - latent_effects.PAYLOAD_BASE)
        self.paper_table = [_cstr(self.payload, a) for a in names]
        self.packs = {}
        for f in sorted(os.listdir(latent_dir)):
            if f.upper().endswith(".LTP"):
                pack = latent_ltp.LTPack(os.path.join(latent_dir, f), self.key)
                if pack.index_checksum_ok:
                    self.packs[pack.code] = pack
        for f in sorted(os.listdir(latent_dir)):    # a lite pack only stands in when the .LTP is absent
            if f not in self.packs and os.path.isfile(os.path.join(latent_dir, f, latent_lite.INDEX)):
                self.packs[f] = latent_lite.LitePack(os.path.join(latent_dir, f))
        self.tables = LRU(len(self.packs))
        self.raws = LRU(3)
        self.cubes = LRU(24)
        self.grains = LRU(8)
        self.noise = LRU(3)
        self.halos = LRU(4)
        self.thumbs = LRU(64)
        self.lock = threading.Lock()
        self.ticket_lock = threading.Lock()
        self.latest_preview = 0
        self.traits, self.traits_error = None, None
        if background_traits:   # the browser build (web/) has no threads and measures in its own worker
            threading.Thread(target=self.measure_traits, daemon=True).start()

    # ------------------------------------------------------------ catalogue

    def film_info(self, pack):
        colour = [g for g in pack.grade if not g & 0x80]
        lo, hi = PAPER_GROUPS.get(len(colour), (0, 0))
        papers, k = [], 0
        for i, g in enumerate(pack.grade):
            if g & 0x80:
                j = BW_PAPERS[0] + k
                name, k = self.paper_table[j] if j < BW_PAPERS[1] else "B&W paper %d" % k, k + 1
            else:
                name = self.paper_table[lo + g] if lo + g < hi else "Paper %d" % i
            papers.append({"index": i, "name": name, "bw": bool(g & 0x80)})
        if not colour:
            family = "B&W"
        elif k:
            family = "B&W, colour or B&W paper"
        else:
            family = FAMILIES.get(len(colour), "film")
        return {
            "code": pack.code, "family": family, "papers": papers,
            "push": pack.push, "grades": pack.extra,
            "kelvin": [round(1e6 / pack.light_mired[-1]), round(1e6 / pack.light_mired[0])],
            "halation": latent_effects.halation_profile(self.payload, pack.code) is not None,
        }

    def measure_traits(self):
        """Fill self.traits with latent_traits.traits(), from the temp-folder cache when it is current."""
        h = hashlib.sha1(open(latent_traits.__file__, "rb").read())
        for pack in sorted(self.packs.values(), key=lambda p: p.code):
            st = os.stat(pack.path)
            h.update(("%s %d %d;" % (pack.code, st.st_size, st.st_mtime_ns)).encode())
        cache = os.path.join(tempfile.gettempdir(), "latent_traits_%s.json" % h.hexdigest()[:16])
        try:
            with open(cache, encoding="utf-8") as f:
                self.traits = json.load(f)
            return
        except (OSError, ValueError):
            pass
        try:
            traits = latent_traits.traits(self.packs, self.payload)
        except Exception as e:  # descriptions are optional, the darkroom works without them
            self.traits_error = "%s: %s" % (type(e).__name__, e)
            return
        tmp = cache + ".%d" % os.getpid()
        with open(tmp, "w", encoding="utf-8") as f:
            json.dump(traits, f, ensure_ascii=False)
        os.replace(tmp, cache)
        self.traits = traits

    def films(self):
        order = ["colour negative", "colour reversal", "motion picture", "B&W"]
        films = [self.film_info(p) for p in self.packs.values()]
        return sorted(films, key=lambda f: (order.index(f["family"]) if f["family"] in order else len(order),
                                            f["code"]))

    def files(self):
        out = []
        for kind, d in (("d", self.folder), ("u", self.upload_dir)):
            for f in sorted(os.listdir(d)):
                p = os.path.join(d, f)
                if f.upper().endswith(RAW_EXTS) and os.path.isfile(p):
                    out.append({"id": "%s:%s" % (kind, f), "name": f, "size": os.path.getsize(p),
                                "uploaded": kind == "u"})
        return out

    def resolve(self, file_id):
        kind, _, name = file_id.partition(":")
        d = {"d": self.folder, "u": self.upload_dir}.get(kind)
        if d is None or not name or os.path.basename(name) != name:
            raise BadRequest("unknown file %r" % file_id)
        path = os.path.join(d, name)
        if not os.path.isfile(path):
            raise BadRequest("file not found: %s" % name)
        return path

    def upload(self, name, data):
        name = re.sub(r"[^A-Za-z0-9._ -]", "_", os.path.basename(name or ""))
        if not name.upper().endswith(RAW_EXTS):
            raise BadRequest("only %s files are accepted" % "/".join(RAW_EXTS))
        path = os.path.join(self.upload_dir, name)
        with open(path, "wb") as f:
            f.write(data)
        try:
            ld.open_raw(path, self.autoexec)
        except Exception as e:
            os.remove(path)
            raise BadRequest("%s: %s" % (name, e))
        return "u:" + name

    def thumb(self, file_id):
        path = self.resolve(file_id)

        def make():
            with rawpy.imread(path) as raw:
                t = raw.extract_thumb()
            if t.format == rawpy.ThumbFormat.JPEG:
                im = Image.open(io.BytesIO(t.data))
            else:
                im = Image.fromarray(t.data)
            im.thumbnail((320, 320))
            orientation = ld.open_raw(path, self.autoexec)["meta"]["orientation"]
            if orientation in ORIENT:
                im = im.transpose(ORIENT[orientation])
            buf = io.BytesIO()
            im.convert("RGB").save(buf, "JPEG", quality=80)
            return buf.getvalue()
        return self.thumbs.get((path, os.path.getmtime(path)), make)

    # ------------------------------------------------------------ cached stages

    def source(self, path, scale):
        """Raw decoded at 1/scale with everything that only depends on the file."""
        def make():
            try:
                src = ld.open_raw(path, self.autoexec)
            except ValueError as e:
                raise BadRequest(str(e))
            rgb = src.pop("load")(scale > 1)
            if scale == 4:
                h, w = rgb.shape[0] // 2 * 2, rgb.shape[1] // 2 * 2
                rgb = rgb[:h, :w].reshape(h // 2, 2, w // 2, 2, 3).mean(axis=(1, 3)).astype(np.uint16)
            src["rgb"] = rgb
            return src
        return self.raws.get((path, os.path.getmtime(path), scale), make)

    def cube(self, pack, i0, i1, w):
        c = self.cubes.get((pack.code, i0), lambda: ld.load_cube16(pack, i0))
        if i1 != i0 and w > 0:
            c = (1 - w) * c + w * self.cubes.get((pack.code, i1), lambda: ld.load_cube16(pack, i1))
        return c

    # ------------------------------------------------------------ render

    def parse(self, q):
        p = {
            "file": q.get("file", [""])[0],
            "film": q.get("film", [""])[0].upper(),
            "paper": _arg(q, "paper", int, 0),
            "push": _arg(q, "push", int, 0),
            "grade": _arg(q, "grade", int, 5),
            "kelvin": _arg(q, "kelvin", float, None),
            "exposure": _arg(q, "exposure", float, 0.0),
            "gamut": _arg(q, "gamut", int, 1) != 0,
            "grain": _arg(q, "grain", int, 1) != 0,
            "halation": _arg(q, "halation", int, 2),     # -1 = off
            "card_path": q.get("card_path", [""])[0].strip(),
            "scale": _arg(q, "scale", int, 4),
            "quality": _arg(q, "quality", int, 95),
        }
        if p["film"] not in self.packs:
            raise BadRequest("unknown film %r" % p["film"])
        if p["scale"] not in SCALES:
            raise BadRequest("scale must be one of %s" % (SCALES,))
        if p["kelvin"] is not None and p["kelvin"] <= 0:
            raise BadRequest("kelvin must be positive")
        if not abs(p["exposure"]) <= EXPOSURE_RANGE:
            raise BadRequest("exposure must be -%g..+%g EV" % (EXPOSURE_RANGE, EXPOSURE_RANGE))
        if p["halation"] not in (-1, 0, 1, 2):
            raise BadRequest("halation must be -1..2")
        if not 1 <= p["quality"] <= 100:
            raise BadRequest("quality must be 1..100")
        if p["card_path"] and not p["card_path"].isascii():
            raise BadRequest("card path must be ASCII")
        return p

    def preview_ticket(self):
        with self.ticket_lock:
            self.latest_preview += 1
            return self.latest_preview

    def render(self, p, ticket=None):
        """Returns (jpeg bytes, info) or None when a newer preview superseded this one."""
        path = self.resolve(p["file"])
        pack = self.packs[p["film"]]
        with self.lock:
            if ticket is not None and ticket != self.latest_preview:
                return None
            t0 = time.time()
            src = self.source(path, p["scale"])
            meta, clip, rgb = src["meta"], src["clip"], src["rgb"]
            mired = 1e6 / p["kelvin"] if p["kelvin"] else src["mired"]
            try:
                i0, i1, w, paper_curves = ld.select_cubes(pack, p["paper"], p["push"], p["grade"], mired)
            except ValueError as e:
                raise BadRequest(str(e))
            cube = self.cube(pack, i0, i1, w)
            tables = self.tables.get(pack.code, pack.tables)
            height, width = rgb.shape[:2]
            # Same as open_raw(exposure=...): the EV only scales the camera matrix, after the sensor clip.
            matrix = (np.asarray(src["matrix"]) * 2 ** p["exposure"]).tolist()

            halo, halo_offsets = None, None
            profile = latent_effects.halation_profile(self.payload, pack.code)
            if profile is not None and p["halation"] >= 0:
                halo = latent_effects.Halation(self.payload, profile, matrix, clip,
                                               latent_effects.HALO_LEVELS[p["halation"]])
                maps = self.halos.get((path, p["scale"], pack.code, p["exposure"]),
                                      lambda: halo.build_map(rgb.astype(np.float32) / 65535.0))
                halo_offsets = halo.offsets(maps, height, width)

            grain, noise, card_path = None, None, None
            if p["grain"]:
                push_i = pack.push.index(p["push"])
                grain = self.grains.get(
                    (pack.code, p["paper"], push_i, p["grade"]),
                    lambda: ld.load_grain(pack, self.latent_dir, self.key, p["paper"], push_i, p["grade"]))
                card_path = p["card_path"] or "A:/DCIM/%s/" % src["card_dir"] + os.path.basename(path).upper()
                seed = latent_effects.fnv1a_seed(card_path)
                noise = self.noise.get(
                    (seed, height, width, grain.streams()),
                    lambda: latent_effects.grain_noise(self.payload, seed, height, width, grain.streams()))

            img = ld.develop(rgb, clip, matrix, tables, cube, paper_curves, gamut=p["gamut"],
                             halo_offsets=halo_offsets, grain=grain, noise=noise)
            pil = Image.fromarray(img)
            if meta["orientation"] in ORIENT:
                pil = pil.transpose(ORIENT[meta["orientation"]])
            exif = Image.Exif()
            exif[0x010F], exif[0x0110] = meta["make"], meta["model"]
            exif[0x0131] = "Latent pipeline reimplementation"
            exif[0x010E] = "%s paper#%d push%+d%s %.0fK%s" % (
                pack.code, p["paper"], p["push"], " grade%d" % p["grade"] if paper_curves else "", 1e6 / mired,
                " %+.1fEV" % p["exposure"] if p["exposure"] else "")
            buf = io.BytesIO()
            pil.save(buf, "JPEG", quality=p["quality"], exif=exif)
            info = {
                "model": meta["model"], "wb": meta["wb"],
                "shot_kelvin": round(1e6 / src["mired"]), "kelvin": round(1e6 / mired),
                "mired": round(mired, 1), "exposure": p["exposure"],
                "baseline_exposure": round(src["baseline_exposure"], 2), "cubes": [i0, i1], "weight": round(w, 3),
                "bw_curves": bool(paper_curves),
                "grain": None if grain is None else "%s, %s" % (
                    "mono" if grain.mono else "colour", "8-bit table" if grain.simple else "17³ lattice"),
                "card_path": card_path,
                "halation": None if halo is None else latent_effects.HALO_LEVELS[p["halation"]],
                "width": pil.width, "height": pil.height,
                "ms": round((time.time() - t0) * 1000),
            }
            return buf.getvalue(), info


# ---------------------------------------------------------------- HTTP

def make_handler(studio):
    dist = os.path.join(HERE, "dist")
    types = {".html": "text/html; charset=utf-8", ".js": "text/javascript; charset=utf-8",
             ".css": "text/css; charset=utf-8", ".json": "application/json", ".wasm": "application/wasm"}

    class Handler(BaseHTTPRequestHandler):
        protocol_version = "HTTP/1.1"

        def log_message(self, fmt, *args):
            pass

        def send(self, status, body, ctype, headers=()):
            self.send_response(status)
            self.send_header("Content-Type", ctype)
            self.send_header("Content-Length", str(len(body)))
            self.send_header("Cache-Control", "no-store")
            for k, v in headers:
                self.send_header(k, v)
            self.end_headers()
            self.wfile.write(body)

        def send_json(self, obj, status=HTTPStatus.OK):
            self.send(status, json.dumps(obj).encode(), "application/json")

        def send_static(self, url_path):
            """The page, as built by Vite into dist/."""
            path = os.path.realpath(os.path.join(dist, url_path.lstrip("/") or "index.html"))
            if not os.path.isfile(path) or not path.startswith(os.path.realpath(dist) + os.sep):
                if os.path.isfile(os.path.join(dist, "index.html")):
                    self.send_json({"error": "not found"}, HTTPStatus.NOT_FOUND)
                else:
                    self.send(HTTPStatus.SERVICE_UNAVAILABLE, b"The page is not built: run npm install && npm run build in analysis/app.",
                              "text/plain; charset=utf-8")
                return
            with open(path, "rb") as f:
                self.send(HTTPStatus.OK, f.read(), types.get(os.path.splitext(path)[1], "application/octet-stream"))

        def guarded(self, fn):
            try:
                fn()
            except BadRequest as e:
                self.send_json({"error": str(e)}, HTTPStatus.BAD_REQUEST)
            except (BrokenPipeError, ConnectionResetError):
                pass
            except Exception as e:  # keep the server up, report to the page
                self.send_json({"error": "%s: %s" % (type(e).__name__, e)}, HTTPStatus.INTERNAL_SERVER_ERROR)

        def do_GET(self):
            self.guarded(self.get)

        def do_POST(self):
            self.guarded(self.post)

        def get(self):
            url = urlparse(self.path)
            q = parse_qs(url.query)
            if url.path == "/api/films":
                self.send_json(studio.films())
            elif url.path == "/api/traits":
                self.send_json({"ready": studio.traits is not None, "error": studio.traits_error,
                                "films": studio.traits or {}})
            elif url.path == "/api/files":
                self.send_json(studio.files())
            elif url.path == "/api/thumb":
                self.send(HTTPStatus.OK, studio.thumb(q.get("file", [""])[0]), "image/jpeg")
            elif url.path == "/api/render":
                p = studio.parse(q)
                download = q.get("download", ["0"])[0] == "1"
                result = studio.render(p, None if download else studio.preview_ticket())
                if result is None:
                    self.send(HTTPStatus.NO_CONTENT, b"", "text/plain")
                    return
                jpg, info = result
                headers = [("X-Latent-Info", json.dumps(info)), ("Access-Control-Expose-Headers", "X-Latent-Info")]
                if download:
                    stem = os.path.splitext(os.path.basename(studio.resolve(p["file"])))[0]
                    headers.append(("Content-Disposition", 'attachment; filename="%s_%s.jpg"' % (stem, p["film"])))
                self.send(HTTPStatus.OK, jpg, "image/jpeg", headers)
            elif url.path.startswith("/api/"):
                self.send_json({"error": "not found"}, HTTPStatus.NOT_FOUND)
            else:
                self.send_static(unquote(url.path))

        def post(self):
            if urlparse(self.path).path != "/api/upload":
                self.send_json({"error": "not found"}, HTTPStatus.NOT_FOUND)
                return
            n = int(self.headers.get("Content-Length") or 0)
            if not 0 < n <= MAX_UPLOAD:
                raise BadRequest("upload must be 1 byte .. %d MB" % (MAX_UPLOAD >> 20))
            data = self.rfile.read(n)
            name = self.headers.get("X-Filename", "")
            self.send_json({"id": studio.upload(name, data)})

    return Handler


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dir", default=REPO, help="folder whose .CR2/.ARW files are listed (default: repo root)")
    ap.add_argument("--host", default="127.0.0.1", help="bind address (default 127.0.0.1, local only)")
    ap.add_argument("--port", type=int, default=8765)
    ap.add_argument("--autoexec", default=os.path.join(REPO, "AUTOEXEC.BIN"))
    ap.add_argument("--latent-dir", default=os.path.join(REPO, "LATENT"))
    ap.add_argument("--upload-dir", help="where dropped files are kept (default: a temporary folder)")
    ap.add_argument("--no-browser", action="store_true")
    a = ap.parse_args()

    upload_dir = a.upload_dir or tempfile.mkdtemp(prefix="latent_app_")
    os.makedirs(upload_dir, exist_ok=True)
    studio = Studio(a.autoexec, a.latent_dir, os.path.abspath(a.dir), upload_dir)
    server = ThreadingHTTPServer((a.host, a.port), make_handler(studio))
    url = "http://%s:%d/" % ("127.0.0.1" if a.host in ("0.0.0.0", "") else a.host, a.port)
    print("%d films, %d raw files in %s" % (len(studio.packs), len(studio.files()), studio.folder))
    print("uploads: %s" % upload_dir)
    print("serving %s  (Ctrl+C to stop)" % url)
    if not a.no_browser:
        threading.Timer(0.5, webbrowser.open, (url,)).start()
    try:
        server.serve_forever()
    except KeyboardInterrupt:
        pass


if __name__ == "__main__":
    sys.exit(main())
