
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> 
#endif

#define LED_PIN    7


#define LED_COUNT 60


Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);



void setup() {
 
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  strip.begin();          
  strip.show();            
  strip.setBrightness(255);
}




void loop() {

  theaterChase(strip.Color(0,   0,   255), 50);
  
 theaterChase(strip.Color(255,   0,   0), 50); 
 
}




void theaterChase(uint32_t color, int wait) {
  for(int a=0; a<10; a++) {  
    for(int b=0; b<3; b++) { 
      strip.clear();        
    
      for(int c=b; c<strip.numPixels(); c += 3) {
        strip.setPixelColor(c, color); 
      }
      strip.show();
      delay(wait);  
    }
  }
}
