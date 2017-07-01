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
#include "PointerBased Graph/AigerReader/AigerReader.h"

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
//int main(int argc, char* arg[]){
int main() {
	int argc {3};
	string arg[3];
	arg[1] = "C17_random";
	//arg[2] = 1;

	string message = "********* AIG Pointer-based Graph (PG / GP) *********";

	if(argc != 3){
		cout <<  "*   @param arg[1] Filename without extension" << endl
		     <<	 "*   @param arg[2] Show output 0 - False 1 - True" << endl;
//			 <<	 "*   @param arg[2] Pointer or Integer based 1 - Pointer 2 - Integer" << endl
//			 <<	 "*   @param arg[3] Bidirection option 1 - Unidirected Graph 2 - Bidirected Graph" << endl
//		     <<	 "*   @param arg[4] AIGER file type 1 - Binary (aig) 2 - ASCII (aag)" << endl;

		exit(-1);
	}

	string fileName(arg[1]);
	//bool showOutput=atoi(arg[2]);
	bool showOutput=1;
	//int pointerOrInteger = atoi(arg[2]);
	//int pointerOrInteger = 1;
   // int bidirectionOption = atoi(arg[3]);
	int bidirectionOption = 1;
    //int aigerFileType = atoi(arg[4]);
	//int aigerFileType = 2;

	if (showOutput==true)
		cout << message << " FileName: " << fileName << endl;

	string absolutePath = "/home/marcelo/git/AIG_LucasAlegre/Debug/";

	string filePathAAG = "aags/";

	filePathAAG = absolutePath + filePathAAG;

	string fileCompletePath = filePathAAG + fileName + ".aag";

	AigerReader reader(fileCompletePath, bidirectionOption);
	GRAPH* aig = reader.readAAGFile();
	reader.generateDot(aig, fileName + ".dot");

	if (showOutput==true)
		aig->print();

    delete aig;

    if (showOutput==true)
    	cout << message << " FileName: " << fileName << endl;

	return 0;

}
