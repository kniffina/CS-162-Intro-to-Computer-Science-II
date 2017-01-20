/*************************************************************
* Filename: user.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/10/2016
* Description: This is the hpp file for the class User. It contains
* function declarations, member variables, and constructors.
***************************************************************/
#include "item.hpp"
#include <vector>
#include <iostream>
using std::vector;
using std::string;

#ifndef USER_HPP
#define USER_HPP

class User
{
private:
	//member variables

	//holds the number of items the user has
	int numOfItems;
	
	//counts the steps the user has taken
	int steps;

	//keeps track of the items the user has picked up
	vector<Item*> Bag;
public:
	//constructor
	User();
	
	//add and remove item function declarations
	void addItem(Item *);
	void removeItem();

	//prints the contents of the users bag
	void print();

	//adds 1 to the steps the user has taken
	void incrementSteps();

	//returns the integer number of Items that the 
	//user is holding
	int getNumItems();

	//checkBag takes an int as its parameters and returns
	//true if the number associated with the item is in the bag
	bool checkBag(int);

	
};

#endif