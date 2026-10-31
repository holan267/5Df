import type { ReactNode } from "react";
import { cn } from "cn";

export function Section({ title, children }: { title?: string; children: ReactNode }) {
  return (
    <section className="border-b px-3.5 py-3 max-[900px]:px-4">
      {title && <h2 className="mt-0 mb-2 text-[11px] font-semibold tracking-[.08em] text-muted-foreground uppercase">{title}</h2>}
      {children}
    </section>
  );
}

export function Row({ children }: { children: ReactNode }) {
  return <div className="my-2 flex min-h-5 items-center justify-between gap-2 first:mt-0">{children}</div>;
}

export function Value({ children }: { children: ReactNode }) {
  return <span className="font-mono text-xs">{children}</span>;
}

export function Note({ className, children }: { className?: string; children: ReactNode }) {
  return <div className={cn("mt-1 text-[11px] text-faint", className)}>{children}</div>;
}
