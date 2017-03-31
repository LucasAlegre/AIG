/*
 * BGraph.h
 *
 *  Created on: Mar 22, 2017
 *      Author: lucas
 */

#ifndef BGRAPH_H_
#define BGRAPH_H_

#include <vector>
#include <iostream>

#include "../../PointerBased Graph/Graph/AIGNode.h"
#include "../../PointerBased Graph/Graph/Graph.h"

class BGraph:public GRAPH {
private:
    vector<AIGNode*> nodes;
    vector<InputNode*> inputs;
    vector<OutputNode*> outputs;
    vector<AndNode*> andNodes;

public:
	BGraph();
	virtual ~BGraph();

	void insertInputNode(const unsigned int id);
	void insertOutputNode(const unsigned int id);
	void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1);
	void addOutputToNodes();  // Insert the outputs vector at the end of the nodes vector

	AIGNode* findNodeById(const unsigned int id);

	void connectOutputs();

	vector<AIGNode_ptr> * getNodes();
	vector<InputNode_ptr> * getInputNodes();
	vector<AndNode_ptr> * getAndNodes();
	vector<OutputNode_ptr> * getOutputNodes();
};



#endif /* BGRAPH_H_ */
