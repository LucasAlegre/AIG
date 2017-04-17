/*
 * main.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

#include "PointerBased Graph/Graph/AIGNode.h"
#include "PointerBased Graph/Graph/Graph.h"
#include "IntegerBased Graph/AigerReaderI/AigerReaderI.h"
#include "IntegerBased Graph/GraphI/GraphI.h"
#include "PointerBased Graph/AigerReader/AigerReader.h"

using namespace std;

/*
 *   Main file
 *
 *   @param arg[1] Filename without extension
 *   @param arg[2] Pointer or Integer based 1 - Pointer 2 - Integer
 *   @param arg[3] Bidirection option 1 - Unidirected Graph 2 - Bidirected Graph
 *
 */
int main(int argc, char* arg[]){

	if(argc != 4){
		cout <<  "*   @param arg[1] Filename without extension" << endl
			 <<	 "*   @param arg[2] Pointer or Integer based 1 - Pointer 2 - Integer" << endl
			 <<	 "*   @param arg[3] Bidirection option 1 - Unidirected Graph 2 - Bidirected Graph" << endl;
		exit(-1);
	}

	string fileName(arg[1]);
	int pointerOrInteger = atoi(arg[2]);
    int bidirectionOption = atoi(arg[3]);

	string filePathAAG = "aags/";
	string filePathAIG = "aigs/";

	if(pointerOrInteger == 1){  // Pointer Based Graph
		AigerReader reader(filePathAIG + fileName + ".aig", bidirectionOption);
	    GRAPH* aig = reader.readAAGFile();
		reader.generateDot(aig, fileName + ".dot");

		aig->print();

        delete aig;
	}

	else if(pointerOrInteger == 2){ // Integer Based Graph
		AigerReaderI reader(filePathAAG + fileName + ".aag", bidirectionOption);
	    GRAPHI* aig = reader.readAAGFile();

        aig->print();

        delete aig;

	}



	return 0;

}


