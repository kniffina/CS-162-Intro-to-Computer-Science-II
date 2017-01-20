/*************************************************************
* Filename: item.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/9/2016
* Description: This is the hpp file for the Item. It contains 
* function declarations and member variables. This is
* an abstract class so it's functions are virtual.
***************************************************************/
#include <iostream>
#include <string>
using std::string;
#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
private:
	//member variables
	string position; //North, east, south, or west
	string explanation; //explanation on what the item is
	string name; //the name of the Item
	int points; //how many points the Item is worth
	int number; //the number correlated to the Item
	
public:

	//get functions. The private member variables
	//will be set in the constructor
	virtual string getExplanation() = 0;
	virtual string getName() = 0;
	virtual int getPoints() = 0;
	virtual int getNumber() = 0;
	virtual string getPosition() = 0;
};

#endif