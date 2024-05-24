/*
 * seven_segment.h
 *
 *  Created on: May 2, 2024
 *      Author: Mohamed Belal
 */

#ifndef INCLUDES_SEVEN_SEGMENT_H_
#define INCLUDES_SEVEN_SEGMENT_H_
#include "STM32F103C6_GPIO_Drivers.h"

/******************************************************************************
                      7 Segment Type Configuration
*******************************************************************************/
#define SEVEN_SEG_TYPE				SEVEN_SEG_COMMON_CATHODE
#define FIRST_PIN_number			9

/******************************************************************************
                      7 Segment PINs Configuration
*******************************************************************************/
#define SEVEN_SEG_PORT		GPIOA
#define SEVEN_SEG_PIN1		GPIO_PIN_9
#define SEVEN_SEG_PIN2		GPIO_PIN_10
#define SEVEN_SEG_PIN3		GPIO_PIN_11
#define SEVEN_SEG_PIN4		GPIO_PIN_12
#define SEVEN_SEG_PIN5		GPIO_PIN_13
#define SEVEN_SEG_PIN6		GPIO_PIN_14
#define SEVEN_SEG_PIN7		GPIO_PIN_15





static uint8_t seg_CAnodeVal[10]   = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
static uint8_t seg_CCathodeVal[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};



#define SEVEN_SEG_COMMON_ANODE 		0
#define SEVEN_SEG_COMMON_CATHODE	1




/*
 * =========================================================================================================
 * 									APIs supported by "MCAL USART driver"
 * =========================================================================================================
 * */
void HAL_SEVEN_SEG_init(void);
void HAL_SEVEN_SEG_Write(uint8_t number);

#endif /* INCLUDES_SEVEN_SEGMENT_H_ */
