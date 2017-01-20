/*************************************************************
* Filename: glowingShard.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the cpp file for the class GlowingShard
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "glowingShard.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
GlowingShard::GlowingShard()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "The shard flickers with beams of light\n"
		" You feel your strength increase.\n";
	this->name = "Glowing Shard";
	this->points = 1;
	this->number = 1;
	this->position = "West";
	this->number = 6;
}

//destructor. Nothing to clear up in memory so left blank 
GlowingShard::~GlowingShard()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string GlowingShard::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string GlowingShard::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int GlowingShard::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int GlowingShard::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string GlowingShard::getPosition()
{
	return this->position;
}