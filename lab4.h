// __________lab4.h__________

/*
* MyUyen Nguyen, Samantha Oung
* 1901980 and 1902685
* November 30, 2023
* Header file defining PortsD, K, M, N, P, and Q to connect
* LCD screen for Lab 4
* Also includes all functions calls
*/

#ifndef __HEADER1_H__
#define __HEADER1_H__

// REGISTER DEFINITIONS
// TASK 1
#define RCGCGPIO (*((volatile uint32_t *)0x400FE608))

// Port D
#define GPIODIR_D (*((volatile uint32_t *)0x4005B400))
#define GPIODEN_D (*((volatile uint32_t *)0x4005B51C))
#define GPIODATA_D (*((volatile uint32_t *)0x4005B3FC))
#define GPIOAFSEL_D (*((volatile uint32_t *)0x4005B420))

// Port K
#define GPIODIR_K (*((volatile uint32_t *)0x40061400))
#define GPIODEN_K (*((volatile uint32_t *)0x4006151C))
#define GPIODATA_K (*((volatile uint32_t *)0x400613FC))
#define GPIOAFSEL_K (*((volatile uint32_t *)0x40061420))

// Port M 
#define GPIODIR_M (*((volatile uint32_t *)0x40063400))
#define GPIODEN_M (*((volatile uint32_t *)0x4006351C))
#define GPIODATA_M (*((volatile uint32_t *)0x400633FC))
#define GPIOAFSEL_M (*((volatile uint32_t *)0x40063420))

// Port N 
#define GPIODIR_N (*((volatile uint32_t *)0x40064400))
#define GPIODEN_N (*((volatile uint32_t *)0x4006451C))
#define GPIODATA_N (*((volatile uint32_t *)0x400643FC))
#define GPIOAFSEL_N (*((volatile uint32_t *)0x40064420))

// Port P
#define GPIODIR_P (*((volatile uint32_t *)0x40065400))
#define GPIODEN_P (*((volatile uint32_t *)0x4006551C))
#define GPIODATA_P (*((volatile uint32_t *)0x400653FC))
#define GPIOAFSEL_P (*((volatile uint32_t *)0x40065420))

// Port Q
#define GPIODIR_Q (*((volatile uint32_t *)0x40066400))
#define GPIODEN_Q (*((volatile uint32_t *)0x4006651C))
#define GPIODATA_Q (*((volatile uint32_t *)0x400663FC))
#define GPIOAFSEL_Q (*((volatile uint32_t *)0x40066420))

#endif //__HEADER1_H__
