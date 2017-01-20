/*********************************************************************
* Author: Adam Kniffin
* Date: 1/14/2016
* Description: This function is used compare the surrounding neighbors in the array function
* passed in. It follows the rules of Conway's Game of life and adds up the amount of
* neighbors are around each value in the array. It then sends the new array to the copy
* function to copy its contents into the main array.
********************************************************************/
#include "compare.hpp"
#include "copy.hpp"

void compare(int array[80][160])
{
	//declare a new int array to put in the information on if cells
	//live or die.
	int copyArr[80][160];

	//for loop to go through each cell in the array
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 160; j++)
		{
			int count = 0;
			//above
			if (array[i - 1][j] == 1)
			{
				count++;
			}
			//above right
			if (array[i - 1][j + 1] == 1)
			{
				count++;
			}
			//right
			if (array[i][j + 1] == 1)
			{
				count++;
			}
			//below right
			if (array[i + 1][j + 1] == 1)
			{
				count++;
			}
			//below
			if (array[i + 1][j] == 1)
			{
				count++;
			}
			//below left
			if (array[i + 1][j - 1] == 1)
			{
				count++;
			}
			//left
			if (array[i][j - 1] == 1)
			{
				count++;
			}
			//top left
			if (array[i - 1][j - 1] == 1)
			{
				count++;
			}

			//set the contents of the copy array to 0
			copyArr[i][j] = 0;


			//any live cell with fewer than two live nighbors dies
			if (array[i][j] == 1 && count < 2)
			{
				copyArr[i][j] = 0;
			}
			//any live cell with more than three live neighbors dies
			if (array[i][j] == 1 && count > 3)
			{
				copyArr[i][j] = 0;
			}
			//Any dead cell with exactly three live neighbors becomes a live cell
			if (array[i][j] == 0 && count == 3)
			{
				copyArr[i][j] = 1;
			}
			if (array[i][j] == 1 && (count == 2 || count == 3))
			{
				copyArr[i][j] = 1;
			}
		}
	}
	//use our copy function to copy what cells have lived and died and put it back
	//entire our array that is being passed in
	copy(copyArr, array);
}