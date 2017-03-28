/*
 * InputNodeI.h
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#ifndef INTEGERBASED_GRAPH_INPUTNODEI_H_
#define INTEGERBASED_GRAPH_INPUTNODEI_H_

#include "AIGNodeI.h"


/*
*   Class that implements an Input Node
*
*/
class InputNodeI: public AIGNodeI{
public:
	/*
	*  Constructor
	*  @param id Id of the node
	*/
	InputNodeI(const int id);
    ~InputNodeI();

	/*
	*  Get one of the inputs
	*
	* @param input0or1 Whether should return the input0 or input1
	* @return The wanted input of the node
	*/
	int getInputIndex(const int input0or1);
};

#endif /* INTEGERBASED_GRAPH_INPUTNODEI_H_ */
