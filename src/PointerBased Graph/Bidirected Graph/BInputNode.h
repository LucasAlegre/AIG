/*
 * BInputNode.h
 *
 *  Created on: Apr 3, 2017
 *      Author: lucas
 */

#ifndef POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BINPUTNODE_H_
#define POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BINPUTNODE_H_

#include <vector>
#include "../Graph/AIGNode.h"

/*
 *  Bidirected Input Node
 */
class BInputNode: public InputNode {
private:
	vector<AIGNode*> outputs;
	vector<bool> outputsInverted;
public:
	BInputNode(const unsigned id): InputNode(id){}

	AigNodeType getNodeType(){
		return INPUT_NODE;
	}
	vector<AIGNode*> * getOutputs(){
		return &(this->outputs);
	}
	void setOutput(AIGNode* node, bool inverted){
		outputs.push_back(node);
		outputsInverted.push_back(inverted);
	}
	vector<bool> * getOutputsInverted(){
		return &(this->outputsInverted);
	}
	AIGNode* getOutput(int x){
		return outputs.at(x);
	}
	bool getOutputInverted(int x){
		return outputsInverted.at(x);
	}
};




#endif /* POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BINPUTNODE_H_ */
