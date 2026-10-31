import type { Settings } from "@/hooks/useSettings";
import type { Film } from "@/lib/types";

export const fmtEv = (v: number) => (v > 0 ? "+" : v < 0 ? "−" : "±") + Math.abs(v).toFixed(1) + " EV";
export const clampEv = (v: number) => Math.round(Math.max(-5, Math.min(5, v)) * 10) / 10;

export function query(s: Settings, film: Film, extra: Record<string, string | number>) {
  const q = new URLSearchParams({
    file: s.file, film: s.film, paper: String(s.paper), push: String(s.push), grade: String(s.grade),
    exposure: String(s.exposure), gamut: s.gamut ? "1" : "0", grain: s.grain ? "1" : "0",
    halation: String(film.halation ? s.halation : -1), card_path: s.card,
    ...Object.fromEntries(Object.entries(extra).map(([k, v]) => [k, String(v)])),
  });
  if (!s.asShot) q.set("kelvin", String(s.kelvin));
  return q.toString();
}
