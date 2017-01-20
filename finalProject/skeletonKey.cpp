/*************************************************************
* Filename: skeletonKey.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the cpp file for the class SkeletonKey.
* It is derived from the class Item. This contains function implementation.
* Each constructor, and function will be described in more detail below.
***************************************************************/
#include"item.hpp"
#include "skeletonKey.hpp"

//constructor sets all of the member variables accordingly. These are
//all preset, so when the user adds the item, it is already know
//what is being added to their bag.
SkeletonKey::SkeletonKey()
{
	//set all the member variables to their appropriate values. The 
	//points and numbers are set based on how 'value' the item is.
	this->explanation = "The key has an eerie feel to it. You think\n"
		" it will come in handy at a later time.\n";
	this->name = "Skeleton Key";
	this->points = 1;
	this->number = 3;
	this->position = "South";

}

//destructor. Nothing to clear up in memory so left blank 
SkeletonKey::~SkeletonKey()
{
	//left blank intentionally
}

//getExplanation function returns the string associated
//with the objects expalanation
string SkeletonKey::getExplanation()
{
	return this->explanation;
}

//getName returns the member variable name
string SkeletonKey::getName()
{
	return this->name;
}

//getPoints returns the points that this item is worth
int SkeletonKey::getPoints()
{
	return this->points;
}

//getNumber returns the number associated with this item
int SkeletonKey::getNumber()
{
	return this->number;
}

//getPosition returns the position of the Item is located in 
//the Cave that is holding it.
string SkeletonKey::getPosition()
{
	return this->position;
}