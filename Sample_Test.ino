#include <FastLED.h>
#include <arduinoFFT.h>

#define SAMPLES       1024
#define SAMPLING_FREQ 40000
#define AMPLITUDE     1000
#define AUDIO_IN_PIN  35
#define LED_PIN       5
#define CHIPSET       WS2812B
#define MAX_MILLIAMPS 2000
#define LED_VOLTS     5
#define NUM_BANDS     8
#define NOISE         500


//Sampling and FFT stuff
unsigned int sampling_period_us;
byte peak[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int bandValues[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
double vReal[SAMPLES];
double vImag[SAMPLES];
unsigned long newTime;

arduinoFFT FFT = arduinoFFT(vReal, vImag, SAMPLES, SAMPLING_FREQ);

void setup(){
  sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQ));
  }

void loop(){
  for(int i = 0; i)
  
  }
