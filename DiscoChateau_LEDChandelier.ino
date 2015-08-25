#include <FastLED.h>
FASTLED_USING_NAMESPACE

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

#define NUM_LEDS 7
#define NUM_LEDS_PER_STRIP 183 
#define BRIGHTNESS  255
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define FRAMES_PER_SECOND 10

//The Full 13 Strips Listed Below 
CRGB leds[NUM_LEDS][NUM_LEDS_PER_STRIP];

#define LED_PIN1 A0
#define LED_PIN2 2
#define LED_PIN3 3
#define LED_PIN4 4
#define LED_PIN5 5
#define LED_PIN6 6
#define LED_PIN7 7
#define LED_PIN8 8
#define LED_PIN9 9
#define LED_PIN10 10
#define LED_PIN11 11
#define LED_PIN12 12
#define LED_PIN13 13

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

void setup() {
  delay( 3000 ); // power-up safety delay
  Serial.begin(9600);
  //Full 13 LED Setup
  FastLED.addLeds<LED_TYPE, LED_PIN1, COLOR_ORDER>(leds[0], NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN2, COLOR_ORDER>(leds[1], NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN3, COLOR_ORDER>(leds[2], NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN4, COLOR_ORDER>(leds[3], NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN5, COLOR_ORDER>(leds[4], NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN6, COLOR_ORDER>(leds[5], NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN7, COLOR_ORDER>(leds[6], NUM_LEDS_PER_STRIP).setCorrection( TypicalLEDStrip );
  
  FastLED.setBrightness(  BRIGHTNESS );
  currentPalette = OceanColors_p;
  currentBlending = LINEARBLEND; 
}

void loop()
{
 
   //Calm Ocean Blend
   static uint8_t startIndex = 0;
   startIndex = startIndex + 1;

    for (int i = 0; i < NUM_LEDS; i++){
          FillLEDsFromPaletteColors(startIndex, leds[i]);
    }  
    for (int i = 0; i < NUM_LEDS; i++){
          confetti(leds[i]);
    }
   FastLED.show();
}
void startUpSequence(CRGB color, CRGB led[]){
  
   uint8_t startIndex = 0;
   fill_solid(currentPalette, 16, color);
   FillLEDsFromPaletteColors(startIndex, led);
    
   for (float i = 0; i < PI*2; i+=.01){  
     FastLED.setBrightness(abs(sin(i))*BRIGHTNESS);
     FastLED.show();
   }
}
//From FASTLED Base Function to fill the LED Strip 
void FillLEDsFromPaletteColors( uint8_t &colorIndex, CRGB led[])
{
  
  for( int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    led[i] = ColorFromPalette( currentPalette, colorIndex, BRIGHTNESS, currentBlending);
    colorIndex += 1;
 
  }
}
void confetti(CRGB led[]) 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( led, NUM_LEDS_PER_STRIP, 10);
  int pos = random16(NUM_LEDS_PER_STRIP);
  led[pos] += CHSV( 200, 200, 255);
}
  
