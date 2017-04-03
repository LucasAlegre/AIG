/*
 * BOutputNode.h
 *
 *  Created on: Apr 3, 2017
 *      Author: lucas
 */

#ifndef POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BOUTPUTNODE_H_
#define POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BOUTPUTNODE_H_

#include <iostream>
#include <vector>
#include "../Graph/AIGNode.h"

class BOutputNode: public OutputNode {
public:
	BOutputNode(const unsigned id): OutputNode(id)	{}

	AigNodeType getNodeType(){
		return OUTPUT_NODE;
	}
	vector<AIGNode*> * getOutputs(){
		std::cout << "Tried to get outputs from an output node\n";
		return NULL;
	}
	void setOutput(AIGNode* node){
		std::cout << "Tried to set an output for an output node\n";
	}
	vector<bool> * getOutputsInverted(){
		std::cout << "Tried to get outputs inverted from an output node\n";
		return NULL;
	}
};


#endif /* POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BOUTPUTNODE_H_ */
