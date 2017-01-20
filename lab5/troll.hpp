/*************************************************************
* Filename: troll.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/3/2016
* Description: This is the hpp file for the Troll class. It contains
* member variables, function declarations, and constructors. It is 
* inherited from the Monster class. 
***************************************************************/
#include "monster.hpp"
#ifndef TROLL_HPP
#define TROLL_HPP

class Troll : public Monster
{
private:
	//member variables
	string type;
	int attacks;
	int strength;
public:
	//default constructor
	Troll();

	//attack function
	int attack();
};

#endif