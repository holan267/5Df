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
  const [renders, setRenders] = useState(0);             // on the canvas, which keeps its own previous one
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
        if (r.blob) {
          const url = URL.createObjectURL(r.blob);
          setUrls(({ current, previous }) => {
            if (previous && previous !== current) URL.revokeObjectURL(previous);
            return { current: url, previous: current };
          });
        } else {
          setRenders((n) => n + 1);
        }
        setInfo(r.info);
        const f = files.find((x) => x.id === s.file);
        setTitle(f ? `${f.name} — ${s.film}, ${film.papers[s.paper].name}` : "");
        setStatus(`${r.info.width}×${r.info.height} · ${(r.info.ms / 1000).toFixed(2)} s`);
      } catch (e) {
        if ((e as Error).name !== "AbortError") setStatus((e as Error).message, true);
      } finally {
        if (ctrl.current === mine) setBusy(false);
      }
    }, backend.canvas ? 16 : 120);
    return () => clearTimeout(timer);
  }, [preview, generation, uploads, backend]);

  async function exportJpg() {
    if (!film) return;
    setExporting(true);
    try {
      const r = await backend.render(query(s, film, { scale: 1, quality: s.quality }), true);
      if (!r?.blob) return;
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

  const live = !!backend.canvas && renders > 0;
  const compare = (on: boolean) => {
    if (live && renders > 1 && (on || comparing)) backend.showPrevious?.(on);
    setComparing(on && (live ? renders > 1 : !!urls.previous));
  };
  const shown = comparing && urls.previous ? urls.previous : urls.current;

  return { shown, canvas: live ? backend.canvas! : null, comparing, info, title, busy, exporting, compare, exportJpg };
}
