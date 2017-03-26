/*
 * AIGNodeI.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#include "AIGNodeI.h"

AIGNodeI::AIGNodeI() {
	// TODO Auto-generated constructor stub

}

AIGNodeI::~AIGNodeI() {
	// TODO Auto-generated destructor stub
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
	cout << "Tried to get ouput from an unidirected node\n";
	return NULL;
}
void AIGNodeI::setOutput(AIGNodeI node){
        cout << "Tried to set ouput to an unidirected node\n";
}
bool * AIGNodeI::getOutputsInverted(){
	cout << "Tried to get ouputs inverted from an unidirected node\n";
	return NULL;
}


