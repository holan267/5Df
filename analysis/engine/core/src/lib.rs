//! The darkroom's pipeline in plain Rust, without LibRaw or the browser: tools/latent_*.py
//! is the reference, and tests/golden.rs holds this crate to what those scripts produce.
//! numpy's type promotions are kept where they change results; the comments say where.
pub mod color;
pub mod develop;
pub mod firmware;
pub mod grain;
pub mod halation;
pub mod jpeg;
pub mod lite;
pub mod meta;
pub mod studio;

pub type Result<T> = std::result::Result<T, String>;
