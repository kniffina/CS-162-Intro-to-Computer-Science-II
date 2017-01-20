/*******************************************************************
* Filename: assignment4.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/25/2016
* Description: This is the main file that usees the Queue class that was implemented
* in the hpp and cpp file. It outputs the options to choose from for the user and selects
* what action they would like to make. This continues until the user decides to quit 
* the program.
* Input: from user.
* Output: different function calls produce different outputs that revolve around
* the elements in the Queue object. 
**********************************************************************/
#include "queue.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::string;

int main()
{
	Queue q1;//creatue a queue list structure to store the elements

	cout << "Welcome to the Queue Structure Doubly Linked List. Your options are: \n\n";

	bool done = false;//declare boolean value to be false until user chooses to exit
	while (done == false)//loop until 
	{
		string choice;//declare string variable to hold the users choice
		displayMenu();//display the menu after each task is completed by the user
		cin >> choice;
		if (choice == "a)")//add value to queue
		{
			int number;//int to allow user to enter into the list
			cin >> number;
			q1.addBack(number);
		}
		else if (choice == "b)")//return the value at the top of the queue
			cout << "The value at the front of the Queue is: " << q1.getFront() << "\n";
		
		else if (choice == "c)")//remove from the front of the list
		{
			int remove = q1.removeFront();
			if (remove == -1)
				cout << "The list is empty and -1 has been returned\n";
			else
				cout << "The value of: " << remove << " has been removed from the front of the Queue\n";
		}
		else if (choice == "d)")//print the queue list
		{
			q1.display();
		}
		else if (choice == "x)")//quit the program
		{
			cout << "\nThank you for using the program!\n";
			done = true;//set bool to true to exit program
		}
		else//user did not input an acceptable value
		{
			cout << "\nERROR please choose an acceptable value.(Ex. 'a)', 'b)', 'c)', etc)\n";
		}

	}
}