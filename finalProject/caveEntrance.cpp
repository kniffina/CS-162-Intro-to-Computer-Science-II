/*************************************************************
* Filename: caveEntrance.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/12/2016
* Description: This is the cpp file for the class CaveEntrance
* It contains constructors, and function implementation. Each of
* the functions will be described in more detail below.
***************************************************************/
#include "caveEntrance.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::vector;

/**************************************************************
* constructor sets the two member variables type, and explanation
* with the appropriate strings. Since this is just an entrance
* nothing else needs to be initialized. 
**************************************************************/
CaveEntrance::CaveEntrance()
{
	this->type = "Cave Entrance";
	this->explanation = "You have just entered the cave and\n"
		"want to move towards your destiny.\n";
}
//destructor won't need to deallocate because nothing is being created
//with the object at run time
CaveEntrance::~CaveEntrance()
{
	//left blank intentionally
}

/**************************************************************
* getExplanation function returns the string variable
* associated with the object's explanation. It takes no parameters
**************************************************************/
string CaveEntrance::getExplanation()
{
	return this->explanation;
}

/**************************************************************
* getType function returns the string variable
* associated with the object's type. It takes no parameters
**************************************************************/
string CaveEntrance::getType()
{
	return this->type;
}
/**************************************************************
* look function takes no parameters and allows the user to look
* in whatever direction they want to. Since this is just the 
* entrance to the cave, they have to move to another cave in 
* order to look at items, 
**************************************************************/
Item* CaveEntrance::look()
{
	cout << "You look around the cave and do not see anything but an\n"
		<< "entrance in the distance. You want to go to it, but are\n"
		<< "afraid of what it might hold. Will you walk in?\n"
		<< "Hint: You have to MOVE to a new cave to find Items!\n";

	return NULL;
}

/**************************************************************
* setArray function takes 4 cave pointers as its parameter and
* sets all of the slots in the objects array to the 4 cave pointers
* passed in. Nothing is returned.
**************************************************************/
void CaveEntrance::setArray(Cave* c1, Cave* c2, Cave* c3, Cave* c4)
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
void CaveEntrance::otherCaves()
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
Cave* CaveEntrance::returnCave0()
{
	return this->array[0];
}
Cave* CaveEntrance::returnCave1()
{
	return this->array[1];
}
Cave* CaveEntrance::returnCave2()
{
	return this->array[2];
}
Cave* CaveEntrance::returnCave3()
{
	return this->array[3];
}

