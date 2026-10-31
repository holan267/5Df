//! latent_app.Studio: the catalogue, the cached stages, and turning a query into a render.
//! The host hands over files on request: a call stops with Stop::Need(path), the host puts
//! the file and calls again, and what was decoded by then is in the caches.
use crate::color::M3;
use crate::develop::{Frame, Tables};
use crate::firmware::Firmware;
use crate::grain::{fnv1a_seed, grain_noise, Grain};
use crate::halation::{self, Halation, Maps, Offsets, Profile, HALO_LEVELS};
use crate::jpeg;
use crate::lite::{self, Film, GRAIN_BLOCK};
use crate::meta::{open_raw, RawInfo, Source};
use serde_json::{json, Value};
use std::collections::HashMap;
use std::rc::Rc;

const PAPER_NAMES: usize = 0x9B1D90;      // 19 pointers: 10 colour, 2 reversal, 4 print, 3 B&W
const BW_PAPERS: (usize, usize) = (16, 19);
const EXPOSURE_RANGE: f64 = 5.0;

pub enum Stop {
    Need(String),
    Bad(String),
}

impl From<String> for Stop {
    fn from(s: String) -> Stop {
        Stop::Bad(s)
    }
}

impl From<&str> for Stop {
    fn from(s: &str) -> Stop {
        Stop::Bad(s.to_string())
    }
}

type Result<T> = std::result::Result<T, Stop>;

/// An opened raw. LibRaw in the module, dumps in tests.
pub trait Decoder {
    fn data(&self) -> &[u8];
    fn info(&self) -> RawInfo;
    /// Demosaiced camera RGB and its width and height.
    fn decode(&mut self, half: bool, black: i32, white: i32) -> crate::Result<(Vec<u16>, usize, usize)>;
}

pub type Opener = fn(Vec<u8>) -> crate::Result<Box<dyn Decoder>>;

/// A value and the number that changes with it, for the GPU's copy to follow.
pub struct Tagged<T> {
    pub tag: u64,
    pub v: T,
}

struct Lru<K, V> {
    size: usize,
    items: Vec<(K, V)>,
}

impl<K: PartialEq, V: Clone> Lru<K, V> {
    fn new(size: usize) -> Self {
        Lru { size, items: Vec::new() }
    }

    fn get(&mut self, key: &K) -> Option<V> {
        let i = self.items.iter().position(|(k, _)| k == key)?;
        let item = self.items.remove(i);
        let v = item.1.clone();
        self.items.push(item);
        Some(v)
    }

    fn put(&mut self, key: K, v: V) {
        self.items.push((key, v));
        if self.items.len() > self.size {
            self.items.remove(0);
        }
    }

    fn retain(&mut self, keep: impl Fn(&K) -> bool) {
        self.items.retain(|(k, _)| keep(k));
    }
}

pub struct Image {
    pub rgb: Vec<u16>,
    pub width: usize,
    pub height: usize,
}

struct Pack {
    film: Film,
    curve: Option<Rc<Vec<f64>>>,
    curves: Option<Rc<Vec<u8>>>,
    grain: Option<(usize, Rc<Vec<u8>>)>,
}

#[derive(Debug, Clone)]
pub struct Query {
    pub file: String,
    pub film: String,
    pub paper: usize,
    pub push: i32,
    pub grade: usize,
    pub kelvin: Option<f64>,
    pub exposure: f64,
    pub gamut: bool,
    pub grain: bool,
    pub halation: i32,
    pub card_path: String,
    pub scale: usize,
    pub quality: u8,
}

