/*
 * GraphI.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#include "GraphI.h"

GraphI::GraphI(int nNodes) {

	this = new AIGNodeI[nNodes];
}

GraphI::~GraphI() {
	// TODO Auto-generated destructor stub
}

int GraphI::getLastFreeIndex(){
	for(int i = 0; i < numNodes; i++){
		if(nodes[i] == NULL)
			return i;
	}
	std::cout << "No free index available!\n";
	return -1;
}

void GraphI::insertInputNode(const unsigned int id){
	nodes[getLastFreeIndex()] = new AIGNodeI(id);
}

void GraphI::insertOutputNode(const unsigned int id){
	nodes[getLastFreeIndex()] = new AIGNodeI(id);
}
void GraphI::insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1){
	int index = getLastFreeIndex();
	nodes[index] = new AIGNode(id);
}

