/*************************************************************
* Filename: cavernOfTime.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/12/2016
* Description: This is the cpp file for the class CavernOfTime
* It contains constructors, and function implementation. Each of
* the functions will be described in more detail below.
***************************************************************/
#include "cavernOfTime.hpp"
#include "HourglassOfEternity.hpp"
#include "relicOfTime.hpp"
#include "prismOfRecurrence.hpp"
#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

/**************************************************************
* constructor sets the two member variables type, and explanation
* with the appropriate strings. The cave is then populated with Items
* that are unique to the cave.
**************************************************************/
CavernOfTime::CavernOfTime()
{
	this->type = "Cavern of Time";
	this->explanation = "You see flickering images of past events\n"
		"Are you seeing them take place? Or is it just an image?\n";

	//create 3 items to place into the Cave object
	Item *i1 = new HourglassOfEternity;
	Item *i2 = new RelicOfTime;
	Item *i3 = new PrismOfRecurrence;

	//move them to the vector
	itemsInCave.push_back(i1);
	itemsInCave.push_back(i2);
	itemsInCave.push_back(i3);

	//set all the Cave pointers to NULL
	for (int i = 0; i < 4; i++)
		array[i] = NULL;
}
//destructor deallocates the memory that was previously reserved
CavernOfTime::~CavernOfTime()
{
	//looop through each item and delete
	for (vector<Item*>::iterator i = itemsInCave.begin(); i != itemsInCave.end(); i++) {
		delete (*i);
	}
}

/**************************************************************
* getExplanation function returns the string variable
* associated with the object's explanation. It takes no parameters
**************************************************************/
string CavernOfTime::getExplanation()
{
	return this->explanation;
}

/**************************************************************
* getType function returns the string variable
* associated with the object's type. It takes no parameters
**************************************************************/
string CavernOfTime::getType()
{
	return this->type;
}
/**************************************************************
* look function takes no parameters and allows the user to look
* in whatever direction they want to. If they choose a direction
* and find an item. If an Item is found the pointer to the Item
* is returned.
**************************************************************/
Item* CavernOfTime::look()
{
	//Declare Item pointer that will be used to return
	//the item that was found in the location, if there.
	Item *toReturn = NULL;

	//declare direction string to hold user's response
	string direction;
	cout << endl
		<< "===========================================\n"
		<< "=== What Direction do you want to look?  ==\n"
		<< "===========================================\n"
		<< "   Enter '1' To look to the  * North *     \n"
		<< "   Enter '2' To look to the  * East  *     \n"
		<< "   Enter '3' To look to the  * South *     \n"
		<< "   Enter '4' To look to the  * West  *     \n"
		<< "===========================================\n"
		<< "===========================================\n";
	cin >> direction;

	//look to the North
	if (direction == "1") {
		//for loop iteratives through the vector of cave pointers to determine
		//if there is an item in the direction the user chose too look
		for (vector<Item*>::iterator i = itemsInCave.begin(); i != itemsInCave.end(); i++) {
			if ((*i)->getPosition() == "North") {
				toReturn = (*i);
				break; //exit loop
			}
			else { //no item found in the direction they looked
				toReturn = NULL;
			}
		}
	}

	//look to the East
	if (direction == "2") {
		//for loop iteratives through the vector of cave pointers to determine
		//if there is an item in the direction the user chose too look
		for (vector<Item*>::iterator i = itemsInCave.begin(); i != itemsInCave.end(); i++) {
			if ((*i)->getPosition() == "East") {
				toReturn = (*i);
				break; //exit loop
			}
			else { //no item found in the direction they looked
				toReturn = NULL;
			}
		}
	}

	//look to the South
	if (direction == "3") {
		//for loop iteratives through the vector of cave pointers to determine
		//if there is an item in the direction the user chose too look
		for (vector<Item*>::iterator i = itemsInCave.begin(); i != itemsInCave.end(); i++) {
			if ((*i)->getPosition() == "South") {
				toReturn = (*i);
				break; //exit loop
			}
			else { //no item found in the direction they looked
				toReturn = NULL;
			}
		}
	}

	//look to the West
	if (direction == "4") {
		//for loop iteratives through the vector of cave pointers to determine
		//if there is an item in the direction the user chose too look
		for (vector<Item*>::iterator i = itemsInCave.begin(); i != itemsInCave.end(); i++) {
			if ((*i)->getPosition() == "West") {
				toReturn = (*i);
				break; //exit loop
			}
			else { //no item found in the direction they looked
				toReturn = NULL;
			}
		}
	}
	//retur true if found, false otherwise
	return toReturn;
}

/**************************************************************
* setArray function takes 4 cave pointers as its parameter and
* sets all of the slots in the objects array to the 4 cave pointers
* passed in. Nothing is returned.
**************************************************************/
void CavernOfTime::setArray(Cave* c1, Cave* c2, Cave* c3, Cave* c4)
{
	//set each element in the array to a Cave pointer
	array[0] = c1;
	array[1] = c2;
	array[2] = c3;
	array[3] = c4;
}

/**************************************************************
* otherCaves function outputs what other caves are connected
* to this current cave object. This is so the user can choose
* what cave to move to next.
**************************************************************/
void CavernOfTime::otherCaves()
{
	//forloop goes through each Cave object that the current
	//object is pointing to and prints its type
	for (int i = 0; i < 4; i++)
		cout << array[i]->getType() << " | ";

	cout << "\n";
}
/**************************************************************
* the next for returnCave functions take no parameters and
* return the Cave pointer that is associated with that
* specific location in the array.
**************************************************************/
Cave* CavernOfTime::returnCave0()
{
	return this->array[0];
}
Cave* CavernOfTime::returnCave1()
{
	return this->array[1];
}
Cave* CavernOfTime::returnCave2()
{
	return this->array[2];
}
Cave* CavernOfTime::returnCave3()
{
	return this->array[3];
}