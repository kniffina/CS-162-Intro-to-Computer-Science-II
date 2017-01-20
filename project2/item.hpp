/*************************************************************
* Filename: Item.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 1/28/2016
* Description: This is the hpp file for class Item.
* It contains constructors, member variables, and other useful
* functions that are being declared.
* Input: none
* Output: none
***************************************************************/
#ifndef ITEM_HPP
#define ITEM_HPP
#include <string>
using std::string;

class Item
{
private:
	//member variables
	string name;
	string unit;
	int numberToBuy;
	double unitPrice;
public:
	//default constructor
	Item();

	//Constructor
	Item(string, string, int, double);

	//set functions
	void setName(string);
	void setUnit(string);
	void setNumberToBuy(int);
	void setUnitPrice(double);

	//get functions
	string getName();
	string getUnit();
	int getNumberToBuy();
	double getUnitPrice();

	//Other Functions
	double calculatePrice();
	void print();

	//overloaded equality operator
	bool operator==(const Item &RHS) const;

	//overloaded assignment operator, used to make items = to the other
	void operator=(const Item &RHS);

	//asks user to enter information regarding Item object
	void Load();


};

#endif