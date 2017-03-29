/*
 * AndNodeI.cpp
 *
 *  Created on: Mar 26, 2017
 *      Author: lucas
 */

#include"AndNodeI.h"
#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

namespace patch
{
    template < typename T > string to_string( const T& n )
    {
        ostringstream stm;
        stm << n ;
        return stm.str() ;
    }
}


AndNodeI::AndNodeI(const int id){
	this->setId(id);
///	this->setName(patch::to_string(id));
	indexInput0 = -1;
	indexInput1 = -1;
	input0Inverted = false;
	input1Inverted = false;
}


bool AndNodeI::isInputInverted(const int input0or1)const{
     if(input0or1 == 0)
    	 return this->input0Inverted;

     else if(input0or1 == 1)
    	 return this->input1Inverted;

     else{
    	 std::cout << "Invalid input number" << "\n";
    	 return false;
     }
}

void AndNodeI::setInputInverted(const bool inputInverted, const int input0or1){
    if(input0or1 == 0)
   	 this->input0Inverted = inputInverted;

    else if(input0or1 == 1)
   	 this->input1Inverted = inputInverted;

    else{
   	 std::cout << "Invalid input number" << "\n";
    }
}


void AndNodeI::setInputIndex(const int index, const int input0or1){

	if(index < 0){
		std::cout << "Negative index!" << endl;
        exit(-1);
	}

	if(input0or1 == 0)
	   	 this->indexInput0 = index;

    else if(input0or1 == 1)
	   	 this->indexInput1 = index;

	else
	   	 std::cout << "Invalid input number" << "\n";

}

int AndNodeI::getInputIndex(const int input0or1){

	if(input0or1 == 0)
		return this->indexInput0;
	else if(input0or1 == 1)
		return this->indexInput1;
	else{
		std::cout << "Invalid parameter \n";
		return -1;
	}
}
