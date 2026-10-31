#!/bin/sh
# Builds Rust + LibRaw into one module, from analysis/engine, with em++ and cargo on PATH.
# Either the Dockerfile's image:
#   docker build -t latent-engine-build analysis/engine
#   docker run --rm -v "$PWD:/src" -w /src/analysis/engine latent-engine-build sh build.sh
# or Git Bash with emsdk 6.0.6 in build/emsdk (picked up below) and
#   rustup target add wasm32-unknown-emscripten
set -eu

if [ -f build/emsdk/emsdk_env.sh ]; then
  . build/emsdk/emsdk_env.sh >/dev/null 2>&1
fi

LIBRAW=third_party/LibRaw
OBJ=build/obj
OUT=build/out
mkdir -p "$OBJ" "$OUT"

# Legacy wasm exceptions: what rustc's std for this target is built with.
EH="-fwasm-exceptions -sWASM_LEGACY_EXCEPTIONS=1"
CXXFLAGS="-O3 -msimd128 $EH -DLIBRAW_NOTHREADS -DLIBRAW_NODLL -I$LIBRAW -Wno-everything"

# LibRaw's own source list. Objects survive between builds, in build/ (ignored by git).
sed -n '/^lib_libraw_a_SOURCES/,/^$/p' "$LIBRAW/Makefile.am" | grep -o 'src/[A-Za-z0-9_/.-]*\.cpp' | sort -u > build/sources
while read -r src; do
  o="$OBJ/$(echo "$src" | tr / _).o"
  [ "$o" -nt "$LIBRAW/$src" ] || printf '%s %s\n' "$LIBRAW/$src" "$o"
done < build/sources > build/todo
# shellcheck disable=SC2086
[ ! -s build/todo ] || xargs -a build/todo -P "$(nproc)" -L 1 sh -c 'em++ '"$CXXFLAGS"' -c "$0" -o "$1"'
# shellcheck disable=SC2086
em++ $CXXFLAGS -c cpp/libraw_shim.cpp -o "$OBJ/shim.o"

export RUSTFLAGS="-C target-feature=+simd128"
cargo build --release --target wasm32-unknown-emscripten -p latent-engine

EXPORTS=_malloc,_free,$(grep -o 'extern "C" fn engine_[a-z0-9_]*' wasm/src/lib.rs | sed 's/.* fn /_/' | paste -sd, -)
# shellcheck disable=SC2086
em++ "$OBJ"/*.o target/wasm32-unknown-emscripten/release/liblatent_engine.a -o "$OUT/latent_engine.mjs" \
  -O3 -msimd128 $EH \
  -sMODULARIZE -sEXPORT_ES6 -sEXPORT_NAME=LatentEngine -sENVIRONMENT=worker,node \
  -sFILESYSTEM=0 -sALLOW_MEMORY_GROWTH -sINITIAL_MEMORY=64MB -sMAXIMUM_MEMORY=4GB -sSTACK_SIZE=5MB \
  -sEXPORTED_FUNCTIONS="$EXPORTS" -sEXPORTED_RUNTIME_METHODS=HEAPU8,UTF8ToString,stringToNewUTF8

DEST=../app/public/vendor/latent-engine
mkdir -p "$DEST"
cp "$OUT/latent_engine.mjs" "$OUT/latent_engine.wasm" "$DEST/"
ls -l "$DEST"
