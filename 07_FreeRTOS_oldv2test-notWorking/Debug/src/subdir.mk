################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ACTIM1_program.c \
../src/AFIO_program.c \
../src/EXTI_program.c \
../src/GPIO_program.c \
../src/GPTIM\ _program.c \
../src/NVICprogram.c \
../src/RCC_program.c \
../src/Tasks_program.c \
../src/USART_program_Old.c \
../src/main.c 

OBJS += \
./src/ACTIM1_program.o \
./src/AFIO_program.o \
./src/EXTI_program.o \
./src/GPIO_program.o \
./src/GPTIM\ _program.o \
./src/NVICprogram.o \
./src/RCC_program.o \
./src/Tasks_program.o \
./src/USART_program_Old.o \
./src/main.o 

C_DEPS += \
./src/ACTIM1_program.d \
./src/AFIO_program.d \
./src/EXTI_program.d \
./src/GPIO_program.d \
./src/GPTIM\ _program.d \
./src/NVICprogram.d \
./src/RCC_program.d \
./src/Tasks_program.d \
./src/USART_program_Old.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/GPTIM\ _program.o: ../src/GPTIM\ _program.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"src/GPTIM _program.d" -MT"src/GPTIM\ _program.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