/// Everything develop() needs for one picture.
pub struct Job {
    pub image: Rc<Tagged<Image>>,
    pub clip: [f32; 3],
    pub matrix: M3,
    pub tables: Rc<Tagged<Tables>>,
    /// The LTVC curves file and the offset of this picture's curves in it.
    pub curves: Option<(Rc<Vec<u8>>, usize)>,
    pub cube: Rc<Tagged<Vec<f32>>>,
    pub gamut: bool,
    pub halo: Option<(Rc<Tagged<Maps>>, Rc<Profile>, u32)>,
    pub grain: Option<(Rc<Tagged<Grain>>, Rc<Tagged<Vec<i16>>>)>,
    pub orientation: u32,
    pub tags: [(u16, String); 4],
    pub info: Value,
    pub name: String,
    pub quality: u8,
    pub gpu: GpuData,
}

/// Forms only the shader wants: words, and floats where develop() works in doubles.
pub struct GpuData {
    pub out8: Vec<u32>,
    pub out8_tag: String,
    pub maps: Vec<f32>,
}

impl Job {
    pub fn out8<'a>(&'a self) -> [&'a [u8]; 3] {
        match &self.curves {
            Some((b, base)) => [0, 1, 2].map(|i| &b[base + 0x1000 * i..base + 0x1000 * (i + 1)]),
            None => [&self.tables.v.out8, &self.tables.v.out8, &self.tables.v.out8],
        }
    }

    /// The CPU path.
    pub fn develop(&self) -> Vec<u8> {
        let img = &self.image.v;
        let offsets = self.halo.as_ref().map(|(m, p, level)| Offsets::new(&m.v, p, *level, img.height, img.width));
        Frame {
            rgb: &img.rgb,
            width: img.width,
            height: img.height,
            clip: self.clip,
            matrix: self.matrix.map(|r| r.map(|v| v as f32)),
            tables: &self.tables.v,
            out8: self.out8(),
            cube: &self.cube.v,
            gamut: self.gamut,
            halo: offsets.as_ref(),
            grain: self.grain.as_ref().map(|(g, n)| (&g.v, n.v.as_slice())),
        }
        .develop()
    }

    /// RGB8 in sensor orientation -> the finished file.
    pub fn encode(&self, rgb: Vec<u8>, width: usize, height: usize) -> crate::Result<Vec<u8>> {
        let (rgb, w, h) = jpeg::rotate(rgb, width, height, self.orientation);
        let tags = [0, 1, 2, 3].map(|i| (self.tags[i].0, self.tags[i].1.as_str()));
        jpeg::encode(&rgb, w, h, self.quality, &tags)
    }
}

fn decode_component(s: &str) -> String {
    let b = s.as_bytes();
    let (mut out, mut i) = (Vec::with_capacity(b.len()), 0);
    while i < b.len() {
        match b[i] {
            b'+' => out.push(b' '),
            b'%' if i + 2 < b.len() => {
                let hex = std::str::from_utf8(&b[i + 1..i + 3]).ok().and_then(|h| u8::from_str_radix(h, 16).ok());
                match hex {
                    Some(v) => {
                        out.push(v);
                        i += 2;
                    }
                    None => out.push(b'%'),
                }
            }
            c => out.push(c),
        }
        i += 1;
    }
    String::from_utf8_lossy(&out).into_owned()
}

fn arg<T: std::str::FromStr>(q: &HashMap<String, String>, name: &str, default: T) -> Result<T> {
    match q.get(name).map(String::as_str) {
        None | Some("") => Ok(default),
        Some(v) => v.parse().map_err(|_| Stop::Bad(format!("bad value for {name}: {v:?}"))),
    }
}

