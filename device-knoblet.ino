//*** NeoPixel ***//
// https://github.com/adafruit/Adafruit_NeoPixel/blob/master/examples/simple/simple.ino
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

//*** EC-11 rotary encoder ***//
// https://little-scale.blogspot.com.au/2016/07/simple-midi-rotary-encoder-with-teensy.html
// http://milkcrate.com.au/_other/downloads/arduino/Teensy_Rotary_Encoder.ino
// Thanks Seb!

#include <Adafruit_NeoPixel.h>
#include <Encoder.h>

#define PIXPIN	PIN_D7
#define LED	11
#define PIXELS	16

int value; 

long enc_one_previous  = -999;
byte button_previous; 

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(PIXELS, PIXPIN, NEO_GRB + NEO_KHZ800);
Encoder enc_one(PIN_D0, PIN_D1);

void setup() {
  pinMode(PIXPIN, OUTPUT);
  pinMode(23, INPUT_PULLUP); 
  
  pixels.begin();

  // flash LED to indicate startup
  pinMode(LED, OUTPUT);
  for (int i=0; i<6; i++) {  
    digitalWrite(LED, i%2 ? HIGH : LOW);
    delay(250);
  }
}

void loop() {
  value = enc_one.read();
  
  if(value > 127) {
    enc_one.write(127);
  }
  
  else if(value < 0) {
    enc_one.write(0);
  } 
  
  value = constrain(value, 0, 127);
  if (value != enc_one_previous) {
    enc_one_previous = value;
    //usbMIDI.sendControlChange(1, value, 1);
    for (int l=0; l<PIXELS; l++) {
      pixels.setPixelColor(l, l <= (value / 8) ? pixels.Color(150, 0, 0) : pixels.Color(0,0,0));
    }
    pixels.show();
  }
  
  value = digitalRead(23); 
  if (value != button_previous) {
    button_previous = value;
    // usbMIDI.sendControlChange(2, (1 - value) * 127, 1);
    delay(3);
  }
  
  delay(1);
  //delay(30);
}
