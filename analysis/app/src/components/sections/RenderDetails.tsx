import { Section } from "@/components/Section";
import { fmtEv } from "@/lib/query";
import type { RenderInfo } from "@/lib/types";

function rows(i: RenderInfo): [string, string | number][] {
  const out: [string, string | number][] = [
    ["Camera", i.model],
    ["WB RGGB", i.wb.join(" ")],
    ["As shot", i.shot_kelvin + " K"],
    ["Light", `${i.kelvin} K · ${i.mired} mired`],
    ["Exposure", `${fmtEv(i.exposure)} · baseline ${i.baseline_exposure >= 0 ? "+" : ""}${i.baseline_exposure}`],
    ["Cubes", i.cubes[0] === i.cubes[1] ? i.cubes[0] : `${i.cubes[0]}/${i.cubes[1]} · w ${i.weight}`],
    ["Output curve", i.bw_curves ? "B&W paper (LTVC)" : "default"],
    ["Grain", i.grain || "off"],
    ["Halation", i.halation ? i.halation + "/256" : "off"],
    ["Size", `${i.width}×${i.height}`],
    ["Time", i.ms + " ms"],
  ];
  if (i.card_path) out.splice(8, 0, ["Grain seed", i.card_path]);
  return out;
}

export function RenderDetails({ info }: { info: RenderInfo | null }) {
  return (
    <Section title="Render">
      <dl className="m-0 grid grid-cols-[auto_1fr] gap-x-2.5 gap-y-[3px] text-xs">
        {(info ? rows(info) : [["—", ""] as [string, string]]).map(([k, v]) => (
          <div key={k} className="contents">
            <dt className="text-muted-foreground">{k}</dt>
            <dd className="m-0 text-right font-mono [overflow-wrap:anywhere]">{v}</dd>
          </div>
        ))}
      </dl>
    </Section>
  );
}
