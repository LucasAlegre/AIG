/*
 * GraphI.h
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#ifndef GRAPHI_H_
#define GRAPHI_H_

#include "../GraphI/AIGNodeI.h"

/*
* Interface Class for AIG Graph with Integers
*
*/
class GRAPHI{
protected:
	unsigned numNodes;
	unsigned nInputs, nOutputs, nAnds, nFFs;
	unsigned lastFreeIndex;

public:
	virtual ~GRAPHI(){};

	/*
	 *  Returns the index of the last free available position of the array
	 */
	unsigned getLastFreeIndex();

	virtual void insertInputNode(const unsigned int id) = 0;
	virtual void insertOutputNode(const unsigned int id) = 0;
	virtual void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1) = 0;

	virtual void initializeArray(const unsigned nNodes) = 0;

	virtual AIGNodeI* getNodes(){return NULL;}

	int findNodeIndexById(const unsigned int id);

	virtual void connectOutputs() = 0;

	virtual void print() = 0;

	/*
	 *  Getters and Setters
	 */
	unsigned getNumNodes()const;
	unsigned getNumAnds() const;
	void setNumAnds(unsigned ands);
	unsigned getNumFFs() const;
	void setNumFFs(unsigned fFs);
	unsigned getNumInputs() const;
	void setNumInputs(unsigned inputs);
	unsigned getNumOutputs() const;
	void setNumOutputs(unsigned outputs);
	void setNumNodes(unsigned numNodes);
};


/*
*  Class that implements an AIG Graph with Integers
*
*/
class GraphI: public GRAPHI{
private:
    AIGNodeI *nodes; // Array of nodes

public:

    /*
     *  Default constructor
     */
	GraphI();

	/*
	 *  Frees the memory allocated for the array of nodes
	 */
	~GraphI();

	/*
	 *  Allocates the array of nodes
	 *  @param nNodes The size of the array
	 */
	void initializeArray(const unsigned nNodes);

	/*
	 *  @return Pointer to the array of nodes
	 */
	AIGNodeI* getNodes();


	AIGNodeI& operator[](unsigned x){
		return nodes[x];
	}

	/*
	 *  Insert an input node to the graph
	 *  @param id Literal of the node
	 */
	void insertInputNode(const unsigned int id);

	/*
	 *  Insert an output node to the graph
	 *  @param id Literal of the node
	 */
	void insertOutputNode(const unsigned int id);

	/*
	 *  Insert an and node to the graph
	 *  @param id Literal of the node
	 */
	void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1);

	/*
	 *  Connects the output nodes in the graph
	 */
	void connectOutputs();

	/*
	 *  Prints the id and input of each node for debugging
	 */
	void print();

};

#endif /* GRAPHI_H_ */
