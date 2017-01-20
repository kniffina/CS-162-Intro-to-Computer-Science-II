/*************************************************************
* Filename: firedragon.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/6/2016
* Description: This is the cpp file for the FireDragon class. It contains
* a default constructor and function implementation which will be
* described in more detail below.
***************************************************************/
#include "firedragon.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cout;

//Default constructor, uses Dragon to set member variables
FireDragon::FireDragon()
	: Dragon()
{
	this->attacks = 4;
	this->strength = 100;
	this->type = "Fire Dragon";
}

/*************************************************************
* attack function takes no parameters and returns an integer value
* which is based upon a random number being divided by the monsters
* strength. The FireDragon class inherits its attack behavior from
* class Dragon, but has a 50% chance when attacking to start its attacking
* all over again. This action can only be done once.
*************************************************************/
int FireDragon::attack()
{
	int specialAttack = 1;//set variable so Dragon has the chance
						  //to get exactly 1 extra attack

	int doubleAttacks = 1;//int to see if the fire dragon gets to attack again

	//initialize total to 0
	int total = 0;

	bool flag = false;//flag to loop until true
	do
	{
		int attack = 1 + (rand() % this->strength);//attack is equal to random amount of strength
		cout << "Fire Dragon attacks for " << attack << "\n";
		this->attacks--;//decrement number of attacks
		total += attack; //count the total 


		//will only be looked at if the specialAttack is equal to 1
		if (this->attacks == 0 && specialAttack == 1)
		{
			int special = rand() % 2;//will generate either a 0 or 1
			if (special == 1)//50% chance of it being 1
			{
				this->attacks++;//increment attacks
				cout << "Fire Dragon gains an extra attack!\n";
				specialAttack = 0;//set variable to 0 so it wont enter if statement again

			}
		}

		//will only be looked at if the doubleAttacks
		//this will determine if the dragon gets to attack all over again
		if (this->attacks == 0 && doubleAttacks == 1)
		{
			int special2 = rand() % 2;//will generate either a 0 or 1
			if (special2 == 1)//50% chance of it being 1
			{
				this->attacks = 4;//increment attacks
				cout << "Fire Dragon gets to attack ALL OVER AGAIN!\n";
				doubleAttacks = 0;//set variable to 0 so it wont enter if statement again
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