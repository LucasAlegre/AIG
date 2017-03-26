/*
 * AndNodeI.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#include "AndNodeI.h"

AndNodeI::~AndNodeI() {
	// TODO Auto-generated destructor stub
}

AndNodeI::AndNodeI(const int id){
	this->setId(id);
	this->setName(patch::to_string(id));
	indexInput0 = -1;
	indexInput1 = -1;
	input0Inverted = false;
	input1Inverted = false;
}


bool AndNodeI::isInputInverted(const int input0or1)const{
     if(input0or1 == 0)
    	 return this->input0Inverted;

     else if(input0or1 == 1)
    	 return this->input1Inverted;

     else{
    	 std::cout << "Invalid input number" << "\n";
    	 return false;
     }
}

void AndNodeI::setInputInverted(const bool inputInverted, const int input0or1){
    if(input0or1 == 0)
   	 this->input0Inverted = inputInverted;

    else if(input0or1 == 1)
   	 this->input1Inverted = inputInverted;

    else{
   	 std::cout << "Invalid input number" << "\n";
    }
}


void AndNodeI::setInputIndex(const int index0, const int index1){
	this->indexInput0 = index0;
	this->indexInput1 = index1;
}

int AndNodeI::getInputIndex(const int input0or1){

	if(input0or1 == 0)
		return this->indexInput0;
	else if(input0or1 == 1)
		return this->indexInput1;
	else{
		cout << "Invalid parameter \n";
		return -1;
	}
}
