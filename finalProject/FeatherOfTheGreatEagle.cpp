/*************************************************************
* Filename: FeatherOfTheGreatEagle.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/7/2016
* Description: This is the cpp file for the class FeatherOfTheGreatEagle
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "FeatherOfTheGreatEagle.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
FeatherOfTheGreatEagle::FeatherOfTheGreatEagle()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "You have heard stories about the Great Eaglen.\n"
		"Why is this feather in the cave? What is it's significance?\n";
	this->name = "Feather of the Great Eagle";
	this->points = 1;
	this->number = 1;
	this->position = "East";
	this->number = 2;
}

//destructor. Nothing to clear up in memory so left blank 
FeatherOfTheGreatEagle::~FeatherOfTheGreatEagle()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string FeatherOfTheGreatEagle::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string FeatherOfTheGreatEagle::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int FeatherOfTheGreatEagle::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int FeatherOfTheGreatEagle::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string FeatherOfTheGreatEagle::getPosition()
{
	return this->position;
}