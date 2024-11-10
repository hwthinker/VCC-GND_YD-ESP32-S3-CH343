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

