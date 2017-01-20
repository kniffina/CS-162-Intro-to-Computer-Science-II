/*******************************************************************
* Filename: stack.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/10/2016
* Description: This is the header file for a class Stack. It contains a struct
* node, a constructor, and other function declarations.
**********************************************************************/
#include <iostream>
#ifndef STACK_HPP
#define STACK_HPP

class Stack
{
protected:
	//declare struct nod
	struct Node
	{
		int value;//will hold value in the node
		Node *next;//pointer that points to the next node

	}; Node *head;
public:
	//constructor that sets the head of the list to NULL
	Stack() { head = NULL;  }

	//add / remove functions
	void add(int);//returns void, int parameter
	int remove();//no param returns and integer
	void print();//prints out all the elements in the list

	void removeLast();
};

#endif