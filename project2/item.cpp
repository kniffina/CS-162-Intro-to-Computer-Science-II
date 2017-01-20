/*************************************************************
* Filename: Item.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 1/28/2016
* Description: This is the cpp file for class Item. It contains
* function implementation. Each function will be described in more
* detail below.
* Input: none
* Output: none
***************************************************************/

#include "item.hpp"
#include <iostream>
using std::cout;
using std::cin;
/*****************************************************************************
* default constructor sets the string variables to "" or nothing, and the integer
* member variables to 0.
*******************************************************************************/
Item::Item()
{
	setName("");
	setUnit("");
	setNumberToBuy(0);
	setUnitPrice(0);
}

/*****************************************************************************
* Constructor takes in 4 parameters. Each member variables set function
* is used to take the value passed into the function, and set the member variable
* equal to that value.
*******************************************************************************/
Item::Item(string n, string u, int amount, double price)
{
	this->setName(n);
	this->setUnit(u);
	this->setNumberToBuy(amount);
	this->setUnitPrice(price);
}


/*****************************************************************************
* calculatePrice function calculates the total price of an Item based on how
* many units are selected, and how much the unit price is. The two member variables
* are multiplied together to get the total price. This total is returned.
*******************************************************************************/
double Item::calculatePrice()
{
	double total;
	total = this->numberToBuy * this->unitPrice;

	return total;
}

/*****************************************************************************
* print function prints all of the information of an Item object. This include,
* the name, unit of measurement, number of units, price per unit, and total cost.
*******************************************************************************/
void Item::print()
{
	cout << "Name: " << this->getName() << "\nUnit: " << this->getUnit() << "\nNumber of Units: "
		<< this->getNumberToBuy() << "\nPrice Per Unit: " << this->getUnitPrice() << "\nTotal: "
		<< this->calculatePrice() << "\n\n";
}

/*****************************************************************************
* This is the overloaded equality operator for the Item class. It check's each
* member variable of the object on the left (using the this operator) with the
* member variable of the object on the right (RHS). IF all of the member variables
* are equal to eachother, true is returned (1), if they are not all equal, false (0) is returned
*******************************************************************************/
bool Item::operator==(const Item &RHS) const
{
	return ((this->name == RHS.name) && (this->unit == RHS.unit) && (this->numberToBuy == RHS.numberToBuy)
		&& (this->unitPrice == RHS.unitPrice));

}
/*********************************************************************************
* assignment operator copies the contents from the right hand side of the equal sign
* to the left hand side of the equal sign.
*********************************************************************************/
void Item::operator=(const Item &RHS)
{
	this->name = RHS.name;
	this->unit = RHS.unit;
	this->numberToBuy = RHS.numberToBuy;
	this->unitPrice = RHS.unitPrice;
}
/*********************************************************
* The next 4 functions are the set functions for the Item class.
* They take in a string, a string, an integer, and a double as parameters,
* and set whatever is passed in EQUAL to the corresponding member
* variable. They return nothing, or void.
**********************************************************/
void Item::setName(string n)
{
	this->name = n;
}

void Item::setUnit(string u)
{
	this->unit = u;
}

void Item::setNumberToBuy(int numb)
{
	this->numberToBuy = numb;
}

void Item::setUnitPrice(double price)
{
	this->unitPrice = price;
}
/*********************************************************
* The next 4 functions are the get functions for the Item class.
* They take no parameters and return the value of the member
* variable associated with each function.
**********************************************************/
string Item::getName()
{
	return this->name;
}

string Item::getUnit()
{
	return this->unit;
}

int Item::getNumberToBuy()
{
	return this->numberToBuy;
}

double Item::getUnitPrice()
{
	return this->unitPrice;
}