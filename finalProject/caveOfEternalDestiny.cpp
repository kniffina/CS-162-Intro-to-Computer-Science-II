/*************************************************************
* Filename: caveOfEternalDestiny.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/12/2016
* Description: This is the cpp file for the class CaveOfEternalDestiny
* It contains constructors, and function implementation. Each of
* the functions will be described in more detail below.
***************************************************************/
#include "caveOfEternalDestiny.hpp"
#include "shadowsEmbrace.hpp"
#include "echoOfDarkness.hpp"
#include "messengerOfFate.hpp"
#include <vector>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

/**************************************************************
* constructor sets the two member variables type, and explanation
* with the appropriate strings. The cave is then populated with Items
* that are unique to the cave. The constructor also sets each
* of the Cave pointers in its array to NULL.
**************************************************************/
CaveOfEternalDestiny::CaveOfEternalDestiny()
{
	this->type = "Cave of Eternal Destiny";
		
	this->explanation = 
	"\n*****************************************\n"
	"******************************************\n"
	"A LOUD HIGH PITCH SOUND COMES OVER THE CAVERNS!\N"
	"You try to cover your ears but the sound is deafening.\n"
	"All of a sudden you are smashed to the ground by a Spirit.\n"
	"You recognize him. He is your father the Great Ner'zhul!\n\n"
	"'You have ventured long and farm my son. We have been waiting\n"
	"for a leader of your caliber to come along and save our people\n"
	"from the tragedies of war. We spirits of the past give you the\n"
	"gift to destroy the enemy and allow your people to live in\n"
	"peace FOREVER!! '\n\n"
	"Before you can say a word, the spirit vanishes. You start to\n"
	"feel light headed..... you try to stay on your feet.... but...\n"
	"you collapse to the ground.\n\n"
	"You awake to the cheers of your people. You look down and see that\n"
	"you are covered in ceremonial regalia that is used for victors of war\n"
	"Your people began to chant your name, and at that very moment you realize\n"
	"you have saved your people from defeat and hardships of war.\n\n"
	"YOU HAVE DONE IT!! YOU ARE A LEGEND THAT WILL LIVE FOREVER!!\n";


	//set all the Cave pointers to NULL
	for (int i = 0; i < 4; i++)
		array[i] = NULL;
}
//destructor deallocates the memory that was previously reserved
CaveOfEternalDestiny::~CaveOfEternalDestiny()
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
string CaveOfEternalDestiny::getExplanation()
{
	return this->explanation;
}

/**************************************************************
* getType function returns the string variable
* associated with the object's type. It takes no parameters
**************************************************************/
string CaveOfEternalDestiny::getType()
{
	return this->type;
}
/**************************************************************
* look function takes no parameters and allows the user to look
* in whatever direction they want to. If they choose a direction
* and find an item. If an Item is found the pointer to the Item
* is returned.
**************************************************************/
Item* CaveOfEternalDestiny::look()
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
void CaveOfEternalDestiny::setArray(Cave* c1, Cave* c2, Cave* c3, Cave* c4)
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
void CaveOfEternalDestiny::otherCaves()
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
Cave* CaveOfEternalDestiny::returnCave0()
{
	return this->array[0];
}
Cave* CaveOfEternalDestiny::returnCave1()
{
	return this->array[1];
}
Cave* CaveOfEternalDestiny::returnCave2()
{
	return this->array[2];
}
Cave* CaveOfEternalDestiny::returnCave3()
{
	return this->array[3];
}
