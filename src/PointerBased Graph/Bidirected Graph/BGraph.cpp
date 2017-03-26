/*
 * BGraph.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: lucas
 */

#include "../../PointerBased Graph/Bidirected Graph/BGraph.h"

#include <vector>
#include <iostream>

#include "../../PointerBased Graph/Bidirected Graph/BAIGNode.h"
#include "../../PointerBased Graph/Graph/AIGNode.h"
#include "../../PointerBased Graph/Graph/Graph.h"

	BGraph::BGraph(){

	}
	BGraph::~BGraph(){

	}

	void BGraph::insertInputNode(const unsigned id){
		BInputNode* input = new BInputNode(id);
		this->inputs.push_back(input);
		this->nodes.push_back(input);
	}

	void BGraph::insertOutputNode(const unsigned int id){
		BOutputNode* output = new BOutputNode(id);

		this->outputs.push_back(output);
	}

	void BGraph::insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1){
		BAndNode* andnode = new BAndNode(id);

		if(rhs0 % 2 == 0){
			andnode->setInputInverted(false, 0);
		}
		else{
			andnode->setInputInverted(true, 0);
			rhs0--;
		}

		if(rhs1 % 2 == 0){
			andnode->setInputInverted(false, 1);
		}
		else{
			andnode->setInputInverted(true, 1);
			rhs1--;
		}


		AIGNode *in0 = findNodeById(rhs0);
		AIGNode *in1 = findNodeById(rhs1);
		andnode->setInput(in0, in1);

		in0->setOutput(andnode);
		in1->setOutput(andnode);

		this->andNodes.push_back(andnode);
		this->nodes.push_back(andnode);
	}

	// Insert the outputs vector at the end of the nodes vector
	void BGraph::addOutputToNodes(){

		this->nodes.insert(nodes.end(), outputs.begin(), outputs.end());
	}

	AIGNode* BGraph::findNodeById(const unsigned int id){
		if(id == 0)
			return nodes[0];

		return nodes[id/2];
	}

	//Connect the outputs to its inputs
	void BGraph::connectOutputs(){

	    vector<OutputNode*>::iterator it;
	    vector<OutputNode*> *outputs = this->getOutputNodes();
		for(it = outputs->begin(); it < outputs->end(); it++){
			int idinp = (*it)->getId();
			if(idinp % 2 != 0){
				(*it)->setInputInverted(true);
				idinp--;
			}
			AIGNode* node = this->findNodeById(idinp);
			(*it)->setInput(node);
			node->setOutput((*it));
		}
		this->addOutputToNodes();
	}

	vector<AIGNode*> * BGraph::getNodes(){
		return &(this->nodes);
	}
	vector<InputNode*> * BGraph::getInputNodes(){
		return &(this->inputs);
	}
	vector<AndNode*> * BGraph::getAndNodes(){
		return &(this->andNodes);
	}
	vector<OutputNode*> * BGraph::getOutputNodes(){
		return &(this->outputs);
	}

