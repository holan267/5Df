# Bản chạy trong trình duyệt (không cần Python)

Giao diện là app React trong `analysis/app/` (Vite, shadcn/ui), dùng chung với `latent_app.py`. Khác biệt duy nhất: toàn bộ việc tráng ảnh chạy ngay trong tab.

- **Pyodide** (Python 3.14 biên dịch sang WebAssembly, kèm numpy 2.4.6 và Pillow 12.2) chạy nguyên `analysis/tools/*.py` và `latent_app.Studio`. Không có bản code thứ hai nào cần giữ đồng bộ.
- **LibRaw‑Wasm** (LibRaw 0.22.1, cùng phiên bản rawpy 0.27 đóng gói) làm phần giải mã và demosaic raw, thay cho rawpy.

## Chạy

```sh
cd analysis/app
npm install
npm run dev            # phát triển, có sẵn COOP/COEP
npm run build          # ra dist/
npm run preview        # xem thử dist/, có sẵn COOP/COEP
```

`dist/` là site tĩnh, dùng đường dẫn tương đối nên chép vào đường dẫn con nào của server tĩnh cũng chạy. Điều kiện:

- Phải mở qua `http://localhost` / `127.0.0.1` hoặc `https`. LibRaw‑Wasm dùng `SharedArrayBuffer`, nên trang cần cross-origin isolation. `public/coi-sw.js` (service worker) tự thêm header COOP/COEP, rồi trang tự reload một lần. Dev server và `vite preview` thì gửi sẵn các header này.
- Lần đầu trang tải khoảng 20 MB Pyodide + numpy + Pillow từ jsDelivr, nên cần có mạng. Từ lần sau trình duyệt dùng cache.
- Đã thử trên Chromium. Các trình duyệt khác có module worker, `SharedArrayBuffer` và service worker (Edge, Firefox, Safari 16.4+) lẽ ra cũng chạy được, nhưng chưa thử.

`public/LATENT_LITE/` được build kèm, nên trang mở thẳng vào lite pack (xem mục sau). Nếu không có thư mục đó, chọn **thư mục kit**: thư mục `kit/` của bộ Ritual tải về, gốc thẻ nhớ (`AUTOEXEC.BIN` + `LATENT/`), hoặc một thư mục `LATENT_LITE`. Thư mục có cả `.LTP` lẫn `AUTOEXEC.BIN` thì dùng `.LTP`.

- Các file được đọc tại chỗ qua WORKERFS: Python chỉ đọc đúng đoạn cần (index pack, cube, khối grain). Vì vậy bộ 3,4 GB mở xong trong vài giây và không tốn RAM.
- Không có gì bị upload.
- Chrome/Edge nhớ thư mục đã chọn (File System Access API); trình duyệt khác phải chọn lại mỗi lần.
- Raw nằm trong thư mục kit được liệt kê luôn. Raw kéo thả vào trang chỉ nằm trong bộ nhớ của tab và mất khi reload.
- Mô tả film (`latent_traits.py`) được đo trong một worker thứ hai: khoảng 1–2 phút cho 20 film ở lần đầu. Kết quả lưu trong IndexedDB và chỉ đo lại khi pack hoặc `latent_traits.py` thay đổi.

Khi trang được `latent_app.py` phục vụ (`uv run analysis/app/latent_app.py`, cần `npm run build` trước), nó dùng API HTTP như trước; phần WebAssembly không được nạp. Trang nhận ra mình đang chạy kiểu nào bằng cách gọi thử `api/films`. Vì vậy trên server tĩnh, DevTools hiện một lỗi 404 cho `api/films` (502 với `npm run dev`, vì `/api` được proxy tới `latent_app.py` ở cổng 8765); lỗi này là bình thường. Tương tự, không có lite pack thì có 404 cho `LATENT_LITE/index.json`.

## Lite pack qua HTTP

`public/LATENT_LITE/` nằm cạnh trang, trong `dist/` là `LATENT_LITE/`. Trang gọi `LATENT_LITE/index.json`; có file đó thì không cần chọn thư mục kit. Đưa thêm raw vào bằng cách kéo thả, hoặc chọn một thư mục raw qua nút **Kit…**. `latent_lite_build.py` mặc định ghi vào `public/LATENT_LITE/`.

- Lúc khởi động trang chỉ tải `firmware.bin` và 20 `film.json`, tổng khoảng 460 KB. Từng `paper<i>.bin`, `grain<i>.bin`, `tables.bin`, `curves.bin` chỉ được tải khi một lần render cần đến: Python báo thiếu file, worker tải về rồi gọi lại (`withLite` trong `worker.js`).
- Một paper tải 0,4–8 MB. Thanh trạng thái hiện `downloading …` với file trên 1 MB. Cả bộ 533 MB chỉ tải hết nếu dùng hết mọi paper.
- File đã tải nằm trong Cache Storage, nên lần sau không tải lại. URL có `?v=<crc>`, nên khi build lại, file cũ tự bị bỏ. Cache không mở được thì trang vẫn chạy, chỉ là tải lại mỗi lần.
- Mọi file đều được so với CRC trong `index.json` trước khi dùng hoặc lưu cache. Host tĩnh và dev server thường trả `index.html` kèm mã 200 cho đường dẫn không có; khi đó trang báo file nào hỏng, thay vì `Error -3 ... incorrect header check` từ zlib. File hỏng đã nằm trong cache từ trước sẽ tự bị xóa và tải lại.
- Để lấy pack từ host khác: `?lite=https://host/duong-dan/`. Host đó phải gửi `Access-Control-Allow-Origin` cho trang.
- Trong Windows, profile Chrome nằm quá sâu có thể làm Cache Storage hỏng do giới hạn độ dài đường dẫn. Khi đó trang rơi vào trường hợp không có cache nói trên.

