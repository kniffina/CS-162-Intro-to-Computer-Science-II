/*************************************************************
* Filename: List.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 1/28/2016
* Description: This is the cpp file for class List. It contains
* function implementation. Each function will be described in more
* detail below.
* Input: none
* Output: none
***************************************************************/
#include "list.hpp"
#include "item.hpp"
#include <iostream>
using std::cout;
using std::cin;
/*****************************************************************************
* default constructor sets the member variable numOfItems to 0 and initializes
* the pointer to array as an array of new Items with 4 in the scope.
*******************************************************************************/
List::List()
{
	//set the numOfItems member variable to 0
	this->numOfItems = 0;
	//set maxSize variable to 4 (starting max)
	this->maxSize = 4;

	//set the array pointer to 4 new Item
	array = new Item[4];
}
/*****************************************************************************
* addItem takes no parameters and allows the user to enter the member variables
* for an Item object. If that item is not found in the array of a List, it is added.
* Additionally, since the array only holds for Item objects, once it has reach it's 
* maxSize, maxSize is doubled. A copy array is created and the contents of the original
* array are stored in the copy array. Once that is complete, array is deleted, and the pointer
* is then pointed at the copy array.
*******************************************************************************/
void List::addItem()
{
	//declare v ariables for suer to enter
	string name, unit;
	int quantity;
	double price;
	
	cout << "Enter the name of the Item:\n";
	cin >> name;
	cout << "Enter the unit of measurement for the Item: \n";
	cin >> unit;
	cout << "Enter the quantity of Units you want:\n";
	cin >> quantity;
	cout << "Enter the price per unit: \n";
	cin >> price;

	
	

	//determine if the List needs to be increased in size
	if (this->numOfItems == maxSize)
	{
		maxSize = maxSize * 2;
		//need to create a pointer to Item array to hold the old contents
		//of old array
		Item *copyArr = new Item[maxSize];

		//copy the contents
		for (int i = 0; i < this->numOfItems; i++)
			copyArr[i] = array[i];
		
		delete[] array; //delete the contents in array
		array = copyArr; //set the array pointer to copyArr
	}

	//use a falg to determine if there value was found in the array or not
	bool flag = false;

	//Loop through all the items and make sure that the item being passed in
	//is not already in the array of Items. The overloaded equality operator
	//is used to determine if the Item is in the array already.
	for (int i = 0; i < this->numOfItems; i++)
	{
		//if item is already in the list
		//use equality operator to do this
		if (this->array[i].getName() == name && this->array[i].getUnit() == unit)
		{
			cout << "This item is already in the List!\n";
			break; //we can break out of the loop
		}
		else
			flag = true;//item not found, can be added
	}

	//item was not found based on the name or the unit
	//this means it can be added
	if (flag == true)
	{
		//user the set functions to set all the variables of the Item
		//equal to the values that were passed in by the user
		this->array[numOfItems].setName(name);
		this->array[numOfItems].setUnit(unit);
		this->array[numOfItems].setNumberToBuy(quantity);
		this->array[numOfItems].setUnitPrice(price);
		this->numOfItems++;//incremement number of items in the array
		cout << "Item successfully added!\n";

	}

	//number of items = 0 so it did not go through the array at all.
	//Also, there is nothing to compare the item to, so it can automatically be added
	if (this->numOfItems == 0)
	{
		//user the set functions to set all the variables of the Item
		//equal to the values that were passed in by the user
		this->array[numOfItems].setName(name);
		this->array[numOfItems].setUnit(unit);
		this->array[numOfItems].setNumberToBuy(quantity);
		this->array[numOfItems].setUnitPrice(price);
		this->numOfItems++;//increment number of items in the array
		cout << "Item successfully added!\n";
	}	
}
/*****************************************************************************
* removeItem takes no parameters and allows the user to enter the name, and unit
* of measurement for the Item they want to remove. A loop is used to go through the 
* array and if an Item is found with the same name, and unit of measurement, it is deleted.
* A new for-loop then shifts the array to the left, based on where the element was
* found in the array. If the item is not found, it is outputted to the user.
*******************************************************************************/
void List::removeItem()
{
	string name;//declare name variable
	string unit;//declare unit variable

	//get the variables to see if the item is in the Array so it can be removed.
	cout << "Enter the name of the object you would like to remove: \n";
	cin >> name;
	cout << "Enter the unit of measurement for the Item you would like to have removed: \n";
	cin >> unit;
	
	bool flag = false;

	//loop through the array to determine if the item is in the array
	for (int i = 0; i < this->numOfItems; i++)
	{
		//if the item is found. Comparing name and unit.Both have to be present
		if (this->array[i].getName() == name && this->array[i].getUnit() == unit)
		{
			//start a new loop from where i left off.
			//this will shift all of the elements to the left 
			for (int j = i; j + 1 < this->numOfItems; j++)
			{
				//shift the elements of the array starting from i		
				this->array[j] = this->array[j + 1];
			}

			this->numOfItems--; //decrement numOfItems member variable
			cout << "Item Removed!\n" << "You now have " << this->numOfItems
				<< " item(s) in your list.\n";
			flag = false;
		}
		else
			flag = true;//can display that the item was not found
		
	}
	//item not found
	if (flag == true)
		cout << "Item not found in your List\n";

}

/*****************************************************************************
* displayList function loops through the array of Items BASED on the amount of
* items that have been added. The function then uses the print function from our
* Item class to display all of the vital information about the Item.
*******************************************************************************/
void List::displayList()
{
	//If there is no items to display
	if (this->numOfItems == 0)
	{
		cout << "\n******************************************************\n"
			<< "No Item's in the List to display.\n**********************************************\n";
	}
	else
	{
		double total = 0; //will hold the total price of all the items

		//loop through the List array and display all Items using the print function
		for (int i = 0; i < this->numOfItems; i++)
		{
			cout << "\n***************************************************\n"
				<< "Item" << i + 1 << ": \n";
			array[i].print();
			total += this->array[i].getUnitPrice() * this->array[i].getNumberToBuy();
		}
		cout << "The total of your shopping list is: " << total << ".\n\n"
			<< "******************************************************\n";
	}
}
