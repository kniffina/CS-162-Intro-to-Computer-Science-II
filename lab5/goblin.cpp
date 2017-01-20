/*************************************************************
* Filename: goblin.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/3/2016
* Description: This is the cpp file for the Goblin class. It contains
* a default constructor and function implementation which will be 
* described in more detail below.
***************************************************************/
#include "goblin.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;

//default constructor. Initializes member variables
Goblin::Goblin()
{
	this->attacks = 1;
	this->strength = 30;
	this->type = "Goblin";
}

/*************************************************************
* attack function takes no parameters and returns an integer value
* which is based upon a random number being divided by the monsters
* strength. The Goblin class has a 10% chance for the total damge
* to be doubled. 
*************************************************************/
int Goblin::attack()
{
	//initialize the variable total that will be used to keep track of all damage done
	int total = 0;

	//set flag to determine if the total damage needs to be doubled
	bool flag = false;

	//loop until attacks = 0. For goblin, this is always only going to be on iteration
	while (this->attacks > 0)
	{
		//need to decrement attacks each time it lops
		int attack = 1 + (rand() % this->strength);//attack is equal to random amount of strength

		cout << "Goblin attacks for " << attack << " damage\n";

		//increment the total damage
		total += attack;

		//special is the Goblins special attack. He has a 10%
		//chance to do twice as much damage
		int special = rand() % 10;
		if (special == 1)//10% chance 0 - 9, or 10 numbers
		{
			cout << "Goblin doubles damage!\n";
			flag = true; //set flag to true
		}
		this->attacks--;//decrement the member variable attacks
	}

	//if flag is true, the total damage is increased times 2
	if (flag == true)
		total = total * 2;

	//display the total damage dealt
	cout << "Total Damage: " << total << "\n";
	return total;//return integer value total	
}

