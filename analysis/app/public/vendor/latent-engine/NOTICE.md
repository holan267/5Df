# latent_engine

`latent_engine.js` and `latent_engine.wasm` are built from `analysis/engine` by its
`build.sh` (see `analysis/engine/README.md`). They are one module: the pipeline in Rust
plus LibRaw, linked statically.

Contents of the build:

- [LibRaw](https://www.libraw.org/) 0.22.1, unmodified, built without LCMS, JPEG or zlib
  support. LibRaw is offered under LGPL 2.1 or CDDL 1.0; this module takes it under
  **CDDL 1.0**, whose file-level terms allow static linking. Licence text: `LICENSE.CDDL`
  in the source. Source: https://github.com/LibRaw/LibRaw/tree/0.22.1 (commit `b860248`),
  a submodule at `analysis/engine/third_party/LibRaw`.
- Emscripten's libc and libc++ (MIT, University of Illinois/NCSA)
- Rust's standard library (MIT or Apache 2.0)
- Rust crates, with versions in `analysis/engine/Cargo.lock`: `jpeg-encoder` (MIT or Apache 2.0),
  `miniz_oxide` (MIT, Zlib or Apache 2.0), `serde` and `serde_json` (MIT or Apache 2.0)

The module holds no keys: firmware tables are read at run time from `LATENT_LITE/firmware.bin`.
