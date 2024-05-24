/*
 * lcd_driver.c
 *
 * Created: 8/28/2023 4:39:26 PM
 *  Author: Mohamed Belal
 */ 

#include "lcd_driver.h"



void delay_ms(uint32_t time)
{
	uint32_t i,j;
	for(i=0 ; i < time ; i++)
		for(j=0 ; j<255 ; j++);
}

void LCD_Init()
{
	GPIO_PinConfig_t PinCfg;
	delay_ms(20);

	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;

	PinCfg.GPIO_PinNumber = EN_switch ;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = RW_switch;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = RS_switch;
	MCAL_GPIO_Init(LCD_CONTROL_PORT, &PinCfg);


	// data pins output
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_output_speed = GPIO_SPEED_10M;



	PinCfg.GPIO_PinNumber = D4;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D5;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D6;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D7;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, EN_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_RESET);

	delay_ms(15);
	LCD_Clear_Screen();

#ifdef EIGHT_BIT_MODE
	PinCfg.GPIO_PinNumber = D0;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D1;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D2;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = D3;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	LCD_Send_Command(LCD_FUNCTION_8BIT_2LINES);
#endif

#ifdef FOUR_BIT_MODE
	MCAL_GPIO_WritePin(LCD_DATA_PORT, D4, (LCD_FUNCTION_4BIT_2LINES&0x10));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, D5, (LCD_FUNCTION_4BIT_2LINES&0x20));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, D6, (LCD_FUNCTION_4BIT_2LINES&0x40));
	MCAL_GPIO_WritePin(LCD_DATA_PORT, D7, (LCD_FUNCTION_4BIT_2LINES&0x80));
	LCD_Send_Command(0x02);
	LCD_Send_Command(LCD_FUNCTION_4BIT_2LINES);
#endif

	LCD_Send_Command(LCD_ENTRY_MODE);
	LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW);
	LCD_Send_Command(LCD_DISP_0N_CURSOR_BLINK);

}

void LCD_Clear_Screen(void)
{
	LCD_Send_Command(LCD_CLEAR);
}

void LCD_Send_Command(uint8_t command)
{
#ifdef EIGHT_BIT_MODE

	//	MCAL_GPIO_WritePort(LCD_DATA_PORT, command);
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D0 , (command&0x01));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D1 , (command&0x02));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D2 , (command&0x04));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D3 , (command&0x08));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D4 , (command&0x10));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D5 , (command&0x20));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D6 , (command&0x40));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D7 , (command&0x80));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS_switch, GPIO_PIN_RESET);
	delay_ms(1);
	LCD_Kick();
#endif

#ifdef FOUR_BIT_MODE
	LCD_Check_Is_Busy();
	//	LCD_PORT = (LCD_PORT &0x0F) | (command & 0xF0);
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D4 , (command&0x10));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D5 , (command&0x20));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D6 , (command&0x40));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D7 , (command&0x80));
//	LCD_CONTROL_PORT &= ~((1<<RW_switch) | (1<<RS_switch));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT ,RW_switch , GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT ,RS_switch , GPIO_PIN_RESET);
	LCD_Kick();

	LCD_Check_Is_Busy();
	//	LCD_PORT = (LCD_PORT &0x0F) | (command << 4);
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D4 , (command&0x01));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D5 , (command&0x02));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D6 , (command&0x04));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D7 , (command&0x08));
//	LCD_CONTROL_PORT &= ~((1<<RW_switch) | (1<<RS_switch));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT ,RW_switch , GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT ,RS_switch , GPIO_PIN_RESET);
	LCD_Kick();
#endif

}
void LCD_Send_Character(uint8_t character)
{
#ifdef EIGHT_BIT_MODE

	//	MCAL_GPIO_WritePort(LCD_DATA_PORT, character<<7 );
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D0 , (character&0x01));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D1 , (character&0x02));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D2 , (character&0x04));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D3 , (character&0x08));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D4 , (character&0x10));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D5 , (character&0x20));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D6 , (character&0x40));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D7 , (character&0x80));
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS_switch, GPIO_PIN_SET);

	delay_ms(1);
	LCD_Kick();
