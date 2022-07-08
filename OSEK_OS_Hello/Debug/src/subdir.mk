################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/IntVect.c \
../src/OS.c \
../src/OsAlarm.c \
../src/OsAsm.c \
../src/OsEvt.c \
../src/OsTask.c \
../src/SysStartup.c \
../src/SysTickTimer.c \
../src/TCB.c \
../src/main.c 

OBJS += \
./src/IntVect.o \
./src/OS.o \
./src/OsAlarm.o \
./src/OsAsm.o \
./src/OsEvt.o \
./src/OsTask.o \
./src/SysStartup.o \
./src/SysTickTimer.o \
./src/TCB.o \
./src/main.o 

C_DEPS += \
./src/IntVect.d \
./src/OS.d \
./src/OsAlarm.d \
./src/OsAsm.d \
./src/OsEvt.d \
./src/OsTask.d \
./src/SysStartup.d \
./src/SysTickTimer.d \
./src/TCB.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


