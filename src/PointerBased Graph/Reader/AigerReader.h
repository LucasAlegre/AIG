/*
 * AAGReader.h
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#ifndef AIGERREADER_H_
#define AIGERREADER_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

#include "../../PointerBased Graph/Graph/Graph.h"
using namespace std;

/*
 *  Class that implements a file reader for AIG
 *
 */
class AigerReader
{
private:
    ifstream source;  // .aag or .aig file
    ofstream debug;   //  debug file
    string word;
    char buf[250];

    GRAPH *aig;

	int nNodes, nInputs, nFFs, nOutputs, nAnds;

public:
	/*
	 *   Constructor
	 *
	 *   @param sourcePath File to be open
	 *   @param bidirectionOption 1 - Unidirected Graph 2 - Bidirected Graph
	 */
    AigerReader(string sourcePath, const int bidirectionOption);

    ~AigerReader(){
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
    GRAPH* readAAGFile();

    //AIG FILE
    void readAIGInputs();
    void readAIGOutputs();
    unsigned int decode();
    void readAIGAnds();
    GRAPH* readAIGFile();

    /*
     *   Generate a .dot file from the given AIG
     *
     *   @param aig Unidirected or Bidirected Graph
     *   @param filename Name of the file that will be created
     */
    void generateDot(GRAPH* aig, string filename);
};

#endif /* AIGERREADER_H_ */
