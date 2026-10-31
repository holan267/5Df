import { Note, Row, Section, Value } from "@/components/Section";
import { Checkbox } from "@/components/ui/checkbox";
import { Label } from "@/components/ui/label";
import { Slider } from "@/components/ui/slider";
import type { Settings } from "@/hooks/useSettings";
import type { Film, RenderInfo } from "@/lib/types";

interface Props { s: Settings; film: Film; info: RenderInfo | null; patch(p: Partial<Settings>): void }

export function Light({ s, film, info, patch }: Props) {
  const [kmin, kmax] = film.kelvin;
  const shot = info && info.shot_kelvin;
  function asShot(on: boolean) {
    patch(!on && info ? { asShot: on, kelvin: Math.round(info.shot_kelvin / 50) * 50 } : { asShot: on });
  }
  return (
    <Section title="Light">
      <Row>
        <Label className="cursor-pointer font-normal">
          <Checkbox checked={s.asShot} onCheckedChange={(v) => asShot(v === true)} /> As shot
        </Label>
        <Value>{(s.asShot ? (shot ? shot : "—") : s.kelvin) + " K"}</Value>
      </Row>
      <Slider
        aria-label="Colour temperature" min={kmin} max={kmax} step={50} disabled={s.asShot}
        value={[s.asShot && shot ? shot : s.kelvin]} onValueChange={([v]) => patch({ kelvin: v })}
      />
      <Note>This film has light steps from {kmin} K to {kmax} K.</Note>
    </Section>
  );
}
