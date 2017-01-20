/*******************************************************************
* Program Filename: game.hpp
* Author: Adam Kniffin
* Date: 1/18/2016
* Description: This is the hpp file for the Game class. It contains
* member variables, function declarations, and other functions that are useful
* for the class. It inherits from the Die class.
* Input: This is an hpp file, there is no input.
* Output: No output
*******************************************************************/
#ifndef GAME_HPP
#define GAME_HPP
#include "die.hpp"
#include "loadedDie.hpp"

class Game : public Die
{
private:
	int player1Score;
	int player2Score;
	int rounds;
public:
	//default constructor
	Game();

	//set functions
	void setPlayer1Score(int);
	void setPlayer2Score(int);
	void setRounds(int);

	//get functions
	int getPlayer1Score(); 
	int getPlayer2Score();
	int getRounds();

	void playGame();

};

#endif
