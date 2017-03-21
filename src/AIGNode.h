/*
 * AIGNode.h
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#ifndef AIGNODE_H_
#define AIGNODE_H_

#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
#include<vector>

using namespace std;

typedef enum {
    AND_NODE,       // 0: AND object
    INPUT_NODE,     // 1: Input object
    OUTPUT_NODE     // 2: Ouput object
} AigNodeType;

// --- AIG Node

class AIGNode {
private:
	unsigned id;
	string name;

public:
	AIGNode();
	virtual ~AIGNode();

	void setId(const unsigned id);
	unsigned int getId() const;
	void setName(const string name){
		this->name = name;
	}
	string getName()const{
		return this->name;
	}

	virtual AigNodeType getNodeType() = 0;

};

// --- Input Node

class InputNode: public AIGNode{
public:

	InputNode(const int id);

	AigNodeType getNodeType();
	AIGNode* getInput(const int input0or1){
		cout << "Tried to get input from an input node.\n";
		return NULL;
	}
};

// --- Output Node

class OutputNode: public AIGNode{
private:
	AIGNode* input0;
	bool input0Inverted;

public:
	OutputNode(const int id);
	~OutputNode(){
		delete input0;
	}

	AigNodeType getNodeType();

	void setInput(AIGNode* node);

	AIGNode* getInput();

	bool isInputInverted() const;

	void setInputInverted(const bool inputInverted);
};

// --- And Node

class AndNode: public AIGNode{
private:
	AIGNode* input0;
	AIGNode* input1;
    bool input0Inverted;
    bool input1Inverted;

public:
    AndNode(const int id);

    ~AndNode(){
    	delete input0;
    	delete input1;
    }

	AigNodeType getNodeType();

	void setInput(AIGNode* inp0, AIGNode* in1);

	bool isInputInverted(const int input0or1) const;

	AIGNode* getInput(const int input0or1);

	void setInputInverted(const bool inputInverted, const int input0or1);
};

class AIGNodeB: public AIGNode {
private:
	vector<AIGNode*> outputs;
	vector<bool> outputsInverted;
public:
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

class InputNodeB: public InputNode, AIGNodeB{
};

class AndNodeB: public AndNode, AIGNodeB{
};

#endif /* AIGNODE_H_ */
