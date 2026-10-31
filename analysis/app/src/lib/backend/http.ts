import type { Backend, Film, RawFile, Started, TraitsReply } from "@/lib/types";

async function api<T>(path: string): Promise<T> {
  const r = await fetch(path);
  if (!r.ok) throw new Error((await r.json().catch(() => ({}))).error || r.statusText);
  return r.json();
}

// latent_app.py serves dist/ at "/" next to its HTTP API. Served from anywhere else the
// API is missing and the page does the work itself: see wasm.ts.
export const http: Backend & { start(): Promise<Started> } = {
  start: async () => {
    const films = await api<Film[]>("api/films");
    return { films, files: await api<RawFile[]>("api/files") };
  },
  files: () => api<RawFile[]>("api/files"),
  traits: () => api<TraitsReply>("api/traits"),
  thumb: async (id) => "api/thumb?file=" + encodeURIComponent(id),
  async upload(f) {
    const r = await fetch("api/upload", { method: "POST", headers: { "X-Filename": f.name }, body: f });
    const j = await r.json();
    if (!r.ok) throw new Error(j.error);
    return j.id;
  },
  async render(q, download, signal) {
    const r = await fetch("api/render?" + q + (download ? "&download=1" : ""), { signal });
    if (r.status === 204) return null;      // superseded by a newer request
    if (!r.ok) throw new Error((await r.json().catch(() => ({}))).error || r.statusText);
    const name = (/filename="([^"]+)"/.exec(r.headers.get("Content-Disposition") || "") || [])[1] || "latent.jpg";
    return { blob: await r.blob(), info: JSON.parse(r.headers.get("X-Latent-Info")!), name };
  },
};
