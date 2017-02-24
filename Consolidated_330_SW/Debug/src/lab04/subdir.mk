################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lab04/clockControl.c \
../src/lab04/clockDisplay.c \
../src/lab04/clockMain.c \
../src/lab04/intervalTimer.c 

OBJS += \
./src/lab04/clockControl.o \
./src/lab04/clockDisplay.o \
./src/lab04/clockMain.o \
./src/lab04/intervalTimer.o 

C_DEPS += \
./src/lab04/clockControl.d \
./src/lab04/clockDisplay.d \
./src/lab04/clockMain.d \
./src/lab04/intervalTimer.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab04/%.o: ../src/lab04/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O2 -finline-functions -g3 -I"D:\Put_Your_Temp_Files_Here\Xilinx_projects_lab4.1\Consolidated_330_SW" -c -fmessage-length=0 -I../../HW3_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


