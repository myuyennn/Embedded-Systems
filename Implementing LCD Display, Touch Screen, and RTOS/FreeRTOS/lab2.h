// __________lab2.h__________

/*
* MyUyen Nguyen, Samantha Oung
* 1901980 and 1902685
* November 2, 2023
* Header file defining Ports F, N, J, L, and Timer0 for Lab 2
* Also includes all functions calls
*/

#ifndef __HEADER1_H__
#define __HEADER1_H__

// REGISTER DEFINITIONS
// TASK 1

// To set up and change the data for switches and LEDs on TIVA board
// Port F (LEDs)
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define GPIODIR_F (*((volatile uint32_t *)0x4005D400))
#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC))

// Port N (LEDs)
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))

// Port J (Switches)
#define GPIODIR_J (*((volatile uint32_t *)0x40060400))
#define GPIODEN_J (*((volatile uint32_t *)0x4006051C))
#define GPIODATA_J (*((volatile uint32_t *)0x400603FC))
#define GPIOPUR_J (*((volatile uint32_t *)0x40060510))

// TIMER
#define RCGCTIMER_0 (*((volatile uint32_t *)0x400FE604))
#define GPTMCTL_0 (*((volatile uint32_t *)0x4003000C))
#define GPTMCFG_0 (*((volatile uint32_t *)0x40030000))
#define GPTMTAMR_0 (*((volatile uint32_t *)0x40030004))
#define GPTMTAILR_0 (*((volatile uint32_t *)0x40030028))
#define GPTMRIS_0 (*((volatile uint32_t *)0x4003001C))
#define GPTMICR_0 (*((volatile uint32_t *)0x40030024))

// TASK 1A
void timer_init();
void port_F_N_init();
int light_Sequence();

// TASK 1B
bool pedestrian_SW();
bool system_SW();

// TASK 2
// To set up and change the data for GPIO (LEDs and Switches)
// Port L
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define GPIOAMSEL_L (*((volatile uint32_t *)0x40062528))
#define GPIODIR_L (*((volatile uint32_t *)0x40062400))
#define GPIODEN_L (*((volatile uint32_t *)0x4006251C))
#define GPIOAFSEL_L (*((volatile uint32_t *)0x40062420))
#define GPIODATA_L (*((volatile uint32_t *)0x400623FC))

enum Traffic_States {off, stop, warn, go} Traffic_State;
int traffic_Control();

#endif //__HEADER1_H__
