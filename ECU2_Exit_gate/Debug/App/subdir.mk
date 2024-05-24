################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/ECU2_TASKS.c \
../App/main.c 

OBJS += \
./App/ECU2_TASKS.o \
./App/main.o 

C_DEPS += \
./App/ECU2_TASKS.d \
./App/main.d 


# Each subdirectory must supply rules for building sources it contributes
App/%.o: ../App/%.c App/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I../utils -I../APP/INC -I../HAL/inc -I../MCAL/inc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


