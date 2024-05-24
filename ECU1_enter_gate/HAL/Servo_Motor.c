/*
 * Servo_Motor.c
 *
 *  Created on: May 15, 2024
 *      Author: moham
 */

#include "Servo_Motor.h"



void servo_Motor_Init()
{
	TIMER0_Config_t Servo_PWM_CFG;
	Servo_PWM_CFG.Timer_Mode = Timer0_Mode_PWM_NONINVERTING;
	Servo_PWM_CFG.Timer_Clock_Source = Timer_Clock_Source_PRESCALING_1024;
	Servo_PWM_CFG.IRQ_Enable = IRQ_Enable_NON;
	Servo_PWM_CFG.P_IRQ_CallBack = 0;

	MCAL_Timer0_Init(&Servo_PWM_CFG);
}

void Open_Gate()
{
	// 0 => 0
	// 10 | 9 => +90

	MCAL_Timer0_PWM_DutyCycle(9);

}
void Close_Gate()
{
	// 0 => 0
	// 10 | 9 => +90

	MCAL_Timer0_PWM_DutyCycle(0);
}
