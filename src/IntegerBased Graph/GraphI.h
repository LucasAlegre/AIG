/*
 * GraphI.h
 *
 *  Created on: Mar 23, 2017
 *      Author: lucas
 */

#ifndef GRAPHI_H_
#define GRAPHI_H_

#include "AIGNodeI.h"

class GraphI {
public:
	GraphI();
	virtual ~GraphI();

private:
	AIGNodeI nodes[];
};

#endif /* GRAPHI_H_ */
