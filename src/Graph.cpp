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
	this->nodes.push_back(output);

}

void Graph::insertAndNode(AndNode* andNode){
	this->andNodes.push_back(andNode);
	this->nodes.push_back(andNode);

}

AIGNode* Graph::findNodeById(const unsigned int id){
	vector<AIGNode*>::iterator it;

	for(it = nodes.begin(); it < nodes.end(); it++){
		if((*it)->getId() == id){
			return *it;
		}
	}
	return NULL;
}


InputNode* Graph::findInputById(const unsigned int id){
	vector<InputNode*>::iterator it;

	for(it = inputs.begin(); it < inputs.end(); it++){
		if((*it)->getId() == id){
			return *it;
		}
	}
	return NULL;
}
OutputNode* Graph::findOutputtById(const unsigned int id){

	vector<OutputNode*>::iterator it;

	for(it = outputs.begin(); it < outputs.end(); it++){
		if((*it)->getId() == id){
			return *it;
		}
	}
	return NULL;
}
AndNode* Graph::findAndById(const unsigned int id){

	vector<AndNode*>::iterator it;

	for(it = andNodes.begin(); it < andNodes.end(); it++){
		if((*it)->getId() == id){
			return *it;
		}
	}
	return NULL;
}
