/*
 * OutputNodeI.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#include "OutputNodeI.h"

OutputNodeI::OutputNodeI() {
	// TODO Auto-generated constructor stub

}

OutputNodeI::~OutputNodeI() {
	// TODO Auto-generated destructor stub
}

OutputNodeI::OutputNodeI(const int id){
	this->setId(id);
	indexInput0 = -1;
	input0Inverted = false;
}

OutputNodeI::~OutputNodeI(){

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

int OutputNodeI::getInputIndex(){

	return this->indexInput0;
}


