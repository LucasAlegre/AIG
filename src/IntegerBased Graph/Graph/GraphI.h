/*
 * GraphI.h
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#ifndef GRAPHI_H_
#define GRAPHI_H_

#include "AIGNodeI.h"

/*
* Interface Class for AIG Graph with Integers
*
*/
class GRAPHI{
public:
	virtual void insertInputNode(const unsigned int id) = 0;
	virtual void insertOutputNode(const unsigned int id) = 0;
	virtual void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1) = 0;
	virtual void addOutputToNodes() = 0;  // Insert the outputs vector at the end of the nodes vector

	virtual void iniatializeNodes(const int nNodes) = 0;

	virtual int getLastFreeIndex() = 0;

	virtual int findNodeIndexById(const unsigned int id) = 0;

	virtual void connectOutputs() = 0;

	virtual AIGNodeI* getNodes() = 0;

};


/*
* Class that implements an AIG Graph with Integers
*
*/
class GraphI: public GRAPHI{
private:
    AIGNodeI *nodes;
    int numNodes;
    int lastFreeIndex;

public:
	GraphI();
	virtual ~GraphI();

	/*
	 *  Returns the index of the last free available position of the array
	 */
	int getLastFreeIndex();

	void iniatializeNodes(const int nNodes);

	void insertInputNode(const unsigned int id);
	void insertOutputNode(const unsigned int id);
	void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1);
	void addOutputToNodes();  // Insert the outputs vector at the end of the nodes vector

	int findNodeIndexById(const unsigned int id);

	void connectOutputs();

	AIGNodeI* getNodes();

};

#endif /* GRAPHI_H_ */
