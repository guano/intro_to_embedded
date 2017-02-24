################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/lab05/buttons.c \
../src/lab05/intervalTimer.c \
../src/lab05/lab05timeTest.c \
../src/lab05/minimax.c \
../src/lab05/switches.c \
../src/lab05/ticTacToeControl.c \
../src/lab05/ticTacToeDisplay.c 

OBJS += \
./src/lab05/buttons.o \
./src/lab05/intervalTimer.o \
./src/lab05/lab05timeTest.o \
./src/lab05/minimax.o \
./src/lab05/switches.o \
./src/lab05/ticTacToeControl.o \
./src/lab05/ticTacToeDisplay.o 

C_DEPS += \
./src/lab05/buttons.d \
./src/lab05/intervalTimer.d \
./src/lab05/lab05timeTest.d \
./src/lab05/minimax.d \
./src/lab05/switches.d \
./src/lab05/ticTacToeControl.d \
./src/lab05/ticTacToeDisplay.d 


# Each subdirectory must supply rules for building sources it contributes
src/lab05/%.o: ../src/lab05/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O2 -finline-functions -g3 -I"D:\Put_Your_Temp_Files_Here\Xilinx_projects_proj5.2\Xilinx_projects\Consolidated_330_SW" -c -fmessage-length=0 -I../../HW3_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


