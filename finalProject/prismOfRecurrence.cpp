/*************************************************************
* Filename: prismOfRecurrence.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the cpp file for the class PrismOfRecurrence
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "prismOfRecurrence.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
PrismOfRecurrence::PrismOfRecurrence()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "The prism flickers. You see the cave\n"
		" the cave you were just in. What is this power?\n";
	this->name = "Prism of Recurrence";
	this->points = 1;
	this->number = 9;
	this->position = "West";
}

//destructor. Nothing to clear up in memory so left blank 
PrismOfRecurrence::~PrismOfRecurrence()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string PrismOfRecurrence::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string PrismOfRecurrence::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int PrismOfRecurrence::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int PrismOfRecurrence::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string PrismOfRecurrence::getPosition()
{
	return this->position;
}