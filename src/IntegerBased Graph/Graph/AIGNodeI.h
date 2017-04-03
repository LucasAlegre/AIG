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

	int indexInput0;
	int indexInput1;
	bool input0Inverted;
	bool input1Inverted;

public:
	AIGNodeI();
	/**
	*   Constructor
	*
	*   @param id Id of the node
	*/
	AIGNodeI(unsigned id, AigNodeType);
	~AIGNodeI();

	/*
	 *  Getters and Setters
	 */
	std::string getName() const;
	void setName(std::string name);
	unsigned getId() const;
	void setId(unsigned id);
	AigNodeType getNodeType() const;
	void setNodeType(AigNodeType nodeType);

	void setInputIndex(const int index, const int input0or1);
	bool isInputInverted(const int input0or1) const;
	int getInputIndex(const int input0or1);
	void setInputInverted(const bool inputInverted, const int input0or1);


};

#endif /* AIGNODEI_H_ */
