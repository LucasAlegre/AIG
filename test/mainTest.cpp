#include "cute/cute.h"
#include "cute/cute_runner.h"
#include "cute/cute_counting_listener.h"
#include "cute/ide_listener.h"
#include "cute/xml_listener.h"

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

#include "src/PointerBased Graph/Graph/AIGNode.h"
#include "src/PointerBased Graph/Graph/Graph.h"
#include "src/PointerBased Graph/AigerReader/AigerReader.h"
#include "src/IntegerBased Graph/AigerReaderI/AigerReaderI.h"
#include "src/IntegerBased Graph/GraphI/GraphI.h"

#include "test_cute.h"

using namespace cute;

int main(int argc, char const *argv[]){
	/*
	using namespace std;

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



	return 0;
	*/

	using namespace std;
	suite s;
	s += make_suite_test_cute();
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::counting_listener<cute::ide_listener<> > > l(xmlfile.out);
	cute::makeRunner(l,argc,argv)(s,"all cute tests");
	cout << flush;
	cerr << flush;
	cerr << l.numberOfTests << " Tests - expect " << s.size() << endl;
	cerr << l.failedTests << " failed - expect 0 failures" << endl;
	cerr << l.errors << " errors - expect 0 errors" << endl;
	return l.failedTests;

}
