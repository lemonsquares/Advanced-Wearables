/*
  Blink-o-Rama
  Giulia Zefilippo
  DIGF-3010-001 Advanced Wearable Electronics
  OCAD University
  Created on Feb 18 2022
  Based on:
  External Neopixels, Circuit Playground Library, https://github.com/adafruit/Adafruit_CircuitPlayground/blob/master/examples/external_neopixels/external_neopixels.ino
  Button Cycler, Adafruit Neopixel Library, https://github.com/adafruit/Adafruit_NeoPixel/blob/master/examples/buttoncycler/buttoncycler.ino
  Circuit Playground Bike Light - Spinner, Carter Nelson, https://learn.adafruit.com/circuit-playground-bike-light/the-spinner
  Circuit Playground Bike Light - Bedazzler, Carter Nelson, https://learn.adafruit.com/circuit-playground-bike-light/the-bedazzler
*/
// libraries
#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define NEOPIXPIN 6  // DI Pin connection for flora neopixels
#define NUMPIXELS 6 // Number of flora neopixels
#define CPLAY_LEFTBUTTON 4 // define pin for internal left button
#define DELAY 300
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// use Adafruit_CPlay_NeoPixel to create a separate external NeoPixel strip
Adafruit_CPlay_NeoPixel strip = Adafruit_CPlay_NeoPixel(NUMPIXELS, NEOPIXPIN, NEO_GRB + NEO_KHZ800);
int pixel1;
int pixel2;
int mode = 0;    // tracking mode states (0-3) for the switch case
int orange = 0xF54505;
int blue = 0x0000FF;
int yellow = 0xFFE060;
bool oldState = LOW;
bool newState = LOW;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  pinMode(CPLAY_LEFTBUTTON, INPUT_PULLDOWN);
  CircuitPlayground.begin();  // initialize the Circuit Playground as usual
  CircuitPlayground.setBrightness(255);
  strip.begin(); // initialize external flora NeoPixels
  strip.setBrightness(255);
  strip.show();
// set starting points for external neopixels
  pixel1 = 0;
  pixel2 = 5;
}
// end of void setup
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  bool newState = digitalRead(CPLAY_LEFTBUTTON);
  if ((newState == HIGH) && (oldState == LOW)) { // checks button
    delay(10);
    newState = digitalRead(CPLAY_LEFTBUTTON);
    if (newState == HIGH) {
      ++mode;
      if (mode > 3) {
        mode = 0; // If mode reaches past 3, reset to beginning.
      }
      switch (mode) { // switch case that cycles through different functions when left button is pressed
        case 0:
          winter();
          break;
        case 1:
          spring();
          break;
        case 2:
          summer();
          break;
        case 3:
          autumn();
          break;
      }
    }
  }
  oldState = newState;
  // neopixels - constantly moving pixels in a circle
  if (newState == LOW) { // if button !pressed, light up
    strip.setPixelColor(pixel1, yellow);
    strip.setPixelColor(pixel2, yellow);
    strip.show();
    // Increment pixels to move around
    pixel1 = pixel1 + 1;
    pixel2 = pixel2 + 1;
    // Check pixel values and if they reach their limit, reset to start.
    if (pixel1 > 5) pixel1 = 0;
    if (pixel2 > 5) pixel2 = 0;
    delay(150);
    strip.clear();
    strip.show();
  } else {    // else if the button is pressed, clear
    strip.clear();
    strip.show();
  }
}
// end of void loop
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// custom functions start
// orange represents sunlight
// blue represents nightlight
// WINTER
void winter() {
  // on-board neopixels pattern
  for (int i = 0; i <= 3; i++) {
    CircuitPlayground.setPixelColor(i, orange);
    delay(DELAY);
  }
  // external flora neopixels - random blinks
  // randomly picks one neopixel out of five to turn on
  // randomly picks a color
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(
      random(5),
      random(100),
      random(100),
      random(100));
    strip.show();
    delay(DELAY);
  }
  strip.clear();
  strip.show();
  for (int i = 4; i <= 9; i++) {
    CircuitPlayground.setPixelColor(i, blue);
    delay(DELAY);
  }
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(
      random(5),
      random(100),
      random(100),
      random(100));
    strip.show();
    delay(DELAY);
  }
  strip.clear();
  strip.show();
  CircuitPlayground.clearPixels();
  delay(20);
}
// SPRING
void spring() {
  for (int i = 0; i <= 5; i++) {
    CircuitPlayground.setPixelColor(i, orange);
    delay(DELAY);
  }
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(
      random(5),
      random(100),
      random(100),
      random(100));
    strip.show();
    delay(DELAY);
  }
  strip.clear();
  strip.show();
  for (int i = 6; i <= 9; i++) {
    CircuitPlayground.setPixelColor(i, blue);
    delay(DELAY);
  }
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(
      random(5),
      random(100),
      random(100),
      random(100));
    strip.show();
    delay(200);
  }
  strip.clear();
  strip.show();
  CircuitPlayground.clearPixels();
  delay(50);
}
// SUMMER
void summer() {
  for (int i = 0; i <= 6; i++) {
    CircuitPlayground.setPixelColor(i, orange);
    delay(DELAY);
  }
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(
      random(5),
      random(100),
      random(100),
      random(100));
    strip.show();
    delay(DELAY);
  }
  strip.clear();
  strip.show();
  for (int i = 7; i <= 9; i++) {
    CircuitPlayground.setPixelColor(i, blue);
    delay(DELAY);
  }
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(
      random(5),
      random(100),
      random(100),
      random(100));
    strip.show();
    delay(DELAY);
  }
  strip.clear();
  strip.show();
  CircuitPlayground.clearPixels();
  delay(20);
}
//AUTUMN
void autumn() {
  for (int i = 0; i <= 4; i++) {
    CircuitPlayground.setPixelColor(i, orange);
    delay(DELAY);
  }
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(
      random(5),
      random(100),
      random(100),
      random(100));
    strip.show();
    delay(DELAY);
  }
  strip.clear();
  strip.show();
  for (int i = 5; i <= 9; i++) {
    CircuitPlayground.setPixelColor(i, blue);
    delay(DELAY);
  }
  for (int i = 0; i < NUMPIXELS; i++) {
    strip.setPixelColor(
      random(5),
      random(100),
      random(100),
      random(100));
    strip.show();
    delay(DELAY);
  }
  strip.clear();
  strip.show();
  CircuitPlayground.clearPixels();
  delay(20);
}
//FIN
