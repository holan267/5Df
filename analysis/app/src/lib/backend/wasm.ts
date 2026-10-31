import traitsSource from "../../../../tools/latent_traits.py?raw";
import { spawn, type Worked } from "@/lib/backend/spawn";
import { idb } from "@/lib/idb";
import type { Backend, KitFile, RawFile, RenderInfo, Started, TraitsReply, Traits } from "@/lib/types";

// The app's root URL: public/ files live here wherever dist/ is hosted.
export const BASE = new URL(import.meta.env.BASE_URL, location.href).href;

// Lite packs (tools/latent_lite.py) in public/LATENT_LITE, or wherever ?lite=URL points.
const LITE_URL = new URL((new URLSearchParams(location.search).get("lite") || `${BASE}LATENT_LITE`).replace(/\/?$/, "/"), location.href).href;

// The descriptions take a while to measure (latent_traits.py over every pack), so a second
// worker does it, once per set of packs: the result is kept until a pack or the code changes.
// Lite packs come with theirs.
async function measureTraits(kit: KitFile[], onStatus: (text: string) => void): Promise<TraitsReply> {
  if (!kit.some((k) => /\.LTP$/i.test(k.path))) {
    const own = kit.find((k) => /(^|\/)traits\.json$/.test(k.path));
    try {
      const films: Traits = JSON.parse(own ? await own.file.text() : await (await fetch(LITE_URL + "traits.json")).text());
      return { ready: true, films };
    } catch (e) { return { ready: true, error: (e as Error).message }; }
  }
  const sig = kit.filter((k) => /\.LTP$/i.test(k.path)).map((k) => `${k.path} ${k.file.size} ${k.file.lastModified};`).join("");
  const hash = await crypto.subtle.digest("SHA-1", new TextEncoder().encode(traitsSource + sig));
  const key = "traits:" + [...new Uint8Array(hash)].map((b) => b.toString(16).padStart(2, "0")).join("");
  let t = await idb.get<{ error?: string | null; films?: Traits }>(key);
  if (!t) {
    const w = spawn(onStatus);
    try { t = await w.call<{ error?: string; films?: Traits }>("init", { kit, role: "traits", base: BASE }); } finally { w.stop(); }
    if (!t.error) idb.set(key, t);
  }
  return { ready: true, error: t.error, films: t.films };
}

interface WasmBackend extends Backend {
  hasLite: boolean;
  onStatus(text: string): void;
  detectLite(): Promise<boolean>;
  start(kit: KitFile[]): Promise<Started>;
}

let worker: Worked;
let traitsP: Promise<TraitsReply>;
const thumbs = new Map<string, Promise<string>>();

export const wasm: WasmBackend = {
  hasLite: false,
  onStatus() {},
  async detectLite() {
    try {
      this.hasLite = !!(await (await fetch(LITE_URL + "index.json", { cache: "no-cache" })).json()).files;
    } catch { /* no packs on this server */ }
    return this.hasLite;
  },
  async start(kit) {
    if (worker) worker.stop();
    thumbs.clear();
    const onStatus = (text: string) => this.onStatus(text);
    worker = spawn(onStatus);
    traitsP = measureTraits(kit, onStatus);
    return worker.call<Started>("init", { kit, liteUrl: this.hasLite ? LITE_URL : null, role: "render", base: BASE });
  },
  files() { return worker.call<RawFile[]>("files"); },
  traits() { return traitsP; },
  async thumb(id) {
    if (!thumbs.has(id)) {
      thumbs.set(id, worker.call<Uint8Array<ArrayBuffer>>("thumb", { file: id })
        .then((jpg) => URL.createObjectURL(new Blob([jpg], { type: "image/jpeg" }))));
    }
    return thumbs.get(id)!;
  },
  async upload(f) {
    const data = await f.arrayBuffer();
    return worker.call<string>("upload", { name: f.name, data }, [data]);
  },
  async render(q, download) {
    const r = await worker.call<{ superseded?: boolean; jpg: Uint8Array<ArrayBuffer>; info: RenderInfo; name?: string }>("render", { query: q, download });
    if (r.superseded) return null;
    return { blob: new Blob([r.jpg], { type: "image/jpeg" }), info: r.info, name: r.name || "latent.jpg" };
  },
};
