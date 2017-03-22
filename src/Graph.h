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

/* Graph with Pointers
*
*/

class GRAPH{
public:
	virtual void insertInputNode(const unsigned int id) = 0;
	virtual void insertOutputNode(const unsigned int id) = 0;
	virtual void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1) = 0;
	virtual void addOutputToNodes() = 0;  // Insert the outputs vector at the end of the nodes vector

	virtual AIGNode* findNodeById(const unsigned int id) = 0;

	virtual vector<AIGNode*> * getNodes() = 0;
	virtual vector<InputNode*> * getInputNodes() = 0;
	virtual vector<AndNode*> * getAndNodes() = 0;
	virtual vector<OutputNode*> * getOutputNodes() = 0;
};

class Graph: public GRAPH{
private:
    vector<AIGNode*> nodes;
    vector<InputNode*> inputs;
    vector<OutputNode*> outputs;
    vector<AndNode*> andNodes;

public:
	Graph();
	virtual ~Graph();

	void insertInputNode(const unsigned int id);
	void insertOutputNode(const unsigned int id);
	void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1);
	void addOutputToNodes();  // Insert the outputs vector at the end of the nodes vector

	AIGNode* findNodeById(const unsigned int id);

	vector<AIGNode*> * getNodes();
	vector<InputNode*> * getInputNodes();
	vector<AndNode*> * getAndNodes();
	vector<OutputNode*> * getOutputNodes();

};


#endif /* GRAPH_H_ */
