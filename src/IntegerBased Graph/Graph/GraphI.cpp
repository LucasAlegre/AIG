/*
 * GraphI.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#include "GraphI.h"
#include "InputNodeI.h"
#include "OutputNodeI.h"
#include "AndNodeI.h"


GraphI::GraphI(int nNodes) {

	nodes = new AIGNodeI[nNodes];
	numNodes = nNodes;
	lastFreeIndex = 0;
}

GraphI::~GraphI() {
	delete[] nodes;
}

int GraphI::getLastFreeIndex(){
	return this->lastFreeIndex;
}


int GraphI::findNodeIndexById(const unsigned int id){

	if(id == 0)
		return 0;

	return id/2;
}

void GraphI::insertInputNode(const unsigned int id){
	new (&nodes[lastFreeIndex]) InputNodeI(id);
	lastFreeIndex++;
}

void GraphI::insertOutputNode(const unsigned int id){
    new (&nodes[lastFreeIndex]) OutputNodeI(id);
	lastFreeIndex++;
}

void GraphI::insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1){

	int index = lastFreeIndex;

	new (&nodes[index]) AndNodeI(id);

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

