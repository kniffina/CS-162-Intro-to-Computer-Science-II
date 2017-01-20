/**********************************************************************
* Author: Adam Kniffin
* Date: 1/14/2016
* Description: This function takes in a string to determine what the starting shape the user
* has decided upon. It then takes in 2 integer values which are the starting x
* and y value for the respective shape. It also takes into the function an array
* which will add a living cell (or 1) to represent the shape that has been decided
* upon.
**********************************************************************/
#include "createDesign.hpp"

void createDesign(string answer, int x, int y, int array[80][160])
{
	if (answer == "glider" || answer == "Glider")
	{
		array[x][y - 1] = 1;
		array[x][y] = 1;
		array[x][y + 1] = 1;
		array[x - 1][y + 1] = 1;
		array[x - 2][y] = 1;


	}
	if (answer == "oscillator" || answer == "Oscillator")
	{
		array[x][y] = 1;
		array[x - 1][y] = 1;
		array[x + 1][y] = 1;
	}
	if (answer == "Cannon" || answer == "cannon")
	{
		//left block
		array[x][y] = 1;
		array[x + 1][y] = 1;
		array[x][y + 1] = 1;
		array[x + 1][y + 1] = 1;
		
		//cannon portion
		array[x][y + 10] = 1;
		array[x + 1][y + 10] = 1;
		array[x + 2][y + 10] = 1;
		array[x + 3][y + 11] = 1;
		array[x + 4][y + 12] = 1;
		array[x + 4][y + 13] = 1;
		array[x + 3][y + 15] = 1;
		array[x + 2][y + 16] = 1;
		array[x + 1][y + 16] = 1;
		array[x][y + 16] = 1;
		array[x + 1][y + 17] = 1;
		array[x + 1][y + 14] = 1;
		array[x - 1][y + 11] = 1;
		array[x - 2][y + 12] = 1;
		array[x - 2][y + 13] = 1;
		array[x - 1][y + 15] = 1;

		//random shape thing
		array[x][y + 20] = 1;
		array[x][y + 21] = 1;
		array[x - 1][y + 20] = 1;
		array[x - 1][y + 21] = 1;
		array[x - 2][y + 20] = 1;
		array[x - 2][y + 21] = 1;
		array[x - 3][y + 22] = 1;
		array[x - 3][y + 24] = 1;
		array[x - 4][y + 24] = 1;
		array[x + 1][y + 22] = 1;
		array[x + 1][y + 24] = 1;
		array[x + 2][y + 24] = 1;

		//far right box
		array[x - 1][y + 34] = 1;
		array[x - 1][y + 35] = 1;
		array[x - 2][y + 34] = 1;
		array[x - 2][y + 35] = 1;
	}
}