/*
 * seven_segmnet.c
 *
 *  Created on: May 2, 2024
 *      Author: Mohamed Belal
 */

#include "seven_segment.h"


void HAL_SEVEN_SEG_init(void)
{
	GPIO_PinConfig_t PinCfg;


	PinCfg.GPIO_PinNumber = SEVEN_SEG_PIN1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(SEVEN_SEG_PORT, &PinCfg);


	PinCfg.GPIO_PinNumber = SEVEN_SEG_PIN2;
	MCAL_GPIO_Init(SEVEN_SEG_PORT, &PinCfg);


	PinCfg.GPIO_PinNumber = SEVEN_SEG_PIN3;
	MCAL_GPIO_Init(SEVEN_SEG_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = SEVEN_SEG_PIN4;
	MCAL_GPIO_Init(SEVEN_SEG_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = SEVEN_SEG_PIN5;
	MCAL_GPIO_Init(SEVEN_SEG_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = SEVEN_SEG_PIN6;
	MCAL_GPIO_Init(SEVEN_SEG_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = SEVEN_SEG_PIN7;
	MCAL_GPIO_Init(SEVEN_SEG_PORT, &PinCfg);
}


void HAL_SEVEN_SEG_Write(uint8_t number)
{
	if(SEVEN_SEG_TYPE == SEVEN_SEG_COMMON_ANODE)
	{
		MCAL_GPIO_WritePort(SEVEN_SEG_PORT, seg_CAnodeVal[number]<<FIRST_PIN_number);
		//MCAL_GPIO_WritePin(GPIOx, PinNumber, value)
	}else if(SEVEN_SEG_TYPE == SEVEN_SEG_COMMON_CATHODE)
	{
		MCAL_GPIO_WritePort(SEVEN_SEG_PORT, seg_CCathodeVal[number]<<FIRST_PIN_number);
	}
}
