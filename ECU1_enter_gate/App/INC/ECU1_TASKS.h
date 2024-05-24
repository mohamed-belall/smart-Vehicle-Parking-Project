/*
 * ECU1_TASKS.h
 *
 *  Author: mohamed belal
 */

#ifndef INC_ECU1_TASKS_H_
#define INC_ECU1_TASKS_H_
#include "lcd_driver.h"
#include "UART.h"
#include "SPI.h"


/* ==========================global macro ========================== */
//#define MCU_Act_As_Master
#define MCU_ACT_As_Slave

#define ECU1_EXTI_PORT	DIO_PORTB
#define ECU1_EXTI_PIN	DIO_PIN2

#define GreenLED_PORT	DIO_PORTC
#define GreenLED_PIN	DIO_PIN1

#define RedLED_PORT		DIO_PORTC
#define RedLED_PIN		DIO_PIN2

#define Buzzer_PORT		DIO_PORTC
#define Buzzer_PIN		DIO_PIN0

/* ========================= global variables ====================== */
//uint8_t data;
//uint8_t *Uart_Buffer_ID;
uint8_t *Entered_ID;
unsigned char ID_State;


void init_Some_Pins();
void ECU1_SPI_init();
void ECU1_UART_init();

void Enter_Gate_ECU1();

void spi_Send_ID_to_ECU3();

void Correct_ID();
void Wrong_ID();
void Play_Buzzer();


#endif /* INC_ECU1_TASKS_H_ */
