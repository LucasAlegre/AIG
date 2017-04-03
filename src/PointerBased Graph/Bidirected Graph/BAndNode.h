/*
 * BAndNode.h
 *
 *  Created on: Apr 3, 2017
 *      Author: lucas
 */

#ifndef POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BANDNODE_H_
#define POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BANDNODE_H_

#include <vector>
#include <iostream>
#include "../Graph/AIGNode.h"

/*
 * Bidirected AND Node
 */
class BAndNode: public AndNode{
private:
	vector<AIGNode*> outputs;
	vector<bool> outputsInverted;
public:
	BAndNode(const unsigned id): AndNode(id){}

	AigNodeType getNodeType(){
		return AND_NODE;
	}

	vector<AIGNode*> * getOutputs(){
		return &(this->outputs);
	}

	void setOutput(AIGNode* node){
		outputs.push_back(node);
	}

	vector<bool> * getOutputsInverted(){
		return &(this->outputsInverted);
	}

};



#endif /* POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BANDNODE_H_ */
