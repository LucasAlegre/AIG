/*
 * BAIGNodeI.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: lucas
 */

#include <iostream>

#include "BAIGNodeI.h"

BAIGNodeI::BAIGNodeI() {
	freeIndexFanOut = 0;
}

BAIGNodeI::~BAIGNodeI() {
	// TODO Auto-generated destructor stub
}

BAIGNodeI::BAIGNodeI(unsigned id, AigNodeType nodeType): AIGNodeI(id, nodeType){
	freeIndexFanOut = 0;
}


void BAIGNodeI::setOutputIndex(int index, bool inverted){
	fanOut[freeIndexFanOut] = index;
	invertedFanOut[freeIndexFanOut] = inverted;

	freeIndexFanOut++;
}

int BAIGNodeI::getOutputIndex(int i){
	return fanOut[i];
}

int BAIGNodeI::getOutputInverted(int i){
	return invertedFanOut[i];
}
