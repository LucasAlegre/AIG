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
	AIGNode(){
		id=-1;
	}
	AIGNode(const unsigned id){
		this->id = id;
	}
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
	virtual vector<AIGNode*> * getOutputs(){return NULL;}
	virtual void setOutput(AIGNode* node){

	}
	vector<bool> * getOutputsInverted(){
		return NULL;
	}
};

// --- Input Node

class InputNode: public AIGNode{
public:
	virtual void setOutput(AIGNode* node){}

	InputNode(const unsigned id);
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
	virtual void setOutput(AIGNode* node){}

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
	virtual void setOutput(AIGNode* node){}

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


#endif /* AIGNODE_H_ */
