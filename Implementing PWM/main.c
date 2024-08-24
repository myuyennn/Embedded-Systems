/*
* MyUyen Nguyen, Samantha Oung
* 1901980 and 1902685
* December 7, 2023
* Program reads ADC value from potentiometer 
* and changes the PWM duty cycle accordingly, displays 
* on an onboard LED.
*/

#include <stdint.h> 
#include "lab5.h"
#include "Lab5_Inits.h"

uint32_t ADC_value;

int main(void) {
  enum frequency freq = PRESET2; // 60 MHz
  PLL_Init(freq);                // Set system clock frequency to 60 MHz
  LED_Init();                    // Initialize the onboard LEDs (GPIO)
  ADCReadPot_Init();             // Initialize ADC0 to read from the potentiometer
  TimerADCTrigger_Init();        // Initialize Timer0A to trigger ADC0
  PWM_Init();                    // Initialize Pulse Width Modulator (PWM)
  
  while(1) {
    // ADC value ranges set PWM duty cycle in 10% increments
    if (ADC_value >= 0 && ADC_value <= 409) {
      PWM0CMPA = 0x1999; // 6553 ticks - 10% 
    } else if (ADC_value >= 410 && ADC_value <= 819) {
      PWM0CMPA = 0x3333; // 13,107 ticks - 20% 
    } else if (ADC_value >= 820 && ADC_value <= 1229) {
      PWM0CMPA = 0x4CCC; // 19660 ticks - 30% 
    } else if (ADC_value >= 1230 && ADC_value <= 1639) {
      PWM0CMPA = 0x6666; // 26214 ticks - 40% 
    } else if (ADC_value >= 1640 && ADC_value <= 2049) {
      PWM0CMPA = 0x7FFF; // 32767 ticks - 50% 
    } else if (ADC_value >= 2050 && ADC_value <= 2459) {
      PWM0CMPA = 0x9999; // 39321 ticks - 60% 
    } else if (ADC_value >= 2460 && ADC_value <= 2869) {
      PWM0CMPA = 0xB332; // 45874 ticks - 70% 
    } else if (ADC_value >= 2870 && ADC_value <= 3279) {
      PWM0CMPA = 0xCCCC; // 52428 ticks - 80% 
    } else if (ADC_value >= 3280 && ADC_value <= 3689) {
      PWM0CMPA = 0xE665; // 58981 ticks - 90% 
    } else {    
      PWM0CMPA = 0x103E6; // max clock ticks - 100% duty cycle
    }
  }
  return 0;
}

// Implements ADC ISR
void ADC0SS3_Handler(void) {
  // Clear the ADC0 interrupt flag
  ADCISC_0 |= 1 << 3;
  // Save the ADC value to global variable ADC_value
  ADC_value = ADCSSFIFO3_0;
}
