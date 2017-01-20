/*******************************************************************
* Filename: stack.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/25/2016
* Description: This is the header file for a class Stack. It contains a struct
* node, a constructor, and other function declarations.
**********************************************************************/
#include <iostream>
#include <string>
#include "creature.hpp"
using std::string;
#ifndef STACK_HPP
#define STACK_HPP

class Stack
{
protected:
	int score; //integer to keep track of how many points each stack has
	int numOfCreatures;//will be adjusted each time a Creature is removed or added to the list

	//declare struct nod
	struct Node
	{
		Creature *c;//will hold string name in the Node
		Node *next;//pointer that points to the next node

	}; Node *head;
public:
	//constructor 
	Stack();

	//add / remove functions
	void add(Creature *);//returns, Creature pointer as paramter
	void remove();//no param returns 
	void print();//prints out all the elements in the list
	
	//returns a pointer to a creature at the top of the list
	Creature* top();

	//increments the score if the Creature won
	void incrementScore();

	//returns the score of the stack
	int getScore();

	//returns string value of member variable team
	string getTeam();

	//sorts the Creatures
	void sort();

	//removes the Front Node
	void removeFront();

	//moves the back value to the front of the list
	void moveToFront();

	//takes no parameters returns integer value
	int getNumCreatures();
};

#endif