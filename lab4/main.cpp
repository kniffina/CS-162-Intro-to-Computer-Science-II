/*************************************************************
* Filename: main.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 1/29/2016
* Description: This is the main file for the lab4 function header file. It
* outputs a menu of options for the user to choose from. The user can enter
* whatever function they would like to use. Once inside the specific function,
* they will be guided what to do. When that function is over, they will be prompted
* with a smaller menu and they can enter another function, or choose to quit the program.
* This will continue until they want to quit the program.
* Input: User input for different variables, function calls, and overall direction
* of the program.
* Output: Descriptions of what to do, as well as, many outputs that will show the user
* what has happened with the variable they wanted to be worked on in each function.
***************************************************************/
#include "lab4.hpp"
#include <iostream>
#include <string>
using std::string;
using namespace std;

int main()
{
	//declare variable to hold the users choice as to what function they want to use
	string choice;

	/****************************************************************************************
	* This explains to the user their options and allows them to enter what sort of function
	* they would like to call. 
	*******************************************************************************************/
	cout << "Welcome to the Recursive Function Menu!\n\n"
		<< "In this program you will have the ability to choose from 3 different recursive functions\n"
		<< "that you would like to see executed. The options are as follows: \n\n"
		<< "*** Option 1 *** - Reverse String \n\n" << "This will allow you to enter a string, and then"
		<< " reverse it's contents.\n\n"
		<< "*** Option 2 *** - Array Sum \n\n" << "This will allow you enter the the contents of an "
		<< "array and then, calculate it's sum.\n\n"
		<< "*** Option 3 *** - Triangle Calculator \n\n" << "This will allow you to enter an integer and then \n"
		<< " it will return the total number of items in the triangle with that number of rows (I.E. Bowling Pins).\n\n"
		<< "*** If you would like to Quit - Enter 'Q'  **** \n\n"
		<< " ****    Enter: '1', '2', '3', or 'Q' if you want to quit    ****\n";
	//user enters their choice as to what option they would like to accomplish
	cin >> choice;

	//set flag to false to validate the inputted value
	bool flag = false;
	
	while (flag == false)
	{
		/*******************************************************************************
		* The user chose function 1 - reverseString. This if statement will include all the details
		* that the user needs in order to input a correct variable. At the end, the user will
		* be prompted with a smaller version of the menu choices and they can determine what they
		* would like to do.
		******************************************************************************/
		if (choice == "1")
		{
			//declare string pass to pass to the function
			string pass;
			cout << "Please enter a string of your choice: \n";
			cin >> pass;

			cout << "\n****   The string in reverse is: " << reverseString(pass) << ".    *****\n\n";

			//give a quick display of the menu choices
			cout << "Now that we have completed using the Reverse String function, what would you like to do next\n\n"
				<< "Enter '1' for Reverse string function \n"
				<< "Enter '2' for Array Sum function\n"
				<< "Enter '3' for Triangular Calculator\n\n"
				<< "Or hit 'Q' to quit the program\n";
			//allow the user to enter their choice again
			cin >> choice;

			//make sure the flag is still false so the loop does not exit
			flag = false;
		}



		/*******************************************************************************
		 * The user chose function 2 - arraySum.  This if statement will include all the details
		* that the user needs in order to input a correct variable. At the end, the user will
		* be prompted with a smaller version of the menu choices and they can determine what they
		* would like to do.
		******************************************************************************/
		else if (choice == "2")
		{

			int sum; //sum integer to hold the number of times the user wants to enter an integer into the array
			cout << "How many numbers would you like to enter into the array? \n";
			cin >> sum;
			cout << "Please enter " << sum << " numbers into the array: \n";

			//declare an integer array. We can assume that the user will not enter more than 1000 ints
			int array[1000];

			//forloop will loop as many times as the user specified by the variable sum and
			//allow them to enter whatever integer value they want into the array
			for (int i = 0; i < sum; i++)
			{
				cin >> array[i];
			}

			//call the function arraySum and cout the sum of the array
			cout << "\n****   The sum of the array is " << arraySum(sum, array) << "  **** \n\n";

			//give a quick display of the menu choices
			cout << "Now that we have completed using the arraySum function, what would you like to do next?\n\n"
				<< "Enter '1' for Reverse string function\n"
				<< "Enter '2' for Array Sum function\n"
				<< "Enter '3' for Triangle \n"
				<< "Or hit 'Q' to quit the program\n";


			//allow the user to enter their choice again
			cin >> choice;

			//make sure the flag is still false so the loop does not exit
			flag = false;
		}
		


		/*******************************************************************************
		* The user chose function 3 - triangularCalc.  This if statement will include all the details
		* that the user needs in order to input a correct variable. At the end, the user will
		* be prompted with a smaller version of the menu choices and they can determine what they
		* would like to do.
		******************************************************************************/
		else if (choice == "3")
		{
			int intToPass;//declare integer to pass into the triangularCalc function

			//prompt the user for the variable size
			cout << "How large of an integer would you like the program to calculate?\n";
			cin >> intToPass;

			cout << "\n****    The Triangular Calculation for " << intToPass << " is " << triangularCalc(intToPass) << "   ****\n\n";

			//give a quick display of the menu choices
			cout << "Now that we have completed using the Triangular Calculation function, what would you like to do next?\n\n"
				<< "Enter '1' for Reverse string function\n"
				<< "Enter '2' for Array Sum function\n"
				<< "Enter '3' for Triangle \n"
				<< "Or hit 'Q' to quit the program\n";


			//allow the user to enter their choice again
			cin >> choice;

			//make sure the flag is still false so the loop does not exit
			flag = false;
		
		}

		/*******************************************************************************
		* The user chose to Quit the program
		******************************************************************************/
		else if (choice == "q" || choice == "Q")
		{
			cout << "Thank you for participating\n";

			//set flag to true, and the while loop will be exited
			flag = true;
		}

		/*******************************************************************************
		* The user entered data that was not valid, and need to re-enter, until something
		* is valid. The smaller menu option is prompted so they can be reminded of what
		* their options are.
		******************************************************************************/
		else
		{
			cout << "That is not a valid input. This allowable inputs are as follows: \n"
				<< "Enter '1' for Reverse string function "
				<< "Enter '2' for Array Sum function\n"
				<< "Enter '3' for Triangle \n"
				<< "Or hit 'Q' to quit the program\n";
			cin >> choice;
			flag = false;
		}

	}//end of while loop


	return 0;
}

