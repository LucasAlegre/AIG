/*
 * BAIGNodeI.cpp
 *
 *  Created on: Apr 6, 2017
 *      Author: lucas
 */

#include <iostream>

#include "BAIGNodeI.h"

BAIGNodeI::BAIGNodeI() {
	fanOut = NULL;
    invertedFanOut = NULL;
}

BAIGNodeI::~BAIGNodeI() {
	// TODO Auto-generated destructor stub
}

BAIGNodeI::BAIGNodeI(unsigned id, AigNodeType nodeType): AIGNodeI(id, nodeType){

}
