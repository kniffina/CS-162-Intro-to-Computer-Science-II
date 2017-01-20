/*******************************************************************
* Filename: queue.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/27/2016
* Description: This is the header file for the QueueNode Class. It contains
* the declaration of a Queue class and its function declarations as well as f
* constructors. It also contains a QueueNode structure in its protected data.
**********************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP

//declare displayMenu which display's menu options to the user in main
void displayMenu();

class Queue
{
protected:

	struct QueueNode
	{		
		QueueNode *next;//next pointer used to point to the next Node in the list
		QueueNode *prev;//prev pointer used to point to the prev Node in the list
		int value;//used to store the integer value in the Node
	};
	QueueNode *front; //first item in the queue, where you take off
	QueueNode *back; //last item in the quee, where you add to

public:
	//constructr
	Queue();

	//adds item to the back of list. If the queue is full a new Node is created
	void addBack(int);

	//getFront returns the value at the front of the structure
	int getFront();

	//removeFront removes the first item in the structure
	int removeFront();	

	//outputs the values in the list
	void display();
};

#endif