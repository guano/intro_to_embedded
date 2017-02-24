################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/simon.cpp 

C_SRCS += \
../src/main.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/main.o \
./src/simon.o 

C_DEPS += \
./src/main.d 

CPP_DEPS += \
./src/simon.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O2 -finline-functions -g3 -I"D:\Put_Your_Temp_Files_Here\Xilinx_projects_lab4.1\Consolidated_330_SW" -c -fmessage-length=0 -I../../HW3_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM g++ compiler'
	arm-xilinx-eabi-g++ -Wall -O2 -finline-functions -g3 -I"D:\Put_Your_Temp_Files_Here\Xilinx_projects_lab4.1\Consolidated_330_SW" -c -fmessage-length=0 -I../../HW3_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


