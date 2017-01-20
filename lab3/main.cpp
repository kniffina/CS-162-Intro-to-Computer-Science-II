/*******************************************************************
* Program Filename: main.cpp
* Author: Adam Kniffin
* Date: 1/18/2016
* Description: This is the main function where you can play a Game 
* using Die and LoadedDie. A game object is created and once the program is
* run, you are able to play.
* Input: User will input the type of Die they want to use, and the rounds to play.
* they also have the option to determine how many rounds they would like to play.
* Output: Many different outputs take place during this, but at the end of the game
* a will will be determined and outputted.
*******************************************************************/
#include "die.hpp"
#include "loadedDie.hpp"
#include "game.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	//not sure if this is needed but figured it couldn't hurt
	srand(static_cast<unsigned int>(time(0)));

	//declare a Game object
	Game g1;

	//play the game
	g1.playGame();

	return 0;
}
