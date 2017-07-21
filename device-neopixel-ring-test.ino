// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            PIN_D7

int ledPin = 11;

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      16

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(PIN, OUTPUT);
  
  pixels.begin(); // This initializes the NeoPixel library.

  // flash to indicate startup
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);
  delay(250);
  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);
  delay(250);
  digitalWrite(ledPin, HIGH);

  // flash to indicate startup
  /*pinMode(PIN, OUTPUT);
  digitalWrite(PIN, HIGH);
  delay(250);
  digitalWrite(PIN, LOW);
  delay(250);
  digitalWrite(PIN, HIGH);
  delay(250);
  digitalWrite(PIN, LOW);
  delay(250);
  digitalWrite(PIN, HIGH);*/
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
