/*
 * AIGNode.cpp
 *
 *  AIG Nodes functions implementations
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "AIGNode.h"
#include <iostream>
#include "Graph.h"

using namespace std;

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

// --------------------- AIG Node ------------------------------

//Default constructor
AIGNode::AIGNode(){
	id=-1;
}
//Constructor
AIGNode::AIGNode(const unsigned id){
	this->id = id;
}

//Default destructor
AIGNode::~AIGNode(){}

// Getters and Setters
void AIGNode::setId(const unsigned id){
	this->id = id;
}
unsigned int AIGNode::getId() const{
	return this->id;
}	
void AIGNode::setName(string name){
	this->name = name;
}
string AIGNode::getName()const{
	return this->name;
}

vector<AIGNode*> * AIGNode::getOutputs(){
	cout << "Tried to get ouput from an unidirected node\n";
	return NULL;
}
void AIGNode::setOutput(AIGNode* node){
        cout << "Tried to set ouput to an unidirected node\n";
}
vector<bool> * AIGNode::getOutputsInverted(){
	cout << "Tried to get ouputs inverted from an unidirected node\n";
	return NULL;
}

// --------------------- InputNode-------------------------------

AigNodeType InputNode::getNodeType(){
	return INPUT_NODE;
}

InputNode::InputNode(const unsigned id):AIGNode(id){
	this->setId(id);
}

AIGNode* InputNode::getInput(const int input0or1){
	cout << "Tried to get input from an input node.\n";
	return NULL;
}

// ----------------------- Output Node --------------------------

OutputNode::OutputNode(const int id){
	this->setId(id);
	input0 = NULL;
	input0Inverted = false;
}

OutputNode::~OutputNode(){
	delete input0;
}


AigNodeType OutputNode::getNodeType(){
	return OUTPUT_NODE;
}


void OutputNode::setInputInverted(const bool inputInverted){
	this->input0Inverted = inputInverted;
}

bool OutputNode::isInputInverted()const{
	return this->input0Inverted;
}

void OutputNode::setInput(AIGNode* node){

	this->input0 = node;
}

AIGNode* OutputNode::getInput(){

	return this->input0;
}

// ------------------------ AND Node ------------------------------

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
		cout << "Invalid parameter \n";
		return NULL;
	}
}
