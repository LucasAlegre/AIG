/*
 * Graph.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "Graph.h"
#include <vector>
#include <iostream>

using namespace std;

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

void Graph::insertInputNode(InputNode* input){
	this->inputs.push_back(input);
	this->nodes.push_back(input);
}

void Graph::insertOutputNode(OutputNode* output){
	this->outputs.push_back(output);
}

void Graph::insertAndNode(AndNode* andNode){
	this->andNodes.push_back(andNode);
	this->nodes.push_back(andNode);
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
