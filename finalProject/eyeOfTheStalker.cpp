/*************************************************************
* Filename: eyeOfThestalker.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/12/2016
* Description: This is the cpp file for the class EyeOfTheStalker
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "eyeOfTheStalker.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
EyeOfTheStalker::EyeOfTheStalker()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "You peer into the eye of the deadly animal. You\n"
		"grow fierce, and gain the eye of a predator!\n";
	this->name = "Eye of the Stalker";
	this->points = 1;
	this->number = 1;
	this->position = "West";
	this->number = 15;
}

//destructor. Nothing to clear up in memory so left blank 
EyeOfTheStalker::~EyeOfTheStalker()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string EyeOfTheStalker::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string EyeOfTheStalker::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int EyeOfTheStalker::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int EyeOfTheStalker::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string EyeOfTheStalker::getPosition()
{
	return this->position;
}