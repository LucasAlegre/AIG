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

	if(fileName.substr(fileName.find_last_of(".") + 1) == "aag"){
		AigerReader reader(filePathAAG + fileName);
	    Graph* aig = reader.readAAGFile();
		reader.generateDot(aig, fileName + ".dot");
	}
	else if(fileName.substr(fileName.find_last_of(".") + 1) == "aig"){
		AigerReader reader(filePathAIG + fileName);
		Graph* aig = reader.readAIGFile();
		reader.generateDot(aig, fileName + ".dot");
	}
	else
		cout << "File must be .aag or .aig\n";

	return 0;

}


