/*
 * OutputNodeI.h
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#ifndef INTEGERBASED_GRAPH_GRAPH_OUTPUTNODEI_H_
#define INTEGERBASED_GRAPH_GRAPH_OUTPUTNODEI_H_

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
	AIGNodeI getInputIndex();
	bool isInputInverted() const;
	void setInputInverted(const bool inputInverted);
};

#endif /* INTEGERBASED_GRAPH_GRAPH_OUTPUTNODEI_H_ */
