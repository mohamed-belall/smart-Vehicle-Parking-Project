/*
 * i2c_slave.h
 *
 *  Created on: May 20, 2024
 *      Author: moham
 */

#ifndef I2C_SLAVE_H_
#define I2C_SLAVE_H_

#include <avr/io.h>

void I2C_Slave_Init(uint8_t slave_address);
void I2C_Slave_Listen(void);
uint8_t I2C_Slave_Receive(void);
void I2C_Slave_Transmit(uint8_t data);

#endif /* I2C_SLAVE_H_ */
