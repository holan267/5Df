# LibRaw-Wasm

`libraw.js` and `libraw.wasm` are copied unchanged from the npm package
[`libraw-wasm@1.6.0`](https://www.npmjs.com/package/libraw-wasm) (`dist/`),
built from https://github.com/ybouane/LibRaw-Wasm (wrapper `libraw_wrapper.cpp`, ISC licence).

| File | SHA-256 |
|---|---|
| `libraw.js` | `e23952fca5b268550af1f84619af5c0c035e5db3bde0e4d5a20300f1614a9487` |
| `libraw.wasm` | `8947f7e668e488461c3e9defe7007583aa8477b4886aa603b36b407f2f0846ff` |

Contents of the build:

- [LibRaw](https://www.libraw.org/) 0.22.1, the same version rawpy 0.27 bundles
  (LGPL 2.1 or CDDL 1.0, at the user's choice). Source: https://github.com/LibRaw/LibRaw/tree/0.22.1
- [Little CMS](https://www.littlecms.com/) 2.19.1 (MIT)
- libjpeg, libpng and zlib from Emscripten's ports

The build uses pthreads (`-s USE_PTHREADS=1`), so its memory is a `SharedArrayBuffer`
and the page has to be cross-origin isolated; `../../coi-sw.js` takes care of that.
It is also compiled with `-ffast-math`; see `../README.md` for how closely it matches rawpy.

To update: `npm pack libraw-wasm@<version>`, copy `package/dist/libraw.js` and
`package/dist/libraw.wasm` here, and check `analysis/app/web/README.md` still holds.
