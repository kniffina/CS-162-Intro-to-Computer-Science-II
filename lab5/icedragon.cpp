/*************************************************************
* Filename: icedragon.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/6/2016
* Description: This is the cpp file for the IceDragon class. It contains
* a default constructor and function implementation which will be
* described in more detail below.
***************************************************************/
#include "icedragon.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;

//Default constructor, uses Dragon to set member variables
IceDragon::IceDragon()
	: Dragon()
{
	this->attacks = 4;
	this->strength = 100;
	this->type = "Fire Dragon";
}

/*************************************************************
* attack function takes no parameters and returns an integer value
* which is based upon a random number being divided by the monsters
* strength. The IceDragon class inherits its attack behavior from
* class Dragon, but also has a 50% chance of all damage done to be doubled.
*************************************************************/
int IceDragon::attack()
{
	int specialAttack = 1;//set variable so Dragon has the chance
							//to get exactly 1 extra attack

	//initialize total to 0
	int total = 0;

	bool flag = false;//flag to loop until true
	do
	{
		int attack = 1 + (rand() % this->strength);//attack is equal to random amount of strength
		cout << "Ice Dragon attacks for " << attack << "\n";
		this->attacks--;//decrement number of attacks
		total += attack; //count the total 


		//will only be looked at if the specialAttack is equal to 1
		if (this->attacks == 0 && specialAttack == 1)
		{
			int special = rand() % 2;//will generate either a 0 or 1
			if (special == 1)//50% chance of it being 1
			{
				this->attacks++;//increment attacks
				cout << "Ice Dragon gains an extra attack!\n";
				specialAttack = 0;//set variable to 0 so it wont enter if statement again
			}
		}

		//condition to end while loop
		if (this->attacks == 0)
		{
			flag = true;//loop will end
		}

	} while (flag == false);

	//integer to determine if damage is doubled
	int totalDamage = rand() % 2;
	if (totalDamage == 1)//50% chance
	{
		cout << "Ice Dragon DOUBLES damage!\n";
		total = total * 2;//double the total damage
	}

	cout << "Total Damage: " << total << "\n";
	return total;//return total damage done
}