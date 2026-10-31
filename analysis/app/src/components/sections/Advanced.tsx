import { ChevronRight } from "lucide-react";
import { Row, Section, Value } from "@/components/Section";
import { Collapsible, CollapsibleContent, CollapsibleTrigger } from "@/components/ui/collapsible";
import { Input } from "@/components/ui/input";
import { Label } from "@/components/ui/label";
import { Slider } from "@/components/ui/slider";
import type { Settings } from "@/hooks/useSettings";

interface Props { s: Settings; patch(p: Partial<Settings>): void }

export function Advanced({ s, patch }: Props) {
  const card = (e: { currentTarget: HTMLInputElement }) => patch({ card: e.currentTarget.value.trim() });
  return (
    <Section>
      <Collapsible>
        <CollapsibleTrigger className="group flex cursor-pointer items-center gap-1 text-[11px] font-semibold tracking-[.08em] text-muted-foreground uppercase">
          <ChevronRight className="size-3 transition-transform group-data-[state=open]:rotate-90" />
          Advanced
        </CollapsibleTrigger>
        <CollapsibleContent className="pt-2">
          <Row><Label htmlFor="card" className="font-normal text-muted-foreground">Card path (grain seed)</Label></Row>
          <Input
            key={s.card} id="card" type="text" defaultValue={s.card} spellCheck={false}
            placeholder="A:/DCIM/100EOS5D/IMG_0001.CR2"
            className="h-8 bg-secondary font-mono text-xs"
            onBlur={card} onKeyDown={(e) => { if (e.key === "Enter") card(e); }}
          />
          <Row>
            <Label className="font-normal text-muted-foreground">Export JPEG quality</Label>
            <Value>{s.quality}</Value>
          </Row>
          <Slider aria-label="Export JPEG quality" min={70} max={100} step={1} value={[s.quality]} onValueChange={([v]) => patch({ quality: v })} />
        </CollapsibleContent>
      </Collapsible>
    </Section>
  );
}
