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
	void setOutput(AIGNode* node){
		outputs.push_back(node);
	}
	vector<bool> * getOutputsInverted(){
		return &(this->outputsInverted);
	}
};




#endif /* POINTERBASED_GRAPH_BIDIRECTED_GRAPH_BINPUTNODE_H_ */
