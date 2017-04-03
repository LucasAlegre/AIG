/*
 * InputNode.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: lucas
 */

#include <iostream>
#include "AIGNode.h"
#include "InputNode.h"

AigNodeType InputNode::getNodeType(){
	return INPUT_NODE;
}

InputNode::InputNode(const unsigned id):AIGNode(id){
	this->setId(id);
}

AIGNode* InputNode::getInput(const int input0or1){
	std::cout << "Tried to get input from an input node.\n";
	return NULL;
}



