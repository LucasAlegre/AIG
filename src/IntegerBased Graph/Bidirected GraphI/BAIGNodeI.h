/*
 * BAIGNodeI.h
 *
 *  Created on: Apr 6, 2017
 *      Author: lucas
 */

#ifndef INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BAIGNODEI_H_
#define INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BAIGNODEI_H_

#include "../GraphI/AIGNodeI.h"

class BAIGNodeI: public AIGNodeI {
private:
	static const int maxSizeFanOut = 100;
	int freeIndexFanOut;
	int fanOut[maxSizeFanOut];
	bool invertedFanOut[maxSizeFanOut];

public:
	/*
	 * Default Constructor
	 */
	BAIGNodeI();
	/*
	 *  Default Destructor
	 */
	~BAIGNodeI();

	/**
	*   Constructor
	*
	*   @param id Id of the node
	*   @param nodeType Enum representing the type of the node
	*/
	BAIGNodeI(unsigned id, AigNodeType nodeType);

	/*
	 *  Sets the index of the output in the "freeIndexFanOut" position
	 *  @param index Index of the output in the graph
	 *  @param inverted Wheter the output is inverted or not
	 */
	void setOutputIndex(int index, bool inverted);

	/*
	 *  Gets the index in the graph of the output in the index i of the fanOut
	 */
	int getOutputIndex(int i);

	/*
	 *  Gets the index in the graph of the output in the index i of the fanOut
	 */
	int getOutputInverted(int i);
};

#endif /* INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BAIGNODEI_H_ */
