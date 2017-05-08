/*
 * BGraphI.cpp
 *
 *  Created on: 7 de abr de 2017
 *      Author: Lucas Alegre
 */

#include "../GraphI/GraphI.h"
#include "../GraphI/AIGNodeI.h"
#include "BGraphI.h"

BGraphI::BGraphI() {
	nodes = NULL;
	numNodes = -1;
	lastFreeIndex = 0;
}

BGraphI::~BGraphI() {
	delete[] nodes;
}


void BGraphI::initializeArray(const unsigned nNodes){
     nodes = new BAIGNodeI[nNodes];
     this->setNumNodes(nNodes);
}


void BGraphI::insertInputNode(const unsigned int id){
	new (&nodes[lastFreeIndex]) BAIGNodeI(id, INPUT_NODE);
	lastFreeIndex++;
}

void BGraphI::insertOutputNode(const unsigned int id){
	new (&nodes[lastFreeIndex + nAnds]) BAIGNodeI(id, OUTPUT_NODE);
	lastFreeIndex++;
}

void BGraphI::insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1){

	int index = lastFreeIndex - nOutputs;

	new (&nodes[index]) BAIGNodeI(id, AND_NODE);

	bool inp0Inverted;
	bool inp1Inverted;

	if(rhs0 % 2 == 0){
		inp0Inverted = false;
		nodes[index].setInputInverted(false, 0);
	}
	else{
		inp0Inverted = true;
		nodes[index].setInputInverted(true, 0);
		rhs0--;
	}

	if(rhs1 % 2 == 0){
		inp1Inverted = false;
		nodes[index].setInputInverted(false, 1);
	}
	else{
		inp1Inverted = true;
		nodes[index].setInputInverted(true, 1);
		rhs1--;
	}

	int indexInp0 = findNodeIndexById(rhs0);
	int indexInp1 = findNodeIndexById(rhs1);

	nodes[index].setInputIndex(indexInp0, 0);
	nodes[index].setInputIndex(indexInp1, 1);

	nodes[indexInp0].setOutputIndex(index, inp0Inverted);
	nodes[indexInp1].setOutputIndex(index, inp1Inverted);


	lastFreeIndex++;
}

void BGraphI::connectOutputs(){

	for(unsigned i = nInputs + nAnds; i < nInputs + nOutputs + nAnds; i++){  // Pass through all outputs

		int idinp = nodes[i].getId();
        bool inpInverted = false;

		if(idinp % 2 != 0){
			inpInverted = true;
			nodes[i].setInputInverted(true, 0);
			idinp--;
		}

		int inpIndex = findNodeIndexById(idinp);
		nodes[i].setInputIndex(inpIndex, 0);
		nodes[inpIndex].setOutputIndex(i, inpInverted);

	}
}

void BGraphI::print(){


	for(unsigned i = 0; i < nInputs; i++){
		std::cout << "Id: " << nodes[i].getId() << endl;
		std::cout << " name: " << nodes[i].getName() << endl;

		for(unsigned j = 0; j < nodes[i].getFanOutSize(); j++){
			unsigned index = nodes[i].getOutputIndex(j);
			cout << " s"<<j<<": " << nodes[index].getId() << " inv? " << nodes[i].getOutputInverted(j) << endl;
		}
	}

	for(unsigned i = nInputs; i < nAnds + nInputs; i++){

		std::cout << "Id: " << nodes[i].getId() << endl;
		std::cout << " name: " << nodes[i].getName() << endl;
		int in0 = nodes[i].getInputIndex(0);
		int in1 = nodes[i].getInputIndex(1);
		if(in0 != -1)
			cout << " in0: " << nodes[in0].getId() << " inv? " << nodes[i].isInputInverted(0) << endl;
		if(in1 != -1)
			cout << " in1: " << nodes[in1].getId() << " inv? " << nodes[i].isInputInverted(1) << endl << endl;

		for(unsigned j = 0; j < nodes[i].getFanOutSize(); j++){
			unsigned index = nodes[i].getOutputIndex(j);
			cout << " s"<<j<<": " << nodes[index].getId() << " inv? " << nodes[i].getOutputInverted(j) << endl;
		}


	}

	for(unsigned i = nInputs + nAnds; i < numNodes; i++){

		std::cout << "Id: " << nodes[i].getId() << endl;
		std::cout << " name: " << nodes[i].getName() << endl;
		int in0 = nodes[i].getInputIndex(0);
		if(in0 != -1)
			cout << " in0: " << nodes[in0].getId() << " inv? " << nodes[i].isInputInverted(0) << endl;
	}
}
