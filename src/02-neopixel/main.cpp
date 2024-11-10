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