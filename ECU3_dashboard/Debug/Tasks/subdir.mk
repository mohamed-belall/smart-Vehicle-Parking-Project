################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Tasks/Admin_Tasks.c 

OBJS += \
./Tasks/Admin_Tasks.o 

C_DEPS += \
./Tasks/Admin_Tasks.d 


# Each subdirectory must supply rules for building sources it contributes
Tasks/%.o Tasks/%.su Tasks/%.cyclo: ../Tasks/%.c Tasks/subdir.mk
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -c -I../Tasks/INC -I../APP/INC -I../MCALL/inc -I../HALL/includes -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Tasks

clean-Tasks:
	-$(RM) ./Tasks/Admin_Tasks.cyclo ./Tasks/Admin_Tasks.d ./Tasks/Admin_Tasks.o ./Tasks/Admin_Tasks.su

.PHONY: clean-Tasks

