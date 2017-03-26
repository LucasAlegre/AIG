################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/IntegerBased\ Graph/AIGNodeI.cpp \
../src/IntegerBased\ Graph/GraphI.cpp 

OBJS += \
./src/IntegerBased\ Graph/AIGNodeI.o \
./src/IntegerBased\ Graph/GraphI.o 

CPP_DEPS += \
./src/IntegerBased\ Graph/AIGNodeI.d \
./src/IntegerBased\ Graph/GraphI.d 


# Each subdirectory must supply rules for building sources it contributes
src/IntegerBased\ Graph/AIGNodeI.o: ../src/IntegerBased\ Graph/AIGNodeI.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/IntegerBased Graph/AIGNodeI.d" -MT"src/IntegerBased\ Graph/AIGNodeI.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/IntegerBased\ Graph/GraphI.o: ../src/IntegerBased\ Graph/GraphI.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/IntegerBased Graph/GraphI.d" -MT"src/IntegerBased\ Graph/GraphI.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


