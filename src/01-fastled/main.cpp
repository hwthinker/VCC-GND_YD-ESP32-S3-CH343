#include <Arduino.h>
#include "FastLED.h"

#define NUM_LEDS 1 // LED灯珠数量
#define DATA_PIN 48 // Arduino输出控制信号引脚 根据需要修改 38 16 8等
#define LED_TYPE WS2812 // LED灯环型号
#define COLOR_ORDER GRB // RGB灯珠中红色、绿色、蓝色LED的排列顺序

uint8_t max_bright = 128; // LED亮度控制变量，可使用数值为 0 ～ 255， 数值越大则光带亮度越高
CRGB leds[NUM_LEDS]; // 建立灯带leds
char i= 0; //led灯的点亮序号

void setup() {
  LEDS.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS); // 初始化灯带
  FastLED.setBrightness(max_bright); // 设置灯带亮度
}

void loop() {
  if (i == NUM_LEDS) {
    i = 0;
  }
  leds[i] = CRGB::Red; // i= 0 设置灯带中第一个灯珠颜色为红色，leds[0]为第一个灯珠，leds[1]为第二个灯珠
  FastLED.show(); // 更新LED色彩
  delay(50); // 等待500毫秒
  leds[i] = CRGB::Black; // 设置灯带中第一个灯珠熄灭
  FastLED.show(); // 更新LED色彩
  delay(50); // 等待500毫秒
  i++;
}
