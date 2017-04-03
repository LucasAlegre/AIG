/*
 * AndNode.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: lucas
 */

#include <iostream>
#include "AIGNode.h"
#include "AndNode.h"

AndNode::AndNode(int id){
	this->setId(id);
	this->setName(patch::to_string(id));
	input0 = NULL;
	input1 = NULL;
	input0Inverted = false;
	input1Inverted = false;
}

AigNodeType AndNode::getNodeType(){
	return AND_NODE;
}

bool AndNode::isInputInverted(const int input0or1)const{
     if(input0or1 == 0)
    	 return this->input0Inverted;

     else if(input0or1 == 1)
    	 return this->input1Inverted;

     else{
    	 std::cout << "Invalid input number" << "\n";
    	 return false;
     }
}

void AndNode::setInputInverted(const bool inputInverted, const int input0or1){
    if(input0or1 == 0)
   	 this->input0Inverted = inputInverted;

    else if(input0or1 == 1)
   	 this->input1Inverted = inputInverted;

    else{
   	 std::cout << "Invalid input number" << "\n";
    }
}


void AndNode::setInput(AIGNode* in0, AIGNode *in1){
	this->input0 = in0;
	this->input1 = in1;
}

AIGNode* AndNode::getInput(const int input0or1){

	if(input0or1 == 0)
		return this->input0;
	else if(input0or1 == 1)
		return this->input1;
	else{
		std::cout << "Invalid parameter \n";
		return NULL;
	}
}


