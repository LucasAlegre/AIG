/*
 * Graph.h
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include "AIGNode.h"
#include <iostream>

using namespace std;

class Graph {
private:
    vector<AIGNode*> nodes;
    vector<InputNode*> inputs;
    vector<OutputNode*> outputs;
    vector<AndNode*> andNodes;

public:
	Graph();
	virtual ~Graph();

	void insertInputNode(InputNode* input);
	void insertOutputNode(OutputNode* output);
	void insertAndNode(AndNode* andNode);

	AIGNode* findNodeById(const unsigned int id);
	InputNode* findInputById(const unsigned int id);
	OutputNode* findOutputtById(const unsigned int id);
	AndNode* findAndById(const unsigned int id);

	vector<AIGNode*> * getNodes();
	vector<InputNode*> * getInputNodes();
	vector<AndNode*> * getAndNodes();
	vector<OutputNode*> * getOutputNodes();

};

#endif /* GRAPH_H_ */
