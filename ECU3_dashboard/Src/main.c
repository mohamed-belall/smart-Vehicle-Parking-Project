/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mohamed Belal
 * @brief          : Smart Private Parking Project (ECU3)
 ******************************************************************************
 */


#include "STM32F103C6_GPIO_Drivers.h"
#include "STM32F103C6_SPI_Driver.h"
#include "STM32F103C6_EXTI_Driver.h"
#include "STM32F103C6_RCC_Drivers.h"
#include "lcd_driver.h"
#include "seven_segment.h"
#include "keypad_Driver.h"
#include "Admin_Tasks.h"
#include "STM32F103C6_I2C_Driver.h"

/*
 ******************************************************************************
 =========================== global variable ==================================
 ******************************************************************************
 */
 uint8_t AdminPassword_flag =0;
 uint8_t flag2 =0;
 uint8_t available_SlotsNumber = 3;
 char IDs[3][5] = {"0000" ,"0000", "0000"};
//spi
 unsigned char ch;
 uint8_t receivedID[5]={0};


 /******************************************************************************
  * ECUs PORT PIN Constants
  *******************************************************************************/
 // ECU1 => Entrance Gate ECU
 #define ECU1_PORT		GPIOB
 #define ECU1_SS_PIN		GPIO_PIN_12
 #define ECU1_EXTI_PIN	GPIO_PIN_10

 // ECU2 => Exit Gate ECU
 #define ECU2_PORT		GPIOB
 #define ECU2_SS_PIN		GPIO_PIN_11
 #define ECU2_EXTI_PIN	GPIO_PIN_9

 #define ID_Size			4

 #define MCU_Act_As_Master
 //#define MCU_Act_As_Slave



 /*
  * ========================================================================
  * 					initialization Functions
  * ========================================================================
  * */
 void ECUs_EXTI_init(void);
 void ECU3_SPI_Init(void);



 /*
  * ========================================================================
  * 					verifying enter&exit cars functions
  * ========================================================================
  * */
 void ECU1_start_Verifying_Entered_Car();
 void ECU2_start_Verifying_Exit_Car(void);


void Clock_Init(void)
{

	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();
	RCC_GPIOC_CLK_EN();

}



int main(void)
{
	Clock_Init();
	keypad_Init();
	LCD_Init();
	HAL_SEVEN_SEG_init();
	ECUs_EXTI_init();
	ECU3_SPI_Init();
	HAL_SEVEN_SEG_Write(available_SlotsNumber);
	while(1)
	{
		if(!AdminPassword_flag)
			Check_Admin_Password(&AdminPassword_flag);
		admin_Tasks(IDs);


	}
}




void ECUs_EXTI_init(void)
{
	EXTI_PinConfig_t EXTI_cfg;


	// init ECU1 => PB10 => ECU1_PORT => ECU1_EXTI_PIN
	// EXTI10PB10 | EXTI15_10_IRQHandler
	EXTI_cfg.EXTI_PINS = EXTI10PB10;
	EXTI_cfg.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_cfg.P_IRQ_CallBack = ECU1_start_Verifying_Entered_Car;
	EXTI_cfg.IRQ_EN = EXTI_IRQ_Enable;
	MCAL_EXTI_GPIO_Init(&EXTI_cfg);


	// init ECU2 => PB9 => ECU2_PORT => ECU2_EXTI_PIN
	// EXTI9PB9 | EXTI9_5_IRQHandler
	EXTI_cfg.EXTI_PINS = EXTI9PB9;
	EXTI_cfg.Trigger_Case = EXTI_Trigger_Rising;
	EXTI_cfg.P_IRQ_CallBack = ECU2_start_Verifying_Exit_Car;
	EXTI_cfg.IRQ_EN = EXTI_IRQ_Enable;
	MCAL_EXTI_GPIO_Init(&EXTI_cfg);
}
void ECU3_SPI_Init(void)
{
	/*
	 * PB13  ====> SPI2_SCK
	 * PB14  ====> SPI2_MISO
	 * PB15  ====> SPI2_MOSI
	 */
	SPI_Config_t ECU3_SPI_cfg;

	ECU3_SPI_cfg.CLKPhase = SPI_CLKPhase_2ndEdge_First_Data_Capture_Edge;
	ECU3_SPI_cfg.CLKPolarity = SPI_CLKPolarity_1_when_idle;
	ECU3_SPI_cfg.Communication_Mode = SPI_Direction_2LINE;
	ECU3_SPI_cfg.DataSize = SPI_DataSize_8BIT;

	ECU3_SPI_cfg.Frame_Format = SPI_Frame_Format_MSB_Transmitted_First;
	// assume by default pclk2 = 8MHz
	ECU3_SPI_cfg.SPI_BaudRate = SPI_BaudRatePrescaler_8;


#ifdef MCU_Act_As_Master
	ECU3_SPI_cfg.Device_Mode = Device_Mode_Master;
	ECU3_SPI_cfg.NSS = SPI_NSS_SW_NSSInternalSoft_Set;
	ECU3_SPI_cfg.IRQ_Enable = SPI_IRQ_Enable_NONE;
	ECU3_SPI_cfg.P_IRQ_CallBack = 0 ;

	//Config SS on PB12 for ECU1
	GPIO_PinConfig_t ECU1_SS_pinCFG;
	ECU1_SS_pinCFG.GPIO_PinNumber = ECU1_SS_PIN;
	ECU1_SS_pinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	ECU1_SS_pinCFG.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(ECU1_PORT, &ECU1_SS_pinCFG);

	//Config SS on PB11 for ECU2
	GPIO_PinConfig_t ECU2_SS_pinCFG;
	ECU2_SS_pinCFG.GPIO_PinNumber = ECU2_SS_PIN;
	ECU2_SS_pinCFG.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	ECU2_SS_pinCFG.GPIO_output_speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(ECU2_PORT, &ECU2_SS_pinCFG);



#endif

#ifdef MCU_Act_As_Slave
	ECU3_SPI_cfg.Device_Mode = Device_Mode_Slave;
	ECU3_SPI_cfg.Communication_Mode = SPI_NSS_HW_Slave;
	ECU3_SPI_cfg.IRQ_Enable = SPI_IRQ_Enable_RXNEIE;
	ECU3_SPI_cfg.P_IRQ_CallBack = SPI_IRQ_CALLBACK;
#endif

	MCAL_SPI_Init(SPI2, &ECU3_SPI_cfg);
	MCAL_SPI_GPIO_Set_Pins(SPI2);

	// force slave select (high) idle mode
	MCAL_GPIO_WritePin(ECU1_PORT, ECU1_SS_PIN, 1);

	// force slave select (high) idle mode
	MCAL_GPIO_WritePin(ECU2_PORT, ECU2_SS_PIN, 1);
}



