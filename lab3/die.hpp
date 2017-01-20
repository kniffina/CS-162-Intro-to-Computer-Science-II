/*******************************************************************
 * Program Filename: die.hpp
 * Author: Adam Kniffin
 * Date: 1/18/2016
 * Description: This is the hpp file for the Die class. It contains
 * member variables, function declarations, and other functions that are useful 
 * for the class.
 * Input: This is an hpp file, there is no input.
 * Output: No output
 *******************************************************************/
#ifndef DIE_HPP
#define DIE_HPP

class Die
{
protected:
	//member variable
	int sides;
public:
	//default constructor
	Die();

	//set function
	void setSides(int);

	//get function
	int getSides();

	//rollDie function
	void rollDie();
};

#endif
