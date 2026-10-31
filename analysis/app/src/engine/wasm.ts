// latent_engine.wasm (analysis/engine): typed calls over its C API. Every call that answers
// with text answers {ok}, {error} or {need}. The module's memory can grow during any call,
// which detaches the old view, so HEAPU8 is read fresh each time and copies are taken at once.

export type Reply<T> = { ok: T } | { need: string } | { error: string };

/** A block of the engine's heap, stable while the render lasts. */
export interface Resource { tag: string; ptr: number; bytes: number }

export interface GpuPlan {
  width: number;
  height: number;
  orientation: number;
  matrix: number[][];
  clip: number[];
  gamut: boolean;
  grain: "lattice" | "simple" | null;
  mono: boolean;
  halo: [number[], number[]] | null;
  res: Record<"rgb" | "noise" | "cube" | "tables" | "out8" | "grain" | "maps", Resource | null>;
}

export interface Prepared { info: Record<string, unknown>; name: string; gpu: GpuPlan }
export interface ThumbInfo { jpeg: boolean; width: number; height: number; orientation: number }
export interface Comparison { max: number; differ: number; values: number; histogram: number[] }

export async function loadEngine(base: string) {
  // Stays out of the bundle, in public/, next to its .wasm.
  const { default: LatentEngine } = await import(/* @vite-ignore */ `${base}vendor/latent-engine/latent_engine.mjs`);
  const m = await LatentEngine();

  const json = <T>(p: number) => JSON.parse(m.UTF8ToString(p)) as Reply<T>;
  const take = (bytes: Uint8Array) => {
    const p = m._engine_alloc(bytes.length);
    m.HEAPU8.set(bytes, p);
    return p;
  };
  const withText = <T>(text: string, fn: (p: number) => T) => {
    const p = m.stringToNewUTF8(text);
    try { return fn(p); } finally { m._free(p); }
  };

  return {
    init(firmware: Uint8Array) { return json<null>(m._engine_init(take(firmware), firmware.length)); },
    addFilm(filmJson: Uint8Array) {
      const p = m._malloc(filmJson.length);
      m.HEAPU8.set(filmJson, p);
      try { return json<null>(m._engine_add_film(p, filmJson.length)); } finally { m._free(p); }
    },
    films<T>() { return json<T>(m._engine_films()); },
    put(path: string, data: Uint8Array) {
      const p = take(data);
      withText(path, (t) => m._engine_put(t, p, data.length));
    },
    clearFiles() { m._engine_clear_files(); },
    forget(id: string) { withText(id, (t) => m._engine_forget(t)); },
    check(data: Uint8Array) { return json<null>(m._engine_check(take(data), data.length)); },
    thumb(data: Uint8Array) { return json<ThumbInfo>(m._engine_thumb(take(data), data.length)); },
    prepare(query: string) { return withText(query, (t) => json<Prepared>(m._engine_prepare(t))); },
    developCpu() { return json<null>(m._engine_develop_cpu()); },
    /** Takes RGBA in sensor orientation; the JPEG lands in the blob. */
    encode(rgba: Uint8Array, width: number, height: number) {
      return json<null>(m._engine_encode(take(rgba), rgba.length, width, height));
    },
    /** The prepared job on the CPU against the same picture from the GPU. */
    compare(rgba: Uint8Array) { return json<Comparison>(m._engine_compare(take(rgba), rgba.length)); },
    heap(): Uint8Array { return m.HEAPU8; },
    blob(): Uint8Array<ArrayBuffer> {
      const p = m._engine_blob_ptr();
      return m.HEAPU8.slice(p, p + m._engine_blob_len());
    },
  };
}

export type Engine = Awaited<ReturnType<typeof loadEngine>>;
