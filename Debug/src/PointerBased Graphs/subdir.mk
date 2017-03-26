################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/PointerBased\ Graphs/AIGNode.cpp \
../src/PointerBased\ Graphs/AigerReader.cpp \
../src/PointerBased\ Graphs/BAIGNode.cpp \
../src/PointerBased\ Graphs/BGraph.cpp \
../src/PointerBased\ Graphs/Graph.cpp 

OBJS += \
./src/PointerBased\ Graphs/AIGNode.o \
./src/PointerBased\ Graphs/AigerReader.o \
./src/PointerBased\ Graphs/BAIGNode.o \
./src/PointerBased\ Graphs/BGraph.o \
./src/PointerBased\ Graphs/Graph.o 

CPP_DEPS += \
./src/PointerBased\ Graphs/AIGNode.d \
./src/PointerBased\ Graphs/AigerReader.d \
./src/PointerBased\ Graphs/BAIGNode.d \
./src/PointerBased\ Graphs/BGraph.d \
./src/PointerBased\ Graphs/Graph.d 


# Each subdirectory must supply rules for building sources it contributes
src/PointerBased\ Graphs/AIGNode.o: ../src/PointerBased\ Graphs/AIGNode.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/PointerBased Graphs/AIGNode.d" -MT"src/PointerBased\ Graphs/AIGNode.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/PointerBased\ Graphs/AigerReader.o: ../src/PointerBased\ Graphs/AigerReader.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/PointerBased Graphs/AigerReader.d" -MT"src/PointerBased\ Graphs/AigerReader.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/PointerBased\ Graphs/BAIGNode.o: ../src/PointerBased\ Graphs/BAIGNode.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/PointerBased Graphs/BAIGNode.d" -MT"src/PointerBased\ Graphs/BAIGNode.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/PointerBased\ Graphs/BGraph.o: ../src/PointerBased\ Graphs/BGraph.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/PointerBased Graphs/BGraph.d" -MT"src/PointerBased\ Graphs/BGraph.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/PointerBased\ Graphs/Graph.o: ../src/PointerBased\ Graphs/Graph.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"src/PointerBased Graphs/Graph.d" -MT"src/PointerBased\ Graphs/Graph.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


