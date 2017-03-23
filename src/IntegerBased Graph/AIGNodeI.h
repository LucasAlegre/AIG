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

};

#endif /* AIGNODEI_H_ */
