// Browser build of latent_app.py: Pyodide runs analysis/tools and latent_app.Studio,
// LibRaw-Wasm stands in for rawpy (see rawpy.py). One worker renders; a second one,
// started with role "traits", measures the film descriptions so renders are not held up.
//
// The kit (AUTOEXEC.BIN, LATENT/*.LTP, LATENT/<code>/GRAIN.LTG, raws next to them) is the
// user's own and never leaves the machine: the files are mounted read-only with WORKERFS,
// which reads only the slices Python asks for, so multi-GB packs cost no memory.
// A LATENT_LITE folder (tools/latent_lite.py) mounts the same way. Lite packs can also come
// from a URL: see mountLite.
import { loadPyodide } from "https://cdn.jsdelivr.net/pyodide/v314.0.7/full/pyodide.mjs";
import latentApp from "../latent_app.py?raw";
import rawpy from "./rawpy.py?raw";
import latentWeb from "./latent_web.py?raw";
import color from "../../tools/latent_color.py?raw";
import crypt from "../../tools/latent_crypt.py?raw";
import develop from "../../tools/latent_develop.py?raw";
import effects from "../../tools/latent_effects.py?raw";
import liteTool from "../../tools/latent_lite.py?raw";
import ltp from "../../tools/latent_ltp.py?raw";
import traits from "../../tools/latent_traits.py?raw";

// Pyodide path -> source; the layout mirrors analysis/ so the modules find each other
// as they do on disk.
const SOURCES = {
  "/analysis/app/latent_app.py": latentApp,
  "/analysis/app/web/rawpy.py": rawpy,
  "/analysis/app/web/latent_web.py": latentWeb,
  "/analysis/tools/latent_color.py": color,
  "/analysis/tools/latent_crypt.py": crypt,
  "/analysis/tools/latent_develop.py": develop,
  "/analysis/tools/latent_effects.py": effects,
  "/analysis/tools/latent_lite.py": liteTool,
  "/analysis/tools/latent_ltp.py": ltp,
  "/analysis/tools/latent_traits.py": traits,
};
const KIT = "/kit", LITE = "/lite", RAWS = "/raws", UPLOADS = "/uploads";
const RAW_RE = /\.(cr2|arw)$/i;

let py = null, web = null, lite = null;

