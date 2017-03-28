/*
 * OutputNodeI.h
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#ifndef INTEGERBASED_GRAPH_GRAPH_OUTPUTNODEI_H_
#define INTEGERBASED_GRAPH_GRAPH_OUTPUTNODEI_H_

#include "AIGNodeI.h"

/*
*   Class that implements an Output Node
*
*/
class OutputNodeI: public AIGNodeI{
private:
	int indexInput0;   // Output node only has one input
	bool input0Inverted;  // Whether the input is inverted

public:

	/*
	*  Constructor
	*  @param id Id of the node
	*/
	OutputNodeI(const int id);
	~OutputNodeI();

	/*
	*  Set pointer to the input node
	*
	*  @param node Pointer to the input
	*/
	void setInputIndex(int index);
	int getInputIndex(const int input0or1);
	bool isInputInverted() const;
	void setInputInverted(const bool inputInverted);
};

#endif /* INTEGERBASED_GRAPH_GRAPH_OUTPUTNODEI_H_ */
