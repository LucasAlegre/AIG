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

/*
 *   Main file
 *
 *   @param arv[1] Filename without extension
 *   @param arv[2] Bidirection option 1 - Unidirected Graph 2 - Bidirected Graph
 *
 */

int main(int argc, char* arv[]){

	if(argc != 3){
		cout << "Must inform the file and the bidirectionOption" << endl;
		exit(-1);
	}

	string fileName(arv[1]);
    int bidirectionOption = atoi(arv[2]);
	string filePathAAG = "aags/";
	string filePathAIG = "aigs/";

	AigerReader reader(filePathAAG + fileName + ".aag", bidirectionOption);
    GRAPH* aig = reader.readAAGFile();
	reader.generateDot(aig, fileName + ".dot");

	vector<AIGNode*> *nodes = aig->getNodes();
	for(auto it = nodes->begin(); it < nodes->end(); it++){
		vector<AIGNode*> *outputs =  (*it)->getOutputs();
		if(outputs != NULL)
			for(auto it2 = outputs->begin(); it2 < outputs->end(); it2++)
				cout << (*it2)->getId() << endl;
	}


	return 0;

}


