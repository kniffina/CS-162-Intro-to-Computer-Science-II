/*************************************************************
* Filename: potionOfEnlightenment.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/7/2016
* Description: This is the cpp file for the class PotionOfEnlightenment.
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "potionOfEnlightenment.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
PotionOfEnlightenment::PotionOfEnlightenment()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "The potion has a murkey look to it. You wonder who made this.\n" 
		"You glare into it, and you can see the fate of your people\n";
	this->name = "Potion of Enlightenment";
	this->points = 1;
	this->number = 1;
	this->position = "North";

}

//destructor. Nothing to clear up in memory so left blank 
PotionOfEnlightenment::~PotionOfEnlightenment()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string PotionOfEnlightenment::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string PotionOfEnlightenment::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int PotionOfEnlightenment::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int PotionOfEnlightenment::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string PotionOfEnlightenment::getPosition()
{
	return this->position;
}