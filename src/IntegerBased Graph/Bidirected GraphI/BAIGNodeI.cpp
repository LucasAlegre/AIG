/*
 * BAIGNodeI.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: lucas
 */

#include <iostream>

#include "BAIGNodeI.h"

BAIGNodeI::BAIGNodeI() {

}

BAIGNodeI::~BAIGNodeI() {
	// TODO Auto-generated destructor stub
}

BAIGNodeI::BAIGNodeI(const unsigned id, const AigNodeType nodeType): AIGNodeI(id, nodeType){

}

void BAIGNodeI::setOutputIndex(const unsigned index,const bool inverted){

    fanOut.push_back(index);
    invertedFanOut.push_back(inverted);

}

unsigned BAIGNodeI::getOutputIndex(unsigned i)const{
	return fanOut[i];
}

bool BAIGNodeI::getOutputInverted(unsigned i)const{
	return invertedFanOut[i];
}

unsigned BAIGNodeI::getFanOutSize(){
	return fanOut.size();
}
