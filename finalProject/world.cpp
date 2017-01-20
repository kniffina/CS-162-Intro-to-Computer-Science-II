/*************************************************************
* Filename: World.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/7/2016
* Description: This is the cpp file for the class World. It 
* contains the function implementatoin for the class and it
* also is where Item's, Cave's and Users will interact.
***************************************************************/
#include "world.hpp"
#include "caveEntrance.hpp"
#include "caveOfTheElders.hpp"
#include "forlornCavern.hpp"
#include "cavernOfTime.hpp"
#include "caveOfShadows.hpp"
#include "theForgottenPools.hpp"
#include "caveOfEternalDestiny.hpp"
#include "user.hpp"

#include <iostream>
using std::cout;
using std::cin;

//Constructor sets the world with caves. The caves
//are contained in a vector and
World::World()
{
	printOpener();

	//set moves to 20, this will be changed depending on what
	//difficulty the user chooses
	setMoves(30);

	//create 5 cave pointers
	Cave *c1, *c2, *c3, *c4, *c5, *c6, *c7;

	//create all of the Caves to be placed into the vector
	c1 = new CaveEntrance;
	c2 = new CaveOfTheElders;
	c3 = new ForlornCavern;
	c4 = new CavernOfTime;
	c5 = new CaveOfShadows;
	c6 = new TheForgottenPools;  
	c7 = new CaveOfEternalDestiny;

	//put the items into the caves Vector
	caves.push_back(c1);
	caves.push_back(c2);
	caves.push_back(c3);
	caves.push_back(c4);
	caves.push_back(c5);
	caves.push_back(c6);
	caves.push_back(c7);

	//point all of the caves to Other caves.
	//This will create a web like structure
	c1->setArray(c2, c3, c4, NULL);
	c2->setArray(c1, c3, c4, c5);
	c3->setArray(c1, c2, c4, c5);
	c4->setArray(c1, c2, c5, c6);
	c5->setArray(c2, c3, c4, c6);
	c6->setArray(c5, c7, NULL, NULL);
	c7->setArray(c6, NULL, NULL, NULL);

	//set the current pointer to the Cave entrance
	current = c1;
}

//destructor deallocates the memory that was previously reserved
World::~World()
{
	//looop through each item and delete
	for (vector<Cave*>::iterator i = caves.begin(); i != caves.end(); i++) {
		delete (*i);
	}
}

/******************************************************************
 * move function displays to the user what cave they are currently
 * in, and then displays to them what the other caves they can move 
 * to
 *****************************************************************/
void World::move()
{
	//set counter used to determine what number to press for user
	int counter = 1;

	//set Cave pointers to the current caves array. These are the
	//caves that are accessible from the current cave
	Cave *newc0 = current->returnCave0();
	Cave *newc1 = current->returnCave1();
	Cave *newc2 = current->returnCave2();
	Cave *newc3 = current->returnCave3();

	
	//these next if / else statements will let the user determine
	//what cave they want to move to next. Since the current pointer
	//is moving to 
	cout
		<< "==============================================\n"
		<< "===  What Cave would you like to move to?  ===\n"
		<< "==============================================\n";

	
	if (newc0 != NULL) {
		cout << " Enter '" << counter << "' To move to | " << newc0->getType() << "\n";
		counter++;//increment counter
	}
	else {
		cout << "\n";
		counter++;
	}
	if (newc1 != NULL) {
		cout << " Enter '" << counter << "' To move to | " << newc1->getType() << "\n";
		counter++;//increment counter
	}
	else {
		cout << "\n";
		counter++;
	}
	if (newc2 != NULL) {
		cout << " Enter '" << counter << "' To move to | " << newc2->getType() << "\n";
		counter++;//increment counter
	}
	else {
		cout << "\n";
		counter++;
	}
	if (newc3 != NULL) {
		cout << " Enter '" << counter << "' To move to | " << newc3->getType() << "\n";
		counter++;//increment counter
	}
	else {
		cout << "\n";
		counter++;
	}
	cout 
		<< "==============================================\n"
		<< "==============================================\n";

	//string will hold the choice that the user enters
	string choice;
	//bool to make sure user inputs a valid input
	bool done = false;
	while (done == false) {
		//allow user to enter where they want to move to
		cin >> choice; 


		
		if (choice == "1") {
			Cave *temp = current; //create temp cave pointer
			current = newc0; //move current cave pointer to new cave

			//the user can move to the new cave
			if (check() == true) {
				done = true;//set done to true, to exit loop
				cout << "== You are now in " << current->getType() << " ==\n\n"
					<< current->getExplanation() << "\n";
			}
			//user does not have item to get through to the other cave
			else { 
				current = temp; //move current back to the temp cave
				done = true;//get out of loop
			}
		}
		else if (choice == "2") {
			Cave *temp = current; //create temp cave pointer
			current = newc1; //move current cave pointer to new cave

			//the user can move to the new cave
			if (check() == true) { //keep current the way it is
				done = true;//set done to true, to exit loop
				cout << "== You are now in " << current->getType() << " ==\n\n"
					<< current->getExplanation() << "\n";
			}
			//user does not have item to get through to the other cave
			else { 
				current = temp; //move current back to the temp cave
				done = true;//get out of loop
			}
		}
		else if (choice == "3") {
			Cave *temp = current; //create temp cave pointer
			current = newc2; //move current cave pointer to new cave

			//the user can move to the new cave
			if (check() == true) { //keep current the way it is
				done = true;//set done to true, to exit loop
				cout << "== You are now in " << current->getType() << " ==\n\n"
					<< current->getExplanation() << "\n";
			}
			//user does not have item to get through to the other cave
			else { 
				current = temp; //move current back to the temp cave
				done = true;//get out of loop
			}
		}
		else if (choice == "4") {
			Cave *temp = current; //create temp cave pointer
			current = newc3; //move current cave pointer to new cave

			//the user can move to the new cave
			if (check() == true) { //keep current the way it is
				done = true;//set done to true, to exit loop
				cout << "== You are now in " << current->getType() << " ==\n\n"
					<< current->getExplanation() << "\n";
			}
			//user does not have item to get through to the other cave
			else { 
				current = temp; //move current back to the temp cave
				done = true;//get out of loop
			}
		}
		else {
			cout << "ERROR. Please enter a valid input to MOVE to.\n";
		}
	}
}

