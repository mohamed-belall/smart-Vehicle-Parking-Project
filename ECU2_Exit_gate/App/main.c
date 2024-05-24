/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Belal
 * @brief          : Smart Private Parking Project (ECU2)
 ******************************************************************************
 */


#include "DIO.h"
#include "UART.h"
#include "SPI.h"
#include "lcd_driver.h"
#include "Timer.h"
#include "ECU2_TASKS.h"
#include "i2c_slave.h"


int main(void)
{
	ECU2_UART_init();
	ECU2_SPI_init();
	servo_Motor_Init();
	LCD_Init();

	/* --------------- init EXTI --------------- */
	init_Some_Pins();

	while(1)
	{
		Enter_Gate_ECU2();
	}


}
