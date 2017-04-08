/*
 * BGraphI.h
 *
 *  Created on: 7 de abr de 2017
 *      Author: Lucas Alegre
 */

#ifndef INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BGRAPHI_H_
#define INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BGRAPHI_H_

#include "../GraphI/GraphI.h"
#include "BAIGNodeI.h"

class BGraphI: public GRAPHI{
private:
    BAIGNodeI *nodes;

public:
	BGraphI();
	~BGraphI();

	void iniatializeArray(const int nNodes);

	void insertInputNode(const unsigned int id);
	void insertOutputNode(const unsigned int id);
	void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1);

	void connectOutputs();

	AIGNodeI* getNodes(){return NULL;}
};

#endif /* INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BGRAPHI_H_ */
