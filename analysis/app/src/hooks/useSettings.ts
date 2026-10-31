import { useEffect, useReducer } from "react";
import type { Film, RawFile } from "@/lib/types";

const DEFAULTS = { file: "", film: "P400", paper: 0, push: 0, grade: 5, exposure: 0, asShot: true, kelvin: 5500,
                   grain: true, gamut: true, halation: 2, scale: 4, card: "", quality: 95 };
export type Settings = typeof DEFAULTS;

export type Action =
  | { type: "patch"; patch: Partial<Settings> }
  | { type: "film"; films: Film[]; code: string }
  | { type: "start"; films: Film[]; files: RawFile[] };

function load(): Settings {
  try { return { ...DEFAULTS, ...JSON.parse(localStorage.getItem("latent-darkroom") || "{}") }; } catch { return DEFAULTS; }
}

// Papers, push steps and grades differ per film; keep what still exists on this one.
function onFilm(s: Settings, films: Film[], code: string): Settings {
  const film = films.find((f) => f.code === code) || films[0];
  const next = { ...s, film: film.code };
  if (next.paper >= film.papers.length) next.paper = 0;
  if (!film.push.includes(next.push)) next.push = film.push.includes(0) ? 0 : film.push[0];
  if (film.grades.length) next.grade = Math.min(next.grade, film.grades.length - 1);
  return next;
}

function reduce(s: Settings, a: Action): Settings {
  if (a.type === "patch") return { ...s, ...a.patch };
  if (a.type === "film") return onFilm(s, a.films, a.code);
  const file = a.files.some((f) => f.id === s.file) ? s.file : a.files.length ? a.files[0].id : "";
  return onFilm({ ...s, file }, a.films, s.film);
}

export function useSettings() {
  const [s, dispatch] = useReducer(reduce, undefined, load);
  useEffect(() => {
    try { localStorage.setItem("latent-darkroom", JSON.stringify(s)); } catch { /* private window */ }
  }, [s]);
  return [s, dispatch] as const;
}
