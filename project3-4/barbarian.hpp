/*************************************************************
* Filename: barbarian.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/26/2016
* Description: This is the hpp file for class Barbarian it contains
* member variables, constructors, and function declarations.
* It is inherited from the Creature class.
* Input: none
* Output: none
***************************************************************/
#include "creature.hpp"
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

class Barbarian : public Creature
{
private:
	int armor;
	int strengthPoints;

public:
	//constructor
	Barbarian();

	int attack();
	void defense(int damage);

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