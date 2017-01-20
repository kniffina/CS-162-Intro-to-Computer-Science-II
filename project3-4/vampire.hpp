/*************************************************************
* Filename: vampire.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/27/2016
* Description: This is the hpp file for the Vampire class. It contains
* member variables, constructors, and function declarations. It
* is inherited from the creature class.
* Input: none
* Output: none
***************************************************************/
#include "creature.hpp"
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

class Vampire : public Creature
{
private:
	//member variables
	int armor;
	int strengthPoints;
	string status;
	string type;
public:
	//default constructor
	Vampire();

	//attack and defense functions
	int attack();
	void defense(int);

	//get functions take no param and return string values
	string getType();
	string getStatus();

	//sets member variable status and returns void
	void setStatus(string);

	//restores original member variable qualities
	void heal();

	//returns the amount of points for the Creature object
	int getPoints();

	//increments the points for the creature
	void incrementPoints();

	//takes a string param and returns void
	void setTeam(string);

	//returns string value of member variable team
	string getTeam();
};

#endif