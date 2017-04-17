/*
 * AigerReaderI.h
 *
 *  Created on: 27 de mar de 2017
 *      Author: lucas
 */

#ifndef INTEGERBASED_GRAPH_AIGERREADERI_AIGERREADERI_H_
#define INTEGERBASED_GRAPH_AIGERREADERI_AIGERREADERI_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

#include "../../IntegerBased Graph/GraphI/GraphI.h"
using namespace std;

/*
 *  Class that implements a file reader for AIG
 *  Supports .aag and .aig format
 *
 */
class AigerReaderI
{
private:
    ifstream source;  // .aag or .aig file
    ofstream debug;   //  debug file
    string word;
    char buf[250];
    int bidirectionOption;

    GRAPHI *aig;

	int nNodes, nInputs, nFFs, nOutputs, nAnds;

public:

	/*
	 *   Constructor
	 *
	 *   @param sourcePath File to be open
	 *   @param bidirectionOption 1 - Unidirected Graph 2 - Bidirected Graph
	 */
    AigerReaderI(string sourcePath, const int bidirectionOption);

    /*
     *  Destructor
     *
     *  Closes the files
     */
    ~AigerReaderI(){
    	source.close();
    	debug.close();
    }

    /*
     *   Read the header of the file
     *
     *   @return true if read succesfully, false if not
     */
    bool readHeader();

    //AAG FILE
    void readAAGInputs();
    void readAAGOutputs();
    void readAAGAnds();
    void readAAGNames();
    GRAPHI* readAAGFile();

    //AIG FILE
    void readAIGInputs();
    void readAIGOutputs();
    unsigned int decode();
    void readAIGAnds();
    GRAPHI* readAIGFile();

    /*
     *   Generate a .dot file from the given AIG
     *
     *   @param aig Unidirected or Bidirected Graph
     *   @param filename Name of the file that will be created
     */
    void generateDot(GRAPHI* aig, string filename);
};
#endif /* INTEGERBASED_GRAPH_AIGERREADERI_AIGERREADERI_H_ */
