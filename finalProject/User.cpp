/*************************************************************
* Filename: cave.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/7/2016
* Description: This is the hpp file for the class Cave. It contains
* member variables and function declarations. The functions are
* virtual functions and this is an abstract class.
***************************************************************/
#include "user.hpp"
#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::cin;

//constructor sets the member variables to 0
User::User()
{
	this->numOfItems = 0;
	this->steps = 0;
}

/***************************************************************
 * addItem takes a pointer to an Item and adds it to the back 
 * of the bag, if there is room. If there is not room. Then
 * the function outputs to the user that they must drop an item
 * before adding it to their bag.
 **************************************************************/
void User::addItem(Item *item)
{
	bool alreadyThere = false;//make that will add item if true

	if (this->numOfItems <= 14) {

		for (vector<Item*>::iterator i = Bag.begin(); i != Bag.end(); ++i) {
			//if the item is already in your bag
			if ((*i)->getName() == item->getName()) {
				alreadyThere = true; //item found in bag
				break; //break out of loop
			}
			else {
				alreadyThere = false; //item not there
			}
		}
		if (alreadyThere == true)
			cout << "== Item ALREADY in your bag ==\n";
		else {
			//move the item to the back of the bag
			this->Bag.push_back(item);

			//increment number of items
			this->numOfItems++;

			cout << "== " << item->getName() << " has been added to your bag! ==\n";
		}
	}
	else {
		cout << "== Your Bag is FULL! You must remove an item before adding a new one! ==\n";
		removeItem();
	}	
}

/******************************************************************
 * removeItem function takes no parameters. It displays the contents
 * of the User object's Bag and then, let's the user remove on
 * of the Item's in the bag. 
 ******************************************************************/
void User::removeItem()
{
	if (this->numOfItems == 0)//bag is empty
		cout << "==  No Items in your Bag!  ==\n";

	else { //there are items to display
		this->print();//output items

		int remove;//string for user to enter what item to remove
		cout << "== What item would you like to remove? ==\n";
		cin >> remove;

		bool removed = false;//make boolean value that will print when false

		//this for loop goes through each item until the name of the
		//item in the vector is equal to that of the item the user
		//wants to remove. The item is them removed from the vector
		for (vector<Item*>::iterator i = Bag.begin(); i != Bag.end(); ++i) {
			if ((*i)->getNumber() == remove) {
				Bag.erase(i);
				removed = true; //set value to true so no ERROR
				cout << "==  Item removed from Bag ==\n";
				break; //exit the loop			
			}
			else
				removed = false;
		}
		if (removed == false)
			cout << "Item Not Found in Bag\n";
		else {
			this->numOfItems--;//decrement number of items
		}
	}
}

/******************************************************************
* print function takes no parameters and prints the contents of the
* the user's bag. It also prints the number that the item corresponds
* to. This makes it easier for the user to add / remove.
******************************************************************/
void User::print()
{
	if (this->numOfItems == 0)//bag is empty
		cout << "== No items in your Bag! ==\n";

	else {
		cout << "== Itmes in your Bag == \n";
		//for loop displays each content in the user's Bag
		for (vector<Item *>::iterator i = Bag.begin(); i != Bag.end(); ++i)
			cout << (*i)->getName() << ": "<< (*i)->getNumber() <<  " | ";

		cout << "\n";//line break
	}
}

/******************************************************************
* incrementSteps function adds 1 to the steps that the user 
* object has taken.
******************************************************************/
void User::incrementSteps()
{
	this->steps = this->steps + 1;
}

/******************************************************************
* getNumItems takes no parameters and returns the integer value
* of Items in the specific User objects bag.
******************************************************************/
int User::getNumItems()
{
	return this->numOfItems;
}

/******************************************************************
* checkBag takes an integer as its parameter and checks to see if the int
* is apart of an Item in the users bag. If it is true, is returns, if
* it is not, false is returned.
******************************************************************/
bool User::checkBag(int num)
{
	//create boolean that will be returned based on the if the
	//item is in the bag
	bool toReturn = false;
	for (vector<Item *>::iterator i = Bag.begin(); i != Bag.end(); ++i) {
		if ((*i)->getNumber() == num) {
			toReturn = true;
			break;//break out of loop
		}
		else {
			toReturn = false; //item not in the bag
		}
	}
	return toReturn;
}

