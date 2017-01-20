/*******************************************************************
* Program Filename: die.cpp
* Author : Adam Kniffin
* Date : 1 / 18 / 2016
* Description : This is the cpp file for the Die class.It contains function implementation
* each function will be described in more detail below.
* Input: None, just function implementation.
* Output: none
*******************************************************************/
#include "die.hpp"
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>

//default constructor. Sets the sides variable to 6.
Die::Die()
{
	this->sides = 6;
}

//rollDice function takes no parameters and sets the objects sides that is showing
//to a random number between 1 and the number that has been set as the sides 
//in the constructor. Since a normal Die always has 6 sides we can assume,
//the value will always be 1 through 6.
void Die::rollDie()
{
	
	this->setSides((rand() % 6) + 1);
	//use set sides?
}

//getSides takes no parameter and returns the objects number of sides
int Die::getSides()
{
	return this->sides;
}

//setSides takes an integer as a parameter and sets the value
//passed to the member variable sides.
void Die::setSides(int s)
{
	this->sides = s;
}
