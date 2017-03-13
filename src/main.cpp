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

    vector<AIGNode*> *nodes = aig->getNodes();
    vector<AndNode*> *ands = aig->getAndNodes();

    vector<AIGNode*>::iterator it;
	for(it = nodes->begin(); it < nodes->end(); it++){
		cout << (*it)->getId() << endl;
	}

	vector<AndNode*>::iterator i;
	for(i = ands->begin(); i < ands->end(); i++){
       cout << (*i)->getInput(0)->getId() <<" "<< (*i)->isInputInverted(0) << endl;
	}

	reader.generateDot(aig, "teste.txt");


	return 0;

}


