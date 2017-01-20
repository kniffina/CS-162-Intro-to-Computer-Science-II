/*******************************************************************
* Filename: queue.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/20/2016
* Description: This is the header file for the QueueNode Class. It contains
* the declaration of a QueueNode struct.
**********************************************************************/
#include "queue.hpp"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

//the default constructor sets the front and back node to sentinel values of -1 and have
//them both point at eachother for their next and previous nodes. Since this is a doubly
//linked list this will allow the pointers to move down the list easily
Queue::Queue()
{
	front = new QueueNode;//make front a new queuenode
	front->value = -1;//set its value as a sentinel to -1
	back = new QueueNode;//make back a new queuenode 
	back->value = -1;//set it as a sentinel to -1

	//point the front pointers at the back to make a loop
	front->next = back;
	front->prev = back;

	//point back pointers to front to make a loop
	back->prev = front;
	back->next = front;
}

/*****************************************************************************
* addBack function takes an integer as its parameter and returns void. If the front
* value is equal to -1 then the function determines if there is any values (front and back -1).
* If there are, the function adds the element to the open front value, and readjusts it
* to be the back node. The front is also adjusted to reflected the value being added to
* the top of the Queue.
*****************************************************************************/
void Queue::addBack(int element)
{	
	if (front->value == -1)//open slots in the list
	{
		if (front->value == -1 && back->value == -1)//no items inthe list yet
			front->value = element;//set the front value to the int passed in
		else//move to the back element and add the value, then readjust the front
		{
			QueueNode *temp = back;//set temp to back

			temp->value = back->value;//set value equal to the value at back
			temp->prev = back->prev;//set the prev to back's prev pointer

			back = front;//set back pointer to the front
			back->value = element;//set the value to the newNode valueaheld prior

			front = back->next;//make front back->next
			front->value = back->next->value;//front value is equal to back next value
			front->prev = back;//the prev pointer can now point back to back node

			//back next can no be set to the front
			back->next = front;

			//now temp can point to back of the list
			temp->next = back;
		}
	}
	else if (back->value == -1)//the back Node is open and needs to be filled
		back->value = element;

	else//need to create a new Node for the element to be placed in 
	{
		QueueNode *newNode = new QueueNode;
		newNode->value = element;

		//create a temp QueueNode to hold the value of back
		QueueNode *temp = back;
		temp->value = back->value;//set value equal to the value at back
		temp->prev = back->prev;//set the prev to back's prev pointer
		
		back = newNode;//set back pointer to the new node
		back->value = newNode->value;//set the value to the newNode value
		back->prev = temp;//set the prev to the temp node holding the value it held prior
		back->next = front;//set next to the front

		//now temp can point to the new N
		temp->next = back;
	}
}

/*****************************************************************************
* removeFront function takes no parameters and returns an integer variable that is
* associated with the value that was removed from the list. The value is not actually
* removed but replaced with a sentinel value of -1. If there are no values in the list,
* then -1 is returned.
*****************************************************************************/
int Queue::removeFront()
{
	int toReturn = 0;//declare return variable
	if (front->value == -1 && back->value == -1)//if nothing is in the list
		toReturn = -1;//set toReturn to -1
	else
	{
		QueueNode *current = front;//create QueueNode pointer to front 
		while (current->value == -1)//loop until the current value != -1
			current = current->next;//move through list
				
		toReturn = current->value;//set the return value to first element not -1
		current->value = -1;//now set that value to -1 (remove)
	}
	return toReturn;
}

/*****************************************************************************
* print function takes no parameters and if the list is empty (front value = -1) then
* that is outputted. Otherwise the print function starts at the front of the list,
* and loops until and outputs all of the values until the node is point back at 
* the front of the list. 
*****************************************************************************/
void Queue::display()
{
	if (front->value == -1 && back->value == -1)
		cout << "No values are in the Queue\n";
	else
	{
		cout << "The Queue contains the values: ";//output
		
		bool done = false;//set bool to loop through until specified
		QueueNode *current = front;//set current to front node

		//check to see if it is -1 or is an actual positive integer
		if (current->value == -1) {
			cout << "";//output nothing
			current = current->next;//move it to the next node
		}
		else {
			cout << current->value << " | ";//output the value
			current = current->next;//move it to the next node
		}
		//now that current does not equal front we can loop until it goes back around to it
		while (current != front)
		{
			if (current->value == -1)//sentinel node
			{
				cout << "";
				current = current->next;//move down the list
			}
			else//node is holding a value
			{
				cout << current->value << " | ";
				current = current->next;//move down the list
			}
		}
		cout << "\n";
		
	}
}

//getFront returns the integer value of the value of at the front QueueNode. It 
//takes no parameters.
int Queue::getFront()
{
	int returnValue = 0;//set value to be returned to 0
	if (front->value == -1 && back->value == -1)
		returnValue = -1;//set to -1 since nothing in the list

	else if (front->value == -1)//elements in the list but not at front
	{
		QueueNode *temp = front;
		while (temp->value == -1)//loop until temp is not -1
			temp = temp->next;

		//set return to temp prev because temp is at -1, or nothing there
		returnValue = temp->value;
	}
	else//there is a value at the front of the list
		returnValue = front->value;

	return returnValue;
}

//displayMenu outputs to the user what their options are when doing different tasks
//with the queue structure
void displayMenu()
{
	cout << "=========================================\n" 
		 << "=           MENU - QUEUE                =\n" 
	     << "=========================================\n" 
		 << "=    a) Enter a value                   =\n"
		 << "=    b) Display first value             =\n"
		 << "=    c) Remove a value                  =\n"
		 << "=    d) Display the queue contents      =\n"
		 << "=    x) Exit                            =\n" 
		 << "=========================================\n";	
}