void ECU1_start_Verifying_Entered_Car()
{
	int counter = 0;

	MCAL_GPIO_WritePin(ECU1_PORT, ECU1_SS_PIN, 0);

	do
	{
		MCAL_SPI_TX_RX(SPI2,&ch, PollingEnable);
		receivedID[counter] = ch;
		counter++;
	}while(counter != 4);

	MCAL_GPIO_WritePin(ECU1_PORT, ECU1_SS_PIN, 1);


	for(int i=0;i<3;i++)
	{
		if(!strcmp(receivedID , IDs+i))
		{
			flag2=1;
			break;
		}
	}
	if(flag2)
	{
		ch = '1';
		MCAL_GPIO_WritePin(ECU1_PORT, ECU1_SS_PIN, 0);
		MCAL_SPI_TX_RX(SPI2,&ch, PollingEnable);
		MCAL_GPIO_WritePin(ECU1_PORT, ECU1_SS_PIN, 1);
		available_SlotsNumber--;
		HAL_SEVEN_SEG_Write(available_SlotsNumber);
	}else
	{
		ch = '0';
		MCAL_GPIO_WritePin(ECU1_PORT, ECU1_SS_PIN, 0);
		MCAL_SPI_TX_RX(SPI2,&ch, PollingEnable);
		MCAL_GPIO_WritePin(ECU1_PORT, ECU1_SS_PIN, 1);
	}
	flag2 = 0;
}
void ECU2_start_Verifying_Exit_Car(void)
{
	int counter = 0;



	MCAL_GPIO_WritePin(ECU2_PORT, ECU2_SS_PIN, 0);

	do
	{
		MCAL_SPI_TX_RX(SPI2,&ch, PollingEnable);
		receivedID[counter] = ch;
		counter++;
	}while(counter != 4);

	MCAL_GPIO_WritePin(ECU2_PORT, ECU2_SS_PIN, 1);


	for(int i=0;i<3;i++)
	{
		if(!strcmp(receivedID , IDs+i))
		{
			flag2=1;
			break;
		}
	}
	if(flag2)
	{
		ch = '1';
		MCAL_GPIO_WritePin(ECU2_PORT, ECU2_SS_PIN, 0);
		MCAL_SPI_TX_RX(SPI2,&ch, PollingEnable);
		MCAL_GPIO_WritePin(ECU2_PORT, ECU2_SS_PIN, 1);
		available_SlotsNumber++;
		HAL_SEVEN_SEG_Write(available_SlotsNumber);
	}else
	{
		ch = '0';
		MCAL_GPIO_WritePin(ECU2_PORT, ECU2_SS_PIN, 0);
		MCAL_SPI_TX_RX(SPI2,&ch, PollingEnable);
		MCAL_GPIO_WritePin(ECU2_PORT, ECU2_SS_PIN, 1);
	}
	flag2 = 0;
}

