################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AAGReader.cpp \
../src/AIGNode.cpp \
../src/Graph.cpp \
../src/main.cpp 

OBJS += \
./src/AAGReader.o \
./src/AIGNode.o \
./src/Graph.o \
./src/main.o 

CPP_DEPS += \
./src/AAGReader.d \
./src/AIGNode.d \
./src/Graph.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


