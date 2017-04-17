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
#include "../../PointerBased Graph/Graph/AIGNode.h"
#include "InputNode.h"
#include "OutputNode.h"
#include "AndNode.h"

//using namespace std;

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

	virtual vector<AIGNode*> * getNodes() = 0;
	virtual vector<InputNode*> * getInputNodes() = 0;
	virtual vector<AndNode*> * getAndNodes() = 0;
	virtual vector<OutputNode*> * getOutputNodes() = 0;

	virtual void print() = 0;
};

/*
* Class that implements an AIG Graph with Pointers
*
*/
class Graph: public GRAPH{
private:
    vector<AIGNode*> nodes;
    vector<InputNode*> inputs;
    vector<OutputNode*> outputs;
    vector<AndNode*> andNodes;

public:
	Graph();
	virtual ~Graph();

	/*
	 *  Insert an InputNode to vectors "nodes" and "inputs"
	 *  @param id Id of the input
	 */
	void insertInputNode(const unsigned int id);

	/*
	 *  Insert an OutputNode to vector "outputs"
	 *  @param id Id of the output
	 */
	void insertOutputNode(const unsigned int id);

	/*
	 *  Insert an ANDNode to vectors "nodes" and "andNodes"
	 *  @param id Id of the AND
	 *  @param rhs0 Literal of the first input
	 *  @param rhs1 Literal of the second input
	 */
	void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1);

	/*
	 * Insert the outputs vector at the end of the nodes vector
	 */
	void addOutputToNodes();

	/*
	 *   Find a node given his id
	 *   @param id Id of the wanted node
	 *   @return pointer to wanted node
	 */
	AIGNode* findNodeById(const unsigned int id);

	/*
	 *  Sets the input pointer to all of the Ouput Nodes of the Graph
	 */
	void connectOutputs();

	void print();

	vector<AIGNode*> * getNodes();
	vector<InputNode*> * getInputNodes();
	vector<AndNode*> * getAndNodes();
	vector<OutputNode*> * getOutputNodes();

};


#endif /* GRAPH_H_ */
