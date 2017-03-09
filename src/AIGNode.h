/*
 * AIGNode.h
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#ifndef AIGNODE_H_
#define AIGNODE_H_

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

};



class InputNode: public AIGNode{
public:
	AigNodeType getNodeType();
    InputNode(const int id);
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

	void setInputInverted(const bool inputInverted, const int input0or1);
};

#endif /* AIGNODE_H_ */
