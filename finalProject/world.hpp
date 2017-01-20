/*************************************************************
* Filename: world.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/11/2016
* Description: This is the hpp file for the class World. It 
* contains memebr variables, function declarations, and constructors.
* This class is where the game will take place, and where the 
* classes of Cave, User, and Item will live.
***************************************************************/
#include "cave.hpp"
#include "user.hpp"

#ifndef WORLD_HPP
#define WORLD_HPP

class World
{
private:
	//integer to hold the number of moves made by the user
	int moves;

	//declare user Object 
	User u1;

	//world holds a vector of cave pointers
	vector<Cave *> caves;

	//declare user pointer to move through vector
	Cave *current;
public:
	//constructor
	World();

	//destructor
	~World();

	//move function allows the user to move through the caves
	void move();

	//allows the user to play the game
	void play();

	//this will be used to check the user for certain items
	//and points to enter a room
	bool check();

	//sets number of moves based on what the user wants
	void setMoves(int);

	//returns the number of moves
	int getMoves();

	//prints openeing paragraph
	void printOpener();


};

#endif