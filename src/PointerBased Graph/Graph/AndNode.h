/*
 * AndNode.h
 *
 *  Created on: Apr 3, 2017
 *      Author: lucas
 */

#ifndef POINTERBASED_GRAPH_GRAPH_ANDNODE_H_
#define POINTERBASED_GRAPH_GRAPH_ANDNODE_H_

class AndNode: public AIGNode{
private:
   	 AIGNode* input0;
	 AIGNode* input1;
	 bool input0Inverted;
	 bool input1Inverted;

public:
   /*
	*  Constructor
	*  @param id Id of the node
	*/
	AndNode(const int id);

	/*
	 *  Default destructor
	 */
	~AndNode(){}

	/*
	*   Returns the enum representing the type of the node
	*/
	AigNodeType getNodeType();

	/*
	*  Getters and Setters
	*/
	void setInput(AIGNode* inp0, AIGNode* in1);

	/*
	*  @param input0or1 0 if it's the input0, 1 if it's the input1
	*  @return true if the input is inverted, if not return false
	*/
	bool isInputInverted(const int input0or1) const;

	/*
	*  @param input0or1 0 if it's the input0, 1 if it's the input1
	*  @return pointer to input of the node
	*/
	AIGNode* getInput(const int input0or1);


	void setInputInverted(const bool inputInverted, const int input0or1);
};




#endif /* POINTERBASED_GRAPH_GRAPH_ANDNODE_H_ */
