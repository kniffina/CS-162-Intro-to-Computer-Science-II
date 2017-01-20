/*************************************************************
* Filename: totemOfHealingRain.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the cpp file for the class TotemOfHealingRain.
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "totemOfHealingRain.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
TotemOfHealingRain::TotemOfHealingRain()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "A burst of raindrops come over you. You can\n"
		"feel your health growing\n";
	this->name = "Totem of Healing Rain";
	this->points = 1;
	this->number = 13;
	this->position = "East";

}

//destructor. Nothing to clear up in memory so left blank 
TotemOfHealingRain::~TotemOfHealingRain()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string TotemOfHealingRain::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string TotemOfHealingRain::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int TotemOfHealingRain::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int TotemOfHealingRain::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string TotemOfHealingRain::getPosition()
{
	return this->position;
}