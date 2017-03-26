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
	virtual ~AIGNodeI();

	/*
	 *  Getters and Setters
	 */
	std::string getName() const;
	void setName(std::string name);
	unsigned getId() const;
	void setId(unsigned id);

	/*
	*   Virtual functions that only Bidirectioned Nodes implement
	*   Unidirected nodes will report an warning
	*/
	virtual AIGNodeI* getOutputs();
	virtual void setOutput(AIGNodeI node);
	virtual bool * getOutputsInverted();
};

#endif /* AIGNODEI_H_ */
