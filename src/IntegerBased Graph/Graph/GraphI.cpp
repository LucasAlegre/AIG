/*
 * GraphI.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#include "GraphI.h"
#include "AIGNodeI.h"

GraphI::GraphI() {
	nodes = NULL;
	numNodes = -1;
	lastFreeIndex = 0;
}

GraphI::~GraphI() {

}

int GRAPHI::getLastFreeIndex(){
	return this->lastFreeIndex;
}


void GraphI::iniatializeArray(const int nNodes){
     nodes = new AIGNodeI[nNodes];
     this->numNodes = nNodes;
}

int GraphI::findNodeIndexById(const unsigned int id){

	if(id == 0)
		return 0;

	return id/2;
}

void GraphI::insertInputNode(const unsigned int id){
	new (&nodes[lastFreeIndex]) AIGNodeI(id, INPUT_NODE);
	lastFreeIndex++;
}

void GraphI::insertOutputNode(const unsigned int id){
	new (&nodes[lastFreeIndex + nAnds]) AIGNodeI(id, OUTPUT_NODE);
	lastFreeIndex++;
}

void GraphI::insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1){

	int index = lastFreeIndex - nOutputs;

	new (&nodes[index]) AIGNodeI(id, AND_NODE);

	if(rhs0 % 2 == 0){
		nodes[index].setInputInverted(false, 0);
	}
	else{
		nodes[index].setInputInverted(true, 0);
		rhs0--;
	}

	if(rhs1 % 2 == 0){
		nodes[index].setInputInverted(false, 1);
	}
	else{
		nodes[index].setInputInverted(true, 1);
		rhs1--;
	}

	nodes[index].setInputIndex(findNodeIndexById(rhs0), 0);
	nodes[index].setInputIndex(findNodeIndexById(rhs1), 1);

	lastFreeIndex++;
}

void GraphI::connectOutputs(){

	for(int i = nInputs + nAnds + 1; i <= nInputs + nOutputs + nAnds; i++){

		int idinp = nodes[i].getId();

		if(idinp % 2 != 0){
			nodes[i].setInputInverted(true, 0);
			idinp--;
		}

		nodes[i].setInputIndex(findNodeIndexById(idinp), 0);

	}
}

AIGNodeI* GraphI::getNodes(){
	return nodes;
}

int GRAPHI::getNumNodes(){
	return this->numNodes;
}
