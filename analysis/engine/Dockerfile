# Toolchain of latent_engine.wasm. emsdk has to be new enough for rustc's LLVM: 3.1.68, the
# version in Rust's docs, has a wasm-opt that rejects what 1.97 emits. See README.
FROM emscripten/emsdk:6.0.6

ENV RUSTUP_HOME=/opt/rustup CARGO_HOME=/opt/cargo PATH=/opt/cargo/bin:$PATH
RUN curl -sSf https://sh.rustup.rs | sh -s -- -y --profile minimal \
      --default-toolchain 1.97.0 --target wasm32-unknown-emscripten
