/*
 * ECU1_TASKS.c
 *
 *  Author: mohamed belal
 */
#include "ECU2_TASKS.h"
#include "Servo_Motor.h"


void Enter_Gate_ECU2()
{


	Entered_ID = MCAL_UART_Receive_String();

	spi_Send_ID_to_ECU3();

	if(ID_State == '1')
	{
		Correct_ID();
	}else
	{
		Wrong_ID();
	}
}

void spi_Send_ID_to_ECU3()
{

	DIO_SetPinValue(ECU2_EXTI_PORT, ECU2_EXTI_PIN, DIO_PIN_HIGH);
	MCAL_SPI_Send_String(Entered_ID);
	DIO_SetPinValue(ECU2_EXTI_PORT, ECU2_EXTI_PIN, DIO_PIN_LOW);

	MCAL_SPI_Receive_Data(&ID_State);
}

void Correct_ID()
{

	Open_Gate();
	_delay_ms(200);
	while(READBIT(PINB , 0)); /* ====== wait until car leave its place and enter the parking (PIR Sensor) ====== */
	Close_Gate();
}

void Wrong_ID()
{
//	DIO_SetPinValue(RedLED_PORT, RedLED_PIN, DIO_PIN_HIGH);
//
//	LCD_Clear_Screen();
//	LCD_gotoXY(3, 3);
//	LCD_Send_String("Wrong ID");
//	_delay_ms(200);
//	DIO_SetPinValue(RedLED_PORT, RedLED_PIN, DIO_PIN_LOW);
}



void init_Some_Pins()
{
	/* --------------- ECU1 EXTI Init --------------- */
	DIO_SetPinDirection(ECU2_EXTI_PORT, ECU2_EXTI_PIN, DIO_PIN_OUTPUT);


	/* --------------- Correct & Wrong ID LED Init --------------- */
	DIO_SetPinDirection(GreenLED_PORT, GreenLED_PIN, DIO_PIN_OUTPUT); // init green led for correct ID
	DIO_SetPinDirection(RedLED_PORT, RedLED_PIN, DIO_PIN_OUTPUT); // init Red   led for Wrong   ID

	/* --------------- Init Buzzer for Wrong ID  --------------- */
	DIO_SetPinDirection(Buzzer_PORT, Buzzer_PIN, DIO_PIN_OUTPUT); // init Bezzer	for Wrong   ID

	/* --------------- Init PIR Sensor  --------------- */
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN0, DIO_PIN_INPUT); // init Bezzer	for Wrong   ID
}


void ECU2_UART_init()
{
	/* --------------- UART configuration (init RFID Cart) --------------- */
	UART_Config_t ECU2_uart_cfg;
	ECU2_uart_cfg.UART_MODE = UART_MODE_Receiver;
	ECU2_uart_cfg.UART_BaudRate = UART_BaudRate_9600;
	ECU2_uart_cfg.UART_DATA_SIZE = UART_DATA_SIZE_8bit;
	ECU2_uart_cfg.UART_Parity_Mode = UART_Parity_Mode_disable;
	ECU2_uart_cfg.UART_STOP_Bit = UART_STOP_Bit_1BIT;
	ECU2_uart_cfg.UART_IRQ = UART_IRQ_disable;
	ECU2_uart_cfg.P_IRQ_CallBack = 0;

	MCAL_UART_Init(&ECU2_uart_cfg);
}
void ECU2_SPI_init()
{
	/* --------------- SPI configuration --------------- */
	SPI_Config_t ECU2_spi_cfg;

	ECU2_spi_cfg.SPI_prescaler = SPI_prescaler_DOUBLE_SPEED_8;
	ECU2_spi_cfg.SPI_Data_Order = SPI_Data_Order_MSB;
	ECU2_spi_cfg.SPI_CLK_Phase = SPI_CLK_Phase_Trailing;
	ECU2_spi_cfg.SPI_CLK_Polarity = SPI_CLK_Polarity_idle_high;
	ECU2_spi_cfg.SPI_Double_Speed = SPI_Double_Speed_Enable;



#ifdef MCU_ACT_As_Master
	ECU2_spi_cfg.SPI_MODE = SPI_MODE_Master;
	ECU2_spi_cfg.SPI_IRQ = SPI_IRQ_Disable;
	ECU2_spi_cfg.P_IRQ_CallBack = 0;
#endif

#ifdef MCU_ACT_As_Slave
	ECU2_spi_cfg.SPI_MODE = SPI_MODE_Slave;
	ECU2_spi_cfg.SPI_IRQ = SPI_IRQ_Disable;
	ECU2_spi_cfg.P_IRQ_CallBack = 0;
#endif

	MCAL_SPI_Init(&ECU2_spi_cfg);

	// set idle HIGH (active HIGH)
	//		DIO_SetPinValue(PORTB, DIO_PIN4, DIO_PIN_HIGH);
}



