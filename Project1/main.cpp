/**********************************************************
* Author: Adam Kniffin
* Date: 1/15/2016
* Description: This is the main file for Conway's Game of life. It tells
* the user how the game is played. It also has all of the implementation
* of the functions declared earlier. It is described in more detail below.
**********************************************************/
#include <iostream>
#include <string>
#include "compare.hpp"
#include "copy.hpp"
#include "createDesign.hpp"
#include "display.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int array1[80][160];

	int xPoint;
	int yPoint;

	string startShape;

	bool start = false;
	bool game = false;
	string canContinue;


	cout << "Welcome To Adam Kniffin's Version of Conway's Game of Life!\n\n";

	cout << "The rules : Each cell has eight neighbor cells.The neighbors are the cells directly" <<
		"\nabove, below, to the right, to the left, diagonally above the right and left, and\n" <<
		"diagonally below to the right and left\n" << endl;

	cout << "1. If an occupied cell has zero or one neighbor, it dies of loneliness.\n"
		<< "2. Any live cell with two or three live neighbours lives on to the next generation.\n"
		<< "3. If an occupied cell has more than three neighbors, it dies of overcrowding.\n"
		<< "4. If an empty cell has exactly three occupied neighbor cells, there is a birth of a new\n"
		<< "cell to replace the empty cell.\n"
		<< "Births and deaths are instantaneous and occuer at the changes of generation.\n\n";

	cout << "The board will display a 40 x 20 grid and will show the development of the game.\n";
	cout << "Before we get started I am going to describe the way each of the shapes and how\n"
		<< "they interact in the game.\n\n"
		<< "Shape 1: Oscillator. It is a simple straight up" <<
		"and down line. Your starting point\n" << "     will be in the middle of this line\n\n"
		<< "Shape 2: Glider. It is a smaller shape and moves down\n" <<
		"     the page and off the screen. Your starting point will be the bottom" <<
		"middle of the glider.\n\n"
		<< "Shape 3: Cannon. It is a combination of shapes that are a bit\n" <<
		"     tricky to describe. Your starting point will be the furthest left 'box'.\n"
		<< "     This cannon spits out gliders towards the bottom of the page so you should start with 2 low numbers!\n"
		<< "     I would recommend an X VALUE OF 2 and Y VALUE OF 5. That way you can see the whole cannon!\n";

	cout << "\nChoose one of the 3 different shapes: Oscillator, a glider and cannon.\n";
	cin >> startShape;

	//While loop to make sure a correct starting shape has been entered.
	while (start == false)
	{
		if (startShape == "glider")
		{
			start = true;
		}
		else if (startShape == "Glider")
		{
			start = true;
		}
		else if (startShape == "oscillator")
		{
			start = true;
		}
		else if (startShape == "Oscillator")
		{
			start = true;
		}
		else if (startShape == "cannon")
		{
			start = true;
		}
		else if (startShape == "Cannon")
		{
			start = true;
		}
		else
		{
			cout << "Please enter glider, oscillator, or cannon to continue: \n";
			cin >> startShape;
			start = false;
		}
	}

	cout << "\nPlease enter the starting x coordinate\n";
	cin >> yPoint;
	if (yPoint < 0 || yPoint > 40)
	{
		cout << "Please enter an integer between 0 and 40\n";
		cin >> yPoint;
	}
	cout << "Enter the starting y coordinate\n";
	cin >> xPoint;
	if (xPoint < 0 || xPoint > 40)
	{
		cout << "Please enter an integer between 0 and 20\n";
		cin >> xPoint;
	}

	

	//set the xPoint and yPoint so they can be visible when using display function
	xPoint = xPoint + 30;
	yPoint = yPoint + 70;
	cout << "Here is the first iteration of " << startShape << "!\n";

	//initialize all the elements in the array to 0
	for (int i = 0; i < 80; i++)
	{
		for (int j = 0; j < 160; j++)
		{
			array1[i][j] = 0;
		}
	}

	//call createDesign function to create live cells for specified x and y 
	//and determine its shape.
	createDesign(startShape, xPoint, yPoint, array1);


	display(array1);

	while (game == false)
	{
		compare(array1);

		cout << "N or Q\n"
			<< "N will show you the next Life Cycle\n"
			<< "Q will quit the game.\n";
		cin >> canContinue;

		if (canContinue == "Q" || canContinue == "q")
		{
			cout << "Thank you for playing!\n";
			game = true;
		}
		else if (canContinue == "N" || canContinue == "n")
		{
			game = false;
			display(array1);
		}
		else
		{
			bool enterNorQ = false;
			while (enterNorQ == false)
			{	
				cout << "Please enter N or Q: \n";
				cin >> canContinue;

				if (canContinue == "N" || canContinue == "n")
				{
					enterNorQ = true;
				}
				else if (canContinue == "Q" || canContinue == "q")
				{
					enterNorQ = true;
					game = true;
				}
				else
				{
					enterNorQ = false;
				}
			}
		}
	}
}
