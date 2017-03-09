/*
 * main.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "Graph.h"
#include "AIGNode.h"
#include "Graph.h"
#include "AAGReader.h"
#include <iostream>

using namespace std;

int main(){

	AAGReader reader("fulladder.aag");
	Graph* aig = reader.readFile();

    vector<AIGNode*> nodes = aig->getNodes();

    vector<AIGNode*>::iterator it;
	for(it = nodes.begin(); it < nodes.end(); it++){
		cout << (*it)->getId();
	}



	return 0;

}


