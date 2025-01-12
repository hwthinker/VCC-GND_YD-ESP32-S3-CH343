

# Tutorial ESP32 DevkitC-1  Model YD-ESP32-S3

![image-20250113044653767](./assets/image-20250113044653767.png)


## Install Board

1. Masuk ke preferences

![](./assets/02.png)

2. Klik Additional Board Manager

![](./assets/03.png)

3. Tambahkan board esp32 kalimat berikut https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

![](./assets/04.png)

4. Pilih Tools -> Board -> Board Manager

![image-20241216161508649](./assets/image-20241216161508649.png)

5. Search ESP32 kemudian klik install

![](./assets/06.png)

6. Pilih Tools -> Board -> ESP32 -> ESP32S3 dev Module

![image-20241216161659535](./assets/image-20241216161659535.png)

7. Untuk Arduino 2.0 bisa juga Klik board pada Tool Bar

![image-20241216051131337](./assets/image-20241216051131337.png)

8. kemudian pilih ESP32S3 Dev Module

![image-20241216051242738](./assets/image-20241216051242738.png)

8. Langkah berikutnya adalah memastikan Arduino mengetahui Kapasitas Flash yang tersedia. ini dilakukan dengan cara mengatur konfigurasi "Flash Size". Sesuaikan Flash dan  PSRAM(jika ada) anda menggunakan konfigurasi seperti pada gambar berikut

![image-20250112100623904](./assets/image-20250112100623904.png)

9. Setting port serial , untuk windows bisa cek device manager, pastikan anda telah install driver serial usb anda, bila tidak dikenali di windows install driver serial tersebut melalui link https://www.wch-ic.com/search?q=CH343&t=downloads

![image-20241216053210299](./assets/image-20241216053210299.png)



## Contoh Kode Program

### Test WS2812 menggunakan library FASTLED

LED WS2812 adalah jenis LED RGB dengan pengontrol bawaan yang memungkinkan setiap LED dikendalikan secara individual menggunakan satu pin data. Untuk mempermudah pengendalian LED ini, kita dapat menggunakan library **FASTLED** yang menyediakan fungsi-fungsi intuitif untuk membuat efek cahaya yang menarik. Panduan berikut akan membantu Anda menginstal library FASTLED di Arduino IDE dan menguji contoh kode sederhana untuk mengontrol LED WS2812.

#### Langkah-langkah Instalasi Library FASTLED

Pastikan library **FASTLED** telah terinstal di Arduino IDE Anda. Jika belum, ikuti langkah-langkah berikut:

1. Klik ikon **Library Manager** di panel **sidebar** Arduino IDE.
2. Ketik **FastLED** di kolom pencarian.
3. Temukan library **FastLED by Daniel Garcia**.
4. Klik tombol **Install** untuk menginstalnya.



![image-20250111140442247](./assets/image-20250111140442247.png)

#### Menggunakan Contoh Kode

Setelah library terinstal, buat file baru atau buka contoh program di **File -> Examples -> Basics -> BareMinimum**.  kemudain yang harus anda lakukan adalah:

1. Gantikan kode yang ada dengan kode berikut:

```c++
#include "FastLED.h"

#define NUM_LEDS 1       // Jumlah LED yang digunakan
#define DATA_PIN 48      // Pin Data untuk kontrol LED (dapat diganti sesuai kebutuhan: 38, 16, 8, dll)
#define LED_TYPE WS2812  // Tipe LED yang digunakan (WS2812/Neopixel)
#define COLOR_ORDER GRB  // Urutan warna pada LED (Green-Red-Blue)

// Variabel untuk mengontrol kecerahan LED (range: 0-255)
// Semakin besar nilai, semakin terang LED
uint8_t max_bright = 128;  

// Membuat array untuk menyimpan data LED
CRGB leds[NUM_LEDS];     

// Variabel untuk menghitung urutan LED yang menyala
char i = 0;              

void setup() {
    // Inisialisasi LED strip dengan konfigurasi yang telah ditentukan
    LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    
    // Mengatur tingkat kecerahan LED
    FastLED.setBrightness(max_bright);
}

void loop() {
    // Reset counter jika sudah mencapai LED terakhir
    if (i == NUM_LEDS) {
        i = 0;
    }
    
    // Menyalakan LED dengan warna merah
    leds[i] = CRGB::Red;
    
    // Memperbarui tampilan LED
    FastLED.show();
    
    // Jeda 50 milidetik
    delay(50);
    
    // Mematikan LED (warna hitam = LED mati)
    leds[i] = CRGB::Black;
    
    // Memperbarui tampilan LED
    FastLED.show();
    
    // Jeda 50 milidetik
    delay(50);
    
    // Pindah ke LED berikutnya
    i++;
}
```



