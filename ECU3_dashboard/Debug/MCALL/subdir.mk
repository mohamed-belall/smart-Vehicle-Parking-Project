################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCALL/STM32F103C6_EXTI_Driver.c \
../MCALL/STM32F103C6_GPIO_Driver.c \
../MCALL/STM32F103C6_I2C_Driver.c \
../MCALL/STM32F103C6_RCC_Drivers.c \
../MCALL/STM32F103C6_SPI_Driver.c \
../MCALL/STM32F103C6_USART_Drivers.c 

OBJS += \
./MCALL/STM32F103C6_EXTI_Driver.o \
./MCALL/STM32F103C6_GPIO_Driver.o \
./MCALL/STM32F103C6_I2C_Driver.o \
./MCALL/STM32F103C6_RCC_Drivers.o \
./MCALL/STM32F103C6_SPI_Driver.o \
./MCALL/STM32F103C6_USART_Drivers.o 

C_DEPS += \
./MCALL/STM32F103C6_EXTI_Driver.d \
./MCALL/STM32F103C6_GPIO_Driver.d \
./MCALL/STM32F103C6_I2C_Driver.d \
./MCALL/STM32F103C6_RCC_Drivers.d \
./MCALL/STM32F103C6_SPI_Driver.d \
./MCALL/STM32F103C6_USART_Drivers.d 


# Each subdirectory must supply rules for building sources it contributes
MCALL/%.o MCALL/%.su MCALL/%.cyclo: ../MCALL/%.c MCALL/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Tasks/INC -I../APP/INC -I../MCALL/inc -I../HALL/includes -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-MCALL

clean-MCALL:
	-$(RM) ./MCALL/STM32F103C6_EXTI_Driver.cyclo ./MCALL/STM32F103C6_EXTI_Driver.d ./MCALL/STM32F103C6_EXTI_Driver.o ./MCALL/STM32F103C6_EXTI_Driver.su ./MCALL/STM32F103C6_GPIO_Driver.cyclo ./MCALL/STM32F103C6_GPIO_Driver.d ./MCALL/STM32F103C6_GPIO_Driver.o ./MCALL/STM32F103C6_GPIO_Driver.su ./MCALL/STM32F103C6_I2C_Driver.cyclo ./MCALL/STM32F103C6_I2C_Driver.d ./MCALL/STM32F103C6_I2C_Driver.o ./MCALL/STM32F103C6_I2C_Driver.su ./MCALL/STM32F103C6_RCC_Drivers.cyclo ./MCALL/STM32F103C6_RCC_Drivers.d ./MCALL/STM32F103C6_RCC_Drivers.o ./MCALL/STM32F103C6_RCC_Drivers.su ./MCALL/STM32F103C6_SPI_Driver.cyclo ./MCALL/STM32F103C6_SPI_Driver.d ./MCALL/STM32F103C6_SPI_Driver.o ./MCALL/STM32F103C6_SPI_Driver.su ./MCALL/STM32F103C6_USART_Drivers.cyclo ./MCALL/STM32F103C6_USART_Drivers.d ./MCALL/STM32F103C6_USART_Drivers.o ./MCALL/STM32F103C6_USART_Drivers.su

.PHONY: clean-MCALL

