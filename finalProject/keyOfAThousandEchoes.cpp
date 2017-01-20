/*************************************************************
* Filename: echoOfDarkness.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/7/2016
* Description: This is the cpp file for the class KeyOfAThousandEchoes
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "keyOfAThousandEchoes.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
KeyOfAThousandEchoes::KeyOfAThousandEchoes()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "You have heard stories of its power but never\n"
		"knew of its existence. This must be extremely important.\n";
	this->name = "Key of a Thousand Echoes";
	this->points = 1;
	this->number = 1;
	this->position = "South";
	this->number = 14;
}

//destructor. Nothing to clear up in memory so left blank 
KeyOfAThousandEchoes::~KeyOfAThousandEchoes()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string KeyOfAThousandEchoes::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string KeyOfAThousandEchoes::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int KeyOfAThousandEchoes::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int KeyOfAThousandEchoes::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string KeyOfAThousandEchoes::getPosition()
{
	return this->position;
}