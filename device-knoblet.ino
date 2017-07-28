//*** NeoPixel ***//
// https://github.com/adafruit/Adafruit_NeoPixel/blob/master/examples/simple/simple.ino
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>

#define PIXPIN	PIN_D7
#define LED	11
#define PIXELS	16

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELS, PIXPIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(PIXPIN, OUTPUT);
  
  pixels.begin();

  // flash LED to indicate startup
  pinMode(LED, OUTPUT);
  for (int i=0; i<6; i++) {  
    digitalWrite(LED, i%2 ? HIGH : LOW);
    delay(250);
  }
}

int i = 0;
int light[16] = {0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};

void loop() {
  pixels.setPixelColor(i % 16, light[i % 16] ? pixels.Color(i * 1 % 255, i * 2 % 255, i * 3 % 255) : pixels.Color(0,0,0));
  light[i % 16] = !light[i%16];
  pixels.show();
  i++;
  delay(30);
}