pub fn parse_query(text: &str) -> Result<Query> {
    let q: HashMap<String, String> = text
        .split('&')
        .filter_map(|p| p.split_once('='))
        .map(|(k, v)| (decode_component(k), decode_component(v)))
        .collect();
    let p = Query {
        file: q.get("file").cloned().unwrap_or_default(),
        film: q.get("film").cloned().unwrap_or_default().to_uppercase(),
        paper: arg(&q, "paper", 0)?,
        push: arg(&q, "push", 0)?,
        grade: arg(&q, "grade", 5)?,
        kelvin: match arg(&q, "kelvin", f64::NAN)? {
            k if k.is_nan() => None,
            k => Some(k),
        },
        exposure: arg(&q, "exposure", 0.0)?,
        gamut: arg(&q, "gamut", 1)? != 0,
        grain: arg(&q, "grain", 1)? != 0,
        halation: arg(&q, "halation", 2)?,
        card_path: q.get("card_path").map_or(String::new(), |c| c.trim().to_string()),
        scale: arg(&q, "scale", 4)?,
        quality: arg(&q, "quality", 95)?,
    };
    if ![1, 2, 4].contains(&p.scale) {
        return Err("scale must be one of (1, 2, 4)".into());
    }
    if p.kelvin.is_some_and(|k| k <= 0.0) {
        return Err("kelvin must be positive".into());
    }
    if !(p.exposure.abs() <= EXPOSURE_RANGE) {
        return Err(format!("exposure must be -{EXPOSURE_RANGE}..+{EXPOSURE_RANGE} EV").into());
    }
    if !(-1..=2).contains(&p.halation) {
        return Err("halation must be -1..2".into());
    }
    if !(1..=100).contains(&p.quality) {
        return Err("quality must be 1..100".into());
    }
    if !p.card_path.is_ascii() {
        return Err("card path must be ASCII".into());
    }
    Ok(p)
}

fn round(v: f64, digits: i32) -> f64 {
    let s = 10f64.powi(digits);
    (v * s).round_ties_even() / s
}

pub struct Studio {
    fw: Firmware,
    open: Opener,
    paper_table: Vec<String>,
    packs: HashMap<String, Pack>,
    files: HashMap<String, Vec<u8>>,
    decoder: Option<(String, Box<dyn Decoder>)>,
    sources: Lru<String, Rc<Source>>,
    images: Lru<(String, usize), Rc<Tagged<Image>>>,
    tables: Lru<String, Rc<Tagged<Tables>>>,
    cubes: Lru<(String, usize), Rc<Tagged<Vec<f32>>>>,
    blended: Option<((String, usize, usize, u64), Rc<Tagged<Vec<f32>>>)>,
    paper: Option<(String, usize, Vec<f32>)>,        // one, over all packs: up to 330 MB
    grains: Lru<(String, usize, usize, usize), Rc<Tagged<Grain>>>,
    noise: Lru<(u32, usize, usize, usize), Rc<Tagged<Vec<i16>>>>,
    halos: Lru<(String, usize, String, u64), Rc<Tagged<Maps>>>,
    next_tag: u64,
}

impl Studio {
    pub fn new(firmware: Vec<u8>, open: Opener) -> crate::Result<Studio> {
        let fw = Firmware::new(firmware);
        let paper_table = (0..19)
            .map(|i| fw.text(fw.u32(PAPER_NAMES + 4 * i)? as usize))
            .collect::<crate::Result<Vec<_>>>()?;
        Ok(Studio {
            fw,
            open,
            paper_table,
            packs: HashMap::new(),
            files: HashMap::new(),
            decoder: None,
            sources: Lru::new(8),
            images: Lru::new(3),
            tables: Lru::new(32),
            cubes: Lru::new(24),
            blended: None,
            paper: None,
            grains: Lru::new(8),
            noise: Lru::new(3),
            halos: Lru::new(4),
            next_tag: 0,
        })
    }

    pub fn add_film(&mut self, film_json: &[u8]) -> crate::Result<()> {
        let film: Film = serde_json::from_slice(film_json).map_err(|e| format!("film.json: {e}"))?;
        self.packs.insert(film.code.clone(), Pack { film, curve: None, curves: None, grain: None });
        Ok(())
    }

    pub fn put(&mut self, path: String, data: Vec<u8>) {
        self.files.insert(path, data);
    }

    /// Whatever a finished call did not use.
    pub fn clear_files(&mut self) {
        self.files.clear();
    }

