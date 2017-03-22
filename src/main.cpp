/*
 * main.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "Graph.h"
#include "AIGNode.h"
#include "Graph.h"
#include "AigerReader.h"
#include <iostream>
#include "BAIGNode.h"

using namespace std;

int main(int argc, char* arv[]){

	if(argc == 1){
		cout << "Must inform the aag file" << endl;
		exit(-1);
	}

	string fileName(arv[1]);

	string filePathAAG = "aags/";
	string filePathAIG = "aigs/";

	AigerReader reader(filePathAAG + fileName + ".aag", 2);
    GRAPH* aig = reader.readAAGFile();
	reader.generateDot(aig, fileName + ".dot");

	vector<InputNode*> *nodes = aig->getInputNodes();
	for(auto it = nodes->begin(); it < nodes->end(); it++){
		cout << (*it)->getOutputs()->at(0)->getId();
	}

	return 0;

}


