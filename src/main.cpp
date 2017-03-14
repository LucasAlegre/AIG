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

int main(int argc, char* arv[]){

	if(argc == 1){
		cout << "Must inform the aag file" << endl;
		exit(-1);
	}

	string filePath = "aigs/";
	string fileName(arv[1]);
	string fileExtension = ".aag";

	AAGReader reader(filePath + fileName + fileExtension);

	Graph* aig = reader.readFile();

	reader.generateDot(aig, fileName + ".dot");

	return 0;

}


