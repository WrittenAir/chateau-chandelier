#include <FastLED.h>

//#define LED_PIN     5
#define NUM_LEDS    150
#define BRIGHTNESS  200
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define duration 10

//Test LED Strip
//CRGB leds[NUM_LEDS];

//The Full 13 Strips Listed Below
CRGB led1[NUM_LEDS];
CRGB led2[NUM_LEDS];
CRGB led3[NUM_LEDS];
CRGB led4[NUM_LEDS];
CRGB led5[NUM_LEDS];
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
*  the analog pin A1
*/ 

#define LED_PIN1 A1
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
  //FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  
  //Full 13 LED Setup
  FastLED.addLeds<LED_TYPE, LED_PIN1, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN2, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN3, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN4, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN5, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
 /* FastLED.addLeds<LED_TYPE, LED_PIN6, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN7, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN8, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN9, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN10, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN11, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN12, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<LED_TYPE, LED_PIN13, COLOR_ORDER>(led5, NUM_LEDS).setCorrection( TypicalLEDStrip );*/
  
  
}


void loop()
{
     startUpSequence(CRGB::Blue);
}

void startUpSequence(CRGB color){
  
   uint8_t startIndex = 0;
   float count = 0; 
   fill_solid(currentPalette, 16, color);
   FillLEDsFromPaletteColors(startIndex);
   
   while (true){
     FastLED.setBrightness(abs(sin(count))*BRIGHTNESS);
     count+=.01;
     FastLED.show();
     //FastLED.delay(duration);
   }
   
}
//From FASTLED Base Function to fill the LED Strip 
void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  uint8_t brightness = 155;
  
  for( int i = 0; i < NUM_LEDS; i++) {
    led5[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 1;
  }
}

//Blend the Colors Closer together - in Progress
void FillLEDsFromPaletteColors( uint8_t colorIndex, uint8_t startLed, uint8_t endLed )
{
  uint8_t brightness = 255;
  
  for( startLed ; startLed < endLed; startLed++) { 
    led5[startLed] = ColorFromPalette( currentPalette, colorIndex, brightness,   currentBlending);
    colorIndex += 3;
  }
}
/*
 * Animate Light Mouse Running through the LEDs
*/
void runningMouseV2(){
  currentPalette = whiteMouseRunning_p;
  currentBlending = BLEND; 
  
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
  FillLEDsFromPaletteColors(startIndex);
  
  FastLED.show();
  FastLED.delay(duration);
}

const TProgmemPalette16 whiteMouseRunning_p PROGMEM =
{
  CRGB::White,
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
  CRGB::Black
};


