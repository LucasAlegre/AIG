/*
 * AIGNodeI.h
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#ifndef AIGNODEI_H_
#define AIGNODEI_H_

#include <iostream>
#include "../../PointerBased Graph/Graph/AIGNode.h"

class AIGNodeI {

private:
	std::string name;
	unsigned id;

	AigNodeType nodeType;

	unsigned indexInput0;
	unsigned indexInput1;
	bool input0Inverted;
	bool input1Inverted;

public:
	/*
	 * Default Constructor
	 */
	AIGNodeI();

	/**
	*   Constructor
	*
	*   @param id Id of the node
	*   @param nodeType Enum representing the type of the node
	*/
	AIGNodeI(unsigned id, AigNodeType nodeType);

	/*
	 *  Default Destructor
	 */
	~AIGNodeI();

	/*
	 *  Getters and Setters
	 */
	std::string getName() const;

	/*
	 *  Sets the name of the node
	 *  @param name Name the node will have
	 */
	void setName(std::string name);

	/*
	 * Returns the literal of the node on the AIG file
	 * @return id
	 */
	unsigned getId() const;

	/*
	 * Sets the id of the node
	 * @param id
	 */
	void setId(unsigned id);

	/*
	 * @return The enum representing the type of the node
	 */
	AigNodeType getNodeType() const;

	/*
	 * @param nodeType the enum representing the type of the node
	 */
	void setNodeType(AigNodeType nodeType);

    /*
     *  Sets the index of the input of the node in the array of nodes
     *  @param index The index of the node's input
     *  @param input0or1 whether it's the input0 or the input1
     */
	void setInputIndex(const unsigned index, const unsigned input0or1);

	/*
	 *  Checks if the input is inverted
	 *  @param input0or1 Whether it is the input0 or input1
	 *  @return True if it is inverted, else return false
	 */
	bool isInputInverted(const unsigned input0or1) const;

	/*
	 *  Sets whether the input is inverted
	 *  @param inputInverted True if its inverted, false if not
	 *  @param input0or1 Whether it is the input0 or input1
	 */
	void setInputInverted(const bool inputInverted, const unsigned input0or1);

	/*
	 *  Gets the index of the node's input
	 *  @param input0or1 Whether it is the input0 or input1
	 *  @return the input's index
	 */
	unsigned getInputIndex(const unsigned input0or1);


};

#endif /* AIGNODEI_H_ */
