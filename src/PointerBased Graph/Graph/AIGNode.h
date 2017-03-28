/*
 * AIGNode.h
 *
 *   AIG Nodes Classes
 *
 *  Created on: Mar 9, 2017
 *      Author: lucas
 */

#ifndef AIGNODE_H_
#define AIGNODE_H_

#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

typedef enum {
    AND_NODE,       // 0: AND object
    INPUT_NODE,     // 1: Input object
    OUTPUT_NODE     // 2: Ouput object
} AigNodeType;

/**
    Class that implements a generic node,
    all kinds of nodes inherit from this class
    
*/
class AIGNode {
private:
	unsigned id;   // Literal read on the .aag or .aig file 
	string name;  // Name of the node

public:
	//Default constructor
	AIGNode();
	
	/**
	*   Constructor
	*
	*   @param id Id of the node
	*/
	AIGNode(unsigned id);
	
	//Default destructor
	virtual ~AIGNode();

	// Getters and Setters
	void setId(const unsigned id);
	unsigned int getId() const;
	void setName(string name);
	string getName()const;
	
	/*
	*   Returns the enum representing the type of the node
	*/
	virtual AigNodeType getNodeType() = 0;
	
	/*
	*   Virtual functions that only Bidirectioned Nodes implement
	*   Unidirected nodes will report an warning
	*/
	virtual vector<AIGNode*> * getOutputs();
	virtual void setOutput(AIGNode* node);
	virtual vector<bool> * getOutputsInverted();
};

/*
*   Class that implements an Input Node
*
*/
class InputNode: public AIGNode{
public:
	/*
	*  Constructor
	*  @param id Id of the node
	*/
	InputNode(const unsigned id);
	
	/*
	*   Returns the enum representing the type of the node
	*/
	AigNodeType getNodeType();
	
	/*
	*  Get one of the inputs
	*
	* @param input0or1 Whether should return the input0 or input1
	* @return The wanted input of the node
	*/
	AIGNode* getInput(const int input0or1);
};

/*
*   Class that implements an Output Node
*
*/
class OutputNode: public AIGNode{
private:
	AIGNode* input0;   // Output node only has one input
	bool input0Inverted;  // Whether the input is inverted

public:
	/*
	*  Constructor
	*  @param id Id of the node
	*/
	OutputNode(const int id);
	~OutputNode();

	/*
	*   Returns the enum representing the type of the node
	*/
	AigNodeType getNodeType();
	
	/*
	*  Set pointer to the input node
	*  
	*  @param node Pointer to the input
	*/
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


#endif /* AIGNODE_H_ */
