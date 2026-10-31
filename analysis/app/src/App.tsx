import { useState } from "react";
import { FileRail } from "@/components/FileRail";
import { FilmPicker } from "@/components/FilmPicker";
import { Header } from "@/components/Header";
import { KitPanel } from "@/components/KitPanel";
import { Viewer } from "@/components/Viewer";
import { Advanced } from "@/components/sections/Advanced";
import { Effects } from "@/components/sections/Effects";
import { Exposure } from "@/components/sections/Exposure";
import { Light } from "@/components/sections/Light";
import { PreviewSize } from "@/components/sections/PreviewSize";
import { Print } from "@/components/sections/Print";
import { RenderDetails } from "@/components/sections/RenderDetails";
import { Button } from "@/components/ui/button";
import { ScrollArea } from "@/components/ui/scroll-area";
import { useRender } from "@/hooks/useRender";
import { useSession } from "@/hooks/useSession";
import { useSettings, type Settings } from "@/hooks/useSettings";
import { useShortcuts } from "@/hooks/useShortcuts";

export default function App() {
  const [s, dispatch] = useSettings();
  const session = useSession(dispatch);
  const { films, files, traits, backend, kit, status, setStatus, generation, uploads } = session;
  const film = films.find((f) => f.code === s.film) ?? null;
  const render = useRender({ s, film, files, backend, generation, uploads, setStatus });
  const [zoomed, setZoomed] = useState(false);
  const toggleZoom = () => setZoomed((z) => !z);
  const patch = (p: Partial<Settings>) => dispatch({ type: "patch", patch: p });
  useShortcuts(s, films, dispatch, toggleZoom, render.compare);

  return (
    <div className="app">
      <Header title={render.title} status={status} kitButton={kit.button} onKit={() => session.toggleKit(films.length > 0)} />

      <FileRail
        files={files}
        selected={s.file}
        backend={backend}
        onSelect={(file) => patch({ file })}
        onUpload={session.upload}
      />

      <Viewer
        url={render.shown}
        canvas={render.canvas}
        waiting={!!(s.file && film)}
        busy={render.busy}
        comparing={render.comparing}
        zoomed={zoomed}
        onZoom={toggleZoom}
        onCompare={render.compare}
      >
        {kit.open && (
          <KitPanel
            kit={kit}
            onChoose={session.chooseKit}
            onReopen={session.reopenKit}
            onPicked={session.kitFromInput}
          />
        )}
      </Viewer>

      <ScrollArea data-side-panel className="side border-l bg-card max-[900px]:border-l-0 [&_[data-slot=scroll-area-viewport]>div]:!block">
        <FilmPicker
          films={films}
          film={film}
          traits={traits}
          onSelect={(code) => dispatch({ type: "film", films, code })}
        />
        {film && (
          <>
            <Exposure s={s} patch={patch} />
            <Print s={s} film={film} patch={patch} />
            <Light s={s} film={film} info={render.info} patch={patch} />
            <Effects s={s} film={film} patch={patch} />
            <PreviewSize s={s} patch={patch} />
            <Advanced s={s} patch={patch} />
          </>
        )}
        <section className="border-b px-3.5 py-3 max-[900px]:px-4">
          <Button className="w-full font-semibold" disabled={!s.file || !film || render.exporting} onClick={render.exportJpg}>
            {render.exporting ? "Rendering full size…" : "Export full-size JPG"}
          </Button>
        </section>
        <RenderDetails info={render.info} />
      </ScrollArea>
    </div>
  );
}
