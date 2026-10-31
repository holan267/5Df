import { useEffect, useRef, type ReactNode } from "react";
import { cn } from "cn";
import { Badge } from "@/components/ui/badge";
import { Button } from "@/components/ui/button";

interface Props {
  url: string | null;
  canvas: HTMLCanvasElement | null;     // the live preview, when the GPU draws it
  waiting: boolean;     // a file is picked, its first render is on the way
  busy: boolean;
  comparing: boolean;
  zoomed: boolean;
  onZoom(): void;
  onCompare(on: boolean): void;
  children: ReactNode;
}

const overlay = "border border-white/15 bg-black/65 text-foreground hover:border-white/30 hover:bg-black/65";

// The worker draws on this element, so it is moved into the page rather than rendered.
function Live({ canvas, className, onClick }: { canvas: HTMLCanvasElement; className: string; onClick(): void }) {
  const slot = useRef<HTMLDivElement>(null);
  useEffect(() => {
    slot.current?.append(canvas);
    return () => { canvas.remove(); };
  }, [canvas]);
  useEffect(() => {
    canvas.className = className;
    canvas.onclick = onClick;
  }, [canvas, className, onClick]);
  return <div ref={slot} className="contents" />;
}

export function Viewer({ url, canvas, waiting, busy, comparing, zoomed, onZoom, onCompare, children }: Props) {
  const picture = cn("block max-h-full max-w-full cursor-zoom-in shadow-[0_2px_24px_#0008]", zoomed && "max-h-none max-w-none cursor-zoom-out");
  return (
    <main className="relative overflow-hidden bg-viewer [grid-area:view]">
      <div className={cn("absolute inset-0 grid place-items-center overflow-auto p-4", zoomed && "place-items-start p-0")}>
        {canvas ? (
          <Live canvas={canvas} className={picture} onClick={onZoom} />
        ) : url ? (
          <img src={url} alt="Preview" onClick={onZoom} className={picture} />
        ) : (
          <div className="text-center text-faint">{waiting ? "Developing…" : "Pick a raw file on the left"}</div>
        )}
      </div>

      <Badge
        variant="secondary"
        className={cn("pointer-events-none absolute top-3 left-1/2 -translate-x-1/2 rounded-full bg-black/80 px-3 py-1 font-normal text-muted-foreground opacity-0 transition-opacity", busy && "opacity-100")}
      >
        Developing…
      </Badge>
      {comparing && (
        <Badge variant="secondary" className="absolute bottom-3 left-3 bg-black/65 font-normal">Previous render</Badge>
      )}

      <div className="absolute right-3 bottom-3 flex gap-1.5">
        <Button
          variant="ghost" size="sm" className={overlay}
          title="Hold to see the previous render (or hold C)"
          onPointerDown={() => onCompare(true)}
          onPointerUp={() => onCompare(false)}
          onPointerLeave={() => onCompare(false)}
        >
          Compare
        </Button>
        <Button variant="ghost" size="sm" className={overlay} title="Toggle fit / 100% (or press Z)" onClick={onZoom}>
          {zoomed ? "Fit" : "100%"}
        </Button>
      </div>

      {children}
    </main>
  );
}
