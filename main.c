// __________MAIN PROGRAM (.c)__________

/*
* MyUyen Nguyen, Samantha Oung
* 1901980, 1902685
* November 16, 2023
* Program uses Bluetooth to accept inputs
* on keyboard (one character at a time), and display it back in the
* PuTTY terminal
*/

// STEP 0b: Include your header file here
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include "lab3.h"
#include "Lab3_Inits.h"

volatile uint32_t ADC_value;
float temp;
int print;

  int main(void) {
  // Select system clock frequency preset
  enum frequency freq = PRESET2;        // 60 MHz
  PLL_Init(freq);        // Set system clock frequency to 60 MHz
  UART_Init();
  
  while(1) {
    returnToSender();
  }
  return 0;
}

// Save user input, then assign it back
// to PuTTY
void returnToSender() 
{
  char userInput;
  
  // Do nothing while register is full
  while ((UARTFR_3 & 0x10) != 0) {}
  userInput = UARTDR_3;
  
  // Do nothing while transmit is busy
  while ((UARTFR_3 & 0x20) != 0) {}
  UARTDR_3 = userInput;
  if (userInput == '\r') {
    UARTDR_3 = '\n';
  }
}
