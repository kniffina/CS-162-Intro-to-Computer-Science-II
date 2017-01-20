/*********************************************************************
* Program Filename: readMatrix.cpp
* Author: Adam Kniffin
* Date: 1/9/2016
* Description: This is the source file for the readMatrix function. It
* takes a pointer to a 2-D array and an integer as its parameters. Since the array is 2-D
* the function first determines the size and divides it by 2 or 3 (depending on the variable
* size that was passed in). It then prompts the user to enter as many values as specified earlier
* and then loops through the array and adds the values entered from the user to the array.
* Input: pointer to 2-day array and integer
* Output: void output
*********************************************************************/

#include "readMatrix.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;


void readMatrix(int **array, int size)
{
	int values; //holds the value that the user enters

	//if size is 4, make it 2 so the two loops can execute correctly
	if (size == 4)
	{
		size = 2;
	}
	//else set size variable to 3 
	else
	{
		size = 3;
	}

	//Prompt user to enter values into the array
	cout << "Thank you. Please enter " << size* size << " numbers to the matrix\n";

	//Loops through the array that was passed in and 
	//allows the user to enter values
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cin >> values;
			array[i][j] = values;
		}
	}

}