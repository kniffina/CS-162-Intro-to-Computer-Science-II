/*************************************************************
* Filename: harrypotter.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/12/2016
* Description: This is the cpp file for class harryPotter. It contains
* a constructor and an attack function which will be described in more
* detail below. It also contains a defense function that takes an integer
* as its parameter that represents the amount of damage done, and
* determines how much damage is ultimately inflicted to the creature.
* Input: none
* Output: none
***************************************************************/
#include "harrypotter.hpp"
#include <iostream>
#include <stdlib.h>
#include <ctime>
using std::cout;

//default constructor sets the member variables to 0 and 10 respectively
HarryPotter::HarryPotter()
{
	this->armor = 0;//set armor to 0
	this->strengthPoints = 10;//set strengthPoints / life to 10
	this->type = "HarryPotter";//set type to HarryPotter
	this->status = "alive";//make HarryPotter alive (2 choices alive or dead)
	this->lifes = 1;//set lifes member variable to 1. Unique to harry potter
	this->points = 0;//set member variable points to 0
	this->team = "";//set team to nothing
}

/******************************************************************************
* attack function. Takes no parameters. The function has variables that correspond with
* the number of dice that this specific class have designated to "attack". Each class
* also has a unique number of sides per dice. The dice are rolled (randomized) and the
* total is added. This is the total damage done to the opponent and the integer value is
* returned.
*******************************************************************************/
int HarryPotter::attack()
{
	//declare variables to hold attackw being done
	int attack1, attack2, total;

	//HarryPotter specific die rolls
	attack1 = 1 + rand() % 6;//1st attack, equal to a dice being rolled with 6 sides
	attack2 = 1 + rand() % 6;//2nd attack, equal to a dice being rolled with 6 sides

	total = attack1 + attack2;//total the damage done by the Blue Men

	return total;
}

/******************************************************************************
* defense function takes an integer value as its parameter. It then calculates the
* total defense of the Creature by rolling the corresponding Die, adding it to the
* armor of the creature, and subtracting the damage. This is then taken away from the
* strength points of the Creature object.
*******************************************************************************/
void HarryPotter::defense(int damage)
{
	//declare variables to hold attacks beings done / defense
	int defense1, defense2, defense, totalDefense;

	//2 die, 6 sides each
	defense1 = 1 + rand() % 6;//1st defense, equal to a Dice being rolled with 6 sides
	defense2 = 1 + rand() % 6;//2nd defense, equal to a Dice being rolled with 6 sides
	defense = defense1 + defense2;//add the two defenses together

	//add the armor value to calculate the total defense of the Creature
	totalDefense = defense + this->armor;

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
	
	//if strength points for the Harry Potter object gets to 0 or less, he will be revived 1 time with 20 strength.
	if (this->strengthPoints <= 0)
	{
		//Harry Potter has second life still
		if (this->lifes == 1)
		{
			this->strengthPoints = 20;//set strengthPoints to 20
			this->lifes = 0;//set lifes variable to 0
		}
		else
		{
			cout
				<< "\n**************************************************\n"
				<<   "****   Harry Potter has been DEFEATED!       ****\n"
				<<   "**************************************************\n\n";
			this->setStatus("dead");//set his status to dead
		}
	}
}

//getType takes no parameters and returns a string value that is 
//the type of the Creature
string HarryPotter::getType()
{
	return this->type;
}
//getStatus takes no parameters and returns a string value that is
//the status of the Creature
string HarryPotter::getStatus()
{
	return this->status;
}

//setStatus takes a string parameter and sets the member variable
//to the variable being passed in
void HarryPotter::setStatus(string s)
{
	this->status = s;
}

/************************************************************************************
* heal function has the properties of the default constructor but it used after a
* fight takes place. This is so the object can be placed back into the linked structure
* to continue battling in the tournament.
************************************************************************************/
void HarryPotter::heal()
{
	this->armor = 0;//set armor to 0
	this->strengthPoints = 10;//set strengthPoints / life to 10
	this->type = "HarryPotter";//set type to HarryPotter
	this->status = "alive";//make HarryPotter alive (2 choices alive or dead)
	this->lifes = 1;//set lifes member variable to 1. Unique to harry potter
}

//incrementPoint function takes no params and returns nothing but increments the
//member variable points
void HarryPotter::incrementPoints()
{
	this->points = this->points + 1;//increase points by 1
}

//getPoints function returns the member variable points
int HarryPotter::getPoints()
{
	return this->points;
}

//setTeam takes a string parameter and sets the member variable team
//to the value that is passed. This will generally be 1 or 2.
void HarryPotter::setTeam(string t)
{
	this->team = t;
}

//getTeam function returns the string value of the member variable
//team. It takes no parameters
string HarryPotter::getTeam()
{
	return this->team;
}