## Upload program

Bila tampilan seperti ini maka anda harus mengkonfigurasi ESP32 anda agar bisa melakukan download

```
- ---esptool.py v3.0-dev
- ---Serial port COM…
- ---Connecting........_____....._____.....__
```

Langkah yang harus dilakukan

- Tekan dan tahan tombol Boot/0  
- Klik(tekan dan lepas) tombol reset/EN sambil tetap tekan tombol Boot .
- Lepas tombol boot
- Klik tombol upload pada Arduino IDE, bila sukses akan menampilkan info

```cpp
- ---Compressed 261792 bytes to 122378...
- ---Writing at 0x00010000... (12 %)
- ---Writing at 0x00014000... (25 %)
- ---Writing at 0x00018000... (37 %)
```

- Setelah selesai Wajib klik tombol **reset** sekali lagi untuk berpindah dari mode download menjadi mode run

> [!NOTE]  
> INGAT YA WAJIB Di Klik Tombol RESET setelah proses upload selesai, tanpa itu program yang baru diupload tidak akan dijalankan



## Menggunakan library Adafruit

Library **Adafruit NeoPixel** adalah pilihan lain yang populer untuk mengontrol LED WS2812 dan jenis LED serupa. Library ini menyediakan fungsi yang mudah digunakan untuk mengontrol warna dan efek pencahayaan pada strip atau matriks LED. Berikut adalah panduan singkat untuk menginstal library ini dan contoh kode sederhana untuk mengontrol LED WS2812.

#### Langkah-langkah Instalasi Library Adafruit NeoPixel

1. Buka Arduino IDE, lalu klik ikon **Library Manager** di panel **sidebar**.
2. Ketik **Adafruit NeoPixel** di kolom pencarian.
3. Temukan library **Adafruit NeoPixel by Adafruit**.
4. Klik tombol **Install** untuk memasangnya, lebih jelas lihat gambar berikut

![image-20250111143415429](./assets/image-20250111143415429.png)

#### Contoh Kode Mengontrol WS2812

Gunakan kode berikut untuk mengontrol satu LED WS2812 yang menyala berwarna merah selama 1 detik:

```c++
#include <Adafruit_NeoPixel.h>

#define PIN        48 
#define NUMPIXELS  1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  pixels.setPixelColor(0, pixels.Color(255,0,0)); 
  pixels.show();
  delay(1000);
  pixels.setPixelColor(0, pixels.Color(0,0,0)); 
  pixels.show();
  delay(1000);
}
```

5. Bila sudah selesai upload program dan kemudian lihat hasilnya

6. Bila berhasil LED RGB WS2812 akan LED akan berkedip  dengan nyala warna merah saat ON

**Catatan:**

- Ganti warna LED dengan nilai RGB yang diinginkan menggunakan `pixels.Color(red, green, blue)`.



## Akses Serial Port di ESP32

Board **ESP32-S3 ** ini mendukung upload dan komunikasi data serial ke komputer dengan dua Mode:

- Mode  USB Serial konverter ch343
- Mode Native USB

Pengaturan ini konfigurasi ini ada dua hal yaitu pengaturan Hardware dan pengaturan Software.  untuk pengaturan hardware bisa dilihat pada gambar dibawah ini:

### Mode USB Serial konverter (default manufaktur)

![1](./assets/1.png)

Pada mode ini Komunikasi Serial ditangani oleh chip usb serial CH343. Pastikan posisi switch dipindah ke serial usb. Untuk memerika apakah mode sudah mode Serial USB, dilinux bisa dicek dengan menggunakan perintah *lsusb*. bila dijalankan hasilnya akan seperti ini:

