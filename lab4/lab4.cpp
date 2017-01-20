/*************************************************************
* Filename: lab4.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 1/28/2016
* Description: This is the cpp file for the lab4 header file. It contains
* function implementation which will be described in more detail below.
* detail below.
* Input: none
* Output: none
***************************************************************/
#include "lab4.hpp"
#include <iostream>
#include <string>
#include <iostream>
using std::string;

/*****************************************************************************
* reverseString recursively reverses a string. The function has a single parameter
* of type string. It then uses a recursive function call to build the string backwards
* and then returns it.
*******************************************************************************/
string reverseString(string start)
{
	int size = start.length(); //get the length of the string as an integer
	//this will be used for our base case
	int i = 0;
	if (start.length() == 0)
		return start;

	string end(1, start[start.length() - 1]); //use the last character to create a string
	string endString = reverseString(start.substr(0, start.length() - 1));//recursively create the new string
	return end + endString;//return the addition of the two to make the string backwards
}

/*****************************************************************************
* arraySum function recursively calculates the sum of an array and has
* 2 params an array, and integer that is the size of the array. If the size is less than 0,
* 0 is returned (this is the base case). Otherwise the integer value is calculated
* by taking the value at the largest value in the array (array[size]) and then the arraySum
* function is called again, but subtracts one from the size. This will move down the array
* until all of the values have been addeded together, and gives the sum of all elements.
*******************************************************************************/
int arraySum(int size, int array[])
{
	int total = 0;
	//base case
	if (size == 1)
		return array[0];

	//decrement the size and make a call to the arraySum function to calculate the total
	return array[size - 1] + arraySum(size - 1, array);

}

/*****************************************************************************
* triangularCalc function takes an integer as its parameter. It then calculates
* the total number of items in the triangle. The integer represents the bottom
* with each subsequent level being less than that, until the triangle reaches the peak
* which will always be 1. It returns the total value.
*******************************************************************************/
int triangularCalc(int n)
{
	//base case
	if (n == 1)
		return n;

	//Use n and call the triangleCalc function to decrement n. This will
	//continue until it reaches the top of the triangle.
	return n + triangularCalc(n - 1);
}