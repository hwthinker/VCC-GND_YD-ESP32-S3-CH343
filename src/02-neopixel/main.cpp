#include<Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN        8 //  根据需要修改  38 16 8
#define NUMPIXELS  1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  pixels.setPixelColor(0, pixels.Color(0,255,0)); // 红色
  pixels.show();
  delay(1000);
}