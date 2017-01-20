/*************************************************************
* Filename: bluemen.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/12/2016
* Description: This is the cpp file for class BlueMen. It contains
* a constructor and an attack function which will be described in more
* detail below. It also contains a defense function that takes an integer
* as its parameter that represents the amount of damage done, and
* determines how much damage is ultimately inflicted to the creature.
* Input: none
* Output: none
***************************************************************/
#include "bluemen.hpp"
#include <iostream>
#include <ctime>
#include <stdlib.h>
using std::cout;

//default constructor sets the member variables to 3 and 12 respectively
BlueMen::BlueMen()
{
	this->armor = 3;//set armor to 3
	this->strengthPoints = 12;//set strengthPoints / life to 12
	this->type = "BlueMen";//set type to BlueMen
	this->status = "alive";//make the BlueMen alive (2 choices alive or dead)
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
int BlueMen::attack()
{
	//declare variables to hold attacks being done
	int attack1, attack2, total;

	//BlueMen specific Die
	attack1 = 1 + rand() % 10;//1st attack, equal to a dice being rolled with 10 sides
	attack2 = 1 + rand() % 10;//2nd attack, equal to a dice being rolled with 10 sides

	total = attack1 + attack2;//total the damage done by the Blue Men

	return total;
}

/******************************************************************************
* defense function takes an integer value as its parameter. It then calculates the
* total defense of the Creature by rolling the corresponding Die, adding it to the
* armor of the creature, and subtracting the damage. This is then taken away from the
* strength points of the Creature object.
*******************************************************************************/
void BlueMen::defense(int damage)
{
	//declare variables to hold attacks beings done / defense
	int defense1, defense2, defense3,defense, totalDefense;

	//2 die, 6 sides each
	defense1 = 1 + rand() % 6;//1st defense, equal to a Dice being rolled with 6 sides
	defense2 = 1 + rand() % 6;//2nd defense, equal to a Dice being rolled with 6 sides
	defense3 = 1 + rand() % 6;//3rd defense, equal to a Dice being rolled with 6 sides
	

	//add the armor value to calculate the total defense of the Creature
	//BlueMen lose 1 dice each time they lose 4 strength points
	if (this->strengthPoints > 8)
	{
		defense = defense1 + defense2 + defense3;//add the 3 defensives together
		totalDefense = defense + this->armor; // all 3 defensive rolls
	}

	else if (this->strengthPoints <= 8 && this->strengthPoints > 4)//<= ??
	{
		defense = defense1 + defense2;
		totalDefense = defense1 + defense2 + this->armor;//2 defense rolls
	}
	
	else //4 or below
	{
		defense = defense1;
		totalDefense = defense1  + this->armor;//2 defense rolls
	}


	if (totalDefense >= damage)//defense is greater than damage so nothing will be inflicted
	{
		this->strengthPoints += 0;//strength points remains the same because damage did not get past defense
		damage = 0;//no damage taken
	}
	else//damage is greater then defense points. Subtract the damage inflicted from the strength points 
	{
		//calculate the total damage to inflict to the monster
		damage = damage - totalDefense;

		//deduct the damage from the strength points that the monster has
		this->strengthPoints = this->strengthPoints - damage;
	}

	//if strength points for the Barbarian object gets to 0 or less, 
	//then the Barbarian is defeated.
	if (this->strengthPoints <= 0)
	{
		cout
			<< "\n*************************************************\n"
			<<   "*****	   Blue Men have been DEFEATED!    ********\n"
			<<   "**************************************************\n\n";
		this->setStatus("dead");//set status to dead
	}
}

//getType takes no parameters and returns a string value that is 
//the type of the Creature
string BlueMen ::getType()
{
	return this->type;
}
//getStatus takes no parameters and returns a string value that is
//the status of the Creature
string BlueMen ::getStatus()
{
	return this->status;
}

//setStatus takes a string parameter and sets the member variable
//to the variable being passed in
void BlueMen::setStatus(string s)
{
	this->status = s;
}

/************************************************************************************
* heal function has the properties of the default constructor but it used after a
* fight takes place. This is so the object can be placed back into the linked structure
* to continue battling in the tournament.
************************************************************************************/
void BlueMen::heal()
{
	this->armor = 3;//set armor to 3
	this->strengthPoints = 12;//set strengthPoints / life to 12
	this->type = "BlueMen";//set type to BlueMen
	this->status = "alive";//make the BlueMen alive (2 choices alive or dead)
}

//incrementPoint function takes no params and returns nothing but increments the
//member variable points
void BlueMen::incrementPoints()
{
	this->points = this->points + 1;//increase points by 1
}

//getPoints function returns the member variable points
int BlueMen::getPoints()
{
	return this->points;
}

//setTeam takes a string parameter and sets the member variable team
//to the value that is passed. This will generally be 1 or 2.
void BlueMen::setTeam(string t)
{
	this->team = t;
}

//getTeam function returns the string value of the member variable
//team. It takes no parameters
string BlueMen::getTeam()
{
	return this->team;
}