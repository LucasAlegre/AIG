/*
 * AAGReader.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "Graph.h"
#include "AIGNode.h"
#include "Graph.h"
#include "AAGReader.h"
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

AAGReader::AAGReader(string sourcePath)
{
	try{
		source.open(sourcePath.c_str());
	    debug.open("aagComentado.txt");
	}
	catch (const ifstream::failure& e) {
	    cout << "Exception opening/reading file";
    }

}

Graph* AAGReader::readFile()
{
    //treating header
    source.getline(buf, 250);
    string s = buf;
    istringstream line(s);
    line >> word;

    if(strcmp("aag",word.c_str())!=0)
    {
        cout << "the file is not an AAG file!";
        return NULL;
    }

    int nNodes, nInputs, nFFs, nOutputs, nAnds;
    line >> word;
    nNodes = atoi(word.c_str());
    line >> word;
    nInputs = atoi(word.c_str());
    line >> word;
    nFFs = atoi(word.c_str());
    line >> word;
    nOutputs = atoi(word.c_str());
    line >> word;
    nAnds = atoi(word.c_str());


    if (nNodes != nInputs + nFFs + nAnds) {
        cout << "Wrong file header";
        return NULL;
    }

    if (nFFs != 0) {
        cout << "FF not supported yet";
        return NULL;
    }

    debug << s << "\nThe file header is ok!\n\n";

    Graph* aig = new Graph;

    //treating inputs
    for (int i = 0; i < nInputs; i++) {

        source.getline(buf, 250);
        string s = buf;
        istringstream line(s);
        line >> word;

    	InputNode* input = new InputNode(atoi(word.c_str()));
    	aig->insertInputNode(input);

        debug << "read the input " << i << " Id: " << input->getId() << " from the file\n";
        debug << "   create in" << i << " and add it to an input list and the all nodes list\n";
    }

    //treating outputs
    debug << "\n";
    for (int i = 0; i < nOutputs; i++) {

        source.getline(buf, 250);
        string s = buf;
        istringstream line(s);
        line >> word;

    	OutputNode* output = new OutputNode(atoi(word.c_str()));
    	aig->insertOutputNode(output);

        debug << "read the output " << i << " Id: " << output->getId()  << " from the file\n";
        debug << "   create out" << i << " and add it to an output list and the all nodes list\n";
    }

    //connecting ands
    debug << "\n";
    for (int i = 0; i < nAnds; i++) {

        source.getline(buf, 250, '\n');
        string s = buf;
        istringstream line(s);
        line >> word;

    	AndNode* andnode = new AndNode(atoi(word.c_str()));

    	int i0, i1;
    	line >> word;
    	i0 = atoi(word.c_str());
    	line >> word;
    	i1 = atoi(word.c_str());

    	if(i0 % 2 == 0){
    		andnode->setInputInverted(false, 0);
    	}
    	else{
    		andnode->setInputInverted(true, 0);
    		i0--;
    	}

    	if(i1 % 2 == 0){
    		andnode->setInputInverted(false, 1);
    	}
    	else{
    		andnode->setInputInverted(true, 1);
    		i1--;
    	}

    	andnode->setInput(aig->findNodeById(i0), aig->findNodeById(i1));
    	aig->insertAndNode(andnode);

        debug << "read the and " << i << " Id: " << andnode->getId()  << " from the file\n";
        debug << "   connect the and" << i << " and set the inversion of this pins\n";
    }

    debug << "\n";
    string aigName;

    while(source)
    {
        source.getline(buf, 250, '\n');
        string s = buf;
        istringstream line;
        line.seekg(0);line.str(s);
        line >> word;

        if(strcmp("c",word.substr(0).c_str())==0){
            debug << "the comments began. Ignore the file from here!\n";
            break;
        } else if(strcmp(word.substr(0).c_str(),"i")==0){

        } else if(strcmp(word.substr(0).c_str(),"o")==0){

        } else if(strcmp(word.substr(0).c_str(),"l")==0){

        }
    }

    //connect the outputs to its andnodes
    vector<OutputNode*>::iterator it;
    vector<OutputNode*> *outputs = aig->getOutputNodes();
	for(it = outputs->begin(); it < outputs->end(); it++){
		int idinp = (*it)->getId();
		if(idinp % 2 != 0){
			(*it)->setInputInverted(true);
			idinp--;
		}
		AndNode* andnode = aig->findAndById(idinp);
		(*it)->setInput(andnode);
	}


    debug << "\ncreate the AIG and add all nodes\n";
    debug << "return the AIG";

    return aig;
}

void AAGReader::generateDot(Graph* aig, string filename){

	ofstream dotfile(filename.c_str());
	string inputDetails = " [shape=circle, height=1, width=1, penwidth=5 style=filled, fillcolor=\"#ff8080\", fontsize=20]";
    string andDetails = " [shape=circle, height=1, width=1, penwidth=5 style=filled, fillcolor=\"#ffffff\", fontsize=20]";
    string outputDetails = " [shape=circle, height=1, width=1, penwidth=5 style=filled, fillcolor=\"#008080\", fontsize=20]";
    string positiveEdgeDetails = " [penwidth = 3, color=blue]";
    string negativeEdgeDetails = " [penwidth = 3, color=red, style=dashed]";
    string inputsIds;
    string outputsIds;

    //first line of the dot file
	dotfile << "digraph aig {" << endl;

	//write the input nodes on the dot file
    vector<InputNode*> *inputs = aig->getInputNodes();
    vector<InputNode*>::iterator it;
	for(it = inputs->begin(); it < inputs->end(); it++){
		dotfile << "\"" << (*it)->getId() << "\"" << inputDetails << endl;
		inputsIds += "\"" +  patch::to_string((*it)->getId()) + "\" ";
	}

	//write the and nodes on the dot file
    vector<AndNode*> *ands = aig->getAndNodes();
    vector<AndNode*>::iterator it2;
	for(it2 = ands->begin(); it2 < ands->end(); it2++){
		dotfile << "\"" << (*it2)->getId() << "\"" << andDetails << endl;
	}

	//write the output nodes on the dot file
    vector<OutputNode*> *outputs = aig->getOutputNodes();
    vector<OutputNode*>::iterator it3;
	for(it3 = outputs->begin(); it3 < outputs->end(); it3++){
		dotfile << "\"S" << (*it3)->getId() << "\"" << outputDetails << endl;
		outputsIds += "\"S" + patch::to_string((*it3)->getId()) + "\" ";
	}

	//write the ands connections on the dot file
	for(it2 = ands->begin(); it2 < ands->end(); it2++){
		dotfile << "\"" << (*it2)->getInput(0)->getId() << "\"" << " -> " << "\"" << (*it2)->getId() << "\"";
		if( (*it2)->isInputInverted(0) )
			dotfile << negativeEdgeDetails << endl;
		else
			dotfile << positiveEdgeDetails << endl;

		dotfile << "\"" << (*it2)->getInput(1)->getId() << "\"" << " -> " << "\"" << (*it2)->getId() << "\"";
		if( (*it2)->isInputInverted(1) )
			dotfile << negativeEdgeDetails << endl;
		else
			dotfile << positiveEdgeDetails << endl;

	}

	//write the outputs connections on the dot file
	for(it3 = outputs->begin(); it3 < outputs->end(); it3++){
		dotfile << "\"" << (*it3)->getInput()->getId() << "\"" << " -> " << "\"" << "S" << (*it3)->getId() << "\"";
		if( (*it3)->isInputInverted() )
			dotfile << negativeEdgeDetails << endl;
		else
			dotfile << positiveEdgeDetails << endl;
	}

	dotfile << "{ rank=source; ";
    dotfile << inputsIds << "}" << endl;
    dotfile << "{ rank=since; ";
    dotfile << outputsIds << "}" << endl;
    dotfile << "rankdir=\"BT\"" << endl << "}";

}
