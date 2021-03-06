/*******************************************************************
* Filename: stack.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/10/2016
* Description: This is cpp file for the class Stack. It contains function implementation.
* Each function will be described in more detail below.
**********************************************************************/
#include "queue.hpp"
#include <iostream>
using std::cout;

/*****************************************************************************
* add function takes an integer value as its parameters. It creates a new Node and sets
* the new nodes value to the number being passed in. If the Node being passed in is null, then it is
* set as the first element. If it is not, then the function goes through the list to find
* Null (end) and adds the value at the end.
*****************************************************************************/
void Queue::add(int number)
{
	Node *newNode = new Node;//create a new Node
	newNode->value = number;//set the value to the integer passed in
	newNode->next = NULL;//set the next variable to NULL

	if (head == NULL)//head is NULL
		head = newNode;//set head equal to the newNode already created

	else
	{
		Node *temp = head;//create a new pointer that starts at head
		while (temp->next != NULL)//loop until NULL is reached
		{
			temp = temp->next;//move through the list until NULL is found
		}//end of while loop
		temp->next = newNode;//set the next node = to the new node already made
	}
}

/*****************************************************************************
* remove takes nothing as its parameter and returns an integer value.
* If the list has no elements, the functions outputs that, and if the function's
* item that is deleted is the last element in the list, it outputs that. Otherwise
* the item is deleted from the FRONT of the list. This is done by locating the 
* head and moving it to the next value. The head Node is then deleted. 
*****************************************************************************/
int Queue::remove()
{
	int toReturn;//create integer which will return the value that gets deleted
	if (head == NULL)
	{
		toReturn = NULL;//set return value to NULL
		cout << "Nothing in the list!\n";
	}
	else if (head->next == NULL)
	{
		toReturn = head->value;//set return value to the value in the head
		delete head;//delete head
		head = NULL;//set head to NULL
		cout << "Removed from the list. There are now NO elements LEFT!\n";
	}
	else
	{
		toReturn = head->value;//set value to the first position
		Node * temp = head;
		head = head->next;
		delete temp;
		cout << "Removed from the FRONT of the list!\n";
	}
	return toReturn;//return integer value

}

/*****************************************************************************
* print function takes no parameters and if the list is empty (head = NULL) then
* that is outputted. Otherwise the print function starts at the head of the List
* and outputs each value until NULL is reached, indicating the end of the list.
*****************************************************************************/
void Queue::print()
{
	Node *current = head;
	if (current == NULL)//nothing in the list
		cout << "List is empty!\n";

	else
	{
		cout << "The list contains the following values: \n";
		while (current != NULL)//cout until current != NULL (end of list)
		{
			cout << current->value << "\n";
			current = current->next;//move to next position
		}
	}
}



