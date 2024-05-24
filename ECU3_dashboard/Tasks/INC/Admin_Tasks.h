/*
 * Admin_Tasks.h
 *
 *  Created on: May 4, 2024
 *      Author: Mohamed Belal
 */

#ifndef INC_ADMIN_TASKS_H_
#define INC_ADMIN_TASKS_H_
#include "lcd_driver.h"
#include "keypad_Driver.h"
#include "STM32F103C6_I2C_Driver.h"
#include "STM32F103C6_SPI_Driver.h"
#include "STM32F103C6_EXTI_Driver.h"






/*
 * ========================================================================
 * 								Admin Functions
 * ========================================================================
 * */

void Check_Admin_Password(uint8_t *flag);
//void admin_Tasks(char *IDs[]);
//void Add_ID(char *IDs[]);
//void Delete_ID(char *IDs[]);
//void Delete_IDs(char *IDs[]);
//void View_IDs(char *IDs[]);

void admin_Tasks(char IDs[3][5]);
void Add_ID(char IDs[3][5]);
void Delete_ID(char IDs[3][5]);
void Delete_IDs(char IDs[3][5]);
void View_IDs(char IDs[3][5]);

int find_ID(char IDs[3][5] , char finded_ID[5]);






#endif /* INC_ADMIN_TASKS_H_ */
