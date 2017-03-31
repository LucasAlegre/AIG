/*
 * Graph.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "Graph.h"
#include "AIGNode.h"
#include <iterator>


Graph::Graph() {
	// TODO Auto-generated constructor stub
}

Graph::~Graph() {
	for(auto it = nodes.begin(); it < nodes.end(); it++){
		delete *it;
	}
}

void Graph::addOutputToNodes(){
	this->nodes.insert(nodes.end(), outputs.begin(), outputs.end());
}

vector<AIGNode_ptr> * Graph::getNodes(){
	return &(this->nodes);
}

vector<InputNode_ptr> * Graph::getInputNodes(){
	return &(this->inputs);
}

vector<OutputNode_ptr> * Graph::getOutputNodes(){
	return &(this->outputs);
}

vector<AndNode_ptr> * Graph::getAndNodes(){
	return &(this->andNodes);
}

void Graph::insertInputNode(const unsigned id){

    InputNode_ptr input(new InputNode(id));

	this->inputs.push_back(input);
	this->nodes.push_back(input);
}

void Graph::insertOutputNode(const unsigned id){

	OutputNode_ptr output(new OutputNode(id));

	this->outputs.push_back(output);
}

void Graph::insertAndNode(const unsigned id, unsigned rhs0, unsigned rhs1){

	AndNode_ptr andnode = make_shared<AndNode>(id);

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

//Connect the outputs to its inputs
void Graph::connectOutputs(){

    vector<OutputNode*>::iterator it;
    vector<OutputNode*> *outputs = this->getOutputNodes();
	for(it = outputs->begin(); it < outputs->end(); it++){
		int idinp = (*it)->getId();
		if(idinp % 2 != 0){
			(*it)->setInputInverted(true, 0);
			idinp--;
		}
		AIGNode* node = this->findNodeById(idinp);
		(*it)->setInput(node);
	}
	this->addOutputToNodes();
}

//it only works for And and Input Nodes
AIGNode* Graph::findNodeById(const unsigned int id){

	if(id == 0)
		return nodes[0];

	return nodes[id/2];
}
