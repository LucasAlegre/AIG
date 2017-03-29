/*
 * AIGNodeI.h
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#ifndef AIGNODEI_H_
#define AIGNODEI_H_

#include <iostream>

class AIGNodeI {

private:
	std::string name;
	unsigned id;

public:
	AIGNodeI();
	/**
	*   Constructor
	*
	*   @param id Id of the node
	*/
	AIGNodeI(unsigned id);
	virtual ~AIGNodeI();

	/*
	 *  Getters and Setters
	 */
	std::string getName() const;
	void setName(std::string name);
	unsigned getId() const;
	void setId(unsigned id);


	virtual void setInputIndex(const int index, const int input0or1);
	virtual bool isInputInverted(const int input0or1) const;
	virtual int getInputIndex(const int input0or1);
	virtual void setInputInverted(const bool inputInverted, const int input0or1);


	/*
	*   Virtual functions that only Bidirectioned Nodes implement
	*   Unidirected nodes will report an warning
	*/
	virtual AIGNodeI* getOutputs();
	virtual void setOutput(AIGNodeI node);
	virtual bool * getOutputsInverted();
};

#endif /* AIGNODEI_H_ */