![image-20241217044355726](./assets/image-20241217044355726.png)

Pastikan juga data serial  di arahkan ke Serial USB CH343 ini dan bukannya ke native USB, ini dilakukan dengan cara mendisable  opsi "USB CDC on boot". Langkah mendisable USB CDC on boot ini bisa di cek pada gambar dibawah ini

![image-20250112093506124](./assets/image-20250112093506124.png)

- Jalankan kode sederhana ini

```c++
void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
}

void loop() {
  Serial.println("hello world");
  delay(500);
}

```

- Klik **Verify** untuk memeriksa kode. 
- Klik **Upload** untuk mengunggah kode ke ESP32-S3.
- Bila sudah selesai Silahkan buka Tools -> Serial Monitor
- Atur baud rate di pojok kanan bawah menjadi **9600** (sesuai dengan `Serial.begin(9600)` di kode).
- Anda akan melihat teks **"hello world"** muncul setiap 500ms.

![image-20250112092642208](./assets/image-20250112092642208.png)

### Mode Native USB untuk Upload dan komunikasi data

![2](./assets/2.png)

Pada mode ini Komunikasi Serial ditangani oleh native USB yang merupakan fitur yang ada di ESP32-S3. untuk mengaktikan mode ini  Pastikan posisi switch dipindah ke native USB. Untuk memerika apakah mode sudah native USB dilinux bisa dicek dengan menggunakan perintah *lsusb*. bila dijalankan hasilnya akan seperti ini:

![image-20241217044046574](./assets/image-20241217044046574.png)

Untuk pengaturan konfigurasi software pastikan data serial  di arahkan Native USB  dengan cara  konfigurasi  USB CDC on Boot  enablekan.  Pengaturan ini memastikan board dapat menggunakan port USB internal untuk komunikasi serial.

![image-20250112095747228](./assets/image-20250112095747228.png)

- Jalankan kode sederhana ini

```c++
void setup() {
  // initialize both serial ports:
  Serial.begin(9600);
}

void loop() {
  Serial.println("hello world");
  delay(500);
}

```

- Klik **Verify** untuk memeriksa kode. 
- Klik **Upload** untuk mengunggah kode ke ESP32-S3.
- Bila sudah selesai Silahkan buka Tools -> Serial Monitor
- Atur baud rate di pojok kanan bawah menjadi **9600** (sesuai dengan `Serial.begin(9600)` di kode).
- Anda akan melihat teks **"hello world"** muncul setiap 500ms.

![image-20250112092642208](./assets/image-20250112092642208.png)



## Diskripsi PIN GPIO
![img](./assets/img11.jpg)



## Pemecahan Masalah

### A. Port Com  tidak dapat dikenali di Arduino

Masuk ke mode unduh: 
- Tekan dan tahan tombol Boot/0  
- Klik(tekan dan lepas) tombol reset/EN sambil tetap tekan tombol Boot .
- Lepas tombol boot
- Setelah selesai Wajib klik tombol **reset** sekali lagi untuk berpindah dari mode download menjadi mode run

### B. Program tidak dapat berjalan setelah diunggah

Setelah upload berhasil, Anda perlu menekan tombol Reset sebelum dapat dijalankan.

### C. Port serial di Arduino tidak dapat mencetak

Anda perlu mengatur USB CDC On Boot di toolbar untuk diaktifkan.

### D. LED RGB tidak mau nyala walapun saya sudah upload program sesuai petunjuk
Setelah upload Coba anda tekan tombol Reset, bila masih tidak bisa kemungkinan Jumper LED belum tersolder. Solder jumper sesuai gambar berikut

![img](./assets/821a53fb08920e2cc12a883fb6aeb8f8396ac226.jpeg)



### E. Cara setting flash untuk board dengan ukuran flash N8R2, N8R8 dan N16R8 bagaimana ya?

Cara pengaturan bisa cek gambar dibawah ini, pilih Tool-> Flash Size dan sesuaikan dengan  ukuran Flash memori anda.

![ESP32-S3 DevkitC-1](./assets/ESP32-S3%20DevkitC-1.png)



