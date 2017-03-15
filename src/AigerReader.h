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

public:
    AigerReader(string sourcePath);

    ~AigerReader(){
    	source.close();
    	debug.close();
    }

    Graph* readAAGFile();

    Graph* readAIGFile();

    void generateDot(Graph* aig, string filename);
};

#endif /* AIGERREADER_H_ */
