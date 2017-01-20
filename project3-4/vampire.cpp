/*************************************************************
* Filename: vampire.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/12/2016
* Description: This is the cpp file for class Vampire. It contains
* a constructor and an attack function which will be described in more
* detail below. It also contains a defense function that takes an integer
* as its parameter that represents the amount of damage done, and
* determines how much damage is ultimately inflicted to the creature.
* Input: none
* Output: none
***************************************************************/
#include "vampire.hpp"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using std::cout;

//default constructor sets the member variables to 1 and 18 respectively
Vampire::Vampire()
{
	this->armor = 1;//set armor to 1
	this->strengthPoints = 18;//set strengthPoints / life to 18
	this->type = "Vampire";//set type to Vampire
	this->status = "alive";//make the Vampire alive (2 choices alive or dead)
	this->points = 0;//set member variable points to 0
	this->team = "";//set team to nothing
}

/******************************************************************************
*attack function.Takes no parameters.The function has variables that correspond with
* the number of dice that this specific class have designated to "attack".Each class
* also has a unique number of sides per dice.The dice are rolled(randomized) and the
* total is added.This is the total damage done to the opponent and the integer value is
* returned.
*******************************************************************************/
int Vampire::attack()
{
	//declare variables to hold attack being done
	int attack;

	attack = 1 + rand() % 12;//1st attack, equal to a dice being rolled with 12 sides

	return attack;//return integer attack
}

/******************************************************************************
* defense function takes an integer value as its parameter. It then calculates the
* total defense of the Creature by rolling the corresponding Die, adding it to the
* armor of the creature, and subtracting the damage. This is then taken away from the
* strength points of the Creature object.
*******************************************************************************/
void Vampire::defense(int damage)
{
	//declare variable to hold amount of defense calculated
	int defense, totalDefense;

	int special = rand() % 2;//randomly choose either a 0 or 1 and store it in special var
	if (special == 1)//50 % chance that it is a 1
		totalDefense = 350;//set total defense to a large variable. This is done strictly if Medusa gets a 12
	
	else//did not charm opponent
	{
		defense = 1 + rand() % 6;//Vampire's defense calculated by 1 random 6 sided die
		totalDefense = defense + this->armor;//calculate total defense by adding armor and defense
	
		if (totalDefense >= damage)
		{
			this->strengthPoints += 0;//strength points remains the same because damage did not get past defense
			damage = 0;//no damage taken
		}

		else//damage is greater then defense points. Subtract the damage inflicted from the strength points 
		{
			//calculate the total damage to inflict to the creature
			damage = damage - totalDefense;

			//deduct the damage from the strength points that the creature has
			this->strengthPoints = this->strengthPoints - damage;
		}
	}

	//if strength points for the Barbarian object gets to 0 or less, 
	//then the Barbarian is defeated.
	if (this->strengthPoints <= 0)
	{
		cout
			<< "\n**************************************************\n"
			<<   "*******	Vampire has been DEFEATED!         *****\n"
			<<   "**************************************************\n\n";
		this->setStatus("dead");//set status to dead
	}
}

//getType takes no parameters and returns a string value that is 
//the type of the Creature
string Vampire::getType()
{
	return this->type;
}
//getStatus takes no parameters and returns a string value that is
//the status of the Creature
string Vampire::getStatus()
{
	return this->status;
}

//setStatus takes a string parameter and sets the member variable
//to the variable being passed in
void Vampire::setStatus(string s)
{
	this->status = s;
}

/************************************************************************************
* heal function has the properties of the default constructor but it used after a
* fight takes place. This is so the object can be placed back into the linked structure
* to continue battling in the tournament.
************************************************************************************/
void Vampire::heal()
{
	this->armor = 1;//set armor to 1
	this->strengthPoints = 18;//set strengthPoints / life to 18
	this->type = "Vampire";//set type to Vampire
	this->status = "alive";//make the Vampire alive (2 choices alive or dead)
}

//incrementPoint function takes no params and returns nothing but increments the
//member variable points
void Vampire::incrementPoints()
{
	this->points = this->points + 1;//increase points by 1
}

//getPoints function returns the member variable points
int Vampire::getPoints()
{
	return this->points;
}

//setTeam takes a string parameter and sets the member variable team
//to the value that is passed. This will generally be 1 or 2.
void Vampire::setTeam(string t)
{
	this->team = t;
}

//getTeam function returns the string value of the member variable
//team. It takes no parameters
string Vampire::getTeam()
{
	return this->team;
}