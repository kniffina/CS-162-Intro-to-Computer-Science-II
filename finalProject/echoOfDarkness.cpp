/*************************************************************
* Filename: echoOfDarkness.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/7/2016
* Description: This is the cpp file for the class EchoOfDarkness
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "echoOfDarkness.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
EchoOfDarkness::EchoOfDarkness()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "You hear the echoes of those who have\n"
		" fallen. You are inspired to save your people from the same fate.\n";
	this->name = "Echo of Darkness";
	this->points = 1;
	this->number = 1;
	this->position = "South";
	this->number = 11;
}

//destructor. Nothing to clear up in memory so left blank 
EchoOfDarkness::~EchoOfDarkness()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string EchoOfDarkness::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string EchoOfDarkness::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int EchoOfDarkness::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int EchoOfDarkness::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string EchoOfDarkness::getPosition()
{
	return this->position;
}