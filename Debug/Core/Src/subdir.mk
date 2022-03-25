################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/stm32f3xx_hal_msp.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f3xx.c 

CPP_SRCS += \
../Core/Src/CButton.cpp \
../Core/Src/CControlLedByUart.cpp \
../Core/Src/CDriver.cpp \
../Core/Src/CHelper.cpp \
../Core/Src/CLed.cpp \
../Core/Src/CStateMachineLed.cpp \
../Core/Src/CUartDriver.cpp \
../Core/Src/main.cpp \
../Core/Src/stm32f3xx_it.cpp 

C_DEPS += \
./Core/Src/stm32f3xx_hal_msp.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f3xx.d 

OBJS += \
./Core/Src/CButton.o \
./Core/Src/CControlLedByUart.o \
./Core/Src/CDriver.o \
./Core/Src/CHelper.o \
./Core/Src/CLed.o \
./Core/Src/CStateMachineLed.o \
./Core/Src/CUartDriver.o \
./Core/Src/main.o \
./Core/Src/stm32f3xx_hal_msp.o \
./Core/Src/stm32f3xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f3xx.o 

CPP_DEPS += \
./Core/Src/CButton.d \
./Core/Src/CControlLedByUart.d \
./Core/Src/CDriver.d \
./Core/Src/CHelper.d \
./Core/Src/CLed.d \
./Core/Src/CStateMachineLed.d \
./Core/Src/CUartDriver.d \
./Core/Src/main.d \
./Core/Src/stm32f3xx_it.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F303xE -c -I../Core/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc -I../Drivers/STM32F3xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F3xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/CButton.d ./Core/Src/CButton.o ./Core/Src/CButton.su ./Core/Src/CControlLedByUart.d ./Core/Src/CControlLedByUart.o ./Core/Src/CControlLedByUart.su ./Core/Src/CDriver.d ./Core/Src/CDriver.o ./Core/Src/CDriver.su ./Core/Src/CHelper.d ./Core/Src/CHelper.o ./Core/Src/CHelper.su ./Core/Src/CLed.d ./Core/Src/CLed.o ./Core/Src/CLed.su ./Core/Src/CStateMachineLed.d ./Core/Src/CStateMachineLed.o ./Core/Src/CStateMachineLed.su ./Core/Src/CUartDriver.d ./Core/Src/CUartDriver.o ./Core/Src/CUartDriver.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/stm32f3xx_hal_msp.d ./Core/Src/stm32f3xx_hal_msp.o ./Core/Src/stm32f3xx_hal_msp.su ./Core/Src/stm32f3xx_it.d ./Core/Src/stm32f3xx_it.o ./Core/Src/stm32f3xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f3xx.d ./Core/Src/system_stm32f3xx.o ./Core/Src/system_stm32f3xx.su

.PHONY: clean-Core-2f-Src

