/*************************************************************
* Filename: forlornCavern.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/7/2016
* Description: This is the hpp file for the class ForlornCavern
* It is inherited from the cave class. It contains member variables,
* function declarations, and constructors.
***************************************************************/
#include "cave.hpp"
#ifndef FORLORNCAVERN_HPP
#define FORLORNCAVERN_HPP

class ForlornCavern : public Cave
{
private:
	//member variables
	string type;
	string explanation;
	vector<Item *> itemsInCave;
	Cave *array[4];
public:
	//constructor
	ForlornCavern();

	//destructor
	~ForlornCavern();

	//get functions
	string getType();
	string getExplanation();

	//look allows the user to look a certain direction
	//and returns the Item in that location if it is there.
	Item* look();

	//set the 4 pointers to the other caves
	void setArray(Cave*, Cave*, Cave*, Cave*);

	//other caves will be used to see what other caves
	//are connected to the Cave object
	void otherCaves();

	//These functions return a cave in the corresponding
	//value in the Cave object array. I.E. array[0]
	Cave* returnCave0();
	Cave* returnCave1();
	Cave* returnCave2();
	Cave* returnCave3();
};

#endif