import { spawn, type Worked } from "@/lib/backend/spawn";
import type { Backend, KitFile, RawFile, RenderInfo, Started, Traits, TraitsReply } from "@/lib/types";

// The app's root URL: public/ files live here wherever dist/ is hosted.
export const BASE = new URL(import.meta.env.BASE_URL, location.href).href;

// Lite packs (tools/latent_lite.py) in public/LATENT_LITE, or wherever ?lite=URL points.
const LITE_URL = new URL((new URLSearchParams(location.search).get("lite") || `${BASE}LATENT_LITE`).replace(/\/?$/, "/"), location.href).href;

// Lite packs come with their descriptions.
async function readTraits(kit: KitFile[]): Promise<TraitsReply> {
  const own = kit.find((k) => /(^|\/)traits\.json$/.test(k.path));
  try {
    const films: Traits = JSON.parse(own ? await own.file.text() : await (await fetch(LITE_URL + "traits.json")).text());
    return { ready: true, films };
  } catch (e) { return { ready: true, error: (e as Error).message }; }
}

interface EngineBackend extends Backend {
  hasLite: boolean;
  onStatus(text: string): void;
  detectLite(): Promise<boolean>;
  start(kit: KitFile[]): Promise<Started>;
}

let worker: Worked;
let traitsP: Promise<TraitsReply>;
const thumbs = new Map<string, Promise<string>>();

export const engine: EngineBackend = {
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
    worker = spawn((text) => this.onStatus(text));
    traitsP = readTraits(kit);
    // A canvas gives its control away once, so each worker gets a new one. ?gpu=off forces the CPU path.
    const wanted = new URLSearchParams(location.search).get("gpu") !== "off" && "gpu" in navigator;
    const canvas = wanted ? document.createElement("canvas") : null;
    const offscreen = canvas?.transferControlToOffscreen() ?? null;
    const r = await worker.call<Started>("init", { kit, liteUrl: this.hasLite ? LITE_URL : null, base: BASE, canvas: offscreen }, offscreen ? [offscreen] : []);
    this.canvas = r.gpu ? canvas : null;
    return r;
  },
  showPrevious(on) { worker.call("show", { previous: on }); },
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
    const r = await worker.call<{ superseded?: boolean; jpg: Uint8Array<ArrayBuffer> | null; info: RenderInfo; name?: string }>("render", { query: q, download });
    if (r.superseded) return null;
    return { blob: r.jpg && new Blob([r.jpg], { type: "image/jpeg" }), info: r.info, name: r.name || "latent.jpg" };
  },
};

// ?check=1: window.latentCheck(query) compares the GPU and CPU paths on one picture, and
// window.latentLose() takes the GPU device away.
if (new URLSearchParams(location.search).has("check")) {
  Object.assign(window, {
    latentCheck: (query: string) => worker.call("check", { query }),
    latentLose: () => worker.call("lose"),
  });
}
