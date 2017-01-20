/*******************************************************************
* Filename: stack.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/10/2016
* Description: This is cpp file for the class Stack. It contains
* function implementation. Each of the functions will be described
* in more detail below.
**********************************************************************/
#include "stack.hpp"
#include <iostream>
using std::cout;

/*****************************************************************************
* add function takes Creature pointer as its parameters. It creates a new Node and sets
* the new nodes value to the Creature being passed in. If the Node being passed in is null, then it is
* set as the first element. If it is not, then the function goes through the list to find
* Null (end) and adds the Creature to the end. 
*****************************************************************************/
#include "stack.hpp"
//constructor sets the head node to NULL and initializes the member variable
//score to 0.
Stack::Stack()
{
	head = NULL; 
	this->score = 0;
	this->numOfCreatures = 0;
}

/*****************************************************************************
* add function takes a creature pointer as parameters and adds it to the top 
* of the list. 
*****************************************************************************/
void Stack::add(Creature *creature)
{
	Node *newNode = new Node;//create a new Node
	newNode->c = creature;//set the value to the integer passed in
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
	this->numOfCreatures++;//increment number of creatures member variable
}

/*****************************************************************************
* remove takes nothing as its parameter and returns a string value that is associated with the the 
* Creature deleted. If the list has no elements, the functions outputs that, and if the function's
* item that is deleted is the last element in the list, it outputs that. Otherwise
* the Node is simply deleted from the back of the list.
*****************************************************************************/
void Stack::remove()
{
	if (head == NULL)//list is empty
		cout << "";
	
	else if (head->next == NULL)
	{
		delete head;//delete head
		head = NULL;//set head to NULL
		this->numOfCreatures--;//decrement number of creatures
	}
	else
	{
		//declare two node pointer variables and set 1 to head, the other to head->next
		Node *nextToEnd = head;
		Node *end = head->next;

		while (end->next != NULL)//loop as long as it does not reach NULL
		{
			nextToEnd = end;//placeholer
			end = end->next;//set end to the next value in the list
		}
		delete end;//delete last node
		nextToEnd->next = NULL;//set the nextToeEnd node to null	
		this->numOfCreatures--;//decerement number of creatures
	}
}

/*****************************************************************************
* print function takes no parameters and if the list is empty (head = NULL) then
* that is outputted. Otherwise the print function starts at the head of the List
* and outputs each value until NULL is reached, indicating the end of the list.
*****************************************************************************/
void Stack::print()
{
	Node *current = head;
	if (current == NULL)//nothing in the list
		cout << "List is empty!\n";

	else
	{
		while (current != NULL)//cout until current != NULL (end of list)
		{
			cout << current->c->getType() << " | ";
			current = current->next;//move to next position
		}
		cout << "\n";
	}
}

/*****************************************************************************
* top function takes no parameters and returns the Creature pointer that is 
* at the top of the list.
*****************************************************************************/
Creature* Stack::top()
{	
	if (head == NULL)//list is empty
	{
		cout << "";
		return NULL;
	}
	else if (head->next == NULL)//1 item in the list
		return head->c;
	
	else//more than 1 item
	{
		//declare two node pointer variables and set 1 to head, the other to head->next
		Node *nextToEnd = head;
		Node *end = head->next;

		while (end->next != NULL)//loop as long as it does not reach NULL
		{
			nextToEnd = end;//placeholer
			end = end->next;//set end to the next value in the list
		}
		return end->c; 
	}	
}

/******************************************************************************
 * incrementScore adds 1 to the current score of the member variable score.
 * it simply accesses the variable then adds the integer value of 1.
 *****************************************************************************/
void Stack::incrementScore()
{
	this->score = this->score + 1;//increment by 1
}

//getScore function returns the integer value that is associated
//with the score for the Stack object
int Stack::getScore()
{
	return this->score;
}

/**************************************************************
* sort function takes no parameters and loops through each Creature
* in the linked list and compares the points that they have gotten
* throughout the tournament and puts them into ascending order. 
* This was originally taken from the URL http://www.cplusplus.com/forum/beginner/66054/.
* It was changed and updated to fit the current linked list.
**************************************************************/
void Stack::sort()
{
	Node * temphead = head;//create NOde temphead and set it equal to the head Point
	Creature *temproll;//create Creature pointer and set it to temproll
	string tempname;//create string variable
	int counter = 0;//set counter variable to 0
	while (temphead)
	{
		temphead = temphead->next;
		counter++;
	}
	temphead = head;//set temphead equal to head after it has looped
	for (int j = 0; j<counter; j++)
	{
		while (temphead->next)  //iterate through list until next is null
		{
			//compare the value at hand and the next one to determine what creature has more poiints
			if (temphead->c->getPoints() > temphead->next->c->getPoints())
			{
				temproll = temphead->c;//set temproll equal to the creature at temphead
				temphead->c = temphead->next->c;//move down list
				temphead->next->c = temproll;
			}
			else
				temphead = temphead->next;//increment node
		}
		temphead = head;//reset temphead
	}
}

/*****************************************************************************
* removeFront takes nothing as its parameter returns nothing or void.
* If the list has no elements, the functions outputs that, and if the function's
* item that is deleted is the last element in the list, it outputs that. Otherwise
* the item is deleted from the FRONT of the list. This is done by locating the
* head and moving it to the next value. The head Node is then deleted.
*****************************************************************************/
void Stack::removeFront()
{
	if (head == NULL)
		cout << "";
	
	else if (head->next == NULL)
	{
		delete head;//delete head
		head = NULL;//set head to NULL
		this->numOfCreatures--;//decerement
	}
	else
	{
		Node * temp = head;
		head = head->next;
		delete temp;
		this->numOfCreatures--;//decrement
	}
}

/**************************************************************
 * moveToFront function takes no parameter and moves the back
 * Node to the front of the list. 
 **************************************************************/
void Stack::moveToFront()
{
	//If linked list is empty do nothing
	if (head == NULL)
		head = NULL;//do nothing

	else if (head->next == NULL)//only one Node so we dont need to do anything
		head = head;
	
	else
	{
		//initialize secLast and last pointers to NULL and head respectively
		Node *secLast = NULL;
		Node *last = head;

		//After this loop secLast contains address of second last
		//node and last contains address of last node in Linked List 
		while (last->next != NULL)
		{
			secLast = last;
			last = last->next;
		}

		//Set second to last to NULL
		secLast->next = NULL;

		//set last Node as head
		last->next = head;

		//point the head at last
		head = last;
	}
}

//getNumCreatures function takes no parameter and returns the integer value associated
//with the integer value of member variable numOfCreatures
int Stack::getNumCreatures()
{
	return this->numOfCreatures;
}

