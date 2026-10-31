"""Entry points for worker.js: latent_app.Studio without the HTTP server, under Pyodide.

The worker mounts the user's own kit read-only (AUTOEXEC.BIN, the .LTP packs and
their GRAIN.LTG, or a LATENT_LITE folder, plus any raws in the chosen folder) and keeps
dropped raws in MEMFS. Lite packs served over HTTP land in LITE file by file: when a call
misses one it answers {"need": path} and the worker fetches it and calls again.
Rendering is latent_app.Studio unchanged; only rawpy is the LibRaw-Wasm shim next to
this file. Every call returns {"ok": value} or {"error": message}, as JS objects.
"""
import json
import os
from urllib.parse import parse_qs

import js
from pyodide.ffi import to_js

import latent_app

LITE = "/lite/"     # worker.js
studio = None


def _reply(fn):
    def call(*args):
        try:
            value = fn(*args)
            out = {"ok": value}
        except latent_app.BadRequest as e:
            out = {"error": str(e)}
        except FileNotFoundError as e:
            out = {"need": e.filename} if str(e.filename).startswith(LITE) else {"error": str(e)}
        except Exception as e:  # keep the worker up, report to the page
            out = {"error": "%s: %s" % (type(e).__name__, e)}
        return to_js(out, dict_converter=js.Object.fromEntries)
    return call


@_reply
def start(autoexec, latent_dir, folder, upload_dir):
    global studio
    studio = latent_app.Studio(autoexec, latent_dir, folder, upload_dir, background_traits=False)
    return {"films": json.dumps(studio.films()), "files": json.dumps(studio.files())}


@_reply
def files():
    return json.dumps(studio.files())


@_reply
def thumb(file_id):
    return studio.thumb(file_id)


@_reply
def upload(name, data):
    return studio.upload(name, data.to_bytes())


@_reply
def render(query, download):
    p = studio.parse(parse_qs(query))
    jpg, info = studio.render(p)
    name = None
    if download:
        stem = os.path.splitext(os.path.basename(studio.resolve(p["file"])))[0]
        name = "%s_%s.jpg" % (stem, p["film"])
    return {"jpg": jpg, "info": json.dumps(info), "name": name}


@_reply
def traits(autoexec, latent_dir):
    """Film descriptions (latent_traits.py) for the second worker; the page caches them."""
    s = latent_app.Studio(autoexec, latent_dir, "/tmp", "/tmp", background_traits=False)
    s.measure_traits()
    return json.dumps({"films": s.traits, "error": s.traits_error})
