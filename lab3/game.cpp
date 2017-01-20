/*******************************************************************
* Program Filename: game.cpp
* Author: Adam Kniffin
* Date: 1/18/2016
* Description: This is the cpp file for the Game class. It contains function implementation
* each function will be described in more detail below.
* Input: none
* Output: none
*******************************************************************/
#include "game.hpp"
#include "die.hpp"
#include "loadedDie.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using std::string;
using std::cout;
using std::cin;

//default constructor. Sets the member variables to 0
Game::Game()
{
	setPlayer1Score(0);
	setPlayer2Score(0);
	setRounds(0);
}

/*************************************************************************
* playGame function allows the user to specify what type of Die they and the other player 
* will be using. Based on their response they can input the sides (if they choose to use a LoadedDie)
* and then enter how many rounds they want to play. The function displays the value
* of each roll, and then tallies up the score for each player. Once the function is 
* complete, the scores are compared and a winner is determined.
***************************************************************************/
void Game::playGame()
{

	srand(static_cast<unsigned int>(time(0)));

	string choice1;
	string loadedPlayer;
	string dieCombo;
	int size1;
	int size2;

	cout << "Welcome to the Die Rolling Game!\n" << "\nThere are two types of of Die available to use."
		<< "\nThe first is the normal 6 sided Die. If you are feeling unlucky, and think you need help\n"
		<< "You can use the 'LoadedDie'. The LoadedDie will let you specify how many sides you would like to play with.\n"
		<< "\nDo you want both players to play with normal Die? Both to play with LoadedDie? Or a combination?\n\n"
		<< "Type 'both' to use the standard Die for both players.\n" << "\nType 'loaded' to use two loaded die\n"
		<< "\nOr type 'either' if one will use a normal Die, and the other will use a LoadedDie.\n";

	cin >> choice1;

	bool flag = false;

	/*********************************************************************************
	 * while loop to validate that the user type in a correct game type. If they did type
	 * in a correct gametype that value will be stored in the string dieCombo variable.
	 * If they entered a wrong game type they will be forced enter a value until it matches,
	 * a variable that is accepted.
	 ******************************************************************************/
	while (flag == false)
	{
		if (choice1 == "both" || choice1 == "Both")
		{
			dieCombo = "twoDie";
			flag = true;
		}
		else if (choice1 == "loaded" || choice1 == "Loaded")
		{
			dieCombo = "doubleLoaded";
			flag = true;
		}
		else if (choice1 == "either" || choice1 == "Either")
		{
			dieCombo = "combo";
			cout << "What player do you want to have the loaded die?\n";
			cin >> loadedPlayer;

			//input validation to make sure they entered the correct player
			bool flag2 = false;
			if (loadedPlayer == "player1" || loadedPlayer == "Player1")
			{
				flag2 = true;
			}
			else if (loadedPlayer == "player2" || loadedPlayer == "Player2")
			{
				flag2 = true;
			}

			//this while loop is to validate that the user inputs a correct value for which 
			//user will be using a loaded die. It loops until they have entered a value that is
			//accepted.
			while (flag2 == false)
			{
				if (loadedPlayer == "player1" || loadedPlayer == "Player1")
				{
					flag2 = true;
				}
				else if (loadedPlayer == "player2" || loadedPlayer == "Player2")
				{
					flag2 = true;
				}
				else
				{
					flag2 = false;
					cout << "Please enter 'player1' or 'player2' to continue\n";
					cin >> loadedPlayer;
					flag2 = false;
				}
			}

			flag = true;
		}
		else
		{
			cout << "Please enter 'both' for two normal die, 'loaded' for two LoadedDie, or 'either' for a combination\n";
			cin >> choice1;
			flag = false;
		}
	}

	//if the user wants to play with 2 LoadedDie
	if (dieCombo == "doubleLoaded")
	{
		cout << "\nPlayer1 and Player2 are both using LoadedDie!\n";
		cout << "\nPlease enter the number of sides for player1's LoadedDie: \n";
		cin >> size1;
		cout << "\nNow please enter the sides for player2: \n";
		cin >> size2;
		//declare LoadedDie objects
		LoadedDie d1(size1);
		LoadedDie d2(size2);

		cout << "\nPlayer1 is using a LoadedDie with " << d1.getSides() << " total sides\n";
		cout << "\nPlayer2 is using a LoadedDie with " << d2.getSides() << " total sides\n";

		cout << "\nNow that the Die are set, how many rounds would you like to play?\n";
		cin >> rounds;
		cout << "\nWe will start the game now!";

		//initialize variables to 0 outside of the loop
		int p1pts = 0;
		int p2pts = 0;

		//set the flag to false. The loop will continue until rounds
		//reaches 0. At that point the score will be displayed and the winner will be
		//shown
		bool flag3 = false;

		int countDown = rounds;
		while (this->rounds > 0 && flag3 == false)
		{

			cout << "\n***We are now beginning round " << countDown - rounds + 1 << "***\n";
			//if it is the last round, we can declare that to the user
			if (rounds == 1)
			{
				cout << "\nThis is the last round of play!\n";
			}
			string nextRound;

			d1.rollDie();
			d2.rollDie();

			cout << "\nplayer1 rolled a " << d1.getSides() << "\n";
			cout << "\nplayer2 rolled a " << d2.getSides() << "\n";

			int diceRoll1 = d1.getSides();
			int diceRoll2 = d2.getSides();

			//compare the two dice rolls 
			if (diceRoll1 > diceRoll2)
			{
				//increment the points and set the player1Score 
				p1pts++;
				setPlayer1Score(p1pts);
				cout << "\nOne point for player1.\n";
			}

			else if (diceRoll1 < diceRoll2)
			{
				//increment the points and set the player2Score 
				p2pts++;
				setPlayer2Score(p2pts);
				cout << "\nOne point for player2.\n";
			}
			else
				cout << "\nBoth Die rolled the same number. No points for either player.\n";

			this->rounds--;

			//displays the score
			cout << "\nScore: \n" << "player1: " << getPlayer1Score()
				<< " points\n" "player2: " << getPlayer2Score() << " points\n\n";

			cout << "\nWhen you are ready for the next round, type 'N' or 'n' to continue.\nIf you want to quit, hit 'Q' or 'q'\n\n";
			cin >> nextRound;

			bool flag4 = false;
			while (flag4 = false)
			{
				if (nextRound == "N" || nextRound == "n")
					flag4 = true;
				else if (nextRound == "Q" || nextRound == "q")
				{
					flag4 = true;
					break;
				}
				else
				{
					cout << "You must of hit the wrong key! Type 'N' to continue or 'Q' to quit.\n";
					cin >> nextRound;
					flag4 = false;
				}
			}
		}
		//compare the scores to determine the winner
		if (getPlayer1Score() > getPlayer2Score())
		{
			cout << "\n\n\n******************************************** " << "\n**    Player1 is the Winner!    **\n"
				 << "*******************************************\n\n\n";
		}
		else if (getPlayer1Score() < getPlayer2Score())
		{
			cout << "\n\n\n******************************************** " << "\n**    Player2 is the Winner!    **\n"
				<< "********************************************\n\n\n";
		}
		else
		{
			cout << "\n\n\n******************************************** " << "\n**    The game ended in a tie!    **\n"
				<< "********************************************\n\n\n";
		}
	}		
	//This will play the game with two normal Die
	else if (dieCombo == "twoDie")
	{
		cout << "\nBoth players are using a normal 6 sided Die.\n";
		Die d1;
		Die d2;

		cout << "\nNow that the Die are set, how many rounds would you like to play?\n";
		cin >> rounds;
		cout << "\nWe will start the game now!";

		//initialize variables to 0 outside of the loop
		int p1pts = 0;
		int p2pts = 0;

		//set the flag to false. The loop will continue until rounds
		//reaches 0. At that point the score will be displayed and the winner will be
		//shown
		bool flag3 = false;

		int countDown = rounds;
		while (this->rounds > 0 && flag3 == false)
		{
			
			cout << "\n***We are now beginning round " << countDown - rounds + 1 << "***\n";
			//if it is the last round, we can declare that to the user
			if (rounds == 1)
			{
				cout << "\nThis is the last round of play!\n";
			}
			string nextRound;		

			d1.rollDie();
			d2.rollDie();

			cout << "\nplayer1 rolled a " << d1.getSides() << "\n";
			cout << "\nplayer2 rolled a " << d2.getSides() << "\n";

			int diceRoll1 = d1.getSides();
			int diceRoll2 = d2.getSides();

			//compare the two dice rolls 
			if (diceRoll1 > diceRoll2)
			{
				//increment the points and set the player1Score 
				p1pts++;
				setPlayer1Score(p1pts);
				cout << "\nOne point for player1.\n";
			}

			else if (diceRoll1 < diceRoll2)
			{
				//increment the points and set the player2Score 
				p2pts++;
				setPlayer2Score(p2pts);
				cout << "\nOne point for player2.\n";
			}
			else
				cout << "\nBoth Die rolled the same number. No points for either player.\n";

			this->rounds--;

			//displays the score
			cout << "\nScore: \n" << "player1: " << getPlayer1Score()
				<< " points\n" "player2: " << getPlayer2Score() << " points\n\n";

			cout << "\nWhen you are ready for the next round, type 'N' or 'n' to continue.\nIf you want to quit, hit 'Q' or 'q'\n\n";
			cin >> nextRound;

			bool flag4 = false;
			while (flag4 = false)
			{
				if (nextRound == "N" || nextRound == "n")
					flag4 = true;
				else if (nextRound == "Q" || nextRound == "q")
				{
					flag4 = true;
					break;
				}
				else
				{
					cout << "\nYou must of hit the wrong key! Type 'N' to continue or 'Q' to quit.\n";
					cin >> nextRound;
					flag4 = false;
				}
			}		
		}
		//compare the scores to determine the winner
		if (getPlayer1Score() > getPlayer2Score())
		{
			cout << "\n\n\n******************************************** " << "\n**    Player1 is the Winner!    **\n"
				<< "*******************************************\n\n\n";
		}
		else if (getPlayer1Score() < getPlayer2Score())
		{
			cout << "\n\n\n******************************************** " << "\n**    Player2 is the Winner!    **\n"
				<< "********************************************\n\n\n";
		}
		else
		{
			cout << "\n\n\n******************************************** " << "\n**    The game ended in a tie!    **\n"
				<< "********************************************\n\n\n";
		}
	}
	else if (dieCombo == "combo")
	{
		//determine's which player will use a loadedDie
		if (loadedPlayer == "player1" || loadedPlayer == "Player1")
		{
			cout << "You have specified that " << loadedPlayer << " will have a LoadedDie\n";

			cout << "\nPlease enter the number of sides for player1's LoadedDie: \n";
			cin >> size1;
			//declare LoadedDie objects
			LoadedDie d1(size1);
			Die d2;
		

			cout << "\nPlayer1 is using a LoadedDie with " << d1.getSides() << " total sides\n";
			cout << "\nPlayer2 is using a normal Die with " << d2.getSides() << " total sides\n";

			cout << "\nNow that the Die are set, how many rounds would you like to play?\n";
			cin >> rounds;
			cout << "\nWe will start the game now!";

			int p1pts = 0;
			int p2pts = 0;

			//set the flag to false. The loop will continue until rounds
			//reaches 0. At that point the score will be displayed and the winner will be
			//shown
			bool flag3 = false;

			int countDown = rounds;
			while (this->rounds > 0 && flag3 == false)
			{

				cout << "\n***We are now beginning round " << countDown - rounds + 1 << "***\n";
				//if it is the last round, we can declare that to the user
				if (rounds == 1)
				{
					cout << "\nThis is the last round of play!\n";
				}
				string nextRound;

				d1.rollDie();
				d2.rollDie();

				cout << "\nplayer1 rolled a " << d1.getSides() << "\n";
				cout << "\nplayer2 rolled a " << d2.getSides() << "\n";

				int diceRoll1 = d1.getSides();
				int diceRoll2 = d2.getSides();

				//compare the two dice rolls 
				if (diceRoll1 > diceRoll2)
				{
					//increment the points and set the player1Score 
					p1pts++;
					setPlayer1Score(p1pts);
					cout << "\nOne point for player1.\n";
				}

				else if (diceRoll1 < diceRoll2)
				{
					//increment the points and set the player2Score 
					p2pts++;
					setPlayer2Score(p2pts);
					cout << "\nOne point for player2.\n";
				}
				else
					cout << "\nBoth Die rolled the same number. No points for either player.\n";

				this->rounds--;

				//displays the score
				cout << "\nScore: \n" << "player1: " << getPlayer1Score()
					<< " points\n" "player2: " << getPlayer2Score() << " points\n\n";

				cout << "\nWhen you are ready for the next round, type 'N' or 'n' to continue.\nIf you want to quit, hit 'Q' or 'q'\n\n";
				cin >> nextRound;

				bool flag4 = false;
				while (flag4 = false)
				{
					if (nextRound == "N" || nextRound == "n")
						flag4 = true;
					else if (nextRound == "Q" || nextRound == "q")
					{
						flag4 = true;
						break;
					}
					else
					{
						cout << "You must of hit the wrong key! Type 'N' to continue or 'Q' to quit.\n";
						cin >> nextRound;
						flag4 = false;
					}
				}
			}
			//compare the scores to determine the winner
			if (getPlayer1Score() > getPlayer2Score())
			{
				cout << "\n\n\n******************************************** " << "\n**    Player1 is the Winner!    **\n"
					<< "*******************************************\n\n\n";
			}
			else if (getPlayer1Score() < getPlayer2Score())
			{
				cout << "\n\n\n******************************************** " << "\n**    Player2 is the Winner!    **\n"
					<< "********************************************\n\n\n";
			}
			else
			{
				cout << "\n\n\n******************************************** " << "\n**    The game ended in a tie!    **\n"
					<< "********************************************\n\n\n";
			}


		}
		//determine's which player will use a loadedDie
		if (loadedPlayer == "player2" || loadedPlayer == "Player2")
		{
			cout << "You have specified that " << loadedPlayer << " will have a LoadedDie\n";
			cout << "\nPlease enter the number of sides for player2's LoadedDie: \n";
			cin >> size1;

			//declare LoadedDie objects
			Die d1;
			LoadedDie d2(size1);


			cout << "\nPlayer1 is using a normal Die with " << d1.getSides() << " total sides\n";
			cout << "\nPlayer2 is using a LoadedDie with " << d2.getSides() << " total sides\n";

			cout << "\nNow that the Die are set, how many rounds would you like to play?\n";
			cin >> rounds;
			cout << "\nWe will start the game now!";

			int p1pts = 0;
			int p2pts = 0;

			//set the flag to false. The loop will continue until rounds
			//reaches 0. At that point the score will be displayed and the winner will be
			//shown
			bool flag3 = false;

			int countDown = rounds;
			while (this->rounds > 0 && flag3 == false)
			{

				cout << "\n***We are now beginning round " << countDown - rounds + 1 << "***\n";
				//if it is the last round, we can declare that to the user
				if (rounds == 1)
				{
					cout << "\nThis is the last round of play!\n";
				}
				string nextRound;

				d1.rollDie();
				d2.rollDie();

				cout << "\nplayer1 rolled a " << d1.getSides() << "\n";
				cout << "\nplayer2 rolled a " << d2.getSides() << "\n";

				int diceRoll1 = d1.getSides();
				int diceRoll2 = d2.getSides();

				//compare the two dice rolls 
				if (diceRoll1 > diceRoll2)
				{
					//increment the points and set the player1Score 
					p1pts++;
					setPlayer1Score(p1pts);
					cout << "\nOne point for player1.\n";
				}

				else if (diceRoll1 < diceRoll2)
				{
					//increment the points and set the player2Score 
					p2pts++;
					setPlayer2Score(p2pts);
					cout << "\nOne point for player2.\n";
				}
				else
					cout << "\nBoth Die rolled the same number. No points for either player.\n";

				this->rounds--;

				//displays the score
				cout << "\nScore: \n" << "player1: " << getPlayer1Score()
					<< " points\n" "player2: " << getPlayer2Score() << " points\n\n";

				cout << "\nWhen you are ready for the next round, type 'N' or 'n' to continue.\nIf you want to quit, hit 'Q' or 'q'\n\n";
				cin >> nextRound;

				bool flag4 = false;
				while (flag4 = false)
				{
					if (nextRound == "N" || nextRound == "n")
						flag4 = true;
					else if (nextRound == "Q" || nextRound == "q")
					{
						flag4 = true;
						break;
					}
					else
					{
						cout << "You must of hit the wrong key! Type 'N' to continue or 'Q' to quit.\n";
						cin >> nextRound;
						flag4 = false;
					}
				}
			}
			//compare the scores to determine the winner
			if (getPlayer1Score() > getPlayer2Score())
			{
				cout << "\n\n\n******************************************** " << "\n**    Player1 is the Winner!    **\n"
					<< "*******************************************\n\n\n";
			}
			else if (getPlayer1Score() < getPlayer2Score())
			{
				cout << "\n\n\n******************************************** " << "\n**    Player2 is the Winner!    **\n"
					<< "********************************************\n\n\n";
			}
			else
			{
				cout << "\n\n\n******************************************** " << "\n**    The game ended in a tie!    **\n"
					<< "********************************************\n\n\n";
			}


		}
	}
}
/*********************************************************************
 * The next three functions are the set functions for the Game class. They 
 * both take an integer as parameters and set the corresponding member variable
 * equal to the value passed in.
 ********************************************************************/
void Game::setPlayer1Score(int s)
{
	this->player1Score = s;
}

void Game::setPlayer2Score(int s)
{
	this->player2Score = s;
}

void Game::setRounds(int r)
{
	this->rounds = r;
}

/*********************************************************************
* The next two functions are the getfunctions for the Game class. They both 
* take no parameters. They both return their respective player score variable.
********************************************************************/
int Game::getPlayer1Score()
{
	return this->player1Score;
}

int Game::getPlayer2Score()
{
	return this->player2Score;

}

int Game::getRounds()
{
	return this->rounds;
}
