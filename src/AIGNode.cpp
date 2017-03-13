/*
 * AIGNode.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "AIGNode.h"
#include "Graph.h"
#include<iostream>

AIGNode::AIGNode() {
    id = -1;
}

AIGNode::~AIGNode() {
	// TODO Auto-generated destructor stub
}

void AIGNode::setId(const int id){
	this->id = id;
}

int AIGNode::getId()const{
	return this->id;
}

AigNodeType InputNode::getNodeType(){
	return INPUT_NODE;
}

AigNodeType OutputNode::getNodeType(){
	return OUTPUT_NODE;
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

void OutputNode::setInputInverted(const bool inputInverted){
	this->input0Inverted = inputInverted;
}

bool OutputNode::isInputInverted()const{
	return this->input0Inverted;
}


void OutputNode::setInput(AIGNode* node){

	this->input0 = node;

	if(node->getId() % 2 == 0){
		this->setInputInverted(false);
	}
	else{
		this->setInputInverted(true);
	}
}

AIGNode* OutputNode::getInput(const int input0or1){
	return this->input0;
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
		cout << "Invalid parameter \n";
		return NULL;
	}
}


InputNode::InputNode(const int id){
	this->setId(id);
}

OutputNode::OutputNode(const int id){
	this->setId(id);
	input0 = NULL;
	input0Inverted = false;
}

AndNode::AndNode(const int id){
	this->setId(id);
	input0 = NULL;
	input1 = NULL;
	input0Inverted = false;
	input1Inverted = false;
}
