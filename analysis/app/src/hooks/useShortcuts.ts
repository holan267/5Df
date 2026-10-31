import { useEffect, type Dispatch } from "react";
import { clampEv } from "@/lib/query";
import type { Film } from "@/lib/types";
import type { Action, Settings } from "@/hooks/useSettings";

const TYPING = "input[type=text], input[type=number], [role=listbox], [role=option], [role=combobox]";

export function useShortcuts(s: Settings, films: Film[], dispatch: Dispatch<Action>,
                             toggleZoom: () => void, compare: (on: boolean) => void) {
  useEffect(() => {
    const down = (e: KeyboardEvent) => {
      if (!films.length || (e.target as Element).matches(TYPING)) return;
      const exposure = (v: number) => dispatch({ type: "patch", patch: { exposure: clampEv(v) } });
      if (e.key === "[" || e.key === "]") {
        const i = films.findIndex((f) => f.code === s.film);
        dispatch({ type: "film", films, code: films[(i + (e.key === "]" ? 1 : films.length - 1)) % films.length].code });
      } else if (e.key === "z" || e.key === "Z") toggleZoom();
      else if ((e.key === "c" || e.key === "C") && !e.repeat) compare(true);
      else if (e.key === "-" || e.key === "=" || e.key === "+") exposure(Math.round(s.exposure * 3 + (e.key === "-" ? -1 : 1)) / 3);   // 1/3 stops
      else if (e.key === "0") exposure(0);
    };
    const up = (e: KeyboardEvent) => { if (e.key === "c" || e.key === "C") compare(false); };
    document.addEventListener("keydown", down);
    document.addEventListener("keyup", up);
    return () => {
      document.removeEventListener("keydown", down);
      document.removeEventListener("keyup", up);
    };
  });
}
