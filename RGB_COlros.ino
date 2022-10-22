#include <FastLED.h>
#include<arduinoFFT.h>

#define LED_PIN         5
#define NUM_LEDS        144
#define SEG_SIZE        12
#define COLOR_1         CRGB(255, 0, 0)
#define NO_COLOR        CRGB(0, 0, 0)
#define SAMPLES         1024
#define SAMPLING_FREQ   40000
#define AMPLITUDE       900          // Depending on your audio source level, you may need to alter this value. Can be used as a 'sensitivity' control.
#define AUDIO_IN_PIN    35            // Signal in on this pin
#define NUM_BANDS       12            // To change this, you will need to change the bunch of if statements describing the mapping from bins to bands
#define NOISE           500           // Used as a crude noise filter, values below this are ignored

unsigned int sampling_period_us;


CRGB leds[NUM_LEDS];
int color_r = 0;
int color_g = 0;
int color_b = 0;
CRGB color1[NUM_LEDS];


int mag_values[] = {0,0,0,0,0,0,0,0,0,0,0,0};  
int bandValues[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double vReal[SAMPLES];
double vImag[SAMPLES];
unsigned long newTime;
arduinoFFT FFT = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);
  
void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(color1, NUM_LEDS);

  sampling_period_us = round(1000000 *(1 / SAMPLING_FREQ));  

  Serial.begin(9600);

} 

