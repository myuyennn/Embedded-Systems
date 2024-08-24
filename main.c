// __________MAIN PROGRAM (.c)__________
/*
* MyUyen Nguyen, Samantha Oung
* 1901980, 1902685
* November 30, 2023
* Program displays frequency and temperature of the board
* in Celcius and Farenheit. The two on-board switches are used
* to change the frequency at which the board operates.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include "SSD2119_Display.h"
#include "tm4c1294ncpdt.h"
#include "lab3.h"
#include "Lab3_Inits.h"

volatile uint32_t ADC_value;

// TASK 1b
int main(void) {
  // Select system clock frequency preset
  enum frequency freq = PRESET2;        // 60 MHz
  PLL_Init(freq);        // Set system clock frequency to 60 MHz
  LED_Init();            // Initialize the 4 onboard LEDs (GPIO)
  ADCReadPot_Init();     // Initialize ADC0 to read from the potentiometer
  TimerADCTrigger_Init(); // Initialize Timer0A to trigger ADC0
  switches_J_Init();    // Initialize switches
  LCD_Init();
  
  while(1) {
    if (GPIODATA_J == 0x1) {
      freq = PRESET1; // 120 MHz
    } else if (GPIODATA_J == 0x2) {
      freq = PRESET3; // 12 MHz
    } else {
      freq = PRESET2; // 60 MHz
    }
   
    PLL_Init(freq);
    LCD_SetCursor(0,0);
    LCD_PrintFloat(ADC_value);
    
    char freq_array[320];
    sprintf(freq_array, "The current clock frequency is %d MHz.\r\n", freq);
    LCD_SetCursor(0,10);
    LCD_PrintString(freq_array);
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
