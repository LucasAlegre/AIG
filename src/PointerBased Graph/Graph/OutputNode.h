/*
 * OutputNode.h
 *
 *  Created on: Apr 3, 2017
 *      Author: lucas
 */

#ifndef POINTERBASED_GRAPH_GRAPH_OUTPUTNODE_H_
#define POINTERBASED_GRAPH_GRAPH_OUTPUTNODE_H_


/*
*   Class that implements an Output Node
*
*/
class OutputNode: public AIGNode{
private:
	AIGNode* input0;   // Output node only has one input
	bool input0Inverted;  // Whether the input is inverted

public:
	/*
	*  Constructor
	*  @param id Id of the node
	*/
	OutputNode(const int id);

	/*
	*  Default destructor
	*/
	~OutputNode();

	/*
	*   Returns the enum representing the type of the node
	*/
	AigNodeType getNodeType();

	/*
	*  Set pointer to the input node
	*
	*  @param node Pointer to the input
	*/
	void setInput(AIGNode* node);

	/*
	*  @return pointer to input of the node
	*/
	AIGNode* getInput();

	/*
	*  @param input0or1 0 if it's the input0, 1 if it's the input1
	*  @return true if the input is inverted, if not return false
	*/
	bool isInputInverted(const int input0or1) const;
	/*
	*  Set whether the input is inverted or not
	*  @param inputInverted true if is inverted, false if not
	*/
	void setInputInverted(const bool inputInverted);
};


#endif /* POINTERBASED_GRAPH_GRAPH_OUTPUTNODE_H_ */