    fn take(&mut self, path: String) -> Result<Vec<u8>> {
        self.files.remove(&path).ok_or(Stop::Need(path))
    }

    fn tag<T>(&mut self, v: T) -> Rc<Tagged<T>> {
        self.next_tag += 1;
        Rc::new(Tagged { tag: self.next_tag, v })
    }

    /// A raw whose file changed: what was kept of the old one goes.
    pub fn forget(&mut self, id: &str) {
        if self.decoder.as_ref().is_some_and(|(d, _)| d == id) {
            self.decoder = None;
        }
        self.sources.retain(|k| k != id);
        self.images.retain(|k| k.0 != id);
        self.halos.retain(|k| k.0 != id);
    }

    // ------------------------------------------------------------ catalogue

    fn film_info(&self, pack: &Pack) -> crate::Result<Value> {
        let f = &pack.film;
        let colour = f.grade.iter().filter(|g| *g & 0x80 == 0).count();
        let (lo, hi) = match colour {
            10 => (0, 10),
            2 => (10, 12),
            4 => (12, 16),
            _ => (0, 0),
        };
        let (mut papers, mut k) = (vec![], 0);
        for (i, g) in f.grade.iter().enumerate() {
            let bw = g & 0x80 != 0;
            let name = if bw {
                let j = BW_PAPERS.0 + k;
                k += 1;
                if j < BW_PAPERS.1 { self.paper_table[j].clone() } else { format!("B&W paper {}", k - 1) }
            } else if lo + (*g as usize) < hi {
                self.paper_table[lo + *g as usize].clone()
            } else {
                format!("Paper {i}")
            };
            papers.push(json!({"index": i, "name": name, "bw": bw}));
        }
        let family = if colour == 0 {
            "B&W"
        } else if k > 0 {
            "B&W, colour or B&W paper"
        } else {
            match colour {
                10 => "colour negative",
                2 => "colour reversal",
                4 => "motion picture",
                _ => "film",
            }
        };
        let (first, last) = (f.light_mired[0], f.light_mired[f.light_mired.len() - 1]);
        Ok(json!({
            "code": f.code, "family": family, "papers": papers, "push": f.push, "grades": f.extra,
            "kelvin": [(1e6 / last).round_ties_even(), (1e6 / first).round_ties_even()],
            "halation": halation::profile(&self.fw, &f.code)?.is_some(),
        }))
    }

    pub fn films(&self) -> crate::Result<Value> {
        let order = ["colour negative", "colour reversal", "motion picture", "B&W"];
        let mut films = self.packs.values().map(|p| self.film_info(p)).collect::<crate::Result<Vec<_>>>()?;
        let rank = |f: &Value| order.iter().position(|o| *o == f["family"]).unwrap_or(order.len());
        films.sort_by(|a, b| rank(a).cmp(&rank(b)).then_with(|| a["code"].as_str().cmp(&b["code"].as_str())));
        Ok(Value::Array(films))
    }

    /// A file the darkroom can work with, or why not: the check of Studio.upload.
    pub fn check(&self, data: Vec<u8>) -> crate::Result<()> {
        let d = (self.open)(data)?;
        open_raw(d.data(), &self.fw, &d.info()).map(|_| ())
    }

    pub fn orientation(&self, d: &dyn Decoder) -> crate::Result<u32> {
        Ok(open_raw(d.data(), &self.fw, &d.info())?.orientation)
    }

    // ------------------------------------------------------------ cached stages

    fn decoder(&mut self, id: &str) -> Result<&mut Box<dyn Decoder>> {
        if self.decoder.as_ref().is_none_or(|(d, _)| d != id) {
            let data = self.take(format!("raw:{id}"))?;
            self.decoder = Some((id.to_string(), (self.open)(data)?));
        }
        Ok(&mut self.decoder.as_mut().unwrap().1)
    }

