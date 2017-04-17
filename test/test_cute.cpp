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

void test_c17() {

	string fileName = "C17";
	int pointerOrInteger = 1;
	int bidirectionOption = 1;

	string filePathAAG = "aags/";
	string filePathAIG = "aigs/";

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


cute::suite make_suite_test_cute() {
	cute::suite s;
	s.push_back(CUTE(test_c17));
	return s;
}
