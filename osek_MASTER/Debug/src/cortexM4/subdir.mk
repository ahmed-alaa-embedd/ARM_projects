################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cortexM4/Os_Arch.c \
../src/cortexM4/Os_Internal_Arch.c \
../src/cortexM4/StartOs_Arch.c \
../src/cortexM4/StartOs_Arch_SysTick.c 

S_UPPER_SRCS += \
../src/cortexM4/PendSV.S 

OBJS += \
./src/cortexM4/Os_Arch.o \
./src/cortexM4/Os_Internal_Arch.o \
./src/cortexM4/PendSV.o \
./src/cortexM4/StartOs_Arch.o \
./src/cortexM4/StartOs_Arch_SysTick.o 

S_UPPER_DEPS += \
./src/cortexM4/PendSV.d 

C_DEPS += \
./src/cortexM4/Os_Arch.d \
./src/cortexM4/Os_Internal_Arch.d \
./src/cortexM4/StartOs_Arch.d \
./src/cortexM4/StartOs_Arch_SysTick.d 


# Each subdirectory must supply rules for building sources it contributes
src/cortexM4/%.o: ../src/cortexM4/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/cortexM4/%.o: ../src/cortexM4/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU Assembler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -x assembler-with-cpp -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


