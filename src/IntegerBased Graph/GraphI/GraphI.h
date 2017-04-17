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

	virtual void iniatializeArray(const unsigned nNodes) = 0;

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
    AIGNodeI *nodes;

public:
	GraphI();
	~GraphI();

	void iniatializeArray(const unsigned nNodes);
	AIGNodeI* getNodes();

	AIGNodeI& operator[](unsigned x){
		return nodes[x];
	}

	void insertInputNode(const unsigned int id);
	void insertOutputNode(const unsigned int id);
	void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1);

	void connectOutputs();

	void print();

};

#endif /* GRAPHI_H_ */
