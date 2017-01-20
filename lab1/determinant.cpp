/*********************************************************************
* Program Filename: determinant.cpp
* Author: Adam Kniffin
* Date: 1/9/2016
* Description: This is the source file for the determinant function. It 
* takes a 2-D array and an integer as its parameters. If the size of the array 
* is 4 or 9 (depending on how large the size int that is passed in) it calculates 
* the determinant and returns the integer value.
* Input: 2-day array and integer
* Output: integer
*********************************************************************/

#include "determinant.hpp"
#include <iostream>
using std::cout;

int determinant(int **arr, int size)
{
	int a;
	int b;
	int c;
	int determinant;

	//If size = 4 calculate the determinant
	if (size == 4)
	{
		determinant = (arr[0][0] * arr[1][1]) - (arr[0][1] * arr[1][0]);
		return determinant;
	}
	else //size = 9 and calculate the determinant with the function below
	{
		a = arr[0][0] * (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1]);
		b = arr[0][1] * (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0]);
		c = arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);

		determinant = (a - b) + c;

		//return the integer value corresponding to determinant
		return determinant;
	}
}