/*************************************************************
* Filename: HourglassOfEternity.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the cpp file for the class HourglassOfEternity
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "HourglassOfEternity.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
HourglassOfEternity::HourglassOfEternity()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "You turn the hour glass over, but\n"
		" the sand doesn't move. Is time standing still?\n";
	this->name = "Hourglass of Eternity";
	this->points = 1;
	this->number = 1;
	this->position = "East";
	this->number = 7;
}

//destructor. Nothing to clear up in memory so left blank 
HourglassOfEternity::~HourglassOfEternity()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string HourglassOfEternity::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string HourglassOfEternity::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int HourglassOfEternity::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int HourglassOfEternity::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string HourglassOfEternity::getPosition()
{
	return this->position;
}
