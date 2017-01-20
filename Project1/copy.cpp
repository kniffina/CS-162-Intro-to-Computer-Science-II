/********************************************************************************************
* Author: Adam Kniffin
* Date: 1/14/2016
* Description: This function takes two arrays as parameters. It then uses two for-loops to
* go through all of the values in array1 and copy them into array 2.
*********************************************************************************************/
#include "copy.hpp"

void copy(int array1[80][160], int array2[80][160])
{
	//2 for-loops go through each arrays total values and copy the contents 
	//of array1 to array2.
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 160; j++)
		{
			//copy the contents of the first array to the second array
			array2[i][j] = array1[i][j];
		}
	}
}