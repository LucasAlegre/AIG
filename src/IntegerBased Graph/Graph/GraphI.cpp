/*
 * GraphI.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#include "GraphI.h"

GraphI::GraphI(int nNodes) {

	this->nodes = new AIGNodeI[nNodes];
	numNodes = nNodes;
	lastFreeIndex = 0;
}

GraphI::~GraphI() {
	// TODO Auto-generated destructor stub
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
	nodes[lastFreeIndex] = new AIGNodeI(id);
	lastFreeIndex++;
}

void GraphI::insertOutputNode(const unsigned int id){
	nodes[lastFreeIndex] = new AIGNodeI(id);
	lastFreeIndex++;
}
void GraphI::insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1){

	int index = lastFreeIndex;

	nodes[index] = new AndNodeI(id);

	if(rhs0 % 2 == 0){
		((AndNodeI)nodes[index]).setInputInverted(false, 0);
	}
	else{
		((AndNodeI)nodes[index]).setInputInverted(true, 0);
		rhs0--;
	}

	if(rhs1 % 2 == 0){
		((AndNodeI)nodes[index]).setInputInverted(false, 1);
	}
	else{
		((AndNodeI)nodes[index]).setInputInverted(true, 1);
		rhs1--;
	}

	((AndNodeI)nodes[index]).setInput(findNodeIndexById(rhs0), findNodeIndexById(rhs1));

	lastFreeIndex++;
}

