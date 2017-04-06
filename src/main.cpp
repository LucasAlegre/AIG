/*
 * main.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include <iostream>

#include "PointerBased Graph/Graph/AIGNode.h"
#include "PointerBased Graph/Graph/Graph.h"
#include "PointerBased Graph/Reader/AigerReader.h"
#include "IntegerBased Graph/AigerReaderI/AigerReaderI.h"
#include "IntegerBased Graph/GraphI/GraphI.h"

using namespace std;

/*
 *   Main file
 *
 *   @param arv[1] Filename without extension
 *   @param arv[2] Pointer or Integer based 1 - Pointer 2 - Integer
 *   @param arv[3] Bidirection option 1 - Unidirected Graph 2 - Bidirected Graph
 *
 */
int main(int argc, char* arv[]){

	if(argc != 4){
		cout <<  "*   @param arv[1] Filename without extension" << endl
			 <<	 "*   @param arv[2] Pointer or Integer based 1 - Pointer 2 - Integer" << endl
			 <<	 "*   @param arv[3] Bidirection option 1 - Unidirected Graph 2 - Bidirected Graph" << endl;
		exit(-1);
	}

	string fileName(arv[1]);
	int pointerOrInteger = atoi(arv[2]);
    int bidirectionOption = atoi(arv[3]);

	string filePathAAG = "aags/";
	string filePathAIG = "aigs/";

	if(pointerOrInteger == 1){  // Pointer Based Graph
		AigerReader reader(filePathAAG + fileName + ".aag", bidirectionOption);
	    GRAPH* aig = reader.readAAGFile();
		reader.generateDot(aig, fileName + ".dot");

		vector<AIGNode*> *v = aig->getNodes();
		for(auto i = v->begin(); i < v->end(); i++)
			cout << (*i)->getName() << endl;

        delete aig;
	}

	else if(pointerOrInteger == 2){ // Integer Based Graph
		AigerReaderI reader(filePathAAG + fileName + ".aag", bidirectionOption);
	    GRAPHI* aig = reader.readAAGFile();

	    AIGNodeI *test = aig->getNodes();
	    for(int i = 0; i < aig->getNumNodes(); i++){
	    	cout << i << " " << test[i].getId() <<" "<< test[test[i].getInputIndex(0)].getId() <<" "<<test[test[i].getInputIndex(1)].getId() << endl;
	    }

	}
	else




	return 0;

}


