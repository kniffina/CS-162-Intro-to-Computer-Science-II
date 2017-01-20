/*******************************************************************
* Filename: stack.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 3/4/2016
* Description: This file contains the implementation of the stack function.
* it will be described in more detail below.
**********************************************************************/
#include "stack.hpp"
#include "queue.hpp"
#include <iostream>
#include <algorithm>
#include <deque>
#include <ctime>
using std::cout;
using std::cin;
using namespace std;

/***************************************************************
 * int main uses the queue and stack functions. The program
 * allows the user to choose from a buffer program or a palindrome
 * program. The user enters the respective values and the program
 * runs. After it is complete the user is sent to the main menu to
 * choose what they would like to do next. To exit the program
 * the user has to enter 'Q' at the main menu.
 ***************************************************************/
int main()
{
	//set seed to get random numbers
	srand(static_cast<unsigned int>(time(NULL)));

	string choice;//declare string for user input

	//declare a queue container
	deque<int> q;

	//declare vector named v
	std::vector<int> v;

	cout << "Welcome to the palindrome and Buffer Program\n\n"
		<< "You have two options:\n"
		<< "- 1 - Enter a percentage. This percentage will be sent\n"
		<< "      to a buffer where the program will generate a random\n"
		<< "      number. Based on your percentage the random number will\n"
		<< "      added, or not to the list. You will also send a percentage\n"
		<< "      for a value to be removed.\n"
		<< "- 2 - Type in a string. The program will then make it into a\n"
		<< "      a palindrome. (Same both ways)\n\n"
		<< " Enter '1' for the buffer\n"
		<< " Enter '2' for the palindrome creator\n"
		<< " Enter 'Q' to quit the program\n\n";


	//make variable to end while loop
	bool done = false;

	//while loop executes until specified
	while (done == false)
	{
		cout << "===========================================\n"
			 << "=====           - MENU -                ===\n"
			 << "===========================================\n"
			 << "    Enter '1' for the buffer\n"
			 << "    Enter '2' for the palindrome creator\n"
			 << "    Enter 'Q' to quit the program\n"
			 << "===========================================\n"
			 << "===========================================\n";
		cin >> choice;

		//entered 1 which is the queue function. This will allow the user
		//to enter a number that represents the percentage chance that 
		// a random number is added to a queue list. 
		if (choice == "1")
		{
			int add, remove, rounds;//for user to enter
			cout << "Enter a percentage for a random number to be entered into a list\n";
			cin >> add;

			//this is the user validation area to make sure the user inputted
			//a number between 0 - 100
			bool addDone = false;
			while (addDone == false)
			{
				if (add >= 0 && add <= 100)//valid
					addDone = true;//exit loop
				else//not a valid number
				{
					cout << "Please enter a number between 0 - 100\n";
					cin >> add;//re-enter add variable to go through loop
				}
			}
			cout << "Enter a percentage for the value at the front of the queue to be removed\n";
			cin >> remove;

			//this is the user validation area to make sure the user inputted
			//a number between 0 - 100
			bool removeDone = false;
			while (removeDone == false)
			{
				if (remove >= 0 && remove <= 100)//valid
					removeDone = true;//exit loop
				else//not a valid number
				{
					cout << "Please enter a number between 0 - 100\n";
					cin >> remove;//re-enter remove variable to go through loop
				}
			}
			cout << "How many rounds of this function would you like to iterate?\n";
			cin >> rounds;

			//this is the user validation area to make sure the user inputted
			//a number between 0 - 100
			bool roundsDone = false;
			while (roundsDone == false)
			{
				if (rounds > 0)//valid
					roundsDone = true;//exit loop
				else//not a valid number
				{
					cout << "Please enter a positive integer greater than 0\n";
					cin >> rounds;//re-enter add variable to go through loop
				}
			}

			//loop until the round has run out
			while (rounds > 0)
			{
				//call the queue function sending it the parameters
				//that the user specified
				Queue(add, remove, q);
				cout << "The size of the queue is " << int(q.size()) << "\n";
				rounds--;//decrement rounds
			}
			cout << "The queue contains: ";
			for (int i = 0; i < int(q.size()); i++)
				cout << q.at(i) << " | ";
			cout << "\n";
		}
		

		//stack function
		else if (choice == "2")
		{
			string palindrome;//declare string for user to input
			cout << "Enter a string to be turned into a palindrome\n";
			cin >> palindrome;

			//make the call to stack function to create palindrome
			cout << "The word turned into a palindrome is: '" << stack(palindrome) << "' .\n";
		}

		//user has specifie they want to quit the program
		else if (choice == "q" || choice == "Q")
		{
			cout << "Thank you for using this program. Have a nice day!\n";
			done = true;//set done to true to exit loop
		}

		//not a valid input from the user. Will send them to main menu.
		else 
			cout << "***   ERROR   ***\n";
		
	}
}