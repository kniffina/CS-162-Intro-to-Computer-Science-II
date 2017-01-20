/*************************************************************
* Filename: relicOfTime.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the cpp file for the class RelicOfTime
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "relicOfTime.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
RelicOfTime::RelicOfTime()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "The relic looks like it was from the first\n"
		" great war. You hold on to it tightly\n";
	this->name = "Relic of Time";
	this->points = 1;
	this->number = 8;
	this->position = "South";
}

//destructor. Nothing to clear up in memory so left blank 
RelicOfTime::~RelicOfTime()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string RelicOfTime::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string RelicOfTime::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int RelicOfTime::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int RelicOfTime::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string RelicOfTime::getPosition()
{
	return this->position;
}