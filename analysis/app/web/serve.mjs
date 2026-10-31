// Serves analysis/ for the browser build of the darkroom, no Python needed:
//
//     node analysis/app/web/serve.mjs [--port 8765] [--lite LATENT_LITE]
//
// then open http://127.0.0.1:8765/app/. Any static server works as well (coi-sw.js adds the
// isolation headers); this one sends them itself and listens on localhost only.
// The lite packs (default: LATENT_LITE at the repo root) are served at /lite/.
import http from "node:http";
import fs from "node:fs";
import path from "node:path";
import { fileURLToPath } from "node:url";

const ROOT = path.resolve(path.dirname(fileURLToPath(import.meta.url)), "..", "..");
const arg = (name) => { const i = process.argv.indexOf(name); return i > 0 ? process.argv[i + 1] : undefined; };
const PORT = +(arg("--port") || 8765);
const LITE = path.resolve(arg("--lite") || path.join(ROOT, "..", "LATENT_LITE"));
const TYPES = { ".html": "text/html; charset=utf-8", ".js": "text/javascript; charset=utf-8",
                ".mjs": "text/javascript; charset=utf-8", ".wasm": "application/wasm",
                ".py": "text/plain; charset=utf-8", ".md": "text/plain; charset=utf-8",
                ".json": "application/json" };

http.createServer((req, res) => {
  const url = new URL(req.url, "http://x");
  // the page uses relative URLs (web/worker.js, api/films...), so "/app" must become "/app/"
  if (url.pathname === "/") { res.writeHead(302, { Location: "/app/" }).end(); return; }
  const lite = url.pathname.startsWith("/lite/"), base = lite ? LITE : ROOT;
  let file = path.join(base, decodeURIComponent(url.pathname.slice(lite ? "/lite".length : 0)));
  if (file !== base && !file.startsWith(base + path.sep)) { res.writeHead(403).end(); return; }
  if (fs.existsSync(file) && fs.statSync(file).isDirectory()) {
    if (!url.pathname.endsWith("/")) { res.writeHead(301, { Location: url.pathname + "/" + url.search }).end(); return; }
    file = path.join(file, "index.html");
  }
  if (!fs.existsSync(file)) { res.writeHead(404, { "Content-Type": "text/plain" }).end("not found"); return; }
  res.writeHead(200, {
    "Content-Type": TYPES[path.extname(file).toLowerCase()] || "application/octet-stream",
    "Cache-Control": "no-cache",
    "Cross-Origin-Opener-Policy": "same-origin",
    "Cross-Origin-Embedder-Policy": "require-corp",
  });
  fs.createReadStream(file).pipe(res);
}).listen(PORT, "127.0.0.1", () => console.log(`serving ${ROOT}\nopen http://127.0.0.1:${PORT}/app/`));
