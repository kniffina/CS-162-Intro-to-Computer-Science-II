/*************************************************************
* Filename: shadowsEmbrace.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the cpp file for the class ShadowsEmbrace
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "shadowsEmbrace.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
ShadowsEmbrace::ShadowsEmbrace()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "Darkness overpowers you. You try to\n"
		" to put the Item down, but you want to hold it\n";
	this->name = "Shadows Embrace";
	this->points = 1;
	this->number = 10;
	this->position = "North";
}

//destructor. Nothing to clear up in memory so left blank 
ShadowsEmbrace::~ShadowsEmbrace()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string ShadowsEmbrace::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string ShadowsEmbrace::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int ShadowsEmbrace::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int ShadowsEmbrace::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string ShadowsEmbrace::getPosition()
{
	return this->position;
}