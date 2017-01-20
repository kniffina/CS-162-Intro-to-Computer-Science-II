/*************************************************************
* Filename: bluemen.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/26/2016
* Description: This is the hpp file for the BlueMen class. It contains
* member variables, constructors, and function declarations. It
* is inherited from the creature class.
* Input: none
* Output: none
***************************************************************/
#include "creature.hpp"
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

class BlueMen : public Creature
{
private:
	//member variables
	int armor;
	int strengthPoints;
public:
	//default constructor
	BlueMen();

	//
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