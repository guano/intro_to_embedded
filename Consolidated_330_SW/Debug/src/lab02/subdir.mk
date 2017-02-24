################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lab02/buttons.c \
../src/lab02/lab02.c \
../src/lab02/switches.c 

OBJS += \
./src/lab02/buttons.o \
./src/lab02/lab02.o \
./src/lab02/switches.o 

C_DEPS += \
./src/lab02/buttons.d \
./src/lab02/lab02.d \
./src/lab02/switches.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab02/%.o: ../src/lab02/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O2 -finline-functions -g3 -I"J:\EE330\Xilinx_projects\Consolidated_330_SW" -c -fmessage-length=0 -I../../HW3_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


