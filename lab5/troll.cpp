/*************************************************************
* Filename: troll.cpp
* Email : kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date : 2 / 3 / 2016
* Description: This is the cpp file for the Troll class. It contains
* a default constructor and function implementation which will be
* described in more detail below.
***************************************************************/
#include "troll.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;

//default constructor. Initializes member variables
Troll::Troll()
{
	this->attacks = 2;
	this->strength = 60;
	this->type = "Troll";
}

/*************************************************************
* attack function takes no parameters and returns an integer value
* which is based upon a random number being divided by the monsters
* strength. The Troll class has a 20% chance to do 100 damage
* for each time they strike (critical hit).
*************************************************************/
int Troll::attack()
{	
	//initialize the variable total that will be used to keep track of all damage done
	int total = 0;

	//loop until attacks = 0. For Troll class, will always be 2 iterations.
	while (this->attacks > 0)
	{
		//set flag to determine if there is a critical hit
		bool flag = false;

		//determine the amount of attack damage is done and store it in variable "attack"
		int attack = 1 + (rand() % this->strength);//attack is equal to random amount of strength

		//Troll's special makes his attack a critical hit. 20% chance
		//If the number is shown, then it is a crit and the attack is set to 100
		int special = rand() % 5;
		if (special == 1)//20% chance
		{
			flag = true;//set flag to true (Crit happened)		
			attack = 100;//set attack to 100
		}

		if (flag == true)//crit happened
			cout << "Troll attacks for CRITICAL damage " << attack << "\n";//display damage

		else
			cout << "Troll attacks for " << attack << " damage\n";

		//increment the total damage
		total += attack;
		this->attacks--;//decrement the member variable attacks
	}

	//display the total damage dealt
	cout << "Total Damage: " << total << "\n";
	return total;//return integer value total	
}