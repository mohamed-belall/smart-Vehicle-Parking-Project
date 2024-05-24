/*
 * i2c_slave.c
 *
 *  Created on: May 20, 2024
 *      Author: moham
 */


#include "i2c_slave.h"

void I2C_Slave_Init(uint8_t slave_address)
{
    TWAR = slave_address;
    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
}

void I2C_Slave_Listen(void)
{
    while (!(TWCR & (1 << TWINT)));
}

uint8_t I2C_Slave_Receive(void)
{
    I2C_Slave_Listen();
    return TWDR;
}

void I2C_Slave_Transmit(uint8_t data)
{
    TWDR = data;
    TWCR = (1 << TWEN) | (1 << TWEA) | (1 << TWINT);
    while (!(TWCR & (1 << TWINT)));
}
