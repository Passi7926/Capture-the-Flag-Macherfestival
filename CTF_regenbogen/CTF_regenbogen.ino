
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
  strip.setBrightness(25); 
}




void loop() {
 
  rainbow(10);             // Flowing rainbow cycle along the whole strip
 
}





void rainbow(int wait) {
 
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
     
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      
      strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
    }
    strip.show(); 
    delay(wait); 
  }
}
