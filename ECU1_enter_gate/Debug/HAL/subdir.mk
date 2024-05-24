################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Servo_Motor.c \
../HAL/SevenSegment.c \
../HAL/keypad.c \
../HAL/lcd_driver.c 

OBJS += \
./HAL/Servo_Motor.o \
./HAL/SevenSegment.o \
./HAL/keypad.o \
./HAL/lcd_driver.o 

C_DEPS += \
./HAL/Servo_Motor.d \
./HAL/SevenSegment.d \
./HAL/keypad.d \
./HAL/lcd_driver.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c HAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I../utils -I../HAL/inc -I../MCAL/inc -I../APP/INC -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


