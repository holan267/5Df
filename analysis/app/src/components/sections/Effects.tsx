import { Note, Row, Section } from "@/components/Section";
import { Segments } from "@/components/sections/Segments";
import { Checkbox } from "@/components/ui/checkbox";
import { Label } from "@/components/ui/label";
import type { Settings } from "@/hooks/useSettings";
import type { Film } from "@/lib/types";

interface Props { s: Settings; film: Film; patch(p: Partial<Settings>): void }

const HALATION: [number, string][] = [[-1, "Off"], [0, "Low"], [1, "Mid"], [2, "Full"]];

export function Effects({ s, film, patch }: Props) {
  return (
    <Section title="Effects">
      <Row>
        <Label className="cursor-pointer font-normal">
          <Checkbox checked={s.grain} onCheckedChange={(v) => patch({ grain: v === true })} /> Grain
        </Label>
      </Row>
      <Row>
        <Label className="cursor-pointer font-normal">
          <Checkbox checked={s.gamut} onCheckedChange={(v) => patch({ gamut: v === true })} /> Gamut compression
        </Label>
      </Row>
      <Row><span className="text-muted-foreground">Halation</span></Row>
      <Segments
        label="Halation" options={HALATION} disabled={!film.halation}
        value={film.halation ? s.halation : null} onChange={(halation) => patch({ halation })}
      />
      {!film.halation && <Note>Halation is only used by the motion-picture films.</Note>}
    </Section>
  );
}
