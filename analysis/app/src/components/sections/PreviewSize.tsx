import { Note, Section } from "@/components/Section";
import { Segments } from "@/components/sections/Segments";
import type { Settings } from "@/hooks/useSettings";

interface Props { s: Settings; patch(p: Partial<Settings>): void }

const SCALES: [number, string][] = [[4, "¼"], [2, "½"], [1, "Full"]];

export function PreviewSize({ s, patch }: Props) {
  return (
    <Section title="Preview size">
      <Segments label="Preview size" options={SCALES} value={s.scale} onChange={(scale) => patch({ scale })} />
      <Note>Grain is generated per output pixel, so it only looks like the camera's at Full.</Note>
    </Section>
  );
}
