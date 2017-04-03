/*
 * InputNode.h
 *
 *  Created on: Apr 3, 2017
 *      Author: lucas
 */

#ifndef POINTERBASED_GRAPH_GRAPH_INPUTNODE_H_
#define POINTERBASED_GRAPH_GRAPH_INPUTNODE_H_

/*
*   Class that implements an Input Node
*
*/
class InputNode: public AIGNode{
public:
	/*
	*  Constructor
	*  @param id Id of the node
	*/
	InputNode(const unsigned id);

	/*
	*   Returns the enum representing the type of the node
	*/
	AigNodeType getNodeType();

	/*
	*  Get one of the inputs
	*
	* @param input0or1 Whether should return the input0 or input1
	* @return The wanted input of the node
	*/
	AIGNode* getInput(const int input0or1);
};



#endif /* POINTERBASED_GRAPH_GRAPH_INPUTNODE_H_ */