/******************************************************************
* play function allows the user to choose what they would like to do
* This is the heavy lifting function of all of the polymorphism done.
* In this function there is an output for what the game is, and the
* circumstances. The user Can then move around the Caves and pick
* up Items. The ultimate goal is to get to the Cave of Destiny where
* the user will be granted immortality and then the game will end.
* They must do this before the moves runs out. That is simulating the
* cave killing the user.
*****************************************************************/
void World::play()
{
	//string to hold users choice on what they choose to do
	string choice;
	cout
		<< "==========================================\n"
		<< " Current Cave  |  * " << current->getType() << " *\n"
		<< "==========================================\n"
		<< "===   What Would you like to Do?        ==\n"
		<< "==========================================\n"
		<< "   Enter '1' To look around the cave you  \n"
		<< "             are currently in.            \n"
		<< "   Enter '2' To move to a different cave  \n"
		<< "   Enter '3' To PRINT the contents of     \n"
		<< "             your BAG                     \n"
		<< "   Enter '4' To QUIT the game             \n"
		<< "==========================================\n"
		<< "==========================================\n";
	cout << "What would you like to do?\n";
	cin >> choice;

	if (choice == "1") {
		//create an Item pointer and call the current look
		//this will look through the cave that you are in and return
		//an Item pointer based on the direction you look
		Item *add = current->look();

		//if the position you look DOES NOT contain an Item
		if (add == NULL)
			cout << "\n== You look through the " << current->getType() << " but find NOTHING in that direction ==\n";

		else { //there IS an item in the direction you looked
			//the next 4 lines output to the user the name of the item, an explanatio of the
			//the item, and then asks them if they would like to add it to their bag.
			cout << "== You find a " << add->getName() << " in the " << add->getPosition()
				<< " of the room. ==\n\n" << "** " << add->getName() << " **\n " << "Explanation: "
				<< add->getExplanation() << "\n"
				<< "== Would you like to " << add->getName() << " this ITEM to your bag? ==\n"
				<< "== Enter '1' to ADD the item ==\n"
				<< "== Enter '2' to leave it where you found it ==\n";

			bool doneAddItem = false;
			string addItem;//string to let the user add the Item to the bag or not

			while (doneAddItem == false) {
				cin >> addItem; //allow user to enter what they want to do
				if (addItem == "1") {
					u1.addItem(add); //add the item to bag
					addItem = true; //break out of loop
					break;
				}
				else if (addItem == "2") {
					cout << "== Item not added to your Bag ==\n";
					addItem = true; //break out of loop
					break;
				}
				else {
					cout << "Enter '1' to ADD the Item. '2' to LEAVE  it\n";
				}
			}
		}
	}
	else if (choice == "2") {
		move();
	}
	else if (choice == "3") {
		//add move back since did not actually move or do anything
		this->moves++; 
		u1.print();
	}
	//user wants to quit
	else if (choice == "4") {
		string quit; //string to validate that they are going to quit
		cout << "Are you sure that you want to QUIT the game?\n"
			<< "Enter '1' to QUIT\n"
			<< "Enter '2' to CONTINUE your journey\n";
		cin >> quit;

		if (quit == "1") {
			setMoves(-5); //loses all of the moves
			cout << "Thank you for playing!\n";
		}
		else if (quit == "2") {
			this->moves = this->moves; //keep playing
		}
	}		
	this->moves--;//increment moves

	//condition at the end of the play function to see if the User has
	//made it to the final cave. This means they won
	if (current->getType() == "Cave of Eternal Destiny") {
		
		//set to -2 to tell the user they won!
		setMoves(-2);
	}
}

