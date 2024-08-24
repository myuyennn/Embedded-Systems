// __________MAIN PROGRAM (.c)__________
/*
* MyUyen Nguyen, Samantha Oung
* 1901980, 1902685
* November 30, 2023
* Program recreates the traffic light controller on the LCD
* screen so all switches and lights are virtual
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <stdbool.h> 
#include "SSD2119_Display.h"
#include "tm4c1294ncpdt.h"
#include "lab2.h"
#include "Lab3_Inits.h"
#include "SSD2119_Touch.h"

int count2 = 0;
int go_to_warn = 0;

int main(void) {
  
  timer_init();
  LCD_Init();           // Initialize LCD display
  Touch_Init();         // Initialize Touch screen
  
  Traffic_State = off;
  
  int count = 0;
  count2 = 0;

  while(1) {
    
    // TouchReadX and TouchReadY are used to print the coordinates of touch screen
    printf("%lu,", Touch_ReadX());
    printf("%lu\n", Touch_ReadY());
    
    // SW1 - on/off
    LCD_DrawFilledRect(50, 50, 50, 50, Color4[9]);
    
    // SW2 - pedestrian
    LCD_DrawFilledRect(50, 135, 50, 50, Color4[13]);
    
    LCD_DrawFilledCircle(225, 55, 20, Color4[7]);
    LCD_DrawFilledCircle(225, 115, 20, Color4[7]);
    LCD_DrawFilledCircle(225, 175, 20, Color4[7]);
    
    count = traffic_Control(count);
  }
  return 0;
}

void timer_init()
{
  RCGCTIMER_0 |= 0x1;
  GPTMCTL_0 = 0x0;
  GPTMCFG_0 = 0x00000000;
  GPTMTAMR_0 = 0x2;
  GPTMTAILR_0 = 160000; // ~10ms (16,000,000 = ~1000ms)
  GPTMCTL_0 = 0x1;
}

bool pedestrian_SW() //PL1
{
  return ((Touch_ReadX() < 1470 && Touch_ReadX() > 1090) && (Touch_ReadY() < 1130 && Touch_ReadY() > 900)); // 0x2 (pressed) or 0 (not pressed)
}

bool system_SW() // PL0
{
  return ((Touch_ReadX() < 1470 && Touch_ReadX() > 1090) && (Touch_ReadY() < 1410 && Touch_ReadY() > 1260)); // 0x1(pressed) or 0 (not pressed)
}

// turn on LED connected to PL4
void GreenLED_on()
{
  LCD_DrawFilledCircle(225, 175, 20, Color4[10]);
}

void YellowLED_on()
{
  LCD_DrawFilledCircle(225, 115, 20, Color4[14]);
}

void RedLED_on()
{
  LCD_DrawFilledCircle(225, 55, 20, Color4[12]);
}

// turn off all LEDs
void LED_off()
{
  LCD_DrawFilledCircle(225, 55, 20, Color4[7]);
  LCD_DrawFilledCircle(225, 115, 20, Color4[7]);
  LCD_DrawFilledCircle(225, 175, 20, Color4[7]);
}

// enum Traffic_States {off, stop, warn, go} Traffic_State;

int traffic_Control(int count, int count2)
{
  switch(Traffic_State) 
  {   // Transitions
     case off:  // Initial transition
       if (system_SW()) 
       {
         GPTMICR_0 = 0x1; // clears flag
         while (count < 200)
         {
           if ((GPTMRIS_0 & 0x1) == 0x1)
           {
             count++;
             GPTMICR_0 = 0x1; // clears flag
           }
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
       if (system_SW()) 
       {
         GPTMICR_0 = 0x1; // clears flag
         while (count < 200)
         {
           if ((GPTMRIS_0 & 0x1) == 0x1)
           {
             count++;
             GPTMICR_0 = 0x1; // clears flag
           }
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
       if (system_SW()) 
       {
         GPTMICR_0 = 0x1; // clears flag
         while (count < 200)
         {
           if ((GPTMRIS_0 & 0x1) == 0x1)
           {
             count++;
             GPTMICR_0 = 0x1; // clears flag
           }
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
       if (system_SW()) 
       {
         GPTMICR_0 = 0x1; // clears flag
         while (count < 200)
         {
           if ((GPTMRIS_0 & 0x1) == 0x1)
           {
             count++;
             GPTMICR_0 = 0x1; // clears flag
           }
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
       RedLED_on();
       while (count < 500) 
       {
         if ((GPTMRIS_0 & 0x1) == 0x1)
         {
           count++;
           GPTMICR_0 = 0x1; // clears flag
         }
       }
       count = 0;
       break;
     
     case warn:
       go_to_warn = 0;
       YellowLED_on();
       while (count < 500) 
       {
         if ((GPTMRIS_0 & 0x1) == 0x1)
         {
           count++;
           GPTMICR_0 = 0x1; // clears flag
         }
       }
       count = 0;
       break;

     case go:
       GreenLED_on();
       count2 = 0;
       while (count < 500) 
       {
         if ((GPTMRIS_0 & 0x1) == 0x1 && pedestrian_SW())
         {
           count++;
           count2++;
           if (count2 == 200)
           {
             Traffic_State = warn;
             go_to_warn = 1;
             break;
           }
           GPTMICR_0 = 0x1; // clears flag
         }
         else if ((GPTMRIS_0 & 0x1) == 0x1)
         {
           count++;
           GPTMICR_0 = 0x1;
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
   return count;
}