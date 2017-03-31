/*
 * main.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include <iostream>
#include <stdlib.h>
#include <string>

#include "IntegerBased Graph/AigerReaderI/AigerReaderI.h"
#include "IntegerBased Graph/Graph/AIGNodeI.h"
#include "IntegerBased Graph/Graph/GraphI.h"
#include "PointerBased Graph/Reader/AigerReader.h"

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

	if(pointerOrInteger == 1){
		AigerReader reader(filePathAAG + fileName + ".aag", bidirectionOption);
	    GRAPH* aig = reader.readAAGFile();
		reader.generateDot(aig, fileName + ".dot");

	}
	else if(pointerOrInteger == 2){
		AigerReaderI reader(filePathAAG + fileName + ".aag", bidirectionOption);
	    GRAPHI* aig = reader.readAAGFile();
	//	reader.generateDot(aig, fileName + ".dot");

	}






	return 0;

}


