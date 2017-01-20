/*************************************************************
* Filename: icedragon.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/4/2016
* Description: This is the hpp file for the IceDragon class. It contains
* member variables, function declarations, and constructors. Ice Dragon
* is inherited from the class Dragon
***************************************************************/
#include "dragon.hpp"
#ifndef ICEDRAGON_HPP
#define ICEDRAGON_HPP

class IceDragon : public Dragon
{
private:
	//member variables
	string type;
	int attacks;
	int strength;
public:
	//default constructor
	IceDragon();

	//attack function
	int attack();
};

#endif