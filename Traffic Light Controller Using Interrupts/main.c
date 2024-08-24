/*
* MyUyen Nguyen, Samantha Oung
* 1901980, 1902685
* November 2, 2023
* Program implements a traffic light controller with
* an on and off button, and pedestrian button using
* timer interrupts to handle all timing issues
*/

// Task 2c
// library and header file
#include <stdint.h>
#include "lab2.h"

int count = 0;
int count2 = 0;
int go_to_warn = 0;

int main()
{ 
  timer_init();
  SW_LED_init();
  Traffic_State = off;
  
  count = 0;
  count2 = 0;
  
  while(1) 
  {
    traffic_Control();
  }
  return 0;
}

void timer_init()
{
  RCGCTIMER |= 0x3;
  
  // Timer0A
  GPTMCTL_0 = 0x0;
  GPTMCFG_0 = 0x00000000;
  GPTMTAMR_0 = 0x2;
  GPTMTAILR_0 = 160000; // ~10ms (16,000,000 = ~1000ms)
  GPTMIMR_0 = 0x1; // Jumps to handler function when timer flag is raised 
  EN0_0_F = 1 << 19; // 10 1000 0000 0000 0000 0000
  GPTMCTL_0 = 0x1;
}

void SW_LED_init()
{
  volatile unsigned short delay = 0;
  RCGCGPIO |= 0x400; // Enable Port L Gating Clock (Bit 10)
  delay++;
  delay++;
  
  GPIOAMSEL_L &= ~0x1F; // Disable PL0 - PL4 analog function
  GPIOAFSEL_L &= ~0x1F; // Select PL0 - PL4 regular port function
  GPIODIR_L = 0x1C; // Set PL2 - PL4 to output direction (0 - input, 1 - output)
  GPIODEN_L |= 0x1F; // Enable PL0 - PL4 digital function
  
}

unsigned long pedestrian_SW() //PL1
{
  return (GPIODATA_L & 0x2); // 0x2 (pressed) or 0 (not pressed)
}

unsigned long system_SW() // PL0
{
  return (GPIODATA_L & 0x1); // 0x1(pressed) or 0 (not pressed)
}

// turn on LED connected to PL4
void GreenLED_on()
{
  GPIODATA_L = 0x10; // PL4
}

void YellowLED_on()
{
  GPIODATA_L = 0x8; // PL3
}

void RedLED_on()
{
  GPIODATA_L = 0x4; // PL2
}

// turn off all LEDs
void LED_off()
{
  GPIODATA_L &= 0x0;
}

// Timer Handler to keep track of button presses
// and LEDs timing
void Timer0A_Handler() {
  GPTMICR_0 = 0x1; // clears flag
  count++;
  if (pedestrian_SW() == 0x2)
  {
    count++;
    count2++;
  }
}

void traffic_Control()
{
  switch(Traffic_State) 
  {   // Transitions
     case off:  // Initial transition
       if (system_SW() == 0x1) 
       { 
         GPTMICR_0 = 0x1; // clears flag
         while (count < 200){
          GPTMICR_0 = 0x1;
         }    
         Traffic_State = stop;
         count = 0;
       } 
       else 
       {
         Traffic_State = off;
         count = 0;
       }
       break; 
     
     case stop:  // Initial transition
       if (system_SW() == 0x1) 
       {
         GPTMICR_0 = 0x1; // clears flag
         while (count < 200){
          GPTMICR_0 = 0x1;
         } 
         Traffic_State = off;
         count = 0;
       } 
       else 
       {
         Traffic_State = go;
         count = 0;
       }
       break;
       
     case warn:  // Initial transition
       if (system_SW() == 0x1) 
       {
         GPTMICR_0 = 0x1; // clears flag
         while (count < 200){
          GPTMICR_0 = 0x1;
         } 
         Traffic_State = off;
         count = 0;
       }
       else if (go_to_warn == 1)
       {
         Traffic_State = warn;
       }
       else 
       {
         Traffic_State = stop;
         count = 0;
       }
       break;
       
     case go:  // Initial transition
       if (system_SW() == 0x1) 
       {
         GPTMICR_0 = 0x1; // clears flag
         while (count < 200){
          GPTMICR_0 = 0x1;
         } 
         Traffic_State = off;
         count = 0;
       } 
       else 
       {
         Traffic_State = stop;
         count = 0;
       }
       break;
        
     default:
        Traffic_State = off;
        count = 0;
        break;
  } // Transitions

  switch(Traffic_State) 
  {   // State actions
     case off:
       LED_off();
       break;

     case stop:
       GPTMICR_0 = 0x1; // clears flag
       RedLED_on();
       while (count < 500)
       {
         GPTMICR_0 = 0x1;
       }
       count = 0;
       break;
     
     case warn:
       GPTMICR_0 = 0x1; // clears flag
       go_to_warn = 0;
       YellowLED_on();
       
       while (count < 500)
       {
         GPTMICR_0 = 0x1;
       }
       count = 0;
       break;

     case go:
       GPTMICR_0 = 0x1; // clears flag
       GreenLED_on();
       count2 = 0;
       
       
       while (count < 500)
       {
         GPTMICR_0 = 0x1;
         if (count2 >= 200)
         { 
           Traffic_State = warn;
           go_to_warn = 1;
         }
       }
       
       count = 0;
       count2 = 0;
       break;

     default:
       LED_off();
       count = 0;
       break;
   } // State actions
}
