/*************************************************************
* Filename: creature
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/12/2016
* Description: This is cpp file for the Class creature. It contains
* a constructor. Other functions are all virtual.
* Input: none
* Output: none
***************************************************************/
#include "creature.hpp"

//constructor for Creature class. Takes 4 integer parameters and
//sets the member variables of the creature class equal to each 
//respective int passed in.
Creature::Creature()
{
	this->armor = 0;
	this->strengthPoints = 0;
	this->type = "Creature";
	this->status = "alive";
	this->team = "";//set team to nothing
}