/*******************************************************************
* Program Filename: loadedDie.cpp
* Author: Adam Kniffin
* Date: 1/18/2016
* Description: This is the cpp file for the LoadedDie class. It contains
* function implementation. Each function is described in more detail below.
* Input: No output, just function implementation.
* Output: No output
*******************************************************************/
#include "loadedDie.hpp"
#include <cstdlib>
#include <ctime>
#include <cmath>

//default constructor sets sides to 6 if no value is passed in
LoadedDie::LoadedDie()
{
	//if the number of sides to be addded to LoadedDie is 
	//not specified it will be set to a normal Die
	this->setSides(6);
	this->setTotalSides(6);
}

//constructor. Sets the objects sides variable equal to the number
//passed in to the function
LoadedDie::LoadedDie(int s)
{
	this->setSides(s);
	this->setTotalSides(s);
}

//rollDice function takes no parameters and sets the objects sides that is showing
//to a random number between 1 and the number that has been set as the sides 
//in the constructor. The number is then returned.
void LoadedDie::rollDie()
{
	this->setSides((rand() % this->getTotalSides()) + 1);
}

//setSide takes an integer paramenter and sets the value
//passed in equal to the member variable sides
void LoadedDie::setSides(int s)
{
	this->sides = s;
}
//setSide takes an integer paramenter and sets the value
//passed in equal to the member variable totalSides
void LoadedDie::setTotalSides(int tS)
{
	this->totalSides = tS;
}

//getTotalSides takes no parameters and returns the
//member variable totalSides
int LoadedDie::getTotalSides()
{
	return this->totalSides;
}
//getSides takes no parameter and returns the value of the
//member variable sides
int LoadedDie::getSides()
{
	return this->sides;
}
