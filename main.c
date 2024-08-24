// __________MAIN PROGRAM (.c)__________

/*
* MyUyen Nguyen, Samantha Oung
* 1901980, 1902685
* November 16, 2023
* Program prints temperature of TiVA board to the terminal 
* I/O using the internal temperature sensor
*/

// STEP 0b: Include your header file here
#include <stdio.h>
#include <stdint.h> 
#include "lab3.h"
#include "Lab3_Inits.h"

volatile uint32_t ADC_value;
float temp;

int main(void) {
  // Select system clock frequency preset
  enum frequency freq = PRESET2;        // 60 MHz
  PLL_Init(freq);        // Set system clock frequency to 60 MHz
  LED_Init();            // Initialize the 4 onboard LEDs (GPIO)
  ADCReadPot_Init();     // Initialize ADC0 to read from the potentiometer
  TimerADCTrigger_Init(); // Initialize Timer0A to trigger ADC0
  switches_J_Init();    // Initialize switches
  
  while(1) {
    if (GPIODATA_J == 0x1) {
      freq = PRESET1; // 120 MHz
    } else if (GPIODATA_J == 0x2) {
      freq = PRESET3; // 12 MHz
    } else {
      freq = PRESET2;
    }
   
    PLL_Init(freq);
   
    temp = (float) 147.5 - ((247.5 * ADC_value) / 4096.0);
    printf("%f \n", temp);
  }
  return 0;
}

// Implement the ADC ISR.
void ADC0SS3_Handler(void) {
  // Clear the ADC0 interrupt flag
  ADCISC_0 |= 1 << 3;
  // Save the ADC value to global variable ADC_value
  ADC_value = ADCSSFIFO3_0;
}
