#include <FastLED.h>
FASTLED_USING_NAMESPACE

#if FASTLED_VERSION < 3001000
#error "Requires FastLED 3.1 or later; check github for latest code."
#endif

//#define LED_PIN     5
#define NUM_LEDS    150
#define BRIGHTNESS  200
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define FRAMES_PER_SECOND 10


//Test LED Strip
CRGB led5[NUM_LEDS];

//The Full 13 Strips Listed Below
CRGB led1[NUM_LEDS];
CRGB led2[NUM_LEDS];
CRGB led3[NUM_LEDS];
CRGB led4[NUM_LEDS];
//CRGB led5[NUM_LEDS];
CRGB led6[NUM_LEDS];
CRGB led7[NUM_LEDS];
CRGB led8[NUM_LEDS];
CRGB led9[NUM_LEDS];
CRGB led10[NUM_LEDS];
CRGB led11[NUM_LEDS];
CRGB led12[NUM_LEDS];
CRGB led13[NUM_LEDS];

/*  
*  List of pins used: number of pin will correspond to
*  led strip number. Except for led1 which will be using
*  digital bin 14
*/ 
#define LED_PIN5 5

#define LED_PIN1 14
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

extern CRGBPalette16 whiteMouseRunning;
extern const TProgmemPalette16 whiteMouseRunning_p PROGMEM;

void setup() {
  delay( 3000 ); // power-up safety delay
  
  //Test LED Strip Setup
  FastLED.addLeds<LED_TYPE, LED_PIN5, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  
  Serial.begin(115200); 
  
  //Full 13 LED Setup
  FastLED.addLeds<LED_TYPE, LED_PIN1, COLOR_ORDER>(led1, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN2, COLOR_ORDER>(led2, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN3, COLOR_ORDER>(led3, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN4, COLOR_ORDER>(led4, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN5, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN6, COLOR_ORDER>(led6, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN7, COLOR_ORDER>(led7, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN8, COLOR_ORDER>(led8, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN9, COLOR_ORDER>(led9, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN10, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN11, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN12, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN13, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  
  
}


void loop()
{
   /* 
   *  There are three diffeent animations below that can be used seperately
   *  To view each one uncomment thier corresponding lines
   *  Warning: Due to high number of leds set up the animations will  
   *  run slowly
   */
  
   //Uncomment next three lines for Confetti animation example on led 2 and 5:
   confetti(led5);
   confetti(led2);
   FastLED.show(); 
   
   //Uncomment for start up Sequence
   //startUpSequence(CRGB::Purple, led5);  
     
   //Uncomment for light running sequence
    /*sinelon(led5); 
    sinelon(led2);
    FastLED.show(); */
}
//startUpSequence Update not tested yet
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
void FillLEDsFromPaletteColors( uint8_t colorIndex, CRGB led[])
{
  uint8_t brightness = 200;
  
  for( int i = 0; i < NUM_LEDS; i++) {
    led[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 1;
  }
}

/*
 * Animate Light Mouse Running through the LEDs
 * Old Implementation: Do not Use
*/
void runningMouseV2(CRGB led[]){
  currentPalette = whiteMouseRunning_p;
  currentBlending = LINEARBLEND; 
  
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors(startIndex, led);
  FastLED.delay(FRAMES_PER_SECOND);
}

// Run through the Led Strip
void sinelon(CRGB led[])
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( led, NUM_LEDS, 20);
  int pos = beat8(2)/1.7;
  led[pos] += CHSV( 192, 192, 192);
}
void confetti(CRGB led[]) 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( led, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  led[pos] += CHSV( 134, 200, 255);
}
const TProgmemPalette16 whiteMouseRunning_p PROGMEM =
{
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::White
};




