// __________lab3.h__________

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

// TASK 1A (ADC0 SS3)
#define RCGCADC (*((volatile uint32_t *)0x400FE638))
#define ADCCC_0 (*((volatile uint32_t *)0x40038FC8))
#define ADCACTSS_0 (*((volatile uint32_t *)0x40038000))
#define ADCEMUX_0 (*((volatile uint32_t *)0x40038014))
#define ADCSSMUX3_0 (*((volatile uint32_t *)0x400380A0))
#define ADCSSEMUX3_0 (*((volatile uint32_t *)0x400380B8))
#define ADCSSCTL3_0 (*((volatile uint32_t *)0x400380A4))
#define ADCIM_0 (*((volatile uint32_t *)0x40038008))
#define ADCRIS_0 (*((volatile uint32_t *)0x40038004))
#define GPTMADCEV (*((volatile uint32_t *)0x40030070))
#define ADCISC_0 (*((volatile uint32_t *)0x4003800C))
#define ADCSSFIFO3_0 (*((volatile uint32_t *)0x400380A8))

// PD6 --> GPIO Port D
#define GPIODEN_D (*((volatile uint32_t *)0x4005B51C))
#define GPIOAMSEL_D (*((volatile uint32_t *)0x4005B528))
#define GPIOAFSEL_D (*((volatile uint32_t *)0x4005B420))

// Port PE3
#define GPIODEN_E (*((volatile uint32_t *)0x4005C51C))
#define GPIOAMSEL_E (*((volatile uint32_t *)0x4005C528))
#define GPIOAFSEL_E (*((volatile uint32_t *)0x4005C420))

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
#define RCGCTIMER_0 (*((volatile uint32_t *)0x400FE604))
#define GPTMCTL_0 (*((volatile uint32_t *)0x4003000C))
#define GPTMCFG_0 (*((volatile uint32_t *)0x40030000))
#define GPTMTAMR_0 (*((volatile uint32_t *)0x40030004))
#define GPTMTAILR_0 (*((volatile uint32_t *)0x40030028))
#define GPTMRIS_0 (*((volatile uint32_t *)0x4003001C))
#define GPTMICR_0 (*((volatile uint32_t *)0x40030024))

// Interrupts
#define GPTMIMR_0 (*((volatile uint32_t *)0x40030018))
#define GPTMIMR_1 (*((volatile uint32_t *)0x40031018))
#define EN0 (*((volatile uint32_t *)0xE000E100))    // Timer 0A, ADC0 SS3
#define EN1 (*((volatile uint32_t *)0xE000E104))
#define EN2 (*((volatile uint32_t *)0xE000E108))

// Defining Priorities for Timers and Ports
#define PRI4 (*((volatile uint32_t *)0xE000E410))
#define PRI5 (*((volatile uint32_t *)0xE000E414))
#define PRI7 (*((volatile uint32_t *)0xE000E41C))
#define PRI12 (*((volatile uint32_t *)0xE000E430))
#define PRI13 (*((volatile uint32_t *)0xE000E434)
#define PRI18 (*((volatile uint32_t *)0xE000E448))

// Task 1b
#define ADCSSTSH3 (*((volatile uint32_t *)0x400380BC))
void switches_J_Init();

#endif //__HEADER1_H__