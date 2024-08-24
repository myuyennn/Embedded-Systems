// __________lab2.h__________

/*
* MyUyen Nguyen, Samantha Oung
* 1901980 and 1902685
* October 18, 2023
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

// TIMER 0
#define RCGCTIMER (*((volatile uint32_t *)0x400FE604))
#define GPTMCTL_0 (*((volatile uint32_t *)0x4003000C))
#define GPTMCFG_0 (*((volatile uint32_t *)0x40030000))
#define GPTMTAMR_0 (*((volatile uint32_t *)0x40030004))
#define GPTMTAILR_0 (*((volatile uint32_t *)0x40030028))
#define GPTMRIS_0 (*((volatile uint32_t *)0x4003001C))
#define GPTMICR_0 (*((volatile uint32_t *)0x40030024))

// TIMER 1
#define GPTMCTL_1 (*((volatile uint32_t *)0x4003100C))
#define GPTMCFG_1 (*((volatile uint32_t *)0x40031000))
#define GPTMTAMR_1 (*((volatile uint32_t *)0x40031004))
#define GPTMTAILR_1 (*((volatile uint32_t *)0x40031028))
#define GPTMRIS_1 (*((volatile uint32_t *)0x4003101C))
#define GPTMICR_1 (*((volatile uint32_t *)0x40031024))

// Interrupts
#define GPTMIMR_0 (*((volatile uint32_t *)0x40030018))
#define GPTMIMR_1 (*((volatile uint32_t *)0x40031018))
#define EN0_0_F (*((volatile uint32_t *)0xE000E100))
#define EN1_J_L (*((volatile uint32_t *)0xE000E104))
#define EN2_N (*((volatile uint32_t *)0xE000E108))

// Interrupts (Port J)
#define GPIOIS_J (*((volatile uint32_t *)0x40060404))
#define GPIOIBE_J (*((volatile uint32_t *)0x40060408))
#define GPIOIEV_J (*((volatile uint32_t *)0x4006040C))
#define GPIOIM_J (*((volatile uint32_t *)0x40060410))

// Interrupts (Port N)
#define GPIOIS_N (*((volatile uint32_t *)0x40064404))
#define GPIOIBE_N (*((volatile uint32_t *)0x40064408))
#define GPIOIEV_N (*((volatile uint32_t *)0x4006440C))
#define GPIOIM_N (*((volatile uint32_t *)0x40064410))

// Interrupts (Port F)
#define GPIOIS_F (*((volatile uint32_t *)0x4005D404))
#define GPIOIBE_F (*((volatile uint32_t *)0x4005D408))
#define GPIOIEV_F (*((volatile uint32_t *)0x4005D40C))
#define GPIOIM_F (*((volatile uint32_t *)0x4005D410))

// Interrupts (Port L)
#define GPIOIS_L (*((volatile uint32_t *)0x40062404))
#define GPIOIBE_L (*((volatile uint32_t *)0x40062408))
#define GPIOIEV_L (*((volatile uint32_t *)0x4006240C))
#define GPIOIM_L (*((volatile uint32_t *)0x40062410))

// Defining Priorities for Timers and Ports
#define PRI4 (*((volatile uint32_t *)0xE000E410))
#define PRI5 (*((volatile uint32_t *)0xE000E414))
#define PRI7 (*((volatile uint32_t *)0xE000E41C))
#define PRI12 (*((volatile uint32_t *)0xE000E430))
#define PRI13 (*((volatile uint32_t *)0xE000E434)
#define PRI18 (*((volatile uint32_t *)0xE000E448))


#define GPIORIS_J (*((volatile uint32_t *)0x40060414))
#define GPIORIS_N (*((volatile uint32_t *)0x40064414))
#define GPIORIS_F (*((volatile uint32_t *)0x4005D414))
#define GPIORIS_L (*((volatile uint32_t *)0x40062414))

// Clear Interrupts
#define GPIOICR_J (*((volatile uint32_t *)0x4006041C))
#define GPIOICR_N (*((volatile uint32_t *)0x4006441C))
#define GPIOICR_L (*((volatile uint32_t *)0x4006241C))

// TASK 1A
void timer_init();
void port_F_N_init();
int light_Sequence();

// TASK 1B
void port_J_N_init();
void check_SW();

// TASK 2
// To set up and change the data for GPIO (LEDs and Switches)
// Port L
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define GPIOAMSEL_L (*((volatile uint32_t *)0x40062528))
#define GPIODIR_L (*((volatile uint32_t *)0x40062400))
#define GPIODEN_L (*((volatile uint32_t *)0x4006251C))
#define GPIOAFSEL_L (*((volatile uint32_t *)0x40062420))
#define GPIODATA_L (*((volatile uint32_t *)0x400623FC))

void SW_LED_init();

enum Traffic_States {off, stop, warn, go} Traffic_State;
void traffic_Control();

#endif //__HEADER1_H__
