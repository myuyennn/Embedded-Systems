// __________MAIN PROGRAM (.c)__________
/*
* MyUyen Nguyen, Samantha Oung
* 1901980, 1902685
* November 30, 2023
* Program displays frequency and temperature of the board
* in Celcius and Farenheit. The two on-board switches are replaced with
* virtual switches on the LCD screen used to change the frequency at 
* which the board operates.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include "SSD2119_Display.h"
#include "tm4c1294ncpdt.h"
#include "lab3.h"
#include "Lab3_Inits.h"
#include "SSD2119_Touch.h"

volatile uint32_t ADC_value;

int main(void) {
  enum frequency freq = PRESET2;        // 60 MHz
  PLL_Init(freq);        // Set system clock frequency to 60 MHz
  LED_Init();            // Initialize the 4 onboard LEDs (GPIO)
  ADCReadPot_Init();     // Initialize ADC0 to read from the potentiometer
  TimerADCTrigger_Init(); // Initialize Timer0A to trigger ADC0
  switches_J_Init();    // Initialize switches
  LCD_Init();           // Initialize LCD display
  Touch_Init();         // Initialize Touch screen

  while(1) {
    
    // TouchReadX and TouchReadY are used to print the coordinates of touch screen
    printf("%lu,", Touch_ReadX());
    printf("%lu\n", Touch_ReadY());
    
    if ((Touch_ReadX() < 1500 && Touch_ReadX() > 1190) && (Touch_ReadY() < 1250 && Touch_ReadY() > 900)) { 
      freq = PRESET1; // 120 MHz
    } else if ((Touch_ReadX() < 2050 && Touch_ReadX() > 1820) && (Touch_ReadY() < 1250 && Touch_ReadY() > 900)) {
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
    
    // SW1 - 120 MHz
    LCD_DrawFilledRect(60, 100, 60, 60, Color4[9]);
    
    // SW2 - 12 MHz
    LCD_DrawFilledRect(200, 100, 60, 60, Color4[13]);
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