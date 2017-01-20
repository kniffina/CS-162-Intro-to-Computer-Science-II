/*************************************************************
* Filename: main.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 1/28/2016
* Description: This is the main cpp file which contains the classes
* Item and List. They are used to add Items to a List when prompted by the user.
* The menu will continue to allow the user to add an item, remove an item, 
* print the list, or quit the program. 
* Input: user input.
* Output: displays items in the array, and lets the user see what is taking palce
* in real time as they add or remove items.
***************************************************************/

#include "item.hpp"
#include "list.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	//declare string variable that will store the users choice on what they
	//want to do
	string choice;

	//display the options to the user
	cout << "Welcome to your list! Here are your options: \n"
		<< "1. Add Item\n"
		<< "2. Remove Item\n"
		<< "3. Print List\n"
		<< "4. Quit - Type 'Q'\n";
	cin >> choice;


	//create a list object to store information in
	List l1; 

	bool flag = false;//set flag
	//loop will go until flag is false. This is indicated by a Q or q from the user
	while (flag == false)
	{
		if (choice == "1")
		{
			//call the addItem function to add a new item into the array
			l1.addItem();

			//display the options again for the user
			cout << "\nHere are your options: \n"
				<< "1. Add Item\n"
				<< "2. Remove Item\n"
				<< "3. Print List\n"
				<< "4. Quit - Type 'Q'\n";
			cin >> choice;

		}
		else if (choice == "2")
		{
			//call the remove function to remove the item from the array
			//If it is equal to the name and units, the item will be removed.
			l1.removeItem();

			//display the optiosn again for the user
			cout << "\nHere are your options: \n"
				<< "1. Add Item\n"
				<< "2. Remove Item\n"
				<< "3. Print List\n"
				<< "4. Quit - Type 'Q'\n";
			cin >> choice;
		}
		else if (choice == "3")
		{

			cout << "\n***   Here are all the items in your list   *** \n";
			//call display list function to display all the items in their list
			l1.displayList();

			cout << "\nHere are your options: \n"
				<< "1. Add Item\n"
				<< "2. Remove Item\n"
				<< "3. Print List\n"
				<< "4. Quit - Type 'Q'\n";
			cin >> choice;
		}
		else if (choice == "q" || choice == "Q")
		{
			cout << "Program will now quit. Thank you!\n";
			flag = true;
		}
		else 
		{
			//invalid input and the user must re-enter the information
			cout << "Please enter a valid input\n"
				<< "1. Add Item\n"
				<< "2. Remove Item\n"
				<< "3. Print List\n"
				<< "4. Quit - Type 'Q'\n";
			cin >> choice;
		}
	}
	
	return 0;
}
