/*
 * main.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "PointerBased Graph/Graph/AIGNode.h"
#include "PointerBased Graph/Graph/Graph.h"
#include "PointerBased Graph/Reader/AigerReader.h"
#include <iostream>
#include "PointerBased Graph/Bidirected Graph/BAIGNode.h"

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

	AigerReader reader(filePathAAG + fileName + ".aag", bidirectionOption);
    GRAPH* aig = reader.readAAGFile();
	reader.generateDot(aig, fileName + ".dot");

	return 0;

}


