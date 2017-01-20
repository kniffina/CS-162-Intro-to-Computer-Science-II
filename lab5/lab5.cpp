/*************************************************************
* Filename: lab5.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/6/2016
* Description: This is the main file. It contains all of the header files
* that are inherited from the Monster class. It then creates an array of 100
* Monster pointers. The array is then filled with objects of each type. Once
* each array value has an object, another loop, loops through the array and uses
* the attack function call on each object of different different classes.
***************************************************************/
#include "monster.hpp"
#include "goblin.hpp"
#include "troll.hpp"
#include "dragon.hpp"
#include "icedragon.hpp"
#include "firedragon.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using std::cout;
using std::string;

int main()
{	
	//set the seed so we get truly random numbers
	//time is always changing so it will never be the same
	srand(static_cast<unsigned int>(time(0)));

	//create 100 pointers to Monster Objects
	Monster *arr[100];

	//loop 100 times, each time generating a random number to be placed
	//into the array of pointers
	for (int i = 0; i < 100; i++)
	{
		//generate a random number between 0 - 4
		int num = rand() % 5;

		//set each array to a specific Monster child
		switch (num) {
		case 0: arr[i] = new Goblin; break;
		case 1: arr[i] = new Troll; break;
		case 2: arr[i] = new Dragon; break;
		case 3: arr[i] = new IceDragon; break;
		case 4: arr[i] = new FireDragon; break;
		}
	}

	//display the attacks
	for (int i = 0; i < 100; i++)
	{
		arr[i]->attack();
		cout << "\n";
	
	}
	
	return 0;
}