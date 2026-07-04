# Tìm hiểu về Công nghệ LoRa (Long Range)

Tài liệu này cung cấp cái nhìn tổng quan, chi tiết và dễ hiểu về khái niệm, nguyên lý hoạt động cũng như các tính chất đặc trưng của công nghệ truyền thông không dây LoRa.

---

## 1. Khái niệm LoRa là gì?

**LoRa** (viết tắt của **Long Range**) là một công nghệ truyền thông không dây tầm xa, được phát triển bởi công ty Semtech. 

Nó thuộc nhóm công nghệ **LPWAN** (Low Power Wide Area Network - Mạng diện rộng tiêu thụ năng lượng thấp). LoRa được thiết kế để phục vụ dự án cần gửi gói dữ liệu nhỏ, và hoạt động trong thời gian dài( tiết kiệm pin).

---

## 2. Nguyên lý hoạt động của LoRa

Bí mật làm nên khả năng truyền xa vượt trội của LoRa nằm ở phương thức mã hóa tín hiệu bằng kỹ thuật **Chirp Spread Spectrum (CSS)** (Phổ trải rộng Chirp).

* **Tín hiệu "Chirp" là gì?** Thay vì truyền tín hiệu trên một tần số cố định giống như sóng vô tuyến thông thường, LoRa gửi dữ liệu bằng cách thay đổi tần số liên tục theo thời gian dưới dạng các xung chirp tăng dần hoặc giảm dần.
* **Khả năng vượt qua nhiễu:** Nhờ cách trải rộng tín hiệu này, LoRa đạt được độ nhạy thu cực kỳ cao. Ngay cả khi tín hiệu truyền đi bị suy hao mạnh, bị che khuất bởi vật cản, hoặc bị "chìm" hoàn toàn dưới ngưỡng nhiễu của môi trường, chip thu LoRa vẫn có thể lọc, giải mã và đọc chính xác dữ liệu.
* **Cơ chế Transceiver (Bán song công):** Các chip LoRa thông thường (như SX1278) là bộ thu phát bán song công (Half-duplex). Tại một thời điểm, chip chỉ có thể chọn một trong hai trạng thái: hoặc là **Phát (Tx)** dữ liệu ra không gian, hoặc là **Nhận (Rx)** dữ liệu từ thiết bị khác truyền tới.

---

## 3. Các tính chất đặc trưng của LoRa

Triết lý thiết kế lõi của LoRa dựa trên mô hình đánh đổi kinh điển trong viễn thông: **Đổi tốc độ lấy khoảng cách**. Công nghệ này mang 3 tính chất cốt lõi sau:

### 📡 Tầm truyền cực xa (Long Range)
* **Trong môi trường đô thị:** Do bị ảnh hưởng bởi nhiều nhà tầng và vật cản che khuất, tầm truyền đạt từ **2km – 5km**.
* **Trong môi trường lý tưởng:** Ở các vùng đồng trống, tầm nhìn thẳng không vật cản, khoảng cách có thể đạt tới **15km** hoặc xa hơn nữa.

### 🔋 Tiêu thụ năng lượng cực thấp (Low Power)
* Khi ở chế độ ngủ (Sleep Mode), module tiêu thụ dòng điện cực kỳ nhỏ, chỉ vài micro-ampe.
* Khi phát tín hiệu, dòng điện sẽ tăng cao hơn nhưng thời gian truyền diễn ra rất nhanh. Nhờ đặc tính này, các thiết bị cảm biến LoRa có thể hoạt động bền bỉ từ **3 đến 5 năm** chỉ với một viên pin AA.

### 📉 Tốc độ truyền dữ liệu thấp (Low Data Rate)
* Đây là điểm đánh đổi lớn nhất: LoRa không dùng để lướt web, xem video hay truyền âm thanh. Tốc độ truyền rất chậm, dao động từ vài trăm bps đến vài chục kbps.
* Định dạng truyền tối ưu nhất là các chuỗi văn bản hoặc số liệu ngắn (Ví dụ: `Temp: 30C, Humid: 70%`).

---

## 4. Các thông số cấu hình cốt lõi

Để tối ưu hóa khoảng cách truyền và khả năng kháng nhiễu, hệ thống LoRa cho phép can thiệp vào 3 thông số cấu hình chính:

| Thông số | Tên đầy đủ | Ý nghĩa cấu hình |
| :--- | :--- | :--- |
| **SF** | Spreading Factor (Hệ số trải phổ) | Thường cấu hình từ 7 đến 12. **SF càng cao** thì chip truyền dữ liệu càng chậm nhưng sóng đi càng xa, xuyên vật cản tốt hơn và tốn pin hơn. |
| **BW** | Bandwidth (Băng thông) | Độ rộng của dải tần số sử dụng, phổ biến ở các mức **125kHz, 250kHz hoặc 500kHz**. |
| **CR** | Coding Rate (Tỷ lệ mã hóa) | Tỷ lệ chèn thêm các bit sửa lỗi vào gói tin để giúp đầu thu khôi phục dữ liệu nguyên vẹn khi gặp nhiễu trên đường truyền. |

---
