/*************************************************************
* Filename: main.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/10/2016
* Description: This is the main file for the Caverns of Destiny Game.
* 
***************************************************************/
#include "user.hpp"
#include "item.hpp"
#include "cave.hpp"
#include "world.hpp"
#include "FeatherOfTheGreatEagle.hpp"
#include "potionOfEnlightenment.hpp"
#include "caveOfTheElders.hpp"
#include "forlornCavern.hpp"
#include "theForgottenPools.hpp"
#include "cavernOfTime.hpp"
#include <iostream>
using std::cout;
using std::cin;

int main()
{
	//Create  World objet
	World w1;

	//allows user to enter a number of moves to the
	string moves;

	//display choices
	cout << "What Difficulty would you like to play at?\n"
		<< "Enter '1' for EASY\n"
		<< "Enter '2' for MEDIUM\n"
		<< "Enter '3' for HARD\n";
	

	bool done = false;
	//while loop to validate that the user entered
	//a correct response
	while (done == false)
	{
		cin >> moves;

		//easy
		if (moves == "1") {
			w1.setMoves(60);
			cout << "You chosee EASY. You have " << w1.getMoves() << " moves to get to the Cave of Eternal Destiny!\n";
			done = true;//exit loop
		}
		//medium
		else if (moves == "2") {
			w1.setMoves(45);
			cout << "You chose MEDIUM. You have " << w1.getMoves() << " moves to get to the Cave of Eternal Destiny!\n";
			done = true;//exit loop
		}
		//hard
		else if (moves == "3") {
			w1.setMoves(30);
			cout << "You chosee HARD. You have " << w1.getMoves() << " moves to get to the Cave of Eternal Destiny!\n";
			done = true;//exit loop
		}
		else {
			cout << "Please enter a valid response!\n"
				<< "Enter '1' for EASY\n"
				<< "Enter '2' for MEDIUM\n"
				<< "Enter '3' for HARD\n";
		}
	}

	//play the game until you are out of moves
	while (w1.getMoves() > 0)
	{

		w1.play();
		//output moves left
		if (w1.getMoves() != -2 && w1.getMoves() != -6) {
			cout << "===========================================\n"
				<< "You have " << w1.getMoves() << " moves left until YOU PERISH!\n";
		}
	}

	if (w1.getMoves() == -2) {
		cout << "YOU WON THE GAME!! Well done!\n"
			<< "Try the harder versions now... if you dare!\n";
	}
	if(w1.getMoves() == -6) {
		cout << "Sorry you had to leave! Hope to see you again!\n";
	}
}
