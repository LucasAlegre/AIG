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

    /*
     *  Default constructor
     */
	BGraphI();

	/*
	 *  Frees the memory allocated for the array of nodes
	 */
	~BGraphI();

	/*
	 *  Allocates the array of nodes
	 *  @param nNodes The size of the array
	 */
	void iniatializeArray(const unsigned nNodes);

	/*
	 *  Insert an input node to the graph
	 *  @param id Literal of the node
	 */
	void insertInputNode(const unsigned int id);

	/*
	 *  Insert an output node to the graph
	 *  @param id Literal of the node
	 */
	void insertOutputNode(const unsigned int id);

	/*
	 *  Insert an and node to the graph
	 *  @param id Literal of the node
	 */
	void insertAndNode(const unsigned int id, unsigned int rhs0, unsigned int rhs1);

	/*
	 *  Connects the output nodes in the graph
	 */
	void connectOutputs();

	// TODO: Useless method??
	AIGNodeI* getNodes(){return NULL;}

	/*
	 *  Prints the id and input of each node for debugging
	 */
	void print();
};

#endif /* INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BGRAPHI_H_ */
