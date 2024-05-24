################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HALL/EEPROM.c \
../HALL/keypad_Driver.c \
../HALL/lcd_driver.c \
../HALL/seven_segmnet.c 

OBJS += \
./HALL/EEPROM.o \
./HALL/keypad_Driver.o \
./HALL/lcd_driver.o \
./HALL/seven_segmnet.o 

C_DEPS += \
./HALL/EEPROM.d \
./HALL/keypad_Driver.d \
./HALL/lcd_driver.d \
./HALL/seven_segmnet.d 


# Each subdirectory must supply rules for building sources it contributes
HALL/%.o HALL/%.su HALL/%.cyclo: ../HALL/%.c HALL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Tasks/INC -I../APP/INC -I../MCALL/inc -I../HALL/includes -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-HALL

clean-HALL:
	-$(RM) ./HALL/EEPROM.cyclo ./HALL/EEPROM.d ./HALL/EEPROM.o ./HALL/EEPROM.su ./HALL/keypad_Driver.cyclo ./HALL/keypad_Driver.d ./HALL/keypad_Driver.o ./HALL/keypad_Driver.su ./HALL/lcd_driver.cyclo ./HALL/lcd_driver.d ./HALL/lcd_driver.o ./HALL/lcd_driver.su ./HALL/seven_segmnet.cyclo ./HALL/seven_segmnet.d ./HALL/seven_segmnet.o ./HALL/seven_segmnet.su

.PHONY: clean-HALL

