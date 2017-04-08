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
    int numNodes;
    int nInputs, nOutputs, nAnds, nFFs;
    int lastFreeIndex;

public:
	virtual ~GRAPHI(){};

	/*
	 *  Returns the index of the last free available position of the array
	 */
	int getLastFreeIndex();

	virtual void insertInputNode(const unsigned int id) = 0;
	virtual void insertOutputNode(const unsigned int id) = 0;
	virtual void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1) = 0;

	virtual void iniatializeArray(const int nNodes) = 0;

	virtual AIGNodeI* getNodes(){return NULL;}

	int findNodeIndexById(const unsigned int id);

	virtual void connectOutputs() = 0;

	virtual void print() = 0;

    int getNumNodes();

	int getNumAnds() const {
		return nAnds;
	}

	void setNumAnds(int ands) {
		nAnds = ands;
	}

	int getNumFFs() const {
		return nFFs;
	}

	void setNumFFs(int fFs) {
		nFFs = fFs;
	}

	int getNumInputs() const {
		return nInputs;
	}

	void setNumInputs(int inputs) {
		nInputs = inputs;
	}

	int getNumOutputs() const {
		return nOutputs;
	}

	void setNumOutputs(int outputs) {
		nOutputs = outputs;
	}

	void setNumNodes(int numNodes) {
		this->numNodes = numNodes;
	}
};


/*
* Class that implements an AIG Graph with Integers
*
*/
class GraphI: public GRAPHI{
private:
    AIGNodeI *nodes;

public:
	GraphI();
	~GraphI();

	void iniatializeArray(const int nNodes);
	AIGNodeI* getNodes();

	AIGNodeI& operator[](int x){
		return nodes[x];
	}

	void insertInputNode(const unsigned int id);
	void insertOutputNode(const unsigned int id);
	void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1);

	void connectOutputs();

	void print();

};

#endif /* GRAPHI_H_ */
