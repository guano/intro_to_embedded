################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lab03/intervalTimer.c \
../src/lab03/lab03milestone1.c \
../src/lab03/lab03milestone2.c 

OBJS += \
./src/lab03/intervalTimer.o \
./src/lab03/lab03milestone1.o \
./src/lab03/lab03milestone2.o 

C_DEPS += \
./src/lab03/intervalTimer.d \
./src/lab03/lab03milestone1.d \
./src/lab03/lab03milestone2.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab03/%.o: ../src/lab03/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O2 -finline-functions -g3 -I"D:\Put_Your_Temp_Files_Here\Xilinx_projects\Consolidated_330_SW" -c -fmessage-length=0 -I../../HW3_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


