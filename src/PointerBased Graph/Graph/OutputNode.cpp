/*
 * OutputNode.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: lucas
 */

#include <iostream>
#include "AIGNode.h"
#include "OutputNode.h"


OutputNode::OutputNode(const int id){
	this->setId(id);
	input0 = NULL;
	input0Inverted = false;
}

OutputNode::~OutputNode(){
}


AigNodeType OutputNode::getNodeType(){
	return OUTPUT_NODE;
}


void OutputNode::setInputInverted(const bool inputInverted){
	this->input0Inverted = inputInverted;
}

bool OutputNode::isInputInverted(const int input0or1)const{
	if(input0or1 != 0)
		std::cout << "Output only has input 0\n";

	return this->input0Inverted;
}

void OutputNode::setInput(AIGNode* node){

	this->input0 = node;
}

AIGNode* OutputNode::getInput(){

	return this->input0;
}


