import { Note, Row, Section, Value } from "@/components/Section";
import { Button } from "@/components/ui/button";
import { Label } from "@/components/ui/label";
import { Slider } from "@/components/ui/slider";
import type { Settings } from "@/hooks/useSettings";
import { clampEv, fmtEv } from "@/lib/query";

interface Props { s: Settings; patch(p: Partial<Settings>): void }

export function Exposure({ s, patch }: Props) {
  const set = (v: number) => patch({ exposure: clampEv(v) });
  return (
    <Section title="Exposure">
      <Row>
        <Label htmlFor="exposure" className="font-normal text-muted-foreground">Exposure</Label>
        <span className="flex items-center gap-2">
          {s.exposure !== 0 && (
            <Button
              variant="link" className="h-auto p-0 text-[11px] font-normal text-faint hover:text-foreground"
              title="Back to 0 EV (or double-click the slider)" onClick={() => set(0)}
            >
              reset
            </Button>
          )}
          <Value>{fmtEv(s.exposure)}</Value>
        </span>
      </Row>
      <Slider
        id="exposure" aria-label="Exposure" min={-5} max={5} step={0.1} value={[s.exposure]}
        onValueChange={([v]) => set(v)} onDoubleClick={() => set(0)}
      />
      <div className="mt-px flex justify-between font-mono text-[10px] text-faint"><span>−5</span><span>0</span><span>+5</span></div>
      <Note>
        Applied to the linear raw before the film. Highlights the sensor clipped stay clipped when you pull down.<br />
        <kbd>-</kbd> <kbd>=</kbd> ⅓ stop · <kbd>0</kbd> reset
      </Note>
    </Section>
  );
}
