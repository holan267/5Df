import { useEffect, useRef, useState } from "react";
import { query } from "@/lib/query";
import type { Backend, Film, RawFile, RenderInfo } from "@/lib/types";
import type { Settings } from "@/hooks/useSettings";

interface Args {
  s: Settings;
  film: Film | null;
  files: RawFile[];
  backend: Backend;
  generation: number;
  uploads: number;
  setStatus(text: string, err?: boolean): void;
}

export function useRender({ s, film, files, backend, generation, uploads, setStatus }: Args) {
  const [urls, setUrls] = useState<{ current: string | null; previous: string | null }>({ current: null, previous: null });
  const [info, setInfo] = useState<RenderInfo | null>(null);
  const [title, setTitle] = useState("");
  const [busy, setBusy] = useState(false);
  const [comparing, setComparing] = useState(false);
  const [exporting, setExporting] = useState(false);
  const ctrl = useRef<AbortController | null>(null);

  // Everything a preview depends on; quality and such only matter to the export.
  const preview = s.file && film ? query(s, film, { scale: s.scale, quality: 90 }) : null;

  useEffect(() => { setInfo(null); }, [generation]);

  useEffect(() => {
    if (!preview || !film) return;
    const timer = setTimeout(async () => {
      if (ctrl.current) ctrl.current.abort();
      const mine = ctrl.current = new AbortController();
      setBusy(true);
      setStatus("developing…");
      try {
        const r = await backend.render(preview, false, mine.signal);
        if (!r) return;                         // superseded by a newer request
        const url = URL.createObjectURL(r.blob);
        setUrls(({ current, previous }) => {
          if (previous && previous !== current) URL.revokeObjectURL(previous);
          return { current: url, previous: current };
        });
        setInfo(r.info);
        const f = files.find((x) => x.id === s.file);
        setTitle(f ? `${f.name} — ${s.film}, ${film.papers[s.paper].name}` : "");
        setStatus(`${r.info.width}×${r.info.height} · ${(r.info.ms / 1000).toFixed(2)} s`);
      } catch (e) {
        if ((e as Error).name !== "AbortError") setStatus((e as Error).message, true);
      } finally {
        if (ctrl.current === mine) setBusy(false);
      }
    }, 120);
    return () => clearTimeout(timer);
  }, [preview, generation, uploads, backend]);

  async function exportJpg() {
    if (!film) return;
    setExporting(true);
    try {
      const r = await backend.render(query(s, film, { scale: 1, quality: s.quality }), true);
      if (!r) return;
      const a = document.createElement("a");
      a.href = URL.createObjectURL(r.blob); a.download = r.name; a.click();
      setTimeout(() => URL.revokeObjectURL(a.href), 5000);
      setStatus(`exported ${r.name} · ${(r.info.ms / 1000).toFixed(1)} s`);
    } catch (e) {
      setStatus((e as Error).message, true);
    } finally {
      setExporting(false);
    }
  }

  const compare = (on: boolean) => setComparing(on && !!urls.previous);
  const shown = comparing && urls.previous ? urls.previous : urls.current;

  return { shown, comparing, info, title, busy, exporting, compare, exportJpg };
}
