/*******************************************************************
* Filename: lab6.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/10/2016
* Description: This is the main file for the Stack and Queue Classes. It displays
* a menu option for the user to input what they would like to do. They then choose
* what sort of list they would like to use and then can add, remove, or print
* the values in the list. 
**********************************************************************/
#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
#include "stack.hpp"
#include "queue.hpp"

//function declarations
void displayMenu();
void options();

int main() {
	bool done = false;//declare variable done to loop until user is done

	string choice; //declare choice variable for user to input
	Stack s1;//declare Stack class object
	Queue q1;//declare Queue class object
	
	//while loop will continue until someone chooses to quit the program by hitting 3 in the main menu
	while (done != true)
	{	
		bool list = false;//declare list = false every time back at main menu
		displayMenu();//display menu options
		cin >> choice;//user enters choice	
		if (choice == "1")
		{
			while (list == false)
			{
				int choice;
				cout << "Stack Menu\n";
				options();

				cin >> choice;

				if (choice == 1)//add value to the list
				{
					int value;//declare value variable to be added to the list
					cout << "Enter the value you would like to ADD to the list.\n";
					cin >> value;
					s1.add(value);
				}
				else if (choice == 2)//remove value
					s1.remove();

				else if (choice == 3)//print list
					s1.print();

				else if (choice == 4)
				{
					cout << "You will be returned to the main menu\n";
					list = true;
					break;
				}
				else
				{
					cout << "Please enter a valid input or hit '4' to go back to the main menu!\n";
					cin >> choice;
				}
			}
		}
		else if (choice == "2")//Queue List
		{
			while (list == false)
			{
				int choice;//declare choice variable for user to enter what they want to do
				cout << "Queue Menu\n";
				options();
				cin >> choice; //user enters their choice

				if (choice == 1)//add value to the list
				{
					int value;//declare value variable to be added to the list
					cout << "Enter the value you would like to ADD to the list.\n";
					cin >> value;
					q1.add(value);//add value to the que list
				}
				else if (choice == 2)//remove value
					q1.remove();

				else if (choice == 3)//print list
					q1.print();

				else if (choice == 4)//quit out of queue option
				{
					cout << "You will be returned to the main menu\n";
					list = true;
					break;
				}
				else//did not enter 1, 2, 3, or 4
				{
					cout << "Please enter a valid input or hit '4' to go back to the main menu!\n";
					cin >> choice;
				}
			}
		}
		else if (choice == "3")//quit program
		{
			cout << "Goodbye!\n";
			done = true;
			break;
		}
		else//not 1, 2, or 3
			cout << "Not a valid Input!\n";


	}//end while loop for total game
}

//displayMenu simply outputs the options to the user so they can decide
// what they would like to do
void displayMenu() 
{
	cout << "\n -  What sort of list would you like to add or remove a value from? -\n\n";
	cout << " - Option 1 - Stack List. The first value in, will be the last value out!\n"
		<< " - Option 2 - Queue List. This first value in will be the first value out!\n"
		<< " - Option 3 - Quit - Exit the program entirely.\n";
	
}
//options menu displays the options for the user. This is so there is not so much code
void options()
{
	cout 
		<< "1) Add value\n"
		<< "2) Remove value\n"
		<< "3) Display list\n"
		<< "4) Quit\n"
		<< "Choice:\n";
}



