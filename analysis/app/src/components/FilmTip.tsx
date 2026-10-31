import { Badge } from "@/components/ui/badge";
import type { Film, Trait, Traits } from "@/lib/types";

function ToneCurve({ m }: { m: Trait["measures"] }) {
  // x: stops over/under grey, y: OKLab lightness of the print. Dashed: plain sRGB, no film.
  const W = 276, H = 96, x0 = m.curve_stops[0], x1 = m.curve_stops[m.curve_stops.length - 1];
  const X = (s: number) => ((s - x0) / (x1 - x0) * W).toFixed(1), Y = (l: number) => (H - l * H).toFixed(1);
  const line = (pts: [number, number][]) => pts.map(([s, l], i) => (i ? "L" : "M") + X(s) + " " + Y(l)).join("");
  const ref: [number, number][] = [];
  for (let s = x0; s <= x1; s += 0.25) ref.push([s, Math.cbrt(Math.min(0.18 * 2 ** s, 1))]);
  const film = m.curve_stops.map((s, i): [number, number] => [s, m.curve[i]]);
  const label = "fill-faint font-mono text-[9px]";
  return (
    <svg viewBox={`-2 -2 ${W + 4} ${H + 16}`} aria-label="Tone curve" className="mb-1.5 block h-auto w-full">
      <rect x="0" y="0" width={W} height={H} fill="none" stroke="var(--border)" />
      <line x1={X(0)} x2={X(0)} y1="0" y2={H} stroke="var(--border)" />
      <path d={line(ref)} fill="none" stroke="var(--faint)" strokeDasharray="3 3" />
      <path d={line(film)} fill="none" stroke="var(--primary)" strokeWidth="2" />
      <text className={label} x="0" y={H + 11}>{x0} EV</text>
      <text className={label} x={X(0)} y={H + 11} textAnchor="middle">grey</text>
      <text className={label} x={W} y={H + 11} textAnchor="end">+{x1} EV</text>
    </svg>
  );
}

const BARS = [["contrast", "Contrast", "soft", "punchy"], ["saturation", "Colour", "muted", "vivid"],
              ["black", "Blacks", "deep", "lifted"], ["shoulder", "Highlights", "clip early", "long roll-off"],
              ["warmth", "Balance", "cool", "warm"]];

export function FilmTip({ film, traits }: { film: Film; traits: Traits | null }) {
  const t = traits && traits[film.code];
  if (!t) return (
    <>
      <h3 className="m-0 text-[13px] font-semibold">{film.code}</h3>
      <div className="mt-px text-[11px] text-muted-foreground">{film.family}</div>
      <p className="mt-2 text-xs leading-[1.45]">Measuring the film's character… (first start only, about half a minute)</p>
    </>
  );
  const paper = film.papers[0];
  return (
    <>
      <h3 className="m-0 text-[13px] font-semibold">{t.brand} {t.name}</h3>
      <div className="mt-px text-[11px] text-muted-foreground">{film.code} · ISO {t.iso} · {t.family}</div>
      <div className="my-2 flex flex-wrap gap-1">
        {t.tags.map((x) => <Badge key={x} variant="outline" className="rounded-full px-[7px] py-px text-[11px] font-normal">{x}</Badge>)}
      </div>
      <p className="mb-2 text-xs leading-[1.45]">{t.summary}</p>
      <ToneCurve m={t.measures} />
      <dl className="m-0 grid grid-cols-[62px_1fr] items-center gap-x-2 gap-y-1 text-[11px]">
        {BARS.filter(([k]) => t.scores[k] !== null).map(([k, label, lo, hi]) => {
          const v = t.scores[k]!, w = Math.abs(v) / 2 * 50;
          return (
            <div key={k} className="contents">
              <dt className="text-muted-foreground">{label}</dt>
              <dd className="m-0">
                <div className="relative h-1.5 rounded-[3px] bg-background after:absolute after:-top-0.5 after:-bottom-0.5 after:left-1/2 after:w-px after:bg-faint">
                  <i className="absolute inset-y-0 rounded-[3px] bg-primary" style={{ left: `${v < 0 ? 50 - w : 50}%`, width: `${w}%` }} />
                </div>
                <div className="mt-px flex justify-between text-[10px] text-faint"><span>{lo}</span><span>{hi}</span></div>
              </dd>
            </div>
          );
        })}
      </dl>
      <div className="mt-2 text-[10px] text-faint">
        Measured from the cube at {t.measures.kelvin} K, {paper ? paper.name : ""}, push 0{paper && paper.bw && film.grades.length > 5 ? ", grade " + film.grades[5] : ""}.
        {" "}Bars compare with the other {Object.keys(traits).length - 1} films here; balance is absolute.
      </div>
    </>
  );
}
