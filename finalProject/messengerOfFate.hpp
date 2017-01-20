/*************************************************************
* Filename: messengerOfFate.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/14/2016
* Description: This is the hpp file for the class MessengerOfFate
* It is inherited from the cave Item. It contains member variables,
* function declarations, and constructors.
***************************************************************/
#include "item.hpp"
#ifndef MESSENGEROFFATE_HPP
#define MESSENGEROFFATE_HPP

class MessengerOfFate : public Item
{
private:
	//member variables
	string position; //North, east, south, or west
	string explanation; //explanation on what the item is
	string name; //the name of the Item
	int points; //how many points the Item is worth
	int number; //the number correlated to the Item

public:
	//constructor
	MessengerOfFate();

	//destructor
	~MessengerOfFate();

	//get functions. The private member variables
	//will be set in the constructor
	string getExplanation();
	string getName();
	string getPosition();
	int getPoints();
	int getNumber();
};

#endif