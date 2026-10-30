// Browser build of latent_app.py: Pyodide runs analysis/tools and latent_app.Studio,
// LibRaw-Wasm stands in for rawpy (see rawpy.py). One worker renders; a second one,
// started with role "traits", measures the film descriptions so renders are not held up.
//
// The kit (AUTOEXEC.BIN, LATENT/*.LTP, LATENT/<code>/GRAIN.LTG, raws next to them) is the
// user's own and never leaves the machine: the files are mounted read-only with WORKERFS,
// which reads only the slices Python asks for, so multi-GB packs cost no memory.
import { loadPyodide } from "https://cdn.jsdelivr.net/pyodide/v314.0.7/full/pyodide.mjs";
import LibRawModule from "./vendor/libraw-wasm/libraw.js";

// Pyodide path -> URL relative to this file; the layout mirrors analysis/ so the
// modules find each other as they do on disk.
const SOURCES = {
  "/analysis/app/latent_app.py": "../latent_app.py",
  "/analysis/app/web/rawpy.py": "rawpy.py",
  "/analysis/app/web/latent_web.py": "latent_web.py",
  ...Object.fromEntries(["color", "crypt", "develop", "effects", "ltp", "traits"].map(
    (m) => [`/analysis/tools/latent_${m}.py`, `../../tools/latent_${m}.py`])),
};
const KIT = "/kit", RAWS = "/raws", UPLOADS = "/uploads";
const RAW_RE = /\.(cr2|arw)$/i;

let py = null, web = null;

async function boot() {
  const [pyodide, libraw] = await Promise.all([loadPyodide(), LibRawModule()]);
  await pyodide.loadPackage(["numpy", "pillow"]);
  for (const [path, url] of Object.entries(SOURCES)) {
    const r = await fetch(new URL(url, import.meta.url), { cache: "no-cache" });
    if (!r.ok) throw new Error(`${url}: ${r.status}`);
    pyodide.FS.mkdirTree(path.slice(0, path.lastIndexOf("/")));
    pyodide.FS.writeFile(path, await r.text());
  }
  const decoder = new libraw.LibRaw();
  pyodide.registerJsModule("_libraw", {
    open: (bytes, settings) => decoder.open(bytes, settings),
    metadata: () => decoder.metadata(true),
    imageData: () => decoder.imageData(),
    thumbnailData: () => decoder.thumbnailData(),
  });
  pyodide.runPython(`import sys; sys.path[:0] = ["/analysis/app/web", "/analysis/app", "/analysis/tools"]`);
  py = pyodide;
  web = pyodide.pyimport("latent_web");
}

// kit: [{path, file}] with paths relative to the folder the user picked.
function mountKit(kit) {
  const FS = py.FS;
  if (!FS.filesystems.WORKERFS) throw new Error("this Pyodide build has no WORKERFS");
  FS.mkdirTree(KIT);
  FS.mount(FS.filesystems.WORKERFS, { blobs: kit.map(({ path, file }) => ({ name: path, data: file })) }, KIT);
  // Raws anywhere in the kit show up in one flat folder, as latent_app lists --dir.
  FS.mkdirTree(RAWS);
  FS.mkdirTree(UPLOADS);
  const seen = new Set();
  for (const { path } of kit) {
    const name = path.slice(path.lastIndexOf("/") + 1);
    if (RAW_RE.test(name) && !seen.has(name)) { seen.add(name); FS.symlink(`${KIT}/${path}`, `${RAWS}/${name}`); }
  }
  const autoexec = kit.map((k) => k.path).filter((p) => /(^|\/)AUTOEXEC\.BIN$/i.test(p))
    .sort((a, b) => a.split("/").length - b.split("/").length)[0];
  if (!autoexec) throw new Error("no AUTOEXEC.BIN in the chosen folder");
  // The packs folder is the one holding the most .LTP files.
  const dirs = {};
  for (const { path } of kit) if (/\.LTP$/i.test(path)) { const d = path.slice(0, path.lastIndexOf("/") + 1); dirs[d] = (dirs[d] || 0) + 1; }
  const latent = Object.keys(dirs).sort((a, b) => dirs[b] - dirs[a])[0];
  if (latent === undefined) throw new Error("no .LTP film packs in the chosen folder");
  return { autoexec: `${KIT}/${autoexec}`, latent: `${KIT}/${latent}`.replace(/\/$/, "") };
}

function call(fn, ...args) {
  const r = fn(...args);
  if (r.error !== undefined) throw new Error(r.error);
  return r.ok;
}

const ops = {
  async init({ kit, role }) {
    await boot();
    const { autoexec, latent } = mountKit(kit);
    if (role === "traits") return JSON.parse(call(web.traits, autoexec, latent));
    const r = call(web.start, autoexec, latent, RAWS, UPLOADS);
    return { films: JSON.parse(r.films), files: JSON.parse(r.files) };
  },
  files: () => JSON.parse(call(web.files)),
  thumb: ({ file }) => call(web.thumb, file),
  upload: ({ name, data }) => call(web.upload, name, new Uint8Array(data)),
  render: ({ query, download }) => {
    const r = call(web.render, query, !!download);
    return { jpg: r.jpg, info: JSON.parse(r.info), name: r.name };
  },
};

// One job at a time (Python blocks the worker). Renders and uploads go before thumbnails,
// and a preview that a newer preview has replaced is answered with {superseded: true}.
const PRIORITY = { init: 0, upload: 1, render: 1, files: 2, thumb: 3 };
const queue = [];
let latestPreview = 0, running = false;

self.onmessage = ({ data }) => {
  const job = { ...data };
  if (job.op === "render" && !job.args.download) job.ticket = ++latestPreview;
  queue.push(job);
  if (!running) run();
};

async function run() {
  running = true;
  while (queue.length) {
    // Let messages that arrived during the last job land first, so stale previews are seen.
    await new Promise((r) => setTimeout(r, 0));
    queue.sort((a, b) => PRIORITY[a.op] - PRIORITY[b.op] || a.id - b.id);
    const job = queue.shift();
    if (job.ticket !== undefined && job.ticket !== latestPreview) {
      self.postMessage({ id: job.id, out: { superseded: true } });
      continue;
    }
    try {
      const out = await ops[job.op](job.args || {});
      const transfer = [];
      if (out instanceof Uint8Array) transfer.push(out.buffer);
      else if (out && out.jpg instanceof Uint8Array) transfer.push(out.jpg.buffer);
      self.postMessage({ id: job.id, out }, transfer);
    } catch (e) {
      self.postMessage({ id: job.id, error: e.message || String(e) });
    }
  }
  running = false;
}
