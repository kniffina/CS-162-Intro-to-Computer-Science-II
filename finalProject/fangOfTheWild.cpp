/*************************************************************
* Filename: fangOfTheWild.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/7/2016
* Description: This is the cpp file for the class FangOfTheWild
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "fangOfTheWild.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
FangOfTheWild::FangOfTheWild()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "This fang looks like it is fresh from the\n"
		" creatures mouth, it is still dripping with blood.\n";
	this->name = "Fang of the Wild";
	this->points = 1;
	this->number = 1;
	this->position = "North";
	this->number = 4;
}

//destructor. Nothing to clear up in memory so left blank 
FangOfTheWild::~FangOfTheWild()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string FangOfTheWild::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string FangOfTheWild::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int FangOfTheWild::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int FangOfTheWild::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string FangOfTheWild::getPosition()
{
	return this->position;
}