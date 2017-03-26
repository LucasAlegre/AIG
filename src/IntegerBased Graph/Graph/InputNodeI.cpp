/*
 * InputNodeI.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#include "InputNodeI.h"

InputNodeI::InputNodeI() {
	// TODO Auto-generated constructor stub

}

InputNodeI::~InputNodeI() {
	// TODO Auto-generated destructor stub
}


InputNodeI::InputNodeI(const unsigned id):AIGNodeI(id){
	this->setId(id);
}

AIGNodeI* InputNodeI::getInput(const int input0or1){
	cout << "Tried to get input from an input node.\n";
	return NULL;
}
