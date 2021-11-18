################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/AFIO_program.c \
../src/EXTI_program.c \
../src/GPIO_program.c \
../src/NVIC_program.c \
../src/RCC_program.c \
../src/STK_program.c \
../src/main.c 

OBJS += \
./src/AFIO_program.o \
./src/EXTI_program.o \
./src/GPIO_program.o \
./src/NVIC_program.o \
./src/RCC_program.o \
./src/STK_program.o \
./src/main.o 

C_DEPS += \
./src/AFIO_program.d \
./src/EXTI_program.d \
./src/GPIO_program.d \
./src/NVIC_program.d \
./src/RCC_program.d \
./src/STK_program.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra  -g -DNDEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


