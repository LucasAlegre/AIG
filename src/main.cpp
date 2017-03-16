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

using namespace std;

int main(int argc, char* arv[]){

	if(argc == 1){
		cout << "Must inform the aag file" << endl;
		exit(-1);
	}

	string fileName(arv[1]);

	string filePathAAG = "aags/";
	string filePathAIG = "aigs/";
	string fileExtensionAAG = ".aag";
	string fileExtensionAIG = ".aig";

	//AigerReader reader(filePathAAG + fileName + fileExtensionAAG);
	//Graph* aig = reader.readAAGFile();

	AigerReader reader(filePathAIG + fileName + fileExtensionAIG);
	Graph* aig = reader.readAIGFile();

	reader.generateDot(aig, fileName + ".dot");

	return 0;

}


