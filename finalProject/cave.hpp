/*************************************************************
* Filename: cave.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/7/2016
* Description: This is the hpp file for the class Cave. It contains
* member variables and function declarations. The functions are
* virtual functions and this is an abstract class. 
***************************************************************/
#include "item.hpp"
#include <string>
#include <iostream>
#include <vector>
using std::vector;
using std::string;
#ifndef CAVE_HPP
#define CAVE_HPP

class Cave
{
private:
	//member variables
	string type;
	string explanation;
	
	//vector to hold items in the cave
	vector<Item *> itemsInCave;

	//array holds the pointers to other Caves connected
	//with this one
	Cave *array[4];
public:
	//virtual functions are just placeholders
	virtual string getType() = 0;
	virtual string getExplanation() = 0;

	//look allows the user to look a certain direction
	//and returns the Item in that location if it is there.
	virtual Item* look() = 0;

	//set the 4 pointers to the other caves
	virtual void setArray(Cave*, Cave*, Cave*, Cave*) = 0;

	//other caves will be used to see what other caves
	//are connected to the Cave object
	virtual void otherCaves() = 0;

	//These functions return a cave in the corresponding
	//value in the array. I.E. array[0]
	virtual Cave* returnCave0() = 0;
	virtual Cave* returnCave1() = 0;
	virtual Cave* returnCave2() = 0;
	virtual Cave* returnCave3() = 0;
};

#endif