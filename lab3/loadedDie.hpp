/*******************************************************************
* Program Filename: loadedDie.hpp
* Author: Adam Kniffin
* Date: 1/18/2016
* Description: This is the hpp file for the LoadedDie class. It contains
* member variables, function declarations, and other functions that are useful
* for the class. It inherits from the Die class.
* Input: This is an hpp file, there is no input.
* Output: No output
*******************************************************************/
#include "die.hpp"
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

class LoadedDie : public Die
{
private:
	//int variable to hold total number of sides
	int totalSides;
public:
	//default constructor
	LoadedDie();

	//overload constructor
	LoadedDie(int);

	//set functions
	void setSides(int);
	void setTotalSides(int);

	//get functions
	int getSides();
	int getTotalSides();

	void rollDie();
};

#endif