## Các file

| File | Vai trò |
|---|---|
| `worker.js` | Web Worker: nạp Pyodide, LibRaw‑Wasm và các file `.py` theo đúng cấu trúc `analysis/`, mount kit, nhận lệnh từ trang theo hàng đợi. Render và upload được ưu tiên hơn thumbnail; preview đã bị lượt mới thay thế thì bỏ qua. Vite gói nguồn Python vào worker qua import `?raw`. |
| `latent_web.py` | Lớp mỏng bọc `latent_app.Studio`: `start`, `files`, `thumb`, `upload`, `render`, `traits`. |
| `rawpy.py` | Module `rawpy` thay thế, chỉ cài đúng phần API mà `latent_develop.py` / `latent_app.py` dùng, chạy trên LibRaw‑Wasm (gọi đồng bộ trong worker). |
| `../src/` | App React: `lib/` (backend, kit), `hooks/` (trạng thái, render), `components/` (shadcn/ui trong `components/ui/`). |
| `../public/coi-sw.js` | Service worker thêm COOP/COEP cho host tĩnh. |
| `../public/vendor/libraw-wasm/` | `libraw.js` + `libraw.wasm` từ npm `libraw-wasm@1.6.0`, giữ nguyên; xem `NOTICE.md`. Không để Vite bundle: pthread của nó khởi động `Worker` trên chính `libraw.js`. |

## Độ chính xác so với bản Python

Đo trên `IMG_1428.CR2` (Canon EOS 5D, raw.pixls.us) và một file Sony A7 III `.ARW`, với kit Ritual 1.0:

| Bước | Kết quả |
|---|---|
| Demosaic ½ cỡ (preview ¼ và ½) | Trùng từng giá trị với rawpy, cả CR2 lẫn ARW |
| Demosaic cỡ đầy đủ (AHD) | 0,004% giá trị khác (khoảng 500 pixel lẻ tẻ), do LibRaw‑Wasm được biên dịch với `-ffast-math` |
| Ảnh đã tráng, trước JPEG (P400, V050, HP5P B&W, ARW) | 2 đến 1.990 giá trị lệch ±1 trên 2,4–9,5 triệu (làm tròn float32) |
| File JPEG | Khác byte. Pillow trong Pyodide dùng libjpeg 9 (IJG), không phải libjpeg-turbo, nên giảm mẫu kênh màu khác: trung bình lệch khoảng 2 mức trên các pixel khác nhau, tối đa khoảng 25 ở vùng grain dày |

Wrapper của LibRaw‑Wasm không xuất `cblack` và `linear_max`, và `black` chung của nó bằng 0 với file Canon. `rawpy.py` đọc lại các giá trị này theo đúng cách LibRaw làm: với Sony, giải mã khối SR2 (tag `0x7310` và `0x787f`); với Canon, lấy `ChannelBlackLevel` và `SpecularWhiteLevel`. Các hãng khác dùng black chung và `white_level`, nên có thể lệch rawpy nếu máy đó có level riêng theo kênh.

## Tốc độ (Chrome, cùng máy)

| | Trình duyệt | Python native |
|---|---|---|
| Preview ¼ đầu tiên của một file (giải mã raw + giải nén cube) | 10–24 s | khoảng 7–9 s |
| Preview ¼ khi đã cache (đổi phơi sáng, grain…) | 2–4 s | khoảng 1 s |
| Export cỡ đầy đủ P400 (4368×2912) | khoảng 90 s | chưa đo được trên máy thử (hết bộ nhớ commit) |

Với lite pack (Chrome headless, `IMG_0002.CR2`, raw đã giải mã sẵn): preview ¼ 2,4–7 s tùy film, gồm cả giải mã paper; export cỡ đầy đủ EK10 và G200 khoảng 65 s. Ảnh web so với `Studio` native trên cùng lite pack (JPEG chất lượng 100): lệch trung bình 0,14–0,71 mức, tối đa 20 mức ở film màu, 4 mức ở B&W, tức cùng mức với khác biệt JPEG ở trên (kit `.LTP`: 0,6 và 18).

## Cập nhật

- Pyodide: đổi phiên bản trong URL ở đầu `worker.js`.
- LibRaw‑Wasm: xem `../public/vendor/libraw-wasm/NOTICE.md`.

Sau khi đổi một trong hai, nên kiểm tra lại bảng độ chính xác ở trên.

## Khi đưa lên mạng

Chỉ publish `dist/`. Không publish gốc repo: ở đó có `AUTOEXEC.BIN` chứa khóa, cùng `analysis/derived/` và `analysis/ghidra_*`.

**`dist/` chứa `LATENT_LITE/`** (khoảng 510 MB, xem `analysis/README.md`, mục 6.4). Đây là dữ liệu của Latent Studios đã giải mã, và `firmware.bin` tuy không có khóa nhưng vẫn là bảng trích từ firmware của họ. Upload `dist/` lên host công khai nghĩa là phát hành lại toàn bộ dữ liệu đó, nên chỉ làm khi có quyền phân phối. Muốn bản không kèm dữ liệu thì build khi không có `public/LATENT_LITE/`: trang sẽ hiện ô chọn thư mục, và kit của người dùng không rời khỏi máy họ.

`LATENT_LITE/` nằm trong `.gitignore`, nên CI build từ repo sẽ không có nó; bản kèm pack phải build và upload từ máy có thư mục này.
