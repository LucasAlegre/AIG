/*
 * AndNodeI.h
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#ifndef INTEGERBASED_GRAPH_GRAPH_ANDNODEI_H_
#define INTEGERBASED_GRAPH_GRAPH_ANDNODEI_H_

class AndNodeI: public AIGNodeI{
private:
    int indexInput0;
    int indexInput1;
    bool input0Inverted;
    bool input1Inverted;

public:
    AndNodeI(const int id);

    ~AndNodeI(){

    }

	void setInput(const int index0, const int index1);
	bool isInputInverted(const int input0or1) const;
	int getInputIndex(const int input0or1);
	void setInputInverted(const bool inputInverted, const int input0or1);
};

#endif /* INTEGERBASED_GRAPH_GRAPH_ANDNODEI_H_ */
