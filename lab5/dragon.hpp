/*************************************************************
* Filename: dragon.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/3/2016
* Description: This is the hpp file for the Dragon class. It contains
* member variables, function declarations, and constructors. It is
* inherited from the Monster class.
***************************************************************/
#include "monster.hpp"
#ifndef DRAGON_HPP
#define DRAGON_HPP

class Dragon : public Monster
{
private:
	//member variables
	string type;
	int attacks;
	int strength;
public:
	//default constructor
	Dragon();

	//attack function
	int attack();
};

#endif