################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ActivateTask.c \
../src/CancelAlarm.c \
../src/ChainTask.c \
../src/ClearEvent.c \
../src/GetActiveApplicationMode.c \
../src/GetAlarm.c \
../src/GetAlarmBase.c \
../src/GetEvent.c \
../src/GetResource.c \
../src/GetTaskID.c \
../src/GetTaskState.c \
../src/Os.c \
../src/Os_Internal.c \
../src/ReleaseResource.c \
../src/Schedule.c \
../src/SetAbsAlarm.c \
../src/SetEvent.c \
../src/SetRelAlarm.c \
../src/ShutdownOS.c \
../src/StartOS.c \
../src/TerminateTask.c \
../src/WaitEvent.c \
../src/fifo.c \
../src/libc.c \
../src/main.c \
../src/message.c 

OBJS += \
./src/ActivateTask.o \
./src/CancelAlarm.o \
./src/ChainTask.o \
./src/ClearEvent.o \
./src/GetActiveApplicationMode.o \
./src/GetAlarm.o \
./src/GetAlarmBase.o \
./src/GetEvent.o \
./src/GetResource.o \
./src/GetTaskID.o \
./src/GetTaskState.o \
./src/Os.o \
./src/Os_Internal.o \
./src/ReleaseResource.o \
./src/Schedule.o \
./src/SetAbsAlarm.o \
./src/SetEvent.o \
./src/SetRelAlarm.o \
./src/ShutdownOS.o \
./src/StartOS.o \
./src/TerminateTask.o \
./src/WaitEvent.o \
./src/fifo.o \
./src/libc.o \
./src/main.o \
./src/message.o 

C_DEPS += \
./src/ActivateTask.d \
./src/CancelAlarm.d \
./src/ChainTask.d \
./src/ClearEvent.d \
./src/GetActiveApplicationMode.d \
./src/GetAlarm.d \
./src/GetAlarmBase.d \
./src/GetEvent.d \
./src/GetResource.d \
./src/GetTaskID.d \
./src/GetTaskState.d \
./src/Os.d \
./src/Os_Internal.d \
./src/ReleaseResource.d \
./src/Schedule.d \
./src/SetAbsAlarm.d \
./src/SetEvent.d \
./src/SetRelAlarm.d \
./src/ShutdownOS.d \
./src/StartOS.d \
./src/TerminateTask.d \
./src/WaitEvent.d \
./src/fifo.d \
./src/libc.d \
./src/main.d \
./src/message.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM GNU C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m3 -mthumb -Og -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -fno-move-loop-invariants -Wall -Wextra  -g3 -DDEBUG -DUSE_FULL_ASSERT -DTRACE -DOS_USE_TRACE_SEMIHOSTING_DEBUG -DSTM32F10X_MD -DUSE_STDPERIPH_DRIVER -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f1-stdperiph" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


