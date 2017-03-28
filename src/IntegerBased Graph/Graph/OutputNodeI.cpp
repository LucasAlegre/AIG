/*
 * OutputNodeI.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#include <iostream>
#include "OutputNodeI.h"


OutputNodeI::~OutputNodeI() {
	// TODO Auto-generated destructor stub
}

OutputNodeI::OutputNodeI(const int id){
	this->setId(id);
	indexInput0 = -1;
	input0Inverted = false;
}


void OutputNodeI::setInputInverted(const bool inputInverted){
	this->input0Inverted = inputInverted;
}

bool OutputNodeI::isInputInverted()const{
	return this->input0Inverted;
}

void OutputNodeI::setInputIndex(const int index){

	this->indexInput0 = index;
}

int OutputNodeI::getInputIndex(const int input0or1){

	if(input0or1 != 0){
		std::cout << "Output only has input0\n";
		return -1;
	}

	else
		return this->indexInput0;
}