    fn source(&mut self, id: &str) -> Result<Rc<Source>> {
        if let Some(s) = self.sources.get(&id.to_string()) {
            return Ok(s);
        }
        self.decoder(id)?;
        let d = &self.decoder.as_ref().unwrap().1;
        let s = open_raw(d.data(), &self.fw, &d.info()).map_err(|e| format!("{}: {e}", id.split_once(':').map_or(id, |p| p.1)))?;
        let s = Rc::new(s);
        self.sources.put(id.to_string(), s.clone());
        Ok(s)
    }

    /// Raw decoded at 1/scale and cropped to the camera's frame.
    fn image(&mut self, id: &str, src: &Source, scale: usize) -> Result<Rc<Tagged<Image>>> {
        let key = (id.to_string(), scale);
        if let Some(i) = self.images.get(&key) {
            return Ok(i);
        }
        let half = scale > 1;
        let (rgb, w, h) = self.decoder(id)?.decode(half, src.black, src.white)?;
        let s = if half { 2 } else { 1 };
        let [x, y, cw, ch] = src.crop.map(|v| v / s);
        let (cw, ch) = (cw.min(w.saturating_sub(x)), ch.min(h.saturating_sub(y)));
        let mut out = Vec::with_capacity(cw * ch * 3);
        for row in y..y + ch {
            out.extend_from_slice(&rgb[(row * w + x) * 3..(row * w + x + cw) * 3]);
        }
        let mut img = Image { rgb: out, width: cw, height: ch };
        if scale == 4 {
            img = quarter(&img);
        }
        let tagged = self.tag(img);
        self.images.put(key, tagged.clone());
        Ok(tagged)
    }

    fn pack_tables(&mut self, code: &str) -> Result<Rc<Tagged<Tables>>> {
        if let Some(t) = self.tables.get(&code.to_string()) {
            return Ok(t);
        }
        let blob = self.take(format!("{code}/tables.bin"))?;
        let words = lite::tables(&blob)?;
        if words.len() < 0x9801 {
            return Err(format!("{code}/tables.bin is too short").into());
        }
        let curve = Rc::new(lite::output_curve(&words));
        self.packs.get_mut(code).unwrap().curve = Some(curve);
        let t = self.tag(Tables::new(&words));
        self.tables.put(code.to_string(), t.clone());
        Ok(t)
    }

    fn cube16(&mut self, code: &str, idx: usize) -> Result<Rc<Tagged<Vec<f32>>>> {
        let key = (code.to_string(), idx);
        if let Some(c) = self.cubes.get(&key) {
            return Ok(c);
        }
        let film = &self.packs[code].film;
        let grade_i = idx / (film.push.len() * film.light_mired.len());
        if self.paper.as_ref().is_none_or(|(c, g, _)| c != code || *g != grade_i) {
            let p = film.papers.get(grade_i).ok_or_else(|| format!("no cube at index {idx}"))?;
            let file = p.file.as_ref().ok_or_else(|| format!("no cube at index {idx}"))?;
            let (delta, k) = (p.delta, p.push_w[0].len() * p.light_w[0].len());
            let blob = self.take(format!("{code}/{file}"))?;
            self.paper = None;      // the old one goes before the new one is built
            self.paper = Some((code.to_string(), grade_i, lite::decode_basis(&blob, delta, k)?));
        }
        let pack = &self.packs[code];
        let c = lite::cube16(&pack.film, &self.paper.as_ref().unwrap().2, pack.curve.as_ref().unwrap(), idx)?;
        let c = self.tag(c);
        self.cubes.put(key, c.clone());
        Ok(c)
    }