// base: the app's root URL. LibRaw stays out of the bundle, in public/: its pthreads start
// new Workers on its own libraw.js, which only holds if the file keeps its name and place.
async function boot(base) {
  const { default: LibRawModule } = await import(/* @vite-ignore */ `${base}vendor/libraw-wasm/libraw.js`);
  const [pyodide, libraw] = await Promise.all([loadPyodide(), LibRawModule()]);
  await pyodide.loadPackage(["numpy", "pillow"]);
  for (const [path, source] of Object.entries(SOURCES)) {
    pyodide.FS.mkdirTree(path.slice(0, path.lastIndexOf("/")));
    pyodide.FS.writeFile(path, source);
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

// Shallowest of the kit paths with this file name.
function findKit(kit, re) {
  return kit.map((k) => k.path).filter((p) => re.test(p)).sort((a, b) => a.split("/").length - b.split("/").length)[0];
}

// kit: [{path, file}] with paths relative to the folder the user picked. Returns where the
// packs are, or null when the folder has none and the page has lite packs at a URL.
function mountKit(kit, hasUrl) {
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
  const autoexec = findKit(kit, /(^|\/)AUTOEXEC\.BIN$/i);
  // The packs folder is the one holding the most .LTP files.
  const dirs = {};
  for (const { path } of kit) if (/\.LTP$/i.test(path)) { const d = path.slice(0, path.lastIndexOf("/") + 1); dirs[d] = (dirs[d] || 0) + 1; }
  const latent = Object.keys(dirs).sort((a, b) => dirs[b] - dirs[a])[0];
  if (autoexec && latent !== undefined) return { autoexec: `${KIT}/${autoexec}`, latent: `${KIT}/${latent}`.replace(/\/$/, "") };
  const firmware = findKit(kit, /(^|\/)firmware\.bin$/);
  if (firmware) return { autoexec: `${KIT}/${firmware}`, latent: `${KIT}/${firmware}`.replace(/\/firmware\.bin$/, "") };
  if (hasUrl) return null;
  throw new Error(autoexec ? "no .LTP film packs in the chosen folder" : "no AUTOEXEC.BIN or LATENT_LITE packs in the chosen folder");
}

// Lite packs over HTTP: firmware.bin and every film.json now, the rest when Python misses
// it (see withLite), so a session downloads only the papers it uses. Cache Storage keeps
// the files between visits; ?v=crc in the URL drops them when a pack is rebuilt.
async function mountLite(base) {
  const r = await fetch(base + "index.json", { cache: "no-cache" });
  if (!r.ok) throw new Error(`${base}index.json: ${r.status}`);
  const { files } = await r.json();
  // The cache only saves downloads: without one (it can fail to open) everything still works.
  const cache = await caches.open("latent-lite " + base).catch(() => null);
  lite = { base, files, cache };
  const current = new Set(Object.keys(files).map(liteUrl));
  if (cache) for (const req of await cache.keys()) if (!current.has(req.url)) cache.delete(req);
  await Promise.all(Object.keys(files).filter((p) => /(^|\/)(firmware\.bin|film\.json)$/.test(p)).map(fetchLite));
  return { autoexec: `${LITE}/firmware.bin`, latent: LITE };
}

function liteUrl(path) { return `${lite.base}${path}?v=${lite.files[path][1]}`; }

async function fetchLite(path) {
  if (!lite.files[path]) throw new Error(`${path} is not in ${lite.base}index.json`);
  const url = liteUrl(path);
  let r = lite.cache && await lite.cache.match(url);
  if (!r) {
    const size = lite.files[path][0];
    if (size > 1 << 20) self.postMessage({ status: `downloading ${path} (${(size / 1e6).toFixed(1)} MB)…` });
    r = await fetch(url);
    if (!r.ok) throw new Error(`${url}: ${r.status}`);
    if (lite.cache) await lite.cache.put(url, r.clone()).catch(() => {});   // out of quota: it still works this once
  }
  const file = `${LITE}/${path}`;
  py.FS.mkdirTree(file.slice(0, file.lastIndexOf("/")));
  py.FS.writeFile(file, new Uint8Array(await r.arrayBuffer()));
  return file;
}

// A Python call that stops on a lite file it does not have yet: fetch it, call again.
// Python keeps what it decodes, so the files only stay in memory for the call.
async function withLite(fn, ...args) {
  const fetched = [];
  try {
    for (;;) {
      const r = fn(...args);
      if (r.need === undefined) {
        if (r.error !== undefined) throw new Error(r.error);
        return r.ok;
      }
      fetched.push(await fetchLite(r.need.slice(LITE.length + 1)));
    }
  } finally {
    for (const f of fetched) py.FS.unlink(f);
  }
}

function call(fn, ...args) {
  const r = fn(...args);
  if (r.error !== undefined) throw new Error(r.error);
  return r.ok;
}

const ops = {
  async init({ kit, liteUrl: url, role, base }) {
    await boot(base);
    const { autoexec, latent } = mountKit(kit, !!url) || await mountLite(url);
    if (role === "traits") return JSON.parse(call(web.traits, autoexec, latent));
    const r = call(web.start, autoexec, latent, RAWS, UPLOADS);
    return { films: JSON.parse(r.films), files: JSON.parse(r.files) };
  },
  files: () => JSON.parse(call(web.files)),
  thumb: ({ file }) => call(web.thumb, file),
  upload: ({ name, data }) => call(web.upload, name, new Uint8Array(data)),
  render: async ({ query, download }) => {
    const r = await withLite(web.render, query, !!download);
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
