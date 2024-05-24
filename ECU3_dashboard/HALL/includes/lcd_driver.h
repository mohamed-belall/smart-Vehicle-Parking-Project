/*
 * lcd_driver.h
 *
 * Created: 8/28/2023 4:39:41 PM
 *  Author: Mohamed Belal
 */ 


#ifndef LCD_DRIVER_H_
#define LCD_DRIVER_H_


#include "STM32F103C6_GPIO_Drivers.h"
#include "STM32F103x6.h"



#define LCD_DATA_PORT                  GPIOA
#define D0                      	   GPIO_PIN_1
#define D1                      	   GPIO_PIN_2
#define D2                      	   GPIO_PIN_3
#define D3                      	   GPIO_PIN_4
#define D4                      	   GPIO_PIN_5
#define D5                      	   GPIO_PIN_6
#define D6                      	   GPIO_PIN_7
#define D7                      	   GPIO_PIN_8


//#define DataDir_LCD_PORT               DDRA
//#define DATA_SHIFT                     0
#define LCD_CONTROL_PORT               GPIOC
#define EN_switch					   GPIO_PIN_13
#define RW_switch                      GPIO_PIN_14
#define RS_switch                      GPIO_PIN_15

#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE


#define LCD_REGISTER_SELECT_PIN       (0)
#define LCD_READ_WRITE_PIN            (1)
#define LCD_ENABLE_PIN                (2)
#define LCD_REGISTER_SELECT_ENABLE    (1)
#define LCD_REGISTER_SELECT_DISABLE   (0)
#define READ_FROM_LCD                 (1)
#define WRITE_TO_LCD                  (0)
#define LCD_ENABLE                    (1)
#define LCD_DISABLE                   (0)
#define LCD_FIRST_LINE                (0)
#define LCD_SECOND_LINE               (1)
#define LCD_FUNCTION_8BIT_2LINES      (0x38)
#define LCD_FUNCTION_4BIT_2LINES      (0x28)
#define LCD_MOVE_DISP_RIGHT			  (0x1C)
#define LCD_MOVE_DISP_LEFT            (0x18)
#define LCD_MOVE_CURSOR_RIGHT         (0x14)
#define LCD_MOVE_CURSOR_LEFT          (0x10)
#define LCD_DISP_OFF                  (0x08)
#define LCD_DISP_0N_CURSOR            (0x0E)
#define LCD_DISP_0N_CURSOR_BLINK      (0x0F)
#define LCD_DISP_0N_BLINK             (0x0D)
#define LCD_DISP_0N                   (0x0C)
#define LCD_ENTRY_DEC                 (0x04)
#define LCD_ENTRY_DEC_SHIFT           (0x05)
#define LCD_ENTRY_INC                 (0x06)
#define LCD_ENTRY_INC_SHIFT           (0x07)
#define LCD_CLEAR					  (0x01)
#define LCD_ENTRY_MODE				  (0x06)


#define LCD_BEGIN_AT_FIRST_RAW        (0x80)
#define LCD_BEGIN_AT_SECOND_RAW       (0xC0)
#define LCD_BEGIN_AT_THIRD_RAW        (0x90)
#define LCD_BEGIN_AT_FOURTH_RAW       (0xD0)

void LCD_Init(void);
void LCD_Clear_Screen(void);

void LCD_Send_Command(uint8_t command);
void LCD_Send_Character(uint8_t character);
void LCD_Send_String(char *string);

void LCD_Kick(void);
void LCD_Check_Is_Busy(void);

void LCD_gotoXY(uint8_t line , uint8_t position);
void LCD_Display_Number(unsigned int Number);
void LCD_Display_Real_Number(double Number);

void delay_ms(uint32_t time);

#endif /* LCD_DRIVER_H_ */