#endif

#ifdef FOUR_BIT_MODE
	//	LCD_PORT = (LCD_PORT &0x0F) | (character & 0xF0);
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D4 , (character&0x10));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D5 , (character&0x20));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D6 , (character&0x40));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D7 , (character&0x80));
//	LCD_CONTROL_PORT |= (1<<RS_switch);     //1: Data Register
//	LCD_CONTROL_PORT &= ~(1<<RW_switch);    //0: Write
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT ,RS_switch , GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT ,RW_switch , GPIO_PIN_RESET);
	LCD_Kick();

	LCD_Check_Is_Busy();
	//	LCD_PORT = (LCD_PORT &0x0F) | (character << 4);
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D4 , (character&0x01));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D5 , (character&0x02));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D6 , (character&0x04));
	MCAL_GPIO_WritePin(LCD_DATA_PORT , D7 , (character&0x08));
//
//	LCD_CONTROL_PORT |= (1<<RS_switch);     //1: Data Register
//	LCD_CONTROL_PORT &= ~(1<<RW_switch);    //0: Write
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT ,RS_switch , GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CONTROL_PORT ,RW_switch , GPIO_PIN_RESET);
	LCD_Kick();
#endif
}
void LCD_Send_String(char *string)
{
	int count =0;

	while(*string >0)
	{


		LCD_Send_Character(*string++);
		if (count == 16)
		{
			LCD_gotoXY(2,0);
		}else if (count == 32)
		{
			LCD_gotoXY(3,0);
		}
		else if (count == 48)
		{
			LCD_gotoXY(4,0);
		}

		else if(count >= 64 )
		{
			LCD_Clear_Screen();
			LCD_gotoXY(1,0);
			count =0;
		}
		count++;
	}
}

void LCD_Kick(void)
{

	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, EN_switch, GPIO_PIN_SET);

	delay_ms(10);

	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, EN_switch, GPIO_PIN_RESET);
}

void LCD_Check_Is_Busy(void)
{
	GPIO_PinConfig_t PinCfg;

	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_INPUT_FLOATING;
	MCAL_GPIO_Init(LCD_DATA_PORT, &PinCfg);



	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_SET);

	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RS_switch, GPIO_PIN_RESET);


	LCD_Kick();


	MCAL_GPIO_WritePin(LCD_CONTROL_PORT, RW_switch, GPIO_PIN_RESET);

}




void LCD_gotoXY(uint8_t line , uint8_t position)
{
	if (line == 1) // line 1
	{
		if(  position >= 0 && position < 16)
			LCD_Send_Command(LCD_BEGIN_AT_FIRST_RAW+position);
	}
	else if (line == 2) //  line 2
	{
		if(  position >= 0 && position < 16)
			LCD_Send_Command(LCD_BEGIN_AT_SECOND_RAW+position);
	}
	else if (line == 3) // line 3
	{
		if(  position >= 0 && position < 16)
			LCD_Send_Command(LCD_BEGIN_AT_THIRD_RAW+position);
	}
	else if (line == 4) //  line 4
	{
		if(  position >= 0 && position < 16)
			LCD_Send_Command(LCD_BEGIN_AT_FOURTH_RAW+position);
	}
}
void LCD_Display_Number(unsigned int Number)
{
	char str[6];
	sprintf(str,"%d",Number); //adjust the formatting to your liking

	LCD_Send_String(str);
}

void LCD_Display_Real_Number(double Number)
{
	char str[16];

	char *tmpsign = (Number < 0) ? "-" : "";
	float tmpVal = (Number < 0) ? -Number : Number;

	int tmpInt1 = tmpVal; //get the integer value 
	float tmpFraction = tmpVal - tmpInt1; // get fraction value
	int tmpInt2 = tmpFraction * 10000; // turn into integer

	sprintf(str,"$s%d.%04d",tmpsign,tmpInt1,tmpInt2);
	LCD_Send_String(str);
}
