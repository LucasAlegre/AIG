/*
 * BAIGNodeI.h
 *
 *  Created on: Apr 6, 2017
 *      Author: lucas
 */

#ifndef INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BAIGNODEI_H_
#define INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BAIGNODEI_H_

#include "../GraphI/AIGNodeI.h"

class BAIGNodeI: public AIGNodeI {
private:
	vector<unsigned> fanOut;
	vector<bool> invertedFanOut;

public:

	/*
	 * Default Constructor
	 */
	BAIGNodeI();
	/*
	 *  Default Destructor
	 */
	~BAIGNodeI();


	/**
	*   Constructor
	*
	*   @param id Id of the node
	*   @param nodeType Enum representing the type of the node
	*/
	BAIGNodeI(const unsigned id, const AigNodeType nodeType);

	/*
	 *  Sets the index of the output in the "freeIndexFanOut" position
	 *  @param index Index of the output in the graph
	 *  @param inverted Wheter the output is inverted or not
	 */
	void setOutputIndex(const unsigned index,const bool inverted);

	/*
	 * 	@param i Index in the fan out of the output
	 *  @return The index in the graph of the output located in the position i of the fanOut
	 */
	unsigned getOutputIndex(unsigned i)const;

	/*
	 *  @param i Index in the fan out of the output
	 *  @return True if the output located in the position i of the fanOut is inverted, returns false otherwise
	 */
	bool getOutputInverted(unsigned i)const;

	/*
	 *  @return The size of the fanOut of the node
	 */
	unsigned getFanOutSize();

};

#endif /* INTEGERBASED_GRAPH_BIDIRECTED_GRAPHI_BAIGNODEI_H_ */
