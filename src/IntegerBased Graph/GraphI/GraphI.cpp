/*
 * GraphI.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#include "../GraphI/GraphI.h"

#include "../GraphI/AIGNodeI.h"

GraphI::GraphI() {
	nodes = NULL;
	numNodes = -1;
	lastFreeIndex = 0;
}

GraphI::~GraphI() {
	delete[] nodes;
}

unsigned GRAPHI::getLastFreeIndex(){
	return this->lastFreeIndex;
}


void GraphI::initializeArray(const unsigned nNodes){
     nodes = new AIGNodeI[nNodes];
     this->numNodes = nNodes;
}

int GRAPHI::findNodeIndexById(const unsigned int id){

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

	unsigned index = lastFreeIndex - nOutputs;

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

	for(unsigned i = nInputs + nAnds; i < nInputs + nOutputs + nAnds; i++){

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

void GraphI::print(){

	for(unsigned i = 0; i < nInputs; i++){
		std::cout << "Id: " << nodes[i].getId() << endl;
		std::cout << " name: " << nodes[i].getName() << endl;
	}

	for(unsigned i = nInputs; i < nAnds + nInputs; i++){

		std::cout << "Id: " << nodes[i].getId() << endl;
		std::cout << " name: " << nodes[i].getName() << endl;
		int in0 = nodes[i].getInputIndex(0);
		int in1 = nodes[i].getInputIndex(1);
		if(in0 != -1)
			cout << " in0: " << nodes[in0].getId() << " inv? " << nodes[i].isInputInverted(0) << endl;
		if(in1 != -1)
			cout << " in1: " << nodes[in1].getId() << " inv? " << nodes[i].isInputInverted(1) << endl;
	}

	for(unsigned i = nInputs + nAnds; i < numNodes; i++){

		std::cout << "Id: " << nodes[i].getId() << endl;
		std::cout << " name: " << nodes[i].getName() << endl;
		int in0 = nodes[i].getInputIndex(0);
		if(in0 != -1)
			cout << " in0: " << nodes[in0].getId() << " inv? " << nodes[i].isInputInverted(0) << endl;
	}

}

unsigned GRAPHI::getNumNodes()const{
	return this->numNodes;
}



unsigned GRAPHI::getNumAnds() const {
	return nAnds;
}

void GRAPHI::setNumAnds(unsigned ands) {
	nAnds = ands;
}

unsigned GRAPHI::getNumFFs() const {
	return nFFs;
}

void GRAPHI::setNumFFs(unsigned fFs) {
	nFFs = fFs;
}

unsigned GRAPHI::getNumInputs() const {
	return nInputs;
}

void GRAPHI::setNumInputs(unsigned inputs) {
	nInputs = inputs;
}

unsigned GRAPHI::getNumOutputs() const {
	return nOutputs;
}

void GRAPHI::setNumOutputs(unsigned outputs) {
	nOutputs = outputs;
}

void GRAPHI::setNumNodes(unsigned numNodes) {
	this->numNodes = numNodes;
}
