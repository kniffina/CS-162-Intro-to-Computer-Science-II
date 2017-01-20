/*************************************************************
* Filename: dragon.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/3/2016
* Description: This is the cpp file for the Dragon class. It contains
* a default constructor and function implementation which will be
* described in more detail below.
***************************************************************/
#include "dragon.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;

//default constructor, initializes member variables
Dragon::Dragon()
{
	this->attacks = 4;
	this->strength = 100;
	this->type = "Dragon";
}

/*************************************************************
* attack function takes no parameters and returns an integer value
* which is based upon a random number being divided by the monsters
* strength. The Dragon class has a 50% chance to gain an extra attack
* when attacking.
*************************************************************/
int Dragon::attack()
{
	
	int specialAttack = 1;//set variable so Dragon has the chance
						  //to get exactly 1 extra attack
	int total = 0;
	
	bool flag = false;//flag to loop until true
	do
	{		
		int attack = rand() % this->strength + 1;//attack is equal to random amount of strength
		cout << "Dragon attacks for " << attack << "\n";
		this->attacks--;//decrement number of attacks
		total += attack; //count the total 

		
		//will only be looked at if the specialAttack is equal to 1
		if (this->attacks == 0 && specialAttack == 1)
		{
			int special = rand() % 2;//will generate either a 0 or 1
			if (special == 1)//50% chance of it being 1
			{
				this->attacks++;//increment attacks
				cout << "Dragon gains an extra attack!\n";
				specialAttack = 0;//set variable to 0 so it wont enter if statement again

			}
		}

		//condition to end while loop
		if (this->attacks == 0)
		{
			flag = true;//loop will end
		}
		
		
	} while (flag == false);

	cout << "Total Damage: " << total << "\n";
	return total;//return total damage done
}