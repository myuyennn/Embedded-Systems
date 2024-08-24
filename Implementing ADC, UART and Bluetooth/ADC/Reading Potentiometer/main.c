// __________MAIN PROGRAM (.c)__________

/*
* MyUyen Nguyen, Samantha Oung
* 1901980, 1902685
* November 16, 2023
* Program displays certain LEDs depending on the resistance values
* that are read from the potentiometer
*/

// STEP 0b: Include your header file here
#include <stdint.h> 
#include "lab3.h"
#include "Lab3_Inits.h"

uint32_t ADC_value;
float resistance;

int main(void) {
  // Select system clock frequency preset
  enum frequency freq = PRESET2; // 60 MHz
  PLL_Init(freq);        // Set system clock frequency to 60 MHz
  LED_Init();            // Initialize the 4 onboard LEDs (GPIO)
  ADCReadPot_Init();     // Initialize ADC0 to read from the potentiometer
  TimerADCTrigger_Init(); // Initialize Timer0A to trigger ADC0
  
  while(1) {
    resistance = ((double) ADC_value / 4095.0) * 10.0;
    printf("%lu\n", ADC_value);
    // 5.2: Change the pattern of LEDs based on the resistance
    if (resistance < 2.5) {
      GPIODATA_N = 0x2; // LED1 - PN1
      GPIODATA_F = 0x0;
    } else if (resistance < 5.0) {
      GPIODATA_N = 0x3; // LED2 - PN0
      GPIODATA_F = 0x0;
    } else if (resistance < 7.5) {
      GPIODATA_N = 0x3; // LED3 - PF4
      GPIODATA_F = 0x10;
    } else {
      GPIODATA_N = 0x3; // LED4 - PF0
      GPIODATA_F = 0x11;
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
