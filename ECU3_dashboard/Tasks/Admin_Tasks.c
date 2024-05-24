/*
 * Admin_Tasks.c
 *
 *  Created on: May 4, 2024
 *      Author: Mohamed Belal
 */

#include "Admin_Tasks.h"


void Check_Admin_Password(uint8_t *AdminPassword_flag)
{
	uint8_t password = 1234;
	uint8_t entered_Password = 0;
	volatile uint8_t key_pressed;
	int countNumberEntered = 0;

	LCD_Clear_Screen();
	LCD_Send_String("   As an Admin     Please Enter      Password:");
	LCD_gotoXY(4, 6);

	while(!(*AdminPassword_flag))
	{
		key_pressed = keypad_GetKey();
		if(key_pressed != 'A')
		{
			LCD_Send_Character('*');
			entered_Password = entered_Password *10 + (int)(key_pressed - '0');
			countNumberEntered++;

			if(countNumberEntered == 4 )
			{
				LCD_gotoXY(4, 0);
				if(password == entered_Password)
				{
					*AdminPassword_flag =  1;
					LCD_Clear_Screen();
					LCD_gotoXY(1, 2);
					LCD_Send_String("== correct ==");
					LCD_gotoXY(2, 3);
					LCD_Send_String("welcome to");
					LCD_gotoXY(3, 0);
					LCD_Send_String("Bello Dashboard");
					delay_ms(100);
					LCD_Clear_Screen();


				}
				else
				{
					LCD_Clear_Screen();
					LCD_Send_String(" Wrong password");
					LCD_gotoXY(2, 0);
					LCD_Send_String("please try again");
					LCD_gotoXY(4, 6);
					entered_Password =0;
					countNumberEntered =0;
				}


			}
		}

	}

}





void admin_Tasks(char IDs[3][5])
{

	volatile uint8_t key_pressed;


	LCD_Send_String("1: ADD ID");
	LCD_gotoXY(2, 0);
	LCD_Send_String("2: Delete ID");
	LCD_gotoXY(3, 0);
	LCD_Send_String("3: Delete ALL IDs");
	LCD_gotoXY(4, 0);
	LCD_Send_String("4: View All IDs");

	while(1)
	{
		key_pressed = keypad_GetKey();
		if(key_pressed != 'A')
		{

		}
		switch(key_pressed)
		{
		case 'A':
			break;
		case '1':
		{
			Add_ID(IDs);
			LCD_Send_String("1: ADD ID");
			LCD_gotoXY(2, 0);
			LCD_Send_String("2: Delete ID");
			LCD_gotoXY(3, 0);
			LCD_Send_String("3: Delete ALL IDs");
			LCD_gotoXY(4, 0);
			LCD_Send_String("4: View All IDs");
			break;
		}
		case '2':
		{
			Delete_ID(IDs);
			LCD_Send_String("1: ADD ID");
			LCD_gotoXY(2, 0);
			LCD_Send_String("2: Delete ID");
			LCD_gotoXY(3, 0);
			LCD_Send_String("3: Delete ALL IDs");
			LCD_gotoXY(4, 0);
			LCD_Send_String("4: View All IDs");
			break;
		}
		case '3':
		{
			Delete_IDs(IDs);
			LCD_Send_String("1: ADD ID");
			LCD_gotoXY(2, 0);
			LCD_Send_String("2: Delete ID");
			LCD_gotoXY(3, 0);
			LCD_Send_String("3: Delete ALL IDs");
			LCD_gotoXY(4, 0);
			LCD_Send_String("4: View All IDs");
			break;
		}
		case '4':
		{
			View_IDs(IDs);
			LCD_Send_String("1: ADD ID");
			LCD_gotoXY(2, 0);
			LCD_Send_String("2: Delete ID");
			LCD_gotoXY(3, 0);
			LCD_Send_String("3: Delete ALL IDs");
			LCD_gotoXY(4, 0);
			LCD_Send_String("4: View All IDs");
			break;
		}
		default:
			break;
		}
	}


}


void Add_ID(char IDs[3][5])
{
	char NewPassword[5] = {0};
	uint8_t flag =0;
	uint8_t flag2 =1;
	static uint8_t number_Of_IDS = 0;
	volatile uint8_t key_pressed;
	int countNumberEntered = 0;

	LCD_Clear_Screen();
	LCD_Send_String("Enter New ID:");
	LCD_gotoXY(2, 0);

	while(!flag)
	{
		key_pressed = keypad_GetKey();
		if(key_pressed != 'A')
		{
			LCD_Send_Character(key_pressed);
			strncat(NewPassword , &key_pressed ,1);
			countNumberEntered++;

			if(countNumberEntered == 4 )
			{

				LCD_gotoXY(4, 0);
				if(flag2)
				{
					flag =  1;
				    strncpy(IDs[number_Of_IDS], NewPassword, sizeof(IDs[number_Of_IDS]) - 1);
				    IDs[number_Of_IDS][sizeof(IDs[number_Of_IDS]) - 1] = '\0';
					number_Of_IDS++;
					LCD_gotoXY(3, 0);
					LCD_Send_String("== Success ==");
					delay_ms(100);
					LCD_Clear_Screen();
				}
				else
				{
					LCD_gotoXY(3, 0);
					LCD_Send_String("password exist");
					//NewPassword = 0;
					countNumberEntered =0;
				}
			}
		}
	}
}
void Delete_ID(char IDs[3][5])
{

}
void Delete_IDs(char IDs[3][5])
{

}
void View_IDs(char IDs[3][5])
{
	char key_pressed = '0';
	LCD_Clear_Screen();
	for(int i=0;i<3;i++)
	{
		LCD_Send_String(IDs[i]);
		LCD_gotoXY(i+2, 0);
	}
	LCD_Send_String("press 1 to back");
	while(key_pressed != '1')
		{
			key_pressed = keypad_GetKey();
		}
	LCD_Clear_Screen();
}

int find_ID(char IDs[3][5] , char finded_ID[5])
{

	for(int i=0;i<3;i++)
	{
		if(strcmp(IDs[i] , finded_ID))
		{
			return 1;
		}

	}
}

















































//		switch (key_pressed) {
//		case 'A':
//			break;
//		case '?':
//		{
//			LCD_gotoXY(4, 0);
//			if(password == entered_Password)
//			{
//				*flag =  1;
//				LCD_Clear_Screen();
//				LCD_gotoXY(1, 2);
//				LCD_Send_String("== correct ==");
//				LCD_gotoXY(2, 3);
//				LCD_Send_String("welcome to");
//				LCD_gotoXY(3, 0);
//				LCD_Send_String("Bello Dashboard");
//				delay_ms(100);
//				LCD_Clear_Screen();
//			}
//			else
//			{
//				LCD_Clear_Screen();
//				LCD_Send_String("Wrong password");
//				LCD_gotoXY(2, 0);
//				LCD_Send_String("please try again");
//				LCD_gotoXY(3, 0);
//				entered_Password =0;
//			}
//
//			break;
//		}
//		default:
//		{
//			LCD_Send_Character(key_pressed);
//			entered_Password = entered_Password *10 + (int)(key_pressed - '0');
//			break;
//		}
//
//		}
