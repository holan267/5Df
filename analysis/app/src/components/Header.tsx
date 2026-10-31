import { cn } from "cn";
import { Button } from "@/components/ui/button";
import type { Status } from "@/hooks/useSession";

interface Props { title: string; status: Status; kitButton: boolean; onKit(): void }

export function Header({ title, status, kitButton, onKit }: Props) {
  return (
    <header className="flex items-center gap-3 border-b bg-card px-3.5 [grid-area:top]">
      <h1 className="m-0 shrink-0 text-sm font-semibold tracking-[.02em] whitespace-nowrap">Latent <span className="text-primary">Darkroom</span></h1>
      <div className="min-w-0 flex-1 truncate text-muted-foreground max-[900px]:hidden">{title}</div>
      <div className={cn("ml-auto min-w-0 truncate font-mono text-xs text-muted-foreground", status.err && "text-destructive")}>{status.text}</div>
      {kitButton && (
        <Button variant="outline" size="xs" title="Choose another kit folder" onClick={onKit}>Kit…</Button>
      )}
    </header>
  );
}
