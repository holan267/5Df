import path from "node:path";
import tailwindcss from "@tailwindcss/vite";
import react from "@vitejs/plugin-react";
import { defineConfig } from "vite";

// LibRaw-Wasm needs SharedArrayBuffer, so the page has to be cross-origin isolated.
// Hosts that cannot send these get them from public/coi-sw.js.
const isolation = {
  "Cross-Origin-Opener-Policy": "same-origin",
  "Cross-Origin-Embedder-Policy": "require-corp",
};

export default defineConfig({
  base: "./",        // dist/ works from any sub-path
  plugins: [react(), tailwindcss()],
  resolve: { alias: { "@": path.resolve(import.meta.dirname, "src") } },
  worker: { format: "es" },
  build: { chunkSizeWarningLimit: 1024 },
  server: {
    headers: isolation,
    proxy: { "/api": "http://127.0.0.1:8765" },   // latent_app.py, when it runs
    // The worker imports ../tools/*.py. Not "..": analysis/derived/ holds the key-bearing payload.
    fs: { allow: [".", "../tools"] },
  },
  preview: { headers: isolation },
});