    fn cube(&mut self, code: &str, i0: usize, i1: usize, w: f64) -> Result<Rc<Tagged<Vec<f32>>>> {
        let c0 = self.cube16(code, i0)?;
        if i1 == i0 || !(w > 0.0) {
            return Ok(c0);
        }
        let key = (code.to_string(), i0, i1, w.to_bits());
        if let Some((k, c)) = &self.blended {
            if *k == key {
                return Ok(c.clone());
            }
        }
        let c1 = self.cube16(code, i1)?;
        let c = self.tag(lite::blend(&c0.v, &c1.v, w));
        self.blended = Some((key, c.clone()));
        Ok(c)
    }

    fn curves(&mut self, code: &str) -> Result<Rc<Vec<u8>>> {
        if let Some(c) = &self.packs[code].curves {
            return Ok(c.clone());
        }
        let blob = self.take(format!("{code}/curves.bin"))?;
        let c = Rc::new(lite::inflate(&blob)?);
        self.packs.get_mut(code).unwrap().curves = Some(c.clone());
        Ok(c)
    }

    fn grain(&mut self, code: &str, paper: usize, push_i: usize, grade: usize) -> Result<Rc<Tagged<Grain>>> {
        let key = (code.to_string(), paper, push_i, grade);
        if let Some(g) = self.grains.get(&key) {
            return Ok(g);
        }
        let n_push = self.packs[code].film.push.len();
        if self.packs[code].grain.as_ref().is_none_or(|(p, _)| *p != paper) {
            let blob = self.take(format!("{code}/grain{paper}.bin"))?;
            let blocks = Rc::new(lite::decode_grain(&blob, n_push)?);
            self.packs.get_mut(code).unwrap().grain = Some((paper, blocks));
        }
        let blocks = self.packs[code].grain.as_ref().unwrap().1.clone();
        let g = Grain::new(&blocks[push_i * GRAIN_BLOCK..][..GRAIN_BLOCK], grade)?;
        let g = self.tag(g);
        self.grains.put(key, g.clone());
        Ok(g)
    }

    // ------------------------------------------------------------ render

