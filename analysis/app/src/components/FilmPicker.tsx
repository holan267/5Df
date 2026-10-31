import { useRef, useState } from "react";
import { FilmTip } from "@/components/FilmTip";
import { Note, Section } from "@/components/Section";
import { ToggleGroup, ToggleGroupItem } from "@/components/ui/toggle-group";
import { Tooltip, TooltipContent, TooltipTrigger } from "@/components/ui/tooltip";
import type { Film, Traits } from "@/lib/types";

function Chip({ film, traits }: { film: Film; traits: Traits | null }) {
  const ref = useRef<HTMLButtonElement>(null);
  const [place, setPlace] = useState<{ side: "left" | "bottom"; offset: number }>({ side: "left", offset: 10 });

  // The description sits outside the side panel, clear of the chips; below them when it does not fit.
  function measure(open: boolean) {
    if (!open || !ref.current) return;
    const panel = ref.current.closest("[data-side-panel]")!.getBoundingClientRect();
    const left = ref.current.getBoundingClientRect().left - panel.left + 10;
    setPlace(panel.left > 316 ? { side: "left", offset: left } : { side: "bottom", offset: 8 });
  }

  // TooltipTrigger takes over data-state, so the chip's look hangs on aria-checked.
  return (
    <Tooltip onOpenChange={measure} disableHoverableContent>
      <TooltipTrigger asChild>
        <ToggleGroupItem ref={ref} value={film.code} aria-label={film.code} className="h-auto rounded-md border bg-secondary px-[7px] py-1 font-mono text-xs text-foreground hover:border-[#555] hover:bg-secondary hover:text-foreground aria-checked:border-primary aria-checked:bg-primary aria-checked:font-semibold aria-checked:text-primary-foreground">
          {film.code}
        </ToggleGroupItem>
      </TooltipTrigger>
      <TooltipContent side={place.side} sideOffset={place.offset} align="start" collisionPadding={8} className="w-[300px] max-w-[calc(100vw-32px)]">
        <FilmTip film={film} traits={traits} />
      </TooltipContent>
    </Tooltip>
  );
}

interface Props { films: Film[]; film: Film | null; traits: Traits | null; onSelect(code: string): void }

export function FilmPicker({ films, film, traits, onSelect }: Props) {
  const groups = new Map<string, Film[]>();
  for (const f of films) groups.set(f.family, [...(groups.get(f.family) ?? []), f]);
  const t = traits && film && traits[film.code];
  return (
    <Section title="Film">
      {[...groups].map(([family, list], i) => (
        <div key={family}>
          <div className={`mb-1 text-[11px] text-faint ${i ? "mt-2" : ""}`}>{family}</div>
          <ToggleGroup
            type="single" spacing={1} className="w-full flex-wrap" aria-label={family}
            value={film && film.family === family ? film.code : ""}
            onValueChange={(code) => { if (code) onSelect(code); }}
          >
            {list.map((f) => <Chip key={f.code} film={f} traits={traits} />)}
          </ToggleGroup>
        </div>
      ))}
      <div className="mt-2 min-h-[17px] text-xs text-muted-foreground">{t ? `${t.brand} ${t.name} · ISO ${t.iso}` : ""}</div>
      <Note><kbd>[</kbd> <kbd>]</kbd> previous / next film · hover a film for its character</Note>
    </Section>
  );
}