//check looks to see if the user has a key, or amount
//of points to move an object to get to a certain point
//in the game
bool World::check()
{
	//declare boolean value to return to the compiler
	bool toReturn;

	//check cave of shadows. You must have a skeleton
	//key to enter
	if (current->getType() == "Cave of Shadows") {
		bool allowEntrance = u1.checkBag(3);
		if (allowEntrance == true) {
			cout << "== You use the Skeleton Key to enter the Cave! ==\n";
			toReturn = true;
		}
		else {
			cout << "== You  must find the Skeleton Key to Enter! ==\n";
			toReturn = false;
		}
	}
	//check to see if the user can enter forgotten pools
	else if (current->getType() == "Forgotten Pools") {
		int strength = u1.getNumItems();
		if (strength >= 10) {
			cout << "== Your strength has GROWN. The Items are making you POWERFUL! ==\n"
				<< " == You PUSH the boulder blocking the Forgotten Pools, and enter the cave! ==\n";
			toReturn = true;
		}
		else {
			cout << "== A LARGE Bouler is blocking your path. You must grow in Strength ==\n"
				<< "==     by finding more Item's to enter this Cave                   ==\n";
			toReturn = false;
		}
	}
	//check to see if the user can enter cave of eternal destiny
	else if (current->getType() == "Cave of Eternal Destiny") {
		bool allowEntrance = u1.checkBag(14);
		if (allowEntrance == true) {
			cout << "== You use the Key of a Thousand Echoes to enter the Cave! ==\n";
			toReturn = true;
		}
		else {
			toReturn = false;
			cout << "== You  must find the Key of a Thousand Echoes to Enter! ==\n";
		}
	}
	else {
		toReturn = true;
	}
	//return what was inputted
	return toReturn;
}

//printOpener prints the opening paragraph which sets the stage
//for the game
void World::printOpener()
{
	cout << "You wake up and hear the pounding of war drums echoing loudly\n"
		<< "in the distance. Your biggest fear has come true. War is upon\n"
		<< "you and your people, and the worst part of all, NO-ONE is prepared for it\n\n"
		<< "You think back to your upbringing as a young ORC. Your father told you\n"
		<< "that one day this would happen, it was told to him by the prophet. Now that\n"
		<< "it is here, you can hardly believe it. Your capitol Orc City of Orgrimmar\n"
		<< "is not prepared. You know there is only one choice.\n\n"
		<< "YOU MUST ENTER THE LOST CAVES OF THE ORGRIMMAR LEGENDS.\n"
		<< "These caves are filled with extreme power for anyone who can find the\n"
		<< "the Cave of Destiny, but all who have tried, have fallen. This is your\n"
		<< "only hope, and as the leader of your people you must make the journey into\n"
		<< "the Caves. You know you must be quick though, or the Cave will DESTROY you \n"
		<< "as they have everyone else who has tried. Eventually the power that holds\n"
		<< "the cave will become your worst nightmare.\n\n"
		<< "You begin your journey to the Cave Entrance, but know that this must be a quick\n"
		<< "expedition. The fate of your life, and more importantly, the fate of your kin\n"
		<< "rest on your shoulders!\n";

}

//setMoves function takes an int parameter and sets it to the member
//variable moves
void World::setMoves(int move)
{
	this->moves = move;
}

//getMoves returns the number of moves available until the
//game is over
int World::getMoves()
{
	return this->moves;
}
