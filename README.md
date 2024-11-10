## Test WS2812 menggunakan library FASTLED

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

## Menggunakan library Adafruit

```c++
#include <Adafruit_NeoPixel.h>

#define PIN        48 // aternatif lainnya  38 16 8
#define NUMPIXELS  1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  pixels.setPixelColor(0, pixels.Color(255,0,0)); 
  pixels.show();
  delay(1000);
}
```



## Blinky dengan Adafruit  neopixel

```c++
#include <Adafruit_NeoPixel.h>

// Parameter konfigurasi LED
#define PIN        48      // Pin Data untuk kontrol LED
#define NUMPIXELS  1       // Jumlah LED yang digunakan
#define BRIGHTNESS 128     // Kecerahan LED (0-255)

// Inisialisasi objek NeoPixel
// Parameter: jumlah LED, pin data, tipe LED (NEO_GRB + NEO_KHZ800 untuk WS2812)
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Variabel untuk menghitung urutan LED yang menyala
int i = 0;

void setup() {
    // Inisialisasi LED strip
    pixels.begin();
    
    // Mengatur kecerahan global
    pixels.setBrightness(BRIGHTNESS);
    
    // Membersihkan semua LED (mematikan semua)
    pixels.clear();
    pixels.show();
}

void loop() {
    // Reset counter jika sudah mencapai LED terakhir
    if (i == NUMPIXELS) {
        i = 0;
    }
    
    // Menyalakan LED dengan warna merah
    // Parameter setPixelColor: nomor LED, Red, Green, Blue
    pixels.setPixelColor(i, pixels.Color(0, 255, 0));  // Warna merah (255,0,0)
    pixels.show();   // Menampilkan perubahan
    
    delay(50);      // Jeda 50 milidetik
    
    // Mematikan LED (warna hitam = LED mati)
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));    // LED mati (0,0,0)
    pixels.show();   // Menampilkan perubahan
    
    delay(50);      // Jeda 50 milidetik
    
    i++;            // Pindah ke LED berikutnya
}
```



## Uji GPIO yang terhubung ke WS2812

```C++
#include <Adafruit_NeoPixel.h>

// Daftar GPIO yang ingin diuji
int gpioList[] = {48, 38, 16, 8, 2, 4, 5, 12, 13, 14, 15, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33, 34, 35, 36, 37};
// Jumlah GPIO dalam daftar
int gpioCount = sizeof(gpioList) / sizeof(gpioList[0]);

#define NUMPIXELS 1
Adafruit_NeoPixel pixels(NUMPIXELS, 0, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  pixels.begin();
}

void loop() {
  for (int i = 0; i < gpioCount; i++) {
    int currentPin = gpioList[i];
    pixels.setPin(currentPin);  // Set GPIO yang akan diuji
    pixels.begin();              // Inisialisasi ulang untuk memastikan perubahan PIN
    
    Serial.print("Testing GPIO: ");
    Serial.println(currentPin);

    // Set warna merah untuk menguji
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.show();
    delay(1000);                 // Tunggu untuk melihat apakah LED menyala

    // Matikan LED untuk pindah ke GPIO berikutnya
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    delay(500);
  }

  Serial.println("Testing selesai. Mengulang kembali...");
  delay(2000); // Tunggu sebentar sebelum mengulangi tes
}

```

Untuk memodifikasi program ini agar dapat menguji seluruh GPIO pada ESP32-S3 YD-ESP32-S3, kita perlu melakukan loop melalui daftar GPIO yang memungkinkan untuk digunakan. Setiap GPIO akan diuji satu per satu sebagai pin kontrol untuk WS2812. Jika lampu LED menyala, kita bisa tahu bahwa GPIO tersebut terhubung ke WS2812.

Berikut adalah modifikasi kode yang akan menguji GPIO yang tersedia dan menampilkan hasilnya di Serial Monitor:Penjelasan

- `gpioList[]`: Daftar GPIO yang akan diuji. Anda dapat menyesuaikan daftar ini sesuai kebutuhan Anda.
- Loop pada `gpioList[]`: Kode akan mencoba setiap GPIO dalam daftar sebagai pin kontrol untuk WS2812.
- Output Serial: Program akan menampilkan nomor GPIO yang sedang diuji di Serial Monitor.
- Delay: Memberikan waktu untuk melihat apakah LED menyala pada setiap GPIO.
