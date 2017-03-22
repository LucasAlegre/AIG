/*
 * AAGReader.cpp
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#include "Graph.h"
#include "AIGNode.h"
#include "BAIGNode.h"
#include "BGraph.h"
#include "Graph.h"
#include <string.h>
#include <iostream>
#include <string>
#include <sstream>
#include "AigerReader.h"

AigerReader::AigerReader(string sourcePath, const int bidirectionOption)
{
    if(bidirectionOption == 1){
    	aig = new Graph;
    }
    else
    	aig = new BGraph;

	nAnds = 0; nInputs = 0; nOutputs = 0; nNodes = 0; nFFs = 0;

	try{
		source.open(sourcePath.c_str());
	    debug.open("Comentado.txt");
	}
	catch (const ifstream::failure& e) {
	    cout << "Exception opening/reading file\n";
    }

}

GRAPH* AigerReader::readAIGFile(){

    if(!readHeader()){
    	cout << "Header not correct" << endl;
    	exit(-1);
    }

	InputNode* constant = new InputNode(0);
	constant->setName("constant");
	aig->getNodes()->push_back(constant);

    readAIGInputs();
    readAIGOutputs();
    readAIGAnds();

    connectAAGOutputs();

    readAAGNames();

    debug << "\ncreate the AIG and add all nodes\n";
    debug << "return the AIG";

   return aig;
}

//based on http://fmv.jku.at/aiger/FORMAT-20070427.pdf
unsigned AigerReader::decode(){

	unsigned x = 0, i = 0;
	unsigned char ch = source.get();

	while(ch & 0x80){
		x |= (ch & 0x7f) << (7 * i++);
		ch = source.get();
	}

	return x | (ch << (7 * i));

}

//based on http://fmv.jku.at/aiger/FORMAT-20070427.pdf
void AigerReader::readAIGAnds(){

	unsigned delta0, delta1, lhs, rhs0, rhs1;

    //connecting ands
    debug << "\n";
    for (int i = 0; i < nAnds; i++) {

    	lhs = 2*(nInputs + nFFs) + (2*(i+1));

    	delta0 = decode();
    	delta1 = decode();

    	rhs0 = lhs - delta0;
    	rhs1 = rhs0 - delta1;

    	debug << "delta0: " << delta0 << "  " << "delta1: "  << delta1 << endl;
    	debug << "rhs0: " << rhs0 << "  " << "rhs1: " << rhs1 << endl;

    	aig->insertAndNode(lhs, rhs0, rhs1);

        debug << "read the and " << i << " Id: " << lhs  << " from the file\n";
        debug << "   connect the and" << i << " and set the inversion of this pins\n";
    }

}

void AigerReader::readAIGInputs(){
    //treating inputs
    for (int i = 0; i < nInputs; i++) {

    	aig->insertInputNode((i+1)*2);

        debug << "read the input " << i << " Id: " << (i+1)*2 << " from the file\n";
    }

}

void AigerReader::readAIGOutputs(){

    //treating outputs
    debug << "\n";
    for (int i = 0; i < nOutputs; i++) {

        source.getline(buf, 250);
        string s = buf;
        istringstream line(s);
        line >> word;

    	aig->insertOutputNode(atoi(word.c_str()));

        debug << "read the output " << i << " Id: " << word  << " from the file\n";
    }
}

GRAPH* AigerReader::readAAGFile()
{

    if(!readHeader()){
    	cout << "Header not correct" << endl;
    	exit(-1);
    }

	InputNode* constant = new InputNode(0);
	constant->setName("constant");
	aig->getNodes()->push_back(constant);

    readAAGInputs();
    readAAGOutputs();
    readAAGAnds();

    connectAAGOutputs();

    readAAGNames();

    debug << "\ncreate the AIG and add all nodes\n";
    debug << "return the AIG\n";

    return aig;
}

void AigerReader::readAAGInputs(){

    //treating inputs
    for (int i = 0; i < nInputs; i++) {

        source.getline(buf, 250);
        string s = buf;
        istringstream line(s);
        line >> word;

    	aig->insertInputNode(atoi(word.c_str()));

        debug << "read the input " << i << " Id: " << word << " from the file\n";
        debug << "   create in" << i << " and add it to an input list and the all nodes list\n";
    }

}

void AigerReader::readAAGOutputs(){

    //treating outputs
    debug << "\n";
    for (int i = 0; i < nOutputs; i++) {

        source.getline(buf, 250);
        string s = buf;
        istringstream line(s);
        line >> word;

    	aig->insertOutputNode(atoi(word.c_str()));

        debug << "read the output " << i << " Id: " << word  << " from the file\n";
        debug << "   create out" << i << " and add it to an output list and the all nodes list\n";
    }
}

void AigerReader::readAAGAnds(){
    //connecting ands
    debug << "\n";
    for (int i = 0; i < nAnds; i++) {

        source.getline(buf, 250, '\n');
        string s = buf;
        istringstream line(s);
        line >> word;

        unsigned id = atoi(word.c_str());

    	int i0, i1;
    	line >> word;
    	i0 = atoi(word.c_str());
    	line >> word;
    	i1 = atoi(word.c_str());

    	aig->insertAndNode(id, i0, i1);

        debug << "read the and " << i << " Id: " << id << " from the file\n";
        debug << "   connect the and" << i << " and set the inversion of this pins\n";
    }

}

bool AigerReader::readHeader()
{
	//treating header
	source.getline(buf, 250);
	string s = buf;
	istringstream line(s);
	line >> word;

	if(strcmp("aag",word.c_str())!=0 && strcmp("aig",word.c_str())!=0)
	{
		cout << "the file is not an AAG or AIG file!" << endl;
		return false;
	}

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
		return false;
	}

	if (nFFs != 0) {
		cout << "FF not supported yet";
		return false;
	}

	debug << s << "\nThe file header is ok!\n\n";
	return true;
}

//Connect the outputs to its inputs
void AigerReader::connectAAGOutputs(){

    debug << "connect the outputs' inputs" << endl;
    vector<OutputNode*>::iterator it;
    vector<OutputNode*> *outputs = aig->getOutputNodes();
	for(it = outputs->begin(); it < outputs->end(); it++){
		int idinp = (*it)->getId();
		if(idinp % 2 != 0){
			(*it)->setInputInverted(true);
			idinp--;
		}
		AIGNode* node = aig->findNodeById(idinp);
		(*it)->setInput(node);
	}
	aig->addOutputToNodes();
}

void AigerReader::readAAGNames(){

    vector<OutputNode*> *outputs = aig->getOutputNodes();
    vector<InputNode*> *inputs = aig->getInputNodes();

    int counter = 0;

    while(source)
    {
        source.getline(buf, 250, '\n');
        string s = buf;
        istringstream line;
        line.seekg(0);line.str(s);
        line >> word;

    	debug << word << endl;

        if(strcmp("c",word.substr(0).c_str())==0){
            debug << "the comments began. Ignore the file from here!\n";
            break;
        }
        else if(strcmp(word.substr(0,1).c_str(),"i")==0){
        	line >> word;

        	inputs->at(counter)->setName(word);
        	if(counter == nInputs - 1)
        		counter = 0;
        	else
        		counter++;
        }
        else if(strcmp(word.substr(0,1).c_str(),"o")==0){
        	line >> word;
        	outputs->at(counter)->setName(word);
        	if(counter == nOutputs - 1)
        		counter = 0;
        	else
        		counter++;
        }
        else if(strcmp(word.substr(0,1).c_str(),"l")==0){

        }
    }

}

void AigerReader::generateDot(GRAPH* aig, string filename){

	if(aig == NULL){
		cout << "Tryed to generate dotfile from an empty aig" << endl;
		exit(-2);
	}

	debug << "generating dotfile..." << endl;

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
	for(auto it = inputs->begin(); it < inputs->end(); it++){
		dotfile << "\"" << (*it)->getName() << "\"" << inputDetails << endl;
		inputsIds += "\"" +  (*it)->getName() + "\" ";
	}

	//write the and nodes on the dot file
    vector<AndNode*> *ands = aig->getAndNodes();
	for(auto it = ands->begin(); it < ands->end(); it++){
		dotfile << "\"" << (*it)->getName() << "\"" << andDetails << endl;
	}

	//write the output nodes on the dot file
    vector<OutputNode*> *outputs = aig->getOutputNodes();
	for(auto it = outputs->begin(); it < outputs->end(); it++){
		dotfile << "\"" << (*it)->getName() << "\"" << outputDetails << endl;
		outputsIds += "\"" + (*it)->getName() + "\" ";
	}

	//write the ands connections on the dot file
	for(auto it = ands->begin(); it < ands->end(); it++){

		dotfile << "\"" << (*it)->getInput(0)->getName() << "\"" << " -> " << "\"" << (*it)->getName() << "\"";
		if( (*it)->isInputInverted(0) )
			dotfile << negativeEdgeDetails << endl;
		else
			dotfile << positiveEdgeDetails << endl;

		dotfile << "\"" << (*it)->getInput(1)->getName() << "\"" << " -> " << "\"" << (*it)->getName() << "\"";
		if( (*it)->isInputInverted(1) )
			dotfile << negativeEdgeDetails << endl;
		else
			dotfile << positiveEdgeDetails << endl;

	}

	//write the outputs connections on the dot file
	for(auto it = outputs->begin(); it < outputs->end(); it++){
		dotfile << "\"" << (*it)->getInput()->getName() << "\"" << " -> " << "\"" << (*it)->getName() << "\"";
		if( (*it)->isInputInverted() )
			dotfile << negativeEdgeDetails << endl;
		else
			dotfile << positiveEdgeDetails << endl;
	}

	dotfile << "{ rank=source; ";
    dotfile << inputsIds << "}" << endl;
    dotfile << "{ rank=since; ";
    dotfile << outputsIds << "}" << endl;
    dotfile << "rankdir=\"BT\"" << endl << "}";

    debug << "dotfile generated\n";

}
