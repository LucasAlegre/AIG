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

#include "IntegerBased Graph/AigerReaderI/AigerReaderI.h"
#include "IntegerBased Graph/GraphI/GraphI.h"


using namespace std;

/*
 *   Main file
 *
 *   @param arg[1] Filename without extension
 *   @param arg[2] Pointer or Integer based 1 - Pointer 2 - Integer
 *   @param arg[3] Bidirection option 1 - Unidirected Graph 2 - Bidirected Graph
 *   @param arg[4] AIGER file type 1 - Binary (aig) 2 - ASCII (aag)
 *
 */
int main(int argc, char* arg[]){

	string message = "*** AIG Index-based Bi-directed Graph (IBG / BGI) ***";

	if(argc != 2){
		cout <<  "*   @param arg[1] Filename without extension" << endl;
		//			 <<	 "*   @param arg[2] Pointer or Integer based 1 - Pointer 2 - Integer" << endl
		//			 <<	 "*   @param arg[3] Bidirection option 1 - Unidirected Graph 2 - Bidirected Graph" << endl
		//		     <<	 "*   @param arg[4] AIGER file type 1 - Binary (aig) 2 - ASCII (aag)" << endl;

		exit(-1);
	}

	string fileName(arg[1]);
	//int pointerOrInteger = atoi(arg[2]);
	int pointerOrInteger = 2;
	//int bidirectionOption = atoi(arg[3]);
	int bidirectionOption = 2;
	//int aigerFileType = atoi(arg[4]);
	int aigerFileType = 2;

	cout << message << " FileName: " << fileName << endl;

	string filePathAAG = "aags/";
	string filePathAIG = "aigs/";

	AigerReaderI reader(filePathAAG + fileName + ".aag", bidirectionOption);
	GRAPHI* aig = reader.readAAGFile();

	aig->print();

	delete aig;

	cout << message << " FileName: " << fileName << endl;

	return 0;

}


