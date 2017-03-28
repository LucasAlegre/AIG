################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/IntegerBased\ Graph/AigerReaderI/AigerReaderI.cpp 

OBJS += \
./src/IntegerBased\ Graph/AigerReaderI/AigerReaderI.o 

CPP_DEPS += \
./src/IntegerBased\ Graph/AigerReaderI/AigerReaderI.d 


# Each subdirectory must supply rules for building sources it contributes
src/IntegerBased\ Graph/AigerReaderI/AigerReaderI.o: ../src/IntegerBased\ Graph/AigerReaderI/AigerReaderI.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/IntegerBased Graph/AigerReaderI/AigerReaderI.d" -MT"src/IntegerBased\ Graph/AigerReaderI/AigerReaderI.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


