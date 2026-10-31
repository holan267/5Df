import { Row, Section, Value } from "@/components/Section";
import { Label } from "@/components/ui/label";
import { Select, SelectContent, SelectItem, SelectTrigger, SelectValue } from "@/components/ui/select";
import { Slider } from "@/components/ui/slider";
import type { Settings } from "@/hooks/useSettings";
import type { Film } from "@/lib/types";

interface Props { s: Settings; film: Film; patch(p: Partial<Settings>): void }

const label = "font-normal text-muted-foreground";

export function Print({ s, film, patch }: Props) {
  const bw = film.papers[s.paper].bw;
  return (
    <Section title="Print">
      <Row><Label className={label}>Paper</Label></Row>
      <Select value={String(s.paper)} onValueChange={(v) => patch({ paper: +v })}>
        <SelectTrigger size="sm" aria-label="Paper" className="w-full bg-secondary text-[13px]"><SelectValue /></SelectTrigger>
        <SelectContent>
          {film.papers.map((p) => (
            <SelectItem key={p.index} value={String(p.index)} className="text-[13px]">{p.name + (p.bw ? "  (B&W)" : "")}</SelectItem>
          ))}
        </SelectContent>
      </Select>
      {bw && (
        <>
          <Row>
            <Label className={label}>Paper grade</Label>
            <Value>{film.grades.length ? "grade " + film.grades[s.grade] : ""}</Value>
          </Row>
          <Slider aria-label="Paper grade" min={0} max={film.grades.length - 1} step={1} value={[s.grade]} onValueChange={([v]) => patch({ grade: v })} />
        </>
      )}
      <Row>
        <Label className={label}>Push / pull</Label>
        <Value>{(s.push > 0 ? "+" : "") + s.push + " stop" + (Math.abs(s.push) === 1 ? "" : "s")}</Value>
      </Row>
      <Slider
        aria-label="Push / pull" min={0} max={film.push.length - 1} step={1} value={[film.push.indexOf(s.push)]}
        disabled={film.push.length < 2} onValueChange={([v]) => patch({ push: film.push[v] })}
      />
    </Section>
  );
}
