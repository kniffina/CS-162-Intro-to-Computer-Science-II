/*************************************************************
* Filename: creature
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/24/2016
* Description: This is the hpp file for class Creature. It is an abstract
* class, and also contains member variables and pure virtual functions.
* Input: none
* Output: none
***************************************************************/
#include <string>
#ifndef CREATURE_HPP
#define CREATURE_HPP
using std::string;

class Creature
{
protected:
	//do we need member variables in an abstract class?
	int armor;//keeps track of armor points
	int strengthPoints;//keep track of strength points or life
	string type;//declares the type of creature
	string status;//variable to tell if creature is alive
	int points;//integer to keep track of how many points the creature has earned
	string team;//string that keeps track of what team the Creature is on

public:
	//constructor
	Creature();

	//pure virtual functions
	virtual int attack() = 0;
	virtual void defense(int damage) = 0;
	
	//virtual get functions take no parameters and return string values
	virtual string getType() = 0;
	virtual string getStatus() = 0;

	//set virtual functions take string param and return void
	virtual void setStatus(string) = 0;

	//restores the member variables original qualities
	virtual void heal() = 0;

	//returns the integer value associated with how many points the creature has
	virtual int getPoints() = 0;

	//increments the amount of points for the member variable points
	virtual void incrementPoints() = 0;

	//sets the team that the Creature is on
	virtual void setTeam(string) = 0;

	//returns the string member variable team
	virtual string getTeam() = 0;
};

#endif