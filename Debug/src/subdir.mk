################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AIGNode.cpp \
../src/AigerReader.cpp \
../src/BAIGNode.cpp \
../src/BGraph.cpp \
../src/Graph.cpp \
../src/main.cpp 

OBJS += \
./src/AIGNode.o \
./src/AigerReader.o \
./src/BAIGNode.o \
./src/BGraph.o \
./src/Graph.o \
./src/main.o 

CPP_DEPS += \
./src/AIGNode.d \
./src/AigerReader.d \
./src/BAIGNode.d \
./src/BGraph.d \
./src/Graph.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


