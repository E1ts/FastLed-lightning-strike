#include <FastLED.h>
 
#define LED_PIN 3
#define NUM_LEDS 14
#define COLOR_ORDER RGB
#define LED_TYPE WS2812B
#define MAX_BRIGHTNESS 255
#define FLASHES 4
#define FREQUENCY 8

struct CRGB leds[NUM_LEDS];

unsigned int dimmer = 1;

void setup() {
  delay(3000);
  LEDS.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(MAX_BRIGHTNESS);
}

void loop() 
{
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
    dimmer = random8(1,3);    
    leds[dot] = CHSV(255, 0, 255/dimmer);
    FastLED.show();
    delay(random8(4,15)); 
    FastLED.showColor(CHSV(255, 0, 0));
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    delay(random8(FREQUENCY)*100);          
  }
}
