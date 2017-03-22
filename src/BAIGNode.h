/*
 * BAIGNode.h
 *
 *  Created on: Mar 22, 2017
 *      Author: lucas
 */

#ifndef BAIGNODE_H_
#define BAIGNODE_H_

#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<vector>
#include"AIGNode.h"

/*
 *  Bidirected Input Node
 */

class BInputNode: public InputNode {
private:
	vector<AIGNode*> outputs;
	vector<bool> outputsInverted;
public:
	BInputNode(const unsigned id): InputNode(id)
	{

	}

	AigNodeType getNodeType(){
		return INPUT_NODE;
	}
	vector<AIGNode*> * getOutputs(){
		cout << "aqui";
		return &(this->outputs);
	}
	void setOutput(AIGNode* node){
        cout << "KKK";
		outputs.push_back(node);
	}
	vector<bool> * getOutputsInverted(){
		return &(this->outputsInverted);
	}
};

class BOutputNode: public OutputNode {
public:
	BOutputNode(const unsigned id): OutputNode(id)
	{

	}
	AigNodeType getNodeType(){
		return OUTPUT_NODE;
	}
	vector<AIGNode*> * getOutputs(){
		cout << "Tried to get outputs from an output node\n";
		return NULL;
	}
	void setOutput(AIGNode* node){
		cout << "Tried to set an output for an output node\n";
	}
	vector<bool> * getOutputsInverted(){
		cout << "Tried to get outputs inverted from an output node\n";
		return NULL;
	}
};

/*
 * Bidirected And Node
 */

class BAndNode: public AndNode{
private:
	vector<AIGNode*> outputs;
	vector<bool> outputsInverted;
public:
	BAndNode(const unsigned id): AndNode(id)
	{

	}
	AigNodeType getNodeType(){
		return AND_NODE;
	}
	vector<AIGNode*> * getOutputs(){
		return &(this->outputs);
	}
	void setOutput(AIGNode* node){
		outputs.push_back(node);
	}
	vector<bool> * getOutputsInverted(){
		return &(this->outputsInverted);
	}

};

#endif /* BAIGNODE_H_ */
