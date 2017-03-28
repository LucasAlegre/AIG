/*
 * InputNodeI.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#include<iostream>
#include "InputNodeI.h"
#include "AIGNodeI.h"


InputNodeI::~InputNodeI() {
	// TODO Auto-generated destructor stub
}


InputNodeI::InputNodeI(const int id){
	this->setId(id);
}

int InputNodeI::getInputIndex(const int input0or1){
	std::cout << "Tried to get input from an input node.\n";
	return -1;
}
