/*
 * AAGReader.h
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#ifndef AAGREADER_H_
#define AAGREADER_H_

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include "Graph.h"
using namespace std;

class AAGReader
{
private:
    ifstream source;
    ofstream debug;
    string word;
    char buf[250];

public:
    AAGReader(string sourcePath);
    Graph* readFile();
    ~AAGReader(){
    	source.close();
    	debug.close();
    }
};

#endif /* AAGREADER_H_ */
