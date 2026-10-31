import { useRef } from "react";
import { cn } from "cn";
import { Button } from "@/components/ui/button";
import { Card, CardContent, CardDescription, CardHeader, CardTitle } from "@/components/ui/card";
import type { KitState } from "@/hooks/useSession";
import type { DirectoryHandle } from "@/lib/types";

interface Props {
  kit: KitState;
  onChoose(fallback: () => void): void;
  onReopen(handle: DirectoryHandle): void;
  onPicked(files: File[]): void;
}

const code = "font-mono text-xs text-foreground";

// Only seen with no lite pack on the server, or through the header's Kit… button.
export function KitPanel({ kit, onChoose, onReopen, onPicked }: Props) {
  const input = useRef<HTMLInputElement>(null);
  const disabled = kit.busy || kit.blocked;
  return (
    <div className="absolute inset-0 z-[2] grid place-items-center bg-viewer p-4">
      <Card className="max-w-[440px] gap-3">
        <CardHeader>
          <CardTitle className="text-[15px]">Open your Ritual kit</CardTitle>
        </CardHeader>
        <CardContent className="space-y-3 leading-normal">
          <CardDescription className="text-[13px]">
            Choose the folder that holds <code className={code}>AUTOEXEC.BIN</code> and the film packs: the <code className={code}>kit</code> folder
            of the Ritual download, or the root of the camera's card (<code className={code}>AUTOEXEC.BIN</code> + <code className={code}>LATENT/</code>),
            or a <code className={code}>LATENT_LITE</code> folder. Raw files in that folder are listed too.
          </CardDescription>
          <CardDescription className="text-[13px]">
            Everything runs in this tab (Python via Pyodide, LibRaw via WebAssembly). Nothing is uploaded;
            the packs are read in place, only the parts a render needs.
          </CardDescription>
          <div className="flex flex-wrap gap-2">
            <Button className="font-semibold" disabled={disabled} onClick={() => onChoose(() => input.current?.click())}>Choose folder…</Button>
            {kit.reopen && (
              <Button variant="outline" disabled={disabled} onClick={() => onReopen(kit.reopen!)}>Reopen {kit.reopen.name}</Button>
            )}
          </div>
          <input
            ref={input} type="file" hidden {...{ webkitdirectory: "" }}
            onChange={(e) => onPicked([...(e.target.files ?? [])])}
          />
          {kit.note && <div className={cn("text-xs text-muted-foreground", kit.err && "text-destructive")}>{kit.note}</div>}
        </CardContent>
      </Card>
    </div>
  );
}
