/*
 * BGraph.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: lucas
 */

#include "../../PointerBased Graph/Bidirected Graph/BGraph.h"

#include <vector>
#include <iostream>

#include "../../PointerBased Graph/Graph/AIGNode.h"
#include "../../PointerBased Graph/Graph/Graph.h"
#include "BInputNode.h"
#include "BOutputNode.h"
#include "BAndNode.h"

	BGraph::BGraph(){

	}

	BGraph::BGraph(Graph &aig){
		InputNode* constant = new InputNode(0);
		constant->setName("constant");
		getNodes()->push_back(constant);

		vector<InputNode*> *inputs = aig.getInputNodes();
		for(auto it = inputs->begin(); it < inputs->end(); it++){
			insertInputNode((*it)->getId());
		}
		vector<OutputNode*> *outputs = aig.getOutputNodes();
		for(auto it = outputs->begin(); it < outputs->end(); it++){
			insertOutputNode((*it)->getId());
		}
		vector<AndNode*> *ands = aig.getAndNodes();
		for(auto it = ands->begin(); it < ands->end(); it++){
			unsigned i0 = (*it)->getInput(0)->getId();
			unsigned i1 = (*it)->getInput(1)->getId();
			if((*it)->isInputInverted(0))
				i0++;
			if((*it)->isInputInverted(1))
				i1++;

			insertAndNode((*it)->getId(), i0, i1);
		}

		connectOutputs();

	}

	BGraph::~BGraph(){
         for(auto it = nodes.begin(); it < nodes.end(); it++){
        	 delete *it;
         }
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
		bool inp0Inverted;
		bool inp1Inverted;

		if(rhs0 % 2 == 0){
			inp0Inverted = false;
			andnode->setInputInverted(false, 0);
		}
		else{
			inp0Inverted = true;
			andnode->setInputInverted(true, 0);
			rhs0--;
		}

		if(rhs1 % 2 == 0){
			inp1Inverted = false;
			andnode->setInputInverted(false, 1);
		}
		else{
			inp1Inverted = true;
			andnode->setInputInverted(true, 1);
			rhs1--;
		}


		AIGNode *in0 = findNodeById(rhs0);
		AIGNode *in1 = findNodeById(rhs1);
		andnode->setInput(in0, in1);

		in0->setOutput(andnode, inp0Inverted);
		in1->setOutput(andnode, inp1Inverted);

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
			bool inpInverted = false;
			int idinp = (*it)->getId();
			if(idinp % 2 != 0){
			     inpInverted = true;
				(*it)->setInputInverted(true);
				idinp--;
			}
			AIGNode* node = this->findNodeById(idinp);
			(*it)->setInput(node);
			node->setOutput((*it), inpInverted);
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

	void BGraph::print(){
		for(auto it = inputs.begin(); it < inputs.end(); it++){
			std::cout << "Id: " << (*it)->getId() << endl;
			std::cout << " name: " << (*it)->getName() << endl;

			for(unsigned i = 0; i < (*it)->getOutputs()->size(); i++){
				std::cout << " out"<<i<<": "<<(*it)->getOutput(i)->getId() << " inv? :" << (*it)->getOutputInverted(i) << endl;
			}
		}

		for(auto it = andNodes.begin(); it < andNodes.end(); it++){
			std::cout << "Id: " << (*it)->getId() << endl;
			std::cout << " name: " << (*it)->getName() << endl;
			for(unsigned i = 0; i < (*it)->getOutputs()->size(); i++){
				std::cout << " out"<<i<<": "<<(*it)->getOutput(i)->getId() << " inv? :" << (*it)->getOutputInverted(i) << endl;
			}
		}

		for(auto it = outputs.begin(); it < outputs.end(); it++){
			std::cout << "Id: " << (*it)->getId() << endl;
			std::cout << " name: " << (*it)->getName() << endl;
			std::cout << " in0: " << (*it)->getInput()->getId() << " inv? :" << (*it)->isInputInverted(0) << endl;

	    }
	}

