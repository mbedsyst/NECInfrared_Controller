################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/NEC.c \
../Src/SYSTICK.c \
../Src/TIM.c \
../Src/UART.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c \
../Src/system_init.c 

OBJS += \
./Src/NEC.o \
./Src/SYSTICK.o \
./Src/TIM.o \
./Src/UART.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o \
./Src/system_init.o 

C_DEPS += \
./Src/NEC.d \
./Src/SYSTICK.d \
./Src/TIM.d \
./Src/UART.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d \
./Src/system_init.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DSTM32F401xE -c -I../Inc -I"../$(ProjDirPath)/Headers/CMSIS/Include" -I"../$(ProjDirPath)/Headers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/NEC.cyclo ./Src/NEC.d ./Src/NEC.o ./Src/NEC.su ./Src/SYSTICK.cyclo ./Src/SYSTICK.d ./Src/SYSTICK.o ./Src/SYSTICK.su ./Src/TIM.cyclo ./Src/TIM.d ./Src/TIM.o ./Src/TIM.su ./Src/UART.cyclo ./Src/UART.d ./Src/UART.o ./Src/UART.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su ./Src/system_init.cyclo ./Src/system_init.d ./Src/system_init.o ./Src/system_init.su

.PHONY: clean-Src

