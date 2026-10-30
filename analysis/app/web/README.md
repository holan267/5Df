# Bản chạy trong trình duyệt (không cần Python)

Giao diện `../index.html` giống hệt bản `latent_app.py`. Khác biệt duy nhất: toàn bộ việc tráng ảnh chạy ngay trong tab.

- **Pyodide** (Python 3.14 biên dịch sang WebAssembly, kèm numpy 2.4.6 và Pillow 12.2) chạy nguyên `analysis/tools/*.py` và `latent_app.Studio`. Không có bản code thứ hai nào cần giữ đồng bộ.
- **LibRaw‑Wasm** (LibRaw 0.22.1, cùng phiên bản rawpy 0.27 đóng gói) làm phần giải mã và demosaic raw, thay cho rawpy.

## Chạy

```sh
node analysis/app/web/serve.mjs        # rồi mở http://127.0.0.1:8765/app/
```

Server tĩnh nào cũng được, miễn nó phục vụ thư mục `analysis/` (trang cần `app/` và `tools/`). Ví dụ VS Code Live Server, hoặc `npx http-server analysis`, rồi mở `/app/`. Điều kiện:

- Phải mở qua `http://localhost` / `127.0.0.1` hoặc `https`. LibRaw‑Wasm dùng `SharedArrayBuffer`, nên trang cần cross-origin isolation. `../coi-sw.js` (service worker) tự thêm header COOP/COEP, rồi trang tự reload một lần. `serve.mjs` thì gửi sẵn các header này.
- Lần đầu trang tải khoảng 20 MB Pyodide + numpy + Pillow từ jsDelivr, nên cần có mạng. Từ lần sau trình duyệt dùng cache.
- Đã thử trên Chrome. Các trình duyệt khác có module worker, `SharedArrayBuffer` và service worker (Edge, Firefox, Safari 16.4+) lẽ ra cũng chạy được, nhưng chưa thử.

Khi trang mở ra, chọn **thư mục kit**: thư mục `kit/` của bộ Ritual tải về, hoặc gốc thẻ nhớ (`AUTOEXEC.BIN` + `LATENT/`).

- Các file được đọc tại chỗ qua WORKERFS: Python chỉ đọc đúng đoạn cần (index pack, cube, khối grain). Vì vậy bộ 3,4 GB mở xong trong vài giây và không tốn RAM.
- Không có gì bị upload.
- Chrome/Edge nhớ thư mục đã chọn (File System Access API); trình duyệt khác phải chọn lại mỗi lần.
- Raw nằm trong thư mục kit được liệt kê luôn. Raw kéo thả vào trang chỉ nằm trong bộ nhớ của tab và mất khi reload.
- Mô tả film (`latent_traits.py`) được đo trong một worker thứ hai: khoảng 1–2 phút cho 20 film ở lần đầu. Kết quả lưu trong IndexedDB và chỉ đo lại khi pack hoặc `latent_traits.py` thay đổi.

Khi trang được `latent_app.py` phục vụ (`uv run analysis/app/latent_app.py`), nó dùng API HTTP như trước; phần WebAssembly không được nạp. Trang nhận ra mình đang chạy kiểu nào bằng cách gọi thử `api/films`. Vì vậy trên server tĩnh, DevTools hiện một lỗi 404 cho `/app/api/films`; lỗi này là bình thường.

## Các file

| File | Vai trò |
|---|---|
| `worker.js` | Web Worker: nạp Pyodide, LibRaw‑Wasm và các file `.py` theo đúng cấu trúc `analysis/`, mount kit, nhận lệnh từ trang theo hàng đợi. Render và upload được ưu tiên hơn thumbnail; preview đã bị lượt mới thay thế thì bỏ qua. |
| `latent_web.py` | Lớp mỏng bọc `latent_app.Studio`: `start`, `files`, `thumb`, `upload`, `render`, `traits`. |
| `rawpy.py` | Module `rawpy` thay thế, chỉ cài đúng phần API mà `latent_develop.py` / `latent_app.py` dùng, chạy trên LibRaw‑Wasm (gọi đồng bộ trong worker). |
| `../coi-sw.js` | Service worker thêm COOP/COEP cho host tĩnh. |
| `serve.mjs` | Server tĩnh không cần thư viện ngoài, chỉ nghe localhost, có sẵn COOP/COEP. |
| `vendor/libraw-wasm/` | `libraw.js` + `libraw.wasm` từ npm `libraw-wasm@1.6.0`, giữ nguyên; xem `NOTICE.md`. |

## Độ chính xác so với bản Python

Đo trên `IMG_1428.CR2` (Canon EOS 5D, raw.pixls.us) và một file Sony A7 III `.ARW`, với kit Ritual 1.0:

| Bước | Kết quả |
|---|---|
| Demosaic ½ cỡ (preview ¼ và ½) | Trùng từng giá trị với rawpy, cả CR2 lẫn ARW |
| Demosaic cỡ đầy đủ (AHD) | 0,004% giá trị khác (khoảng 500 pixel lẻ tẻ), do LibRaw‑Wasm được biên dịch với `-ffast-math` |
| Ảnh đã tráng, trước JPEG (P400, V050, HP5P B&W, ARW) | 2 đến 1.990 giá trị lệch ±1 trên 2,4–9,5 triệu (làm tròn float32) |
| File JPEG | Khác byte. Pillow trong Pyodide dùng libjpeg 9 (IJG), không phải libjpeg-turbo, nên giảm mẫu kênh màu khác: trung bình lệch khoảng 2 mức trên các pixel khác nhau, tối đa khoảng 25 ở vùng grain dày |

Wrapper của LibRaw‑Wasm không xuất `cblack` và `linear_max`. `rawpy.py` đọc lại hai giá trị này theo đúng cách LibRaw làm: với Sony, giải mã khối SR2 (tag `0x7310` và `0x787f`); với Canon, lấy `SpecularWhiteLevel`. Các hãng khác dùng black chung và `white_level`, nên có thể lệch rawpy nếu máy đó có level riêng theo kênh.

## Tốc độ (Chrome, cùng máy)

| | Trình duyệt | Python native |
|---|---|---|
| Preview ¼ đầu tiên của một file (giải mã raw + giải nén cube) | 10–24 s | khoảng 7–9 s |
| Preview ¼ khi đã cache (đổi phơi sáng, grain…) | 2–4 s | khoảng 1 s |
| Export cỡ đầy đủ P400 (4368×2912) | khoảng 90 s | chưa đo được trên máy thử (hết bộ nhớ commit) |

## Cập nhật

- Pyodide: đổi phiên bản trong URL ở đầu `worker.js`.
- LibRaw‑Wasm: xem `vendor/libraw-wasm/NOTICE.md`.

Sau khi đổi một trong hai, nên kiểm tra lại bảng độ chính xác ở trên.

## Khi đưa lên mạng

Trang không chứa file nào của Latent Studios: kit do người dùng tự chọn và không rời khỏi máy họ. Nếu publish, chỉ đưa `analysis/app/` và `analysis/tools/`. Không publish gốc repo: ở đó có `AUTOEXEC.BIN` chứa khóa, cùng `analysis/derived/` và `analysis/ghidra_*`.
