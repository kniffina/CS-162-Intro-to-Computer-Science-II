/*****************************************************************
* Author: Adam Kniffin
* Date: 1/14/2016
* Description: Display takes an integer array as parameters. The function then loops through each
* value in the array, and if that value is equal to the integer value 1, a
* "*" is displayed. The star represents a living cell. If the value is equal
* to 0, then nothing is displayed. Zero represents a dead or non-living cell.
*****************************************************************/
#include "display.hpp"
#include <iostream>
using std::cout;
using std::endl;

void display(int array[80][160])
{
	//Use the for loops to create a smaller (40, 20) 2-day array
	//but have the broder outline of the whole game still going on
	for (int i = 30; i < 50; i++)
	{
		for (int j = 70; j < 110; j++)
		{
			cout << "-";
			if (array[i][j] == 1)//alive
			{
				cout << "*";
			}
			else//dead
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	//end of displaying array
	cout << "+------------------------------------------------------------------------------+\n";
}