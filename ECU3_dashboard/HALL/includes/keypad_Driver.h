/*
 * keypad_Driver.h
 *
 * Created: 8/29/2023 10:29:40 AM
 *  Author: mohamed belal
 */


#ifndef KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_H_

#include "STM32F103C6_GPIO_Drivers.h"
#include "STM32F103x6.h"

#include <string.h>

#define small_keypad
//#define calculator_keypad

#define KEYPAD_PORT     GPIOB

//keypad Information
#define R0				GPIO_PIN_1
#define R1				GPIO_PIN_2
#define R2				GPIO_PIN_3
#define R3				GPIO_PIN_4
#define C0				GPIO_PIN_5
#define C1				GPIO_PIN_6
#define C2				GPIO_PIN_7

#ifdef calculator_keypad
#define C3              GPIO_PIN_8
#endif




//keypad functions and global ariable

void keypad_Init();
char keypad_GetKey();



#endif /* KEYPAD_DRIVER_H_ */
