/*
 * AAGReader.h
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#ifndef AIGERREADER_H_
#define AIGERREADER_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Graph.h"
using namespace std;

class AigerReader
{
private:
    ifstream source;
    ofstream debug;
    string word;
    char buf[250];

    Graph* aig;

	int nNodes, nInputs, nFFs, nOutputs, nAnds;

public:
    AigerReader(string sourcePath);

    ~AigerReader(){
    	source.close();
    	debug.close();
    }

    bool readHeader();

    //AAG FILE
    void readAAGInputs();
    void readAAGOutputs();
    void readAAGAnds();
    void connectAAGOutputs();
    void readAAGNames();
    Graph* readAAGFile();

    //AIG FILE
    void readAIGInputs();
    void readAIGOutputs();
    unsigned int decode();
    void readAIGAnds();
    Graph* readAIGFile();


    void generateDot(Graph* aig, string filename);
};

#endif /* AIGERREADER_H_ */
