
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif


int PIN = 7;
int totalLEDs = 30;
int ledFadeTime = 5;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(totalLEDs, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  blueFadeInAndOut(0, 0, 255, ledFadeTime); // Blue
  delay(100);
   redFadeInAndOut(255, 0, 0, ledFadeTime); // Red
   delay(100);
}

void blueFadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {
  for(uint8_t b = 0; b <255; b++) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }

     strip.show();
     delay(wait);
  };

  for(uint8_t b=255; b > 0; b--) {
     for(uint8_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }
     strip.show();
     delay(wait);
  };
};





void redFadeInAndOut(uint8_t red, uint8_t green, uint8_t blue, uint8_t wait) {
  for(uint8_t b = 0; b <255; b++) {
     for(uint8_t i=0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }

     strip.show();
     delay(wait);
  };

  for(uint8_t b=255; b > 0; b--) {
     for(uint8_t i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, red * b/255, green * b/255, blue * b/255);
     }
     strip.show();
     delay(wait);
  };
};
