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

typedef struct AND{
	int id;
	int i0;
	int i1;
	string name;
}AND;

typedef struct node{
	vector<int> inputs;
	vector<int> outputs;
	vector<AND> ands;
}NODE;

class AigerReader
{
private:
    ifstream source;
    ofstream debug;
    string word;
    char buf[250];

    GRAPH *aig;

	int nNodes, nInputs, nFFs, nOutputs, nAnds;

public:
    AigerReader(string sourcePath, const int bidirectionOption);

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
    GRAPH* readAAGFile();

    //AIG FILE
    void readAIGInputs();
    void readAIGOutputs();
    unsigned int decode();
    void readAIGAnds();
    GRAPH* readAIGFile();


    void generateDot(GRAPH* aig, string filename);
};

#endif /* AIGERREADER_H_ */
