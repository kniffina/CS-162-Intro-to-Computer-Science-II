/*************************************************************
* Filename: lab10.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/13/2016
* Description: This is the main file for the two fibonacci functions.
* It allows the user to choose what they would like to do. Either
* they can use the two functions to calculate each fibonacci
* function takes to calculate. The user can also quit the program
* entirely.
***************************************************************/
#include "fibonacci.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <fstream>
using std::vector;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*****************************************************************
* main allows the user to choose what they want to do. They have
* 2 options: look at the time it takes to get to a certain
* number in the fibonacci sequence with iterative, and recursive
* functions, or quit the program entirely. It also writes the
* results of the testing to a file to look at the results.
****************************************************************/
int main()
{
	ofstream outFile;//create outputfile
	outFile.open("data.txt");//name it data.txt

	cout << "----------------------------------------------------------------------------\n"
		 << "- Hello and welcome to the Fiboanicci sequence program!                    -\n"
		 << "- In this program you will type in the number in the Fibonacci sequence    -\n"
		 << "- that you would like to see, and then two different programs will return  -\n"
		 << "- the value. EXCEPT they time it takes to calculate what number it is will -\n"
		 << "- also be displayed. This is because one is done ITERATIVELY, and the      -\n"
	 	 << "- other is done RECURSIVELY                                                -\n"
		 << "----------------------------------------------------------------------------\n";

	bool done = false;//bool for while loop
	while (done == false)//loop until specified
	{
		string choice;//will hold the variable that the user enters
		cout << "===========================================\n"
			<< "=====           - MENU -                ===\n"
			<< "===========================================\n"
			<< "  Enter '1' To See how long it takes EACH  \n"
			<< "            program to return the          \n"
			<< "            sequence number of your choice \n"
			<< "  Enter 'Q' to quit the program          \n"
			<< "===========================================\n"
			<< "===========================================\n";
		cin >> choice;

		//use both functions and test the speed
		if (choice == "1") {
			int iterativeNum;//int for user to enter
			cout << "Enter what sequence number you would like to calculate iteratively:\n";
			cin >> iterativeNum;

			clock_t t1 = clock();//set clock before running the function
			iterative(iterativeNum);//run iterative function
			clock_t t2 = clock();//get time after function ran
			clock_t total = t2 - t1;
			cout << "It took the ITERATIVE program ";
			printf("%d clicks (%f seconds).\n", total, ((float)total) / CLOCKS_PER_SEC);
			outFile << total << "  |  ";//write to the output file


			int recursiveNum;
			cout << "Enter what sequence number you would like to calculate recursively:\n";
			cin >> recursiveNum;
			clock_t rt1 = clock();//set clock before running the function
			recursive(recursiveNum);//run recursive function
			clock_t rt2 = clock();//get time after function ran

			clock_t rtotal = rt2 - rt1; //calculate time gone
			cout << "It took the RECURSIVE program ";
			printf("%d clicks (%f seconds).\n", rtotal, ((float)rtotal) / CLOCKS_PER_SEC);
			outFile << rtotal << endl;

	
		
		}
		//user has specified they want to quit the program
		else if (choice == "Q" || choice == "q") {
			cout << "Thank you for using the program!\n";
			done = true; //set to true to exit loop
		}
		//user did not enter valid input
		else
			cout << "** ERRROR ** Please enter valid input\n";
	}
	
}