//! Tables at the firmware's addresses, read from LATENT_LITE/firmware.bin.
use crate::Result;

const PAYLOAD_BASE: usize = 0x982000;
const AUTOEXEC_PAYLOAD_OFFSET: usize = 0x7E0;

pub struct Firmware(Vec<u8>);

impl Firmware {
    pub fn new(mut data: Vec<u8>) -> Firmware {
        if data.starts_with(&[0, 0, 0x0F, 0xE1]) {
            data.drain(..AUTOEXEC_PAYLOAD_OFFSET);
        }
        Firmware(data)
    }

    pub fn bytes(&self, addr: usize, n: usize) -> Result<&[u8]> {
        addr.checked_sub(PAYLOAD_BASE)
            .and_then(|o| self.0.get(o..o + n))
            .ok_or_else(|| format!("firmware.bin has nothing at {addr:#x}"))
    }

    pub fn u32(&self, addr: usize) -> Result<u32> {
        Ok(u32::from_le_bytes(self.bytes(addr, 4)?.try_into().unwrap()))
    }

    pub fn i32s(&self, addr: usize, n: usize) -> Result<Vec<i32>> {
        Ok(self.bytes(addr, n * 4)?.chunks_exact(4).map(|b| i32::from_le_bytes(b.try_into().unwrap())).collect())
    }

    pub fn u16s(&self, addr: usize, n: usize) -> Result<Vec<u16>> {
        Ok(self.bytes(addr, n * 2)?.chunks_exact(2).map(|b| u16::from_le_bytes(b.try_into().unwrap())).collect())
    }

    pub fn f64s(&self, addr: usize, n: usize) -> Result<Vec<f64>> {
        Ok(self.bytes(addr, n * 8)?.chunks_exact(8).map(|b| f64::from_le_bytes(b.try_into().unwrap())).collect())
    }

    /// The NUL-terminated string at `addr`.
    pub fn text(&self, addr: usize) -> Result<String> {
        let o = addr.checked_sub(PAYLOAD_BASE).filter(|o| *o < self.0.len());
        let tail = o.map(|o| &self.0[o..]).ok_or_else(|| format!("firmware.bin has no text at {addr:#x}"))?;
        let end = tail.iter().position(|b| *b == 0).ok_or("unterminated text in firmware.bin")?;
        Ok(tail[..end].iter().map(|b| *b as char).collect())
    }
}
