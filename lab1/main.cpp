/*********************************************************************
* Program Filename: main.cpp
* Author: Adam Kniffin
* Date: 1/9/2016
* Description: This is the program with int main(). It starts by creating a pointer to pointer 
* array and then prompting the user to enter either a 2x2 (4 total) or 3x3 (9 total) matrix.
* The array is then dynamically allocated and passed into the readMatrix function
* as well as the size parameter. 
* Input: pointer to 2-day array and integer
* Output: void output
*********************************************************************/

#include <iostream>
#include <math.h>

#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int size;

	cout << "How large of a matrix would you like?\nFor 2x2 enter 4\nFor 3x3 enter 9\n";
	cin >> size;

	int **array;
	array = new int*[size];

	//The while loops continues until the user inputs a valid number
	while (size != 4 && size != 9)
	{
		cout << "Please enter either 4 or 9 to continue\n";
		cin >> size;
	}

	for (int i = 0; i < size; i++)
	{
		array[i] = new int[size];
	}

	readMatrix(array, size);

	cout << "\nThank you for filling in the matrix.\n" <<
		"The contents of your array are: " << endl;

	//Loop through the array that was entered and display the values
	//Use sqrt b/c the double loops will multiply by themselves. IE 3x3 = 9. 
	for (int i = 0; i < sqrt(size); i++)
	{
		for (int j = 0; j < sqrt(size); j++)
		{
			cout << array[i][j] << endl;//display the contents
		}
	}

	cout << "Based on those numbers entered into the matrix"
		//determinant function is called and the information is displayed
		<< "\nthe determinant is " << determinant(array, size) << endl;
	
	
	return 0;
}
