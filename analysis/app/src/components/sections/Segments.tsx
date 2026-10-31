import { ToggleGroup, ToggleGroupItem } from "@/components/ui/toggle-group";

interface Props {
  label: string;
  options: [number, string][];
  value: number | null;       // null: none lit
  disabled?: boolean;
  onChange(v: number): void;
}

export function Segments({ label, options, value, disabled, onChange }: Props) {
  return (
    <ToggleGroup
      type="single" variant="outline" size="sm" aria-label={label} disabled={disabled} className="w-full"
      value={value === null ? "" : String(value)}
      onValueChange={(v) => { if (v) onChange(+v); }}
    >
      {options.map(([v, text]) => (
        <ToggleGroupItem
          key={v} value={String(v)}
          className="h-7 flex-1 bg-secondary text-xs font-normal data-[state=on]:bg-primary data-[state=on]:font-semibold data-[state=on]:text-primary-foreground"
        >
          {text}
        </ToggleGroupItem>
      ))}
    </ToggleGroup>
  );
}
