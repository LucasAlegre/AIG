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

namespace patch
{
    template < typename T >
    string to_string( const T& n )
    {
        ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


typedef enum {
    AND_NODE,       // 0: AND object
    INPUT_NODE,     // 1: Input object
    OUTPUT_NODE     // 2: Ouput object
} AigNodeType;

/**
*    Class that implements a generic node,
*    all kinds of nodes inherit from this class
*    
*/
class AIGNode {
private:
	unsigned id;   // Literal of the node in the file
	string name;  // Name of the node

public:
	/*
	 *  Default constructor
	 */
	AIGNode();
	
	/**
	*   Constructor
	*   @param id Id of the node
	*/
	AIGNode(unsigned id);
	
	/*
	 * Default destructor
	 */
	virtual ~AIGNode();

	// Getters and Setters
	void setId(const unsigned id);
	unsigned int getId() const;
	void setName(string name);
	string getName()const;
	
	/*
	*   @return the enum representing the type of the node
	*/
	virtual AigNodeType getNodeType() = 0;
	
	/*
	*   Virtual functions that only Bidirectioned Nodes implement
	*   Unidirected nodes will report a warning
	*/
	virtual AIGNode* getOutput(int x);
	virtual bool getOutputInverted(int x);
	virtual vector<AIGNode*> * getOutputs();
	virtual void setOutput(AIGNode* node, bool inverted);
	virtual vector<bool> * getOutputsInverted();
};




// --- And Node



#endif /* AIGNODE_H_ */
