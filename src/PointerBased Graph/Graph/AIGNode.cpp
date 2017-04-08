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

void AIGNode::setOutput(AIGNode* node, bool inverted){
        cout << "Tried to set ouput to an unidirected node\n";
}

vector<bool> * AIGNode::getOutputsInverted(){
	cout << "Tried to get ouputs inverted from an unidirected node\n";
	return NULL;
}

