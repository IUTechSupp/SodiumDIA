################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/font/font.c 

OBJS += \
./Core/Src/font/font.o 

C_DEPS += \
./Core/Src/font/font.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/font/%.o Core/Src/font/%.su Core/Src/font/%.cyclo: ../Core/Src/font/%.c Core/Src/font/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-font

clean-Core-2f-Src-2f-font:
	-$(RM) ./Core/Src/font/font.cyclo ./Core/Src/font/font.d ./Core/Src/font/font.o ./Core/Src/font/font.su

.PHONY: clean-Core-2f-Src-2f-font

