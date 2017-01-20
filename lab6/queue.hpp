/*******************************************************************
* Filename: queue.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/10/2016
* Description: This is the header file for a class Queue. It contains a struct
* node, a constructor, and other function declarations.
**********************************************************************/
#include <iostream>
#ifndef QUEUE_HPP
#define QUEUE_HPP

class Queue
{
protected:
	//declare struct nod
	struct Node
	{
		int value;//will hold value in the node
		Node *next;//pointer that points to the next node
		Node *front;//front node to keep track of the next position in the front

	}; Node *head;
public:
	//constructor that sets the head of the list to NULL
	Queue() { head = NULL; }

	//add / remove functions
	void add(int);//returns void, int parameter
	int remove();//no param returns and integer
	void print();//prints out all the elements in the list
};

#endif