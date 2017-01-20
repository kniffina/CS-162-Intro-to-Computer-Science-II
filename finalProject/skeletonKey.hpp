/*************************************************************
* Filename: skeletonKey.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/12/2016
* Description: This is the hpp file for the class SkeletonKey
* It is inherited from the cave Item. It contains member variables,
* function declarations, and constructors.
***************************************************************/
#include "item.hpp"

#ifndef SKELETONKEY_HPP
#define SKELETONKEY_HPP

class SkeletonKey : public Item
{
private:
	//member variables
	string position; //North, east, south, or west
	string explanation; //explanation on what the item is
	string name; //the name of the Item
	int points; //how many points the Item is worth
	int number; //the number correlated to the Item

public:
	//constructor
	SkeletonKey();

	//destructor
	~SkeletonKey();

	//get functions. The private member variables
	//will be set in the constructor
	string getExplanation();
	string getName();
	string getPosition();
	int getPoints();
	int getNumber();
};

#endif