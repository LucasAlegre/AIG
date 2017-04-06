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
	int *fanOut;
	bool *invertedFanOut;

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
};

#endif /* INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BAIGNODEI_H_ */
