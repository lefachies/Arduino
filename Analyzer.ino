#include <FastLED.h>

#define LED_PIN  5
#define NUM_LEDS 144

CRGB leds[NUM_LEDS];
int color_r = 0;
int color_g = 0;
int color_b = 0;

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
}

void loop() {
  
  for(int i = 0; i <= NUM_LEDS - 1; ++i){
    leds[i] = CRGB(color_r, color_g, color_b);
    FastLED.show();
    color_r++;

    
    delay(2);
    }

   for(int i = 0; i <= NUM_LEDS - 1; ++i){
    leds[i] = CRGB(color_r, color_g, color_b);

    FastLED.show();
    color_g++;

    
    
    delay(2);
    }

    for(int i = 0; i <= NUM_LEDS - 1; ++i){
    leds[i] = CRGB(color_r, color_g, color_b);
    FastLED.show();
    color_b++;
    
    
    delay(2);
    }

  }
