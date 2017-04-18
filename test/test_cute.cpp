#include "../cute/cute.h"
#include "../cute/cute_runner.h"
#include "../cute/cute_counting_listener.h"
#include "../cute/ide_listener.h"
#include "../cute/xml_listener.h"

#include <iostream>

#include "test_cute.h"

#include "../src/PointerBased Graph/Graph/AIGNode.h"
#include "../src/PointerBased Graph/Graph/Graph.h"
#include "../src/PointerBased Graph/AigerReader/AigerReader.h"
#include "../src/IntegerBased Graph/AigerReaderI/AigerReaderI.h"
#include "../src/IntegerBased Graph/GraphI/GraphI.h"

using namespace std;

string filePathAAG = "aags/";
string filePathAIG = "aigs/";

/*
void test_general(string fileName, int pointerOrInteger,int bidirectionOption) {

	if(pointerOrInteger == 1){  // Pointer Based Graph
		AigerReader reader(filePathAAG + fileName + ".aag", bidirectionOption);
		GRAPH* aig = reader.readAAGFile();
		reader.generateDot(aig, fileName + ".dot");

		aig->print();

		delete aig;
	}

	else if(pointerOrInteger == 2){ // Integer Based Graph
		AigerReaderI reader(filePathAAG + fileName + ".aag", bidirectionOption);
		GRAPHI* aig = reader.readAAGFile();

		aig->print();

	}
}
*/



void test_c17_1Pointer_1UndirectGraph() {

	string fileName = "C17";

	AigerReader reader(filePathAAG + fileName + ".aag", 1);
	GRAPH* aig = reader.readAAGFile();
	reader.generateDot(aig, fileName + ".dot");

	aig->print();

	delete aig;
}

void test_c432_1Pointer_2BidirectGraph() {

	string fileName = "C432";

	AigerReader reader(filePathAAG + fileName + ".aag", 2);
	GRAPH* aig = reader.readAAGFile();
	reader.generateDot(aig, fileName + ".dot");

	aig->print();

	delete aig;
}


void test_c499_2Integer_1UndirectGraph() {

	string fileName = "C499";

	AigerReaderI reader(filePathAAG + fileName + ".aag", 1);
	GRAPHI* aig = reader.readAAGFile();

	aig->print();

	delete aig;
}

void test_c7552_2Integer_2BidirectGraph() {

	string fileName = "C7552";

	AigerReaderI reader(filePathAAG + fileName + ".aag", 2);
	GRAPHI* aig = reader.readAAGFile();

	aig->print();

	delete aig;
}


cute::suite make_suite_test_cute() {
	cute::suite s;
	/*
	s.push_back(CUTE( test_general("C17",  1, 1) ) );
	s.push_back(CUTE( test_general("C432", 1, 2) ) );
	*/

	s.push_back(CUTE(test_c17_1Pointer_1UndirectGraph));
	s.push_back(CUTE(test_c432_1Pointer_2BidirectGraph));

	s.push_back(CUTE(test_c499_2Integer_1UndirectGraph));
	s.push_back(CUTE(test_c7552_2Integer_2BidirectGraph));


	return s;
}