    /// Everything up to develop().
    pub fn prepare(&mut self, p: &Query) -> Result<Job> {
        if !self.packs.contains_key(&p.film) {
            return Err(format!("unknown film {:?}", p.film).into());
        }
        let name = p.file.split_once(':').map(|n| n.1).filter(|n| !n.is_empty() && !n.contains('/'));
        let name = name.ok_or_else(|| format!("unknown file {:?}", p.file))?.to_string();
        let src = self.source(&p.file)?;
        let image = self.image(&p.file, &src, p.scale)?;
        let (height, width) = (image.v.height, image.v.width);
        let mired = p.kelvin.map_or(src.mired, |k| 1e6 / k);
        let sel = lite::select_cubes(&self.packs[&p.film].film, p.paper, p.push, p.grade, mired)?;
        let tables = self.pack_tables(&p.film)?;
        let cube = self.cube(&p.film, sel.i0, sel.i1, sel.weight)?;
        let curves = match sel.curves {
            Some(base) => Some((self.curves(&p.film)?, base)),
            None => None,
        };
        // The EV only scales the camera matrix, after the sensor clip.
        let scale = p.exposure.exp2();
        let matrix = src.matrix.map(|r| r.map(|v| v * scale));

        let mut halo = None;
        let profile = halation::profile(&self.fw, &p.film)?;
        if let (Some(profile), true) = (profile, p.halation >= 0) {
            let key = (p.file.clone(), p.scale, p.film.clone(), p.exposure.to_bits());
            let maps = match self.halos.get(&key) {
                Some(m) => m,
                None => {
                    let h = Halation::new(&self.fw, &profile, &matrix, src.clip)?;
                    let m = self.tag(h.build_map(&image.v.rgb, width, height));
                    self.halos.put(key, m.clone());
                    m
                }
            };
            halo = Some((maps, Rc::new(profile), HALO_LEVELS[p.halation as usize]));
        }

        let (mut grain, mut card_path) = (None, None);
        if p.grain {
            let push_i = self.packs[&p.film].film.push.iter().position(|v| *v == p.push).unwrap();
            let g = self.grain(&p.film, p.paper, push_i, p.grade)?;
            let card = if p.card_path.is_empty() {
                format!("A:/DCIM/{}/{}", src.card_dir, name.to_uppercase())
            } else {
                p.card_path.clone()
            };
            let seed = fnv1a_seed(&card);
            let streams = g.v.streams();
            let key = (seed, height, width, streams);
            let noise = match self.noise.get(&key) {
                Some(n) => n,
                None => {
                    let n = grain_noise(&self.fw, seed, height, width, streams)?;
                    let n = self.tag(n);
                    self.noise.put(key, n.clone());
                    n
                }
            };
            card_path = Some(card);
            grain = Some((g, noise));
        }

        let bw = sel.curves.is_some();
        let description = format!(
            "{} paper#{} push{:+}{} {:.0}K{}",
            p.film, p.paper, p.push,
            if bw { format!(" grade{}", p.grade) } else { String::new() },
            1e6 / mired,
            if p.exposure != 0.0 { format!(" {:+.1}EV", p.exposure) } else { String::new() },
        );
        let (out_w, out_h) = if matches!(src.orientation, 6 | 8) { (height, width) } else { (width, height) };
        let info = json!({
            "model": src.model, "wb": src.wb,
            "shot_kelvin": (1e6 / src.mired).round_ties_even(), "kelvin": (1e6 / mired).round_ties_even(),
            "mired": round(mired, 1), "exposure": p.exposure,
            "baseline_exposure": round(src.baseline_exposure, 2), "cubes": [sel.i0, sel.i1], "weight": round(sel.weight, 3),
            "bw_curves": bw,
            "grain": grain.as_ref().map(|(g, _)| format!("{}, {}",
                if g.v.mono { "mono" } else { "colour" }, if g.v.simple { "8-bit table" } else { "17³ lattice" })),
            "card_path": card_path,
            "halation": halo.as_ref().map(|h| h.2),
            "width": out_w, "height": out_h,
        });
        let stem = name.rsplit_once('.').map_or(name.as_str(), |n| n.0);
        let out8: Vec<u32> = match &curves {
            Some((b, base)) => b[*base..base + 0x3000].iter().map(|v| *v as u32).collect(),
            None => tables.v.out8.iter().cycle().take(0x3000).map(|v| *v as u32).collect(),
        };
        let gpu = GpuData {
            out8,
            out8_tag: format!("{}.{}", tables.tag, sel.curves.map_or(-1, |c| c as i64)),
            maps: halo.as_ref().map_or(vec![], |(m, _, _)| m.v.iter().map(|v| *v as f32).collect()),
        };
        Ok(Job {
            gpu,
            clip: src.clip,
            matrix,
            tables,
            curves,
            cube,
            gamut: p.gamut,
            halo,
            grain,
            orientation: src.orientation,
            tags: [
                (0x010E, description),
                (0x010F, src.make.clone()),
                (0x0110, src.model.clone()),
                (0x0131, "Latent pipeline reimplementation".to_string()),
            ],
            info,
            name: format!("{stem}_{}.jpg", p.film),
            quality: p.quality,
            image,
        })
    }
}

/// half_size, then a 2x2 mean truncated to u16, on an even-sized image.
fn quarter(img: &Image) -> Image {
    let (h, w) = (img.height / 2, img.width / 2);
    let mut rgb = Vec::with_capacity(h * w * 3);
    let px = |y: usize, x: usize, c: usize| img.rgb[(y * img.width + x) * 3 + c] as u32;
    for y in 0..h {
        for x in 0..w {
            for c in 0..3 {
                let s = px(2 * y, 2 * x, c) + px(2 * y, 2 * x + 1, c) + px(2 * y + 1, 2 * x, c) + px(2 * y + 1, 2 * x + 1, c);
                rgb.push((s / 4) as u16);
            }
        }
    }
    Image { rgb, width: w, height: h }
}
