/*************************************************************
* Filename: prismOfInnerCalm.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the cpp file for the class PrismOfInnerCalm
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "prismOfInnerCalm.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
PrismOfInnerCalm::PrismOfInnerCalm()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "You feel a sensation of calm come over\n"
		" You. You are no longer worried about the fate of your people.\n";
	this->name = "Prism of Inner Calm";
	this->points = 1;
	this->number = 1;
	this->position = "East";
	this->number = 5;
}

//destructor. Nothing to clear up in memory so left blank 
PrismOfInnerCalm::~PrismOfInnerCalm()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string PrismOfInnerCalm::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string PrismOfInnerCalm::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int PrismOfInnerCalm::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int PrismOfInnerCalm::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string PrismOfInnerCalm::getPosition()
{
	return this->position;
}