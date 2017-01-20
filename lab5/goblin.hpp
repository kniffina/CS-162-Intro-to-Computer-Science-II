/*************************************************************
* Filename: goblin.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/3/2016
* Description: This is the hpp file for the Goblin class. It contains
* member variables, function declarations, and constructors. Goblin
* is inherited from the class Monster.
***************************************************************/
#include "monster.hpp"
#ifndef GOBLIN_HPP
#define GOBLIN_HPP

class Goblin : public Monster
{
private:
	//member variables
	string type;
	int attacks;
	int strength;
public:
	//default constructor
	Goblin();

	//attack function
	int attack();
};

#endif