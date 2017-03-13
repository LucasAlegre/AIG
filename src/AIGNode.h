/*
 * AIGNode.h
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#ifndef AIGNODE_H_
#define AIGNODE_H_

#include<iostream>
using namespace std;

typedef enum {
    AND_NODE,       // 0: AND object
    INPUT_NODE,     // 1: Input object
    OUTPUT_NODE     // 2: Ouput object
} AigNodeType;


class AIGNode {
private:
	int id;

public:
	AIGNode();
	virtual ~AIGNode();

	void setId(const int id);

	int getId() const;

	virtual AigNodeType getNodeType() = 0;

	virtual AIGNode* getInput(const int input0or1) = 0;

};



class InputNode: public AIGNode{
public:
	AigNodeType getNodeType();
    InputNode(const int id);
	AIGNode* getInput(const int input0or1){
		cout << "Tried to get input from an input node.\n";
		return NULL;
	}
};


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

	AIGNode* getInput(const int input0or1);

	bool isInputInverted() const;

	void setInputInverted(const bool inputInverted);
};



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

#endif /* AIGNODE_H_ */
