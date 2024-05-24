/*
 * I2C.c
 *
 * Created: 12/27/2023 3:18:48 PM
 *  Author: Mohamed Belal
 */ 

#include "I2C.h"

// Global variables can be declared here if needed

void MCAL_I2C_Init(I2C_config_t* I2C_CFG) {
	// Set prescaler
	TWSR = (TWSR & 0xFC) | (I2C_CFG->I2C_Prescaler);

	// Set bit rate
	switch (I2C_CFG->I2C_Prescaler) {
	case I2C_Prescaler_1:
		TWBR = GET_I2C_Frequency(I2C_CFG->I2C_SCL_Clock, 1);
		break;
	case I2C_Prescaler_4:
		TWBR = GET_I2C_Frequency(I2C_CFG->I2C_SCL_Clock, 4);
		break;
	case I2C_Prescaler_16:
		TWBR = GET_I2C_Frequency(I2C_CFG->I2C_SCL_Clock, 16);
		break;
	case I2C_Prescaler_64:
		TWBR = GET_I2C_Frequency(I2C_CFG->I2C_SCL_Clock, 64);
		break;
	}

	// Enable TWI Interrupt if configured
	if (I2C_CFG->I2C_IRQ == I2C_IRQ_enable) {
		TWCR |= (1 << TWIE);
	}

	// Enable I2C
	TWCR |= (1 << TWEN);

	// Set ACK if enabled
	if (I2C_CFG->I2C_ACK_Control == I2C_ACK_Control_enable) {
		TWCR |= (1 << TWEA);
	} else {
		TWCR &= ~(1 << TWEA);
	}

	// Set slave address
	TWAR = I2C_CFG->I2C_Slave_Address;
}

void MCAL_I2C_Start_Condition(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
	while (!(TWCR & (1 << TWINT)));
}

void MCAL_I2C_Stop_Condition(void) {
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	while (TWCR & (1 << TWSTO));
}

void MCAL_I2C_TX(uint8_t* TX_buffer) {
	TWDR = *TX_buffer;
	TWCR = (1 << TWEN) | (1 << TWINT);
	while (!(TWCR & (1 << TWINT)));
}

void MCAL_I2C_RX_ACK(uint8_t* RX_buffer) {
	TWCR = (1 << TWEN) | (1 << TWINT) | (1 << TWEA);
	while (!(TWCR & (1 << TWINT)));
	*RX_buffer = TWDR;
}

void MCAL_I2C_RX_NACK(uint8_t* RX_buffer) {
	TWCR = (1 << TWEN) | (1 << TWINT);
	while (!(TWCR & (1 << TWINT)));
	*RX_buffer = TWDR;
}
