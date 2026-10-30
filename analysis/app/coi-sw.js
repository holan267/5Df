// Cross-origin isolation for the browser build on any static server.
// LibRaw-Wasm is built with pthreads, so its memory is a SharedArrayBuffer, which browsers
// only allow when the page is served with COOP + COEP. Static hosts usually cannot set
// headers, so this worker adds them to same-origin responses. Cross-origin requests
// (the Pyodide CDN) pass through: jsDelivr sends CORS and CORP headers itself.
self.addEventListener("install", () => self.skipWaiting());
self.addEventListener("activate", (e) => e.waitUntil(self.clients.claim()));

self.addEventListener("fetch", (e) => {
  const req = e.request;
  if (new URL(req.url).origin !== self.location.origin) return;
  if (req.cache === "only-if-cached" && req.mode !== "same-origin") return;
  e.respondWith(fetch(req).then((r) => {
    if (r.status === 0) return r;
    const headers = new Headers(r.headers);
    headers.set("Cross-Origin-Embedder-Policy", "require-corp");
    headers.set("Cross-Origin-Opener-Policy", "same-origin");
    return new Response(r.body, { status: r.status, statusText: r.statusText, headers });
  }));
});
