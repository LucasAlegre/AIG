#include "../cute/cute.h"
#include "../cute/cute_runner.h"
#include "../cute/cute_counting_listener.h"
#include "../cute/ide_listener.h"
#include "../cute/xml_listener.h"

#include <iostream>
#include <string.h>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>



#include "test_cute.h"

using namespace cute;

int main(int argc, char const *argv[]){

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
