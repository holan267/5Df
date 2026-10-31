import { useCallback, useEffect, useMemo, useState, type Dispatch } from "react";
import { engine } from "@/lib/backend/engine";
import { idb } from "@/lib/idb";
import { fromInput, RAW_FILE, walk } from "@/lib/kit";
import type { Backend, DirectoryHandle, Film, KitFile, RawFile, Started, Traits } from "@/lib/types";
import type { Action } from "@/hooks/useSettings";

export interface KitState {
  open: boolean;
  note: string;
  err: boolean;
  busy: boolean;       // a kit is loading
  button: boolean;     // the header's Kit… button
  reopen: DirectoryHandle | null;
}

export interface Status { text: string; err: boolean }

// StrictMode runs effects twice; a second start would be a second engine.
let booted = false;

export function useSession(dispatch: Dispatch<Action>) {
  const [backend, setBackend] = useState<Backend>(engine);
  const [films, setFilms] = useState<Film[]>([]);
  const [files, setFiles] = useState<RawFile[]>([]);
  const [traits, setTraits] = useState<Traits | null>(null);
  const [generation, setGeneration] = useState(0);        // +1 per kit opened
  const [uploads, setUploads] = useState(0);
  const [status, setStatusState] = useState<Status>({ text: "loading…", err: false });
  const [kit, setKit] = useState<KitState>({ open: false, note: "", err: false, busy: false, button: false, reopen: null });

  const setStatus = useCallback((text: string, err = false) => setStatusState({ text, err }), []);

  const actions = useMemo(() => {
    const kitPanel = (note = "", err = false) => setKit((k) => ({ ...k, open: true, note, err }));
    let traitsRun = 0;

    function loadTraits(from: Backend, run: number) {
      from.traits().then((t) => {
        if (run !== traitsRun || t.error) return;
        if (!t.ready) { setTimeout(() => loadTraits(from, run), 2000); return; }
        setTraits(t.films || null);
      }, () => { if (run === traitsRun) setTimeout(() => loadTraits(from, run), 5000); });
    }

    function started(from: Backend, r: Started, label?: string) {
      setBackend(() => from);
      setFilms(r.films);
      setFiles(r.files);
      setTraits(null);
      setGeneration((g) => g + 1);
      dispatch({ type: "start", films: r.films, files: r.files });
      setStatus(`${r.films.length} films · ${r.files.length} raw files` + (label ? " · " + label : ""));
      loadTraits(from, ++traitsRun);
    }

    async function openKit(list: KitFile[], label: string) {
      setKit((k) => ({ ...k, busy: true, open: true, note: "Loading the engine…", err: false }));
      setStatus("starting…");
      try {
        const r = await engine.start(list);
        setKit((k) => ({ ...k, open: false, button: true }));
        started(engine, r, label);
      } catch (e) {
        const message = (e as Error).message;
        kitPanel(message, true);
        setStatus(message, true);
      } finally {
        setKit((k) => ({ ...k, busy: false }));
      }
    }

    async function chooseKit(fallback: () => void) {
      if (!window.showDirectoryPicker) { fallback(); return; }
      let handle: DirectoryHandle;
      try { handle = await window.showDirectoryPicker({ id: "latent-kit" }); } catch { return; }   // cancelled
      idb.set("kit-handle", handle);
      kitPanel("Reading the folder…");
      openKit(await walk(handle), handle.name);
    }

    async function reopenKit(handle: DirectoryHandle) {
      if ((await handle.requestPermission({ mode: "read" })) !== "granted") return;
      kitPanel("Reading " + handle.name + "…");
      openKit(await walk(handle), handle.name);
    }

    function kitFromInput(picked: File[]) {
      const { list, top } = fromInput(picked);
      openKit(list, top);
    }

    function toggleKit(hasFilms: boolean) {
      setKit((k) => (k.open ? { ...k, open: !hasFilms } : { ...k, open: true, note: "", err: false }));
    }

    async function boot() {
      setBackend(() => engine);
      setStatus("choose a kit folder");
      const handle = await idb.get<DirectoryHandle>("kit-handle");
      const granted = handle && handle.queryPermission && (await handle.queryPermission({ mode: "read" })) === "granted";
      // Lite packs on the server need no folder; the last one picked still gives its raws.
      if (await engine.detectLite()) return openKit(granted ? (await walk(handle)).filter((k) => RAW_FILE.test(k.path)) : [], "lite packs");
      if (handle) {
        if (granted) {
          kitPanel("Reading " + handle.name + "…");
          return openKit(await walk(handle), handle.name);
        }
        setKit((k) => ({ ...k, reopen: handle }));
      }
      kitPanel();
    }

    return { boot, chooseKit, reopenKit, kitFromInput, toggleKit };
  }, [dispatch, setStatus]);

  useEffect(() => {
    engine.onStatus = setStatus;
    if (booted) return;
    booted = true;
    actions.boot().catch((e) => setStatus(e.message, true));
  }, [actions, setStatus]);

  async function upload(list: File[]) {
    if (!films.length) return;      // no kit open yet
    let added = false;
    for (const f of list) {
      setStatus("adding " + f.name + "…");
      try {
        const id = await backend.upload(f);
        dispatch({ type: "patch", patch: { file: id } });
        added = true;
      } catch (e) { setStatus((e as Error).message, true); }
    }
    if (!added) return;     // a new render would write over the error
    setFiles(await backend.files());
    setUploads((n) => n + 1);
  }

  return { backend, films, files, traits, generation, uploads, status, setStatus, kit, upload, ...actions };
}
