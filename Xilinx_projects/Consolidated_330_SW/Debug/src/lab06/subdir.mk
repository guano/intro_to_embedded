################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lab06/buttonHandler.c \
../src/lab06/buttons.c \
../src/lab06/flashSequence.c \
../src/lab06/globals.c \
../src/lab06/lab06test.c \
../src/lab06/simonDisplay.c \
../src/lab06/verifySequence.c 

OBJS += \
./src/lab06/buttonHandler.o \
./src/lab06/buttons.o \
./src/lab06/flashSequence.o \
./src/lab06/globals.o \
./src/lab06/lab06test.o \
./src/lab06/simonDisplay.o \
./src/lab06/verifySequence.o 

C_DEPS += \
./src/lab06/buttonHandler.d \
./src/lab06/buttons.d \
./src/lab06/flashSequence.d \
./src/lab06/globals.d \
./src/lab06/lab06test.d \
./src/lab06/simonDisplay.d \
./src/lab06/verifySequence.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab06/%.o: ../src/lab06/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O2 -finline-functions -g3 -I"D:\Put_Your_Temp_Files_Here\Xilinx_projects_proj5.3.2\Xilinx_projects_proj5.3.2\Xilinx_projects_proj5.3\Xilinx_projects\Consolidated_330_SW" -c -fmessage-length=0 -I../../HW3_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


