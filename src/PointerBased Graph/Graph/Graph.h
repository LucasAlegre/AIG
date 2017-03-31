/*
 * Graph.h
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <iostream>
#include <memory>
#include "../../PointerBased Graph/Graph/AIGNode.h"

typedef std::shared_ptr<AIGNode> AIGNode_ptr;
typedef std::shared_ptr<InputNode> InputNode_ptr;
typedef std::shared_ptr<OutputNode> OutputNode_ptr;
typedef std::shared_ptr<OutputNode> AndNode_ptr;

using namespace std;

/* 
* Abstract Class for AIG Graph with Pointers
*
*/
class GRAPH{
public:
	virtual ~GRAPH(){};
	virtual void insertInputNode(const unsigned int id) = 0;
	virtual void insertOutputNode(const unsigned int id) = 0;
	virtual void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1) = 0;
	virtual void addOutputToNodes() = 0;  // Insert the outputs vector at the end of the nodes vector

	virtual AIGNode* findNodeById(const unsigned int id) = 0;

	virtual void connectOutputs() = 0;

	virtual vector<AIGNode_ptr> * getNodes() = 0;
	virtual vector<InputNode_ptr> * getInputNodes() = 0;
	virtual vector<AndNode_ptr> * getAndNodes() = 0;
	virtual vector<OutputNode_ptr> * getOutputNodes() = 0;
};

/*
* Class that implements an AIG Graph with Pointers
*
*/
class Graph: public GRAPH{
private:
    vector<AIGNode_ptr> nodes;
    vector<InputNode_ptr> inputs;
    vector<OutputNode_ptr> outputs;
    vector<AndNode_ptr> andNodes;

public:
	Graph();
	~Graph();

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


#endif /* GRAPH_H_ */
