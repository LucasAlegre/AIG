/*
 * AIGNodeI.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#include "../GraphI/AIGNodeI.h"

#include <iostream>

AIGNodeI::AIGNodeI(){
	this->id = -1;
	this->nodeType = INPUT_NODE;
	indexInput0 = -1;
	indexInput1 = -1;
	input0Inverted = false;
	input1Inverted = false;
}

AIGNodeI::~AIGNodeI() {
	// TODO Auto-generated destructor stub
}


AIGNodeI::AIGNodeI(unsigned id, AigNodeType nodeType){
	this->id = id;
	this->nodeType = nodeType;
	indexInput0 = -1;
	indexInput1 = -1;
	input0Inverted = false;
	input1Inverted = false;
}


std::string AIGNodeI::getName() const {
	return name;
}

void AIGNodeI::setName(std::string name) {
	this->name = name;
}

unsigned AIGNodeI::getId() const {
	return id;
}

void AIGNodeI::setId(unsigned id) {
	this->id = id;
}


void AIGNodeI::setInputIndex(const int index, const int input0or1){
	if(nodeType == INPUT_NODE){
		std::cout << "Trie to set input to an input node\n";
		exit(-1);
	}

	if(input0or1 == 0)
		indexInput0 = index;
	else if(input0or1 == 1)
		indexInput1 = index;

}
bool AIGNodeI::isInputInverted(const int input0or1) const{
	if(nodeType == INPUT_NODE){
		std::cout << "Trie to get inputInverted from an input node\n";
		return false;
	}

	if(input0or1 == 0)
		return input0Inverted;
	else if(input0or1 == 1)
		return input1Inverted;
	else{
		std::cout << "invalid parameter to get input inverted\n";
		return false;
	}
}
int AIGNodeI::getInputIndex(const int input0or1){
	if(nodeType == INPUT_NODE){
		std::cout << "Trie to get input index from an input node\n";
		return -1;
	}

	if(input0or1 == 0)
		return indexInput0;
	else if(input0or1 == 1)
		if(nodeType == OUTPUT_NODE){
			std::cout << "Output node only has input0\n";
			return -1;
		}
		else
			return indexInput1;
	else{
		std::cout << "invalid parameter to get input index\n";
		return -1;
	}


}
void AIGNodeI::setInputInverted(const bool inputInverted, const int input0or1){
	if(nodeType == INPUT_NODE){
		std::cout << "Trie to set input inverted to an input node\n";
	}

	if(input0or1 == 0)
		input0Inverted = inputInverted;
	else if(input0or1 == 1)
		input1Inverted = inputInverted;
	else{
		std::cout << "invalid parameter to get input index\n";
	}

}

AigNodeType AIGNodeI::getNodeType() const {
	return nodeType;
}

void AIGNodeI::setNodeType(AigNodeType nodeType) {
	this->nodeType = nodeType;
}

