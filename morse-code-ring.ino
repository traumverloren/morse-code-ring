/**
*
*  gemma.SMN
*`
*  Convert string to morse code and display via Neopixels
*
*  https://github.com/klinstifen/gemma.SMN
*  
**/

#include <Adafruit_NeoPixel.h> // Include the adafruit Neopixel Library

// adafruit gemma

#define PIN        2
#define NUMPIXELS  1

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int brightness = 1;
uint32_t red = pixels.Color(255, 0, 0);
uint32_t lightred = pixels.Color(140, 0, 0);
uint32_t off = pixels.Color(0, 0, 0);
uint32_t turquoise = pixels.Color(64, 224, 208);

uint8_t dit = 60;
uint8_t dah = 180;
uint8_t shogap = 180;
uint8_t medgap = 420;
uint8_t interchar = 60;

void setup() {
  pixels.begin();
  pixels.setBrightness(brightness);
  pixels.show();
}

void loop() {
  convert("i love myself");
}
/**
 * 
 * Convert messages to morse code
 * 
 */
void convert(String mCode) {
  for (int i = 0; i < mCode.length() + 1; i++) {
    switch (mCode.charAt(i)) {
      case 'a':
        mark(dit);
        mark(dah);
        break;
      case 'b':
        mark(dah);
        mark(dit);
        mark(dit);
        mark(dit);
        break;
      case 'c':
        mark(dah);
        mark(dit);
        mark(dah);
        mark(dit);
        break;
      case 'd':
        mark(dah);
        mark(dit);
        mark(dit);
        break;
      case 'e':
        mark(dit);
        break;
      case 'f':
        mark(dit);
        mark(dit);
        mark(dah);
        mark(dit);
        break;
      case 'g':
        mark(dah);
        mark(dah);
        mark(dit);
        break;
      case 'h':
        mark(dit);
        mark(dit);
        mark(dit);
        mark(dit);
        break;
      case 'i':
        mark(dit);
        mark(dit);
        break;
      case 'j':
        mark(dit);
        mark(dah);
        mark(dah);
        mark(dah);
        break;
      case 'k':
        mark(dah);
        mark(dit);
        mark(dah);
        break;
      case 'l':
        mark(dit);
        mark(dah);
        mark(dit);
        mark(dit);
        break;
      case 'm':
        mark(dah);
        mark(dah);
        break;
      case 'n':
        mark(dah);
        mark(dit);
        break;
      case 'o':
        mark(dah);
        mark(dah);
        mark(dah);
        break;
      case 'p':
        mark(dit);
        mark(dah);
        mark(dah);
        mark(dit);
        break;
      case 'q':
        mark(dah);
        mark(dah);
        mark(dit);
        mark(dah);
        break;
      case 'r':
        mark(dit);
        mark(dah);
        mark(dit);
        break;
      case 's':
        mark(dit);
        mark(dit);
        mark(dit);
        break;
      case 't':
        mark(dah);
        break;
      case 'u':
        mark(dit);
        mark(dit);
        mark(dah);
        break;
      case 'v':
        mark(dit);
        mark(dit);
        mark(dit);
        mark(dah);
        break;
      case 'w':
        mark(dit);
        mark(dah);
        mark(dah);
        break;
      case 'x':
        mark(dah);
        mark(dit);
        mark(dit);
        mark(dah);
        break;
      case 'y':
        mark(dah);
        mark(dit);
        mark(dah);
        mark(dah);
        break;
      case 'z':
        mark(dah);
        mark(dah);
        mark(dit);
        mark(dit);
        break;
      case ' ':
        pause(medgap);
        break;
    }
    pause(shogap);
  }
  eot();
}

/**
 *
 * Display short or long mark
 *
 */
void mark(uint8_t blip) {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, turquoise);
  }
  pixels.show();
  delay(blip*5);
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, off);
  }
  pixels.show();
  delay(interchar*5);
}

/**
 *
 * Pause between a letter or word
 *
 */
void pause(uint8_t wait) {
  delay(wait*5);
}

/**
 *
 * Display end of transmission animation
 *
 */
void eot() {
  pixels.show();
  delay(50);
  for (int i = 0; i < NUMPIXELS; i = i + 2) {
   pixels.setPixelColor(i, off);
  }
  delay(2000);
}
