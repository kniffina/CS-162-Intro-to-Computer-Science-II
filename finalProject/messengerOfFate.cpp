/*************************************************************
* Filename: messengerOfFate.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the cpp file for the class MessengerOfFate
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "messengerOfFate.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
MessengerOfFate::MessengerOfFate()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "The item looks like a dagger from the Undead Lord.\n"
		" It's power is extraordinary.\n";
	this->name = "Messenger of Fate";
	this->points = 1;
	this->number = 12;
	this->position = "West";

}

//destructor. Nothing to clear up in memory so left blank 
MessengerOfFate::~MessengerOfFate()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string MessengerOfFate::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string MessengerOfFate::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int MessengerOfFate::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int MessengerOfFate::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string MessengerOfFate::getPosition()
{
	return this->position;
}

