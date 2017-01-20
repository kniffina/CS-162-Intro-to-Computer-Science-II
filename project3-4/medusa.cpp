/*************************************************************
* Filename: medusa.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/12/2016
* Description: This is the cpp file for class Medusa. It contains
* a constructor and an attack function which will be described in more
* detail below. It also contains a defense function that takes an integer
* as its parameter that represents the amount of damage done, and
* determines how much damage is ultimately inflicted to the creature.
* Input: none
* Output: none
***************************************************************/
#include "medusa.hpp"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using std::cout;

//default constructor sets the member variables to 3 and 8 respectively
Medusa::Medusa()
{
	this->armor = 3;//set armor to 3
	this->strengthPoints = 8;//set strengthPoints / life to 12
	this->type = "Medusa";//set type to Medusa
	this->status = "alive";//make Medusa alive (2 choices alive or dead)
	this->points = 0; //set member variable points to 0
	this->team = "";//set team to nothing
}

/******************************************************************************
* attack function. Takes no parameters. The function has variables that correspond with
* the number of dice that this specific class have designated to "attack". Each class
* also has a unique number of sides per dice. The dice are rolled (randomized) and the
* total is added. This is the total damage done to the opponent and the integer value is
* returned.
*******************************************************************************/
int Medusa::attack()
{
	//declare variables to hold attacks beings done
	int attack1, attack2, total;
	//2 die, 6 sides each

	attack1 = 1 + rand() % 6;//1st attack, equal to a Dice being rolled with 6 sides
	attack2 = 1 + rand() % 6;//2nd attack, equal to a Dice being rolled with 6 sides
	total = attack1 + attack2;//add the two attacks together

	if (total == 12)
		total = 1000; //set total to a large integer so Medusa always wins

	return total;//return the total damage	
}

/******************************************************************************
* defense function takes an integer value as its parameter. It then calculates the
* total defense of the Creature by rolling the corresponding Die, adding it to the
* armor of the creature, and subtracting the damage. This is then taken away from the
* strength points of the Creature object.
*******************************************************************************/
void Medusa::defense(int damage)
{
	//declare variable to hold amount of defense calculated
	int defense, totalDefense;

	defense = 1 + rand() % 6;//Medusa's defense calculated by 1 random 6 sided die

	totalDefense = defense + this->armor; //calculate total Defense

	if (totalDefense >= damage)
	{
		this->strengthPoints += 0;//strength points remains the same because damage did not get past defense
		damage = 0;//no damage taken
	}

	else//damage is greater then defense points. Subtract the damage inflicted from the strength points 	
	{
		damage = damage - totalDefense;//calculate total damange to inflict on Creature
		this->strengthPoints = this->strengthPoints - damage;//deduct the damage from the strength points that the monster has
	}
	

	//if strength points for the Barbarian object gets to 0 or less, 
	//then the Barbarian is defeated.
	if (this->strengthPoints <= 0)
	{
		cout
			<< "\n**************************************************\n"
			<<   "*******	 Medusa has been DEFEATED!         ******\n"
			<<   "**************************************************\n\n";
		this->setStatus("dead");//set status to dead
	}
}

//getType takes no parameters and returns a string value that is 
//the type of the Creature
string Medusa::getType()
{
	return this->type;
}
//getStatus takes no parameters and returns a string value that is
//the status of the Creature
string Medusa::getStatus()
{
	return this->status;
}

//setStatus takes a string parameter and sets the member variable
//to the variable being passed in
void Medusa::setStatus(string s)
{
	this->status = s;
}

/************************************************************************************
* heal function has the properties of the default constructor but it used after a
* fight takes place. This is so the object can be placed back into the linked structure
* to continue battling in the tournament.
************************************************************************************/
void Medusa::heal()
{
	this->armor = 3;//set armor to 3
	this->strengthPoints = 8;//set strengthPoints / life to 12
	this->type = "Medusa";//set type to Medusa
	this->status = "alive";//make Medusa alive (2 choices alive or dead)
}

//incrementPoint function takes no params and returns nothing but increments the
//member variable points
void Medusa::incrementPoints()
{
	this->points = this->points + 1;//increase points by 1
}

//getPoints function returns the member variable points
int Medusa::getPoints()
{
	return this->points;
}

//setTeam takes a string parameter and sets the member variable team
//to the value that is passed. This will generally be 1 or 2.
void Medusa::setTeam(string t)
{
	this->team = t;
}

//getTeam function returns the string value of the member variable
//team. It takes no parameters
string Medusa::getTeam()
{
	return this->team;
}