################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/I2C/I2C.c \
../MCAL/I2C/i2c_slave.c 

OBJS += \
./MCAL/I2C/I2C.o \
./MCAL/I2C/i2c_slave.o 

C_DEPS += \
./MCAL/I2C/I2C.d \
./MCAL/I2C/i2c_slave.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/I2C/%.o: ../MCAL/I2C/%.c MCAL/I2C/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I../utils -I../HAL/inc -I../MCAL/inc -I../APP/INC -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


