/*
 * Graph.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "Graph.h"
#include <vector>
#include <iostream>

Graph::Graph() {
	// TODO Auto-generated constructor stub
}

Graph::~Graph() {
}

void Graph::addOutputToNodes(){
	this->nodes.insert(nodes.end(), outputs.begin(), outputs.end());
}

vector<AIGNode*> * Graph::getNodes(){
	return &(this->nodes);
}

vector<InputNode*> * Graph::getInputNodes(){
	return &(this->inputs);
}

vector<OutputNode*> * Graph::getOutputNodes(){
	return &(this->outputs);
}

vector<AndNode*> * Graph::getAndNodes(){
	return &(this->andNodes);
}

void Graph::insertInputNode(const unsigned id){

	InputNode* input = new InputNode(id);

	this->inputs.push_back(input);
	this->nodes.push_back(input);
}

void Graph::insertOutputNode(const unsigned id){

	OutputNode* output = new OutputNode(id);

	this->outputs.push_back(output);
}

void Graph::insertAndNode(const unsigned id, unsigned rhs0, unsigned rhs1){

	AndNode* andnode = new AndNode(id);

	if(rhs0 % 2 == 0){
		andnode->setInputInverted(false, 0);
	}
	else{
		andnode->setInputInverted(true, 0);
		rhs0--;
	}

	if(rhs1 % 2 == 0){
		andnode->setInputInverted(false, 1);
	}
	else{
		andnode->setInputInverted(true, 1);
		rhs1--;
	}

	andnode->setInput(findNodeById(rhs0), findNodeById(rhs1));

	this->andNodes.push_back(andnode);
	this->nodes.push_back(andnode);
}

//it only works for And and Input Nodes
AIGNode* Graph::findNodeById(const unsigned int id){

	/*vector<AIGNode*>::iterator it;

	for(it = nodes.begin(); it < nodes.end(); it++){
		if((*it)->getId() == id){
			return *it;
		}
	}*/

	if(id == 0)
		return nodes[0];

	return nodes[id/2];
}
