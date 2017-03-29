/*
 * AIGNodeI.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#include "AIGNodeI.h"
#include <iostream>

AIGNodeI::AIGNodeI() {
	id = -1;

}

AIGNodeI::~AIGNodeI() {
	// TODO Auto-generated destructor stub
}


AIGNodeI::AIGNodeI(unsigned id){
	this->id = id;
}


std::string AIGNodeI::getName() const {
	return name;
}

void AIGNodeI::setName(std::string name) {
	this->name = name;
}

unsigned AIGNodeI::getId() const {
	return id;
}

void AIGNodeI::setId(unsigned id) {
	this->id = id;
}

AIGNodeI * AIGNodeI::getOutputs(){
	std::cout << "Tried to get ouput from an unidirected node\n";
	return NULL;
}
void AIGNodeI::setOutput(AIGNodeI node){
    std::cout << "Tried to set ouput to an unidirected node\n";
}
bool * AIGNodeI::getOutputsInverted(){
	std::cout << "Tried to get ouputs inverted from an unidirected node\n";
	return NULL;
}

void AIGNodeI::setInputIndex(const int index, const int input0or1){
	std::cout << "Tried to set input to a generic node\n";
}
bool AIGNodeI::isInputInverted(const int input0or1) const{
	std::cout << "Tried to get inputInverted from a generic node\n";
	return false;
}
int AIGNodeI::getInputIndex(const int input0or1){
	std::cout << "Tried to get inputIndex of a generic node\n";
    return -1;

}
void AIGNodeI::setInputInverted(const bool inputInverted, const int input0or1){
	std::cout << "Tried to set input inverted to a generic node\n";

}