void loop() {

  

  for(int i = 0; i <SAMPLES; i++){
    newTime = micros();
    vReal[i] = analogRead(AUDIO_IN_PIN);
    vImag[i] = 0;
    while(micros() < (newTime + sampling_period_us)){/*chill*/ } }

    // Compute FFt
    FFT.DCRemoval();
    FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
    FFT.Compute(FFT_FORWARD);
    FFT.ComplexToMagnitude();

// Reset bandValues[]
  for (int i = 0; i<NUM_BANDS; i++){
    bandValues[i] = 0;
  }

  // Sample the audio pin
  for (int i = 0; i < SAMPLES; i++) {
    newTime = micros();
    vReal[i] = analogRead(AUDIO_IN_PIN); // A conversion takes about 9.7uS on an ESP32
    vImag[i] = 0;
    while ((micros() - newTime) < sampling_period_us) { /* chill */ }
  }

  // Compute FFT
  FFT.DCRemoval();
  FFT.Windowing(FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(FFT_FORWARD);
  FFT.ComplexToMagnitude();

  // Analyse FFT results
  for (int i = 2; i < (SAMPLES/2); i++){       // Don't use sample 0 and only first SAMPLES/2 are usable. Each array element represents a frequency bin and its value the amplitude.
    if (vReal[i] > NOISE) {                    // Add a crude noise filter

      /*8 bands, 12kHz top band
      if (i<=1 )           bandValues[0]  += (int)vReal[i];
      if (i>3   && i<=6  ) bandValues[1]  += (int)vReal[i];
      if (i>6   && i<=13 ) bandValues[2]  += (int)vReal[i];
      if (i>13  && i<=27 ) bandValues[3]  += (int)vReal[i];
      if (i>27  && i<=55 ) bandValues[4]  += (int)vReal[i];
      if (i>55  && i<=112) bandValues[5]  += (int)vReal[i];
      if (i>112 && i<=229) bandValues[6]  += (int)vReal[i];
      if (i>112 && i<=229) bandValues[6]  += (int)vReal[i];      
      if (i>112 && i<=229) bandValues[6]  += (int)vReal[i];      
      if (i>112 && i<=229) bandValues[6]  += (int)vReal[i];
      if (i>112 && i<=229) bandValues[6]  += (int)vReal[i];
      if (i>264          ) bandValues[7]  += (int)vReal[i];*/
//    16 bands, 12kHz top band
      if (i<=2 )           bandValues[0]  += (int)vReal[i];
      if (i>2   && i<=3  ) bandValues[1]  += (int)vReal[i];
      if (i>3   && i<=5  ) bandValues[2]  += (int)vReal[i];
      if (i>5   && i<=7  ) bandValues[3]  += (int)vReal[i];
      if (i>7   && i<=9  ) bandValues[4]  += (int)vReal[i];
      if (i>9   && i<=13 ) bandValues[5]  += (int)vReal[i];
      if (i>13  && i<=18 ) bandValues[6]  += (int)vReal[i];
      if (i>18  && i<=25 ) bandValues[7]  += (int)vReal[i];
      if (i>25  && i<=50 ) bandValues[8]  += (int)vReal[i];
      if (i>50  && i<=135 ) bandValues[9] += (int)vReal[i];
      if (i>135 && i<=264) bandValues[10] += (int)vReal[i];
      if (i>264          ) bandValues[11] += (int)vReal[i];
    }
  }




  
for(int i = 0; i < 12; i++){
  mag_values[i] = (bandValues[i]/AMPLITUDE);
  if (mag_values[i] > 12)
    mag_values[i] = 12;

  Serial.println(mag_values[i]);
  }

  // mag_0 Segment
  for(int i = (SEG_SIZE * 0); i < mag_values[0] + (SEG_SIZE * 0); i++){
    color1[i] = CRGB(255, 0, 0);
    delay(10);
    FastLED.show();}
  for(int i = (SEG_SIZE * 0 + mag_values[0]); i < (SEG_SIZE * (0 + 1)) ; i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

  // mag_1 Segment
  for(int i = SEG_SIZE * 1; i < mag_values[1] + (SEG_SIZE * 1); i++){
    color1[i] = CRGB(255, 127, 0);
    delay(10);
    FastLED.show();}
  for(int i = (SEG_SIZE * 1 + mag_values[1]); i < (SEG_SIZE * (1 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

  // mag_2 Segment
  for(int i = SEG_SIZE * 2; i < mag_values[2] + (SEG_SIZE * 2); i++){
    color1[i] = CRGB(255, 255, 0);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 2 + mag_values[2]); i < (SEG_SIZE * (2 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

    // mag_3 Segment
  for(int i = SEG_SIZE * 3; i < mag_values[3] + (SEG_SIZE * 3); i++){
    color1[i] = CRGB(127, 255, 0);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 3 + mag_values[3]); i < (SEG_SIZE * (3 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

    // mag_4 Segment
  for(int i = SEG_SIZE * 4; i < mag_values[4] + (SEG_SIZE * 4); i++){
    color1[i] = CRGB(0, 255, 0);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 4 + mag_values[4]); i < (SEG_SIZE * (4 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

        // mag_5 Segment
  for(int i = SEG_SIZE * 5; i < mag_values[5] + (SEG_SIZE * 5); i++){
    color1[i] = CRGB(0, 255, 127);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 5 + mag_values[5]); i < (SEG_SIZE * (5 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

        // mag_6 Segment
  for(int i = SEG_SIZE * 6; i < mag_values[6] + (SEG_SIZE * 6); i++){
    color1[i] = CRGB(0, 255, 255);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 6 + mag_values[6]); i < (SEG_SIZE * (6 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

        // mag_7 Segment
  for(int i = SEG_SIZE * 7; i < mag_values[7] + (SEG_SIZE * 7); i++){
    color1[i] = CRGB(0, 127, 255);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 7 + mag_values[7]); i < (SEG_SIZE * (7 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

        // mag_8 Segment
  for(int i = SEG_SIZE * 8; i < mag_values[8] + (SEG_SIZE * 8); i++){
    color1[i] = CRGB(0, 0, 255);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 8 + mag_values[8]); i < (SEG_SIZE * (8 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}


        // mag_9 Segment
  for(int i = SEG_SIZE * 9; i < mag_values[9] + (SEG_SIZE * 9); i++){
    color1[i] = CRGB(127, 0, 255);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 9 + mag_values[9]); i < (SEG_SIZE * (9 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

        // mag_10 Segment
  for(int i = SEG_SIZE * 10; i < mag_values[10] + (SEG_SIZE * 10); i++){
    color1[i] = CRGB(255, 0, 255);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 10 + mag_values[10]); i < (SEG_SIZE * (10 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}

        // mag_11 Segment
  for(int i = SEG_SIZE * 11; i < mag_values[11] + (SEG_SIZE * 11); i++){
    color1[i] = CRGB(255, 0, 127);
    FastLED.show();}
    
  for(int i = (SEG_SIZE * 11 + mag_values[11]); i < (SEG_SIZE * (11 + 1)); i++){
    color1[i] = NO_COLOR;
    FastLED.show();}






    
  
  }



      

   
