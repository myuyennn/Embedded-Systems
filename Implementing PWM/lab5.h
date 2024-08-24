// __________lab5.h__________

/*
* MyUyen Nguyen, Samantha Oung
* 1901980 and 1902685
* December 7, 2023
* Header file defining Ports D, F, Timer0, 
* ADC, and PWM for Lab 5
* Also includes all functions calls
*/

#ifndef __HEADER1_H__
#define __HEADER1_H__

// REGISTER DEFINITIONS

// ADC0 SS3
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
#define ADCSSTSH3 (*((volatile uint32_t *)0x400380BC))

// GPIO Port D (Connect potentiometer)
#define GPIODEN_D (*((volatile uint32_t *)0x4005B51C))
#define GPIOAMSEL_D (*((volatile uint32_t *)0x4005B528)) 
#define GPIOAFSEL_D (*((volatile uint32_t *)0x4005B420))
#define GPIODIR_D (*((volatile uint32_t *)0x4005B400))

// GPIO Port F (On-board LEDs)
#define GPIODIR_F (*((volatile uint32_t *)0x4005D400))
#define GPIODEN_F (*((volatile uint32_t *)0x4005D51C))
#define GPIODATA_F (*((volatile uint32_t *)0x4005D3FC))
#define GPIOAFSEL_F (*((volatile uint32_t *)0x4005D420))
#define GPIOPCTL_F (*((volatile uint32_t *)0x4005D52C))

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

// PWM0 (Pulse Width Modulator)
#define RCGCPWM (*((volatile uint32_t *)0x400FE640))
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))
#define PWMCC (*((volatile uint32_t *)0x40028FC8))
#define PWM0CTL (*((volatile uint32_t *)0x40028040))
#define PWM0GENA (*((volatile uint32_t *)0x40028060))
#define PWM0GENB (*((volatile uint32_t *)0x40028064))
#define PWM0LOAD (*((volatile uint32_t *)0x40028050))
#define PWM0CMPA (*((volatile uint32_t *)0x40028058))
#define PWM0CMPB (*((volatile uint32_t *)0x4002805C))
#define PWMENABLE (*((volatile uint32_t *)0x40028008))

#endif //__HEADER1_H__
