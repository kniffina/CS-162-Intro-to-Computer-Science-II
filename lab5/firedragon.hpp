/*************************************************************
* Filename: firedragon.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/4/2016
* Description: This is the hpp file for the FireDragon class. It contains
* member variables, function declarations, and constructors. It is
* inherited from the Dragon class.
***************************************************************/
#include "dragon.hpp"
#ifndef FIREDRAGON_HPP
#define FIREDRAGON_HPP

class FireDragon : public Dragon
{
private:
	//member variables
	string type;
	int attacks;
	int strength;
public:
	//default constructor
	FireDragon();

	//attack function
	int attack();
};

#endif