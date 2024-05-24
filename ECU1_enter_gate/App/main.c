/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Belal
 * @brief          : Smart Private Parking Project (ECU1)
 ******************************************************************************
 */


#include "DIO.h"
#include "UART.h"
#include "SPI.h"
#include "lcd_driver.h"
#include "Timer.h"
#include "Servo_Motor.h"
#include "I2C.h"
#include "i2c_slave.h"



int main(void)
{
	ECU1_UART_init();
	ECU1_SPI_init();
	servo_Motor_Init();
	LCD_Init();

	/* --------------- init green,red pin & Buzzer & EXTI --------------- */
	init_Some_Pins();


	/* ======== welcome message ========= */
	LCD_Clear_Screen();
	LCD_gotoXY(1, 3);
	LCD_Send_String("Welcome in");
	LCD_gotoXY(2, 1);
	LCD_Send_String("Mohamed Belal's");
	LCD_gotoXY(3, 2);
	LCD_Send_String("Smart Private");
	LCD_gotoXY(4, 5);
	LCD_Send_String("Parking");
	_delay_ms(300);

	while(1)
	{
		Enter_Gate_ECU1();
	}


}


