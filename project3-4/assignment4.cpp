/*************************************************************
* Filename: assignment4.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 2/27/2016
* Description: This is main file for the Creature and its child classes.
* It allows the user to enter how many Creatures per team they will use
* and then the lineup of each team are fought against one another. Each Creature
* gets a point for winning and is put iinto the winners bracket. The winners bracket
* is then put against one another until there is a final winner. 
* Input: User chooses creatures and how many Creatures per team. 
* Output: The winners of each rounds are outputted. Then once all the Creatures
* have been defeated and there is a winner, the third, second, and first place finishers
* are outputted. Then the team that had more points is outputted.
***************************************************************/
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
using std::string;
using std::cout;
using std::cin;
#include "stack.hpp"
#include "creature.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "bluemen.hpp"
#include "harrypotter.hpp"

void displayMenu();//declare function to display the options to the user

int main()
{	
	//declare the list to keep track of what Creature is on what team
	Stack team1;
	Stack team2;
	Stack winner;//declare a winner bracket
	Stack loser;//declare loser bracket
	Stack thirdPlace;//declare a stack to keep track of third place Creatures

	srand(static_cast<unsigned int>(time(NULL)));
	
	int numOfCreatures;//variable to hold the number of creatures
	cout << "*** Welcome to the Creature vs Creature Tournament!!! ***\n\n"
		<< "*  In this program you will have the ability to pick a team of creatures and \n"
		<< "*  fight them against another team of Creatures.\n\n";
	cout << "  -  Step 1  -  Choose how many Creatures per team!\n"
		<< "  -  Step 2  -  Each player will choose the Creatures they want on their team\n"
		<< "  -  Step 3  -  Sit back and see if you chose the best Creatures. The computer\n"
		<< "		simulate the rounds and display which Creature won against the other.\n"
		<< "                The points will be tallied and after the Tournament has concluded the\n"
		<< "                winner will be displayed!\n"
		<< " - In order for the brackets to be fair you must choose an even number of Creatures that\n"
		<< "   is a factorial of 2 up to 32(I.E. 2, 4, 8, 16, 32)\n"
		<< "\n***   Enter number of Creatures per team:  ***\n";
	cin >> numOfCreatures;

	bool even = false;
	while (even == false)//make sure the user entered a value that is acceptable
	{
		if (numOfCreatures == 2 || numOfCreatures == 4 || numOfCreatures == 8 || numOfCreatures == 16 || numOfCreatures == 32)
			even = true;//value is accepted and can exit loop
		else//value is not accepted
		{
			cout << "***   Please enter a number of Creatures that is a factorial of 2 (I.E. 2, 4, 8, 16, or 32)   ***\n";
			cin >> numOfCreatures;
		}
	}

	cout << "Here are your choices of Creatures!\n\n";
	displayMenu();//display creatures so User can decide what they want on their team

	//create new variable to hold number of Creatures per team for playe 2 to decrement as well
	int numOfCreatures2 = numOfCreatures;

	cout << "Player 1 will now add the Creatures of their choosing to their team\n";
	while (numOfCreatures > 0)
	{
		string choice1;//string variable to hold user input
		cout << "Enter the Creatures you would like to add to your Roster!\n";
		cin >> choice1;

		if (choice1 == "1")//Barbarian
		{
			team1.add(new Barbarian);
			numOfCreatures--;//decrement number of creatures
			cout << "You have selected Barbarian to add to the team 1 roster!\n";
		}
		else if (choice1 == "2")//Medusa
		{
			team1.add(new Medusa);//create new Medusa Object and put it in the back of the list
			numOfCreatures--;
			cout << "You have selected Medusa to add to the team 1 roster\n";
		}
		else if (choice1 == "3")//Vampire
		{
			team1.add(new Vampire);//create new Medusa Object and put it in the back of the list
			numOfCreatures--;
			cout << "You have selected Vampire to add to the team 1 roster\n";
		}
		else if (choice1 == "4")//Blue Men
		{
			team1.add(new BlueMen);//create new Medusa Object and put it in the back of the list
			numOfCreatures--;
			cout << "You have selected BlueMen to add to the team 1 roster\n";
		}
		else if (choice1 == "5")//Harry Potter
		{
			team1.add(new HarryPotter);//create new Medusa Object and put it in the back of the list
			numOfCreatures--;
			cout << "You have selected Harry Potter to add to the team 1 roster\n";
		}
		else if (choice1 == "Q" || choice1 == "q")
		{
			cout << "Thank you for playing! Goodbye!\n";
			break;//they have quit
		}
		else//No Creatures matched the users input
			cout << "***  ERROR No Creature matches your input. Please enter a valid Creature!  ***\n";		
	}
	cout << "\n\n    This is Team 1's Creature Lineup: ";
	team1.print();
	cout << "\n";


	displayMenu();
	cout << "\nPlayer 2 will now add the Creatures of their choosing to their team\n";
	while (numOfCreatures2 > 0)
	{
		string choice1;
		cout << "Enter the Creatures you would like to add to your Roster!\n";
		cin >> choice1;

		if (choice1 == "1")//Barbarian
		{
			team2.add(new Barbarian);
			numOfCreatures2--;//decrement number of creatures
			cout << "You have selected Barbarian to add to the team 1 roster!\n";
		}
		else if (choice1 == "2")//Medusa
		{
			team2.add(new Medusa);//create new Medusa Object and put it in the back of the list
			numOfCreatures2--;
			cout << "You have selected Medusa to add to the team 1 roster\n";
		}
		else if (choice1 == "3")//Vampire
		{
			team2.add(new Vampire);//create new Medusa Object and put it in the back of the list
			numOfCreatures2--;
			cout << "You have selected Vampire to add to the team 1 roster\n";
		}
		else if (choice1 == "4")//Blue Men
		{
			team2.add(new BlueMen);//create new Medusa Object and put it in the back of the list
			numOfCreatures2--;
			cout << "You have selected BlueMen to add to the team 1 roster\n";
		}
		else if (choice1 == "5")//Harry Potter
		{
			team2.add(new HarryPotter);//create new Medusa Object and put it in the back of the list
			numOfCreatures2--;
			cout << "You have selected Harry Potter to add to the team 1 roster\n";
		}
		else if (choice1 == "Q" || choice1 == "q")
		{
			cout << "Thank you for playing! Goodbye!\n";
			break;//they have quit
		}
		else //error on the input and nothing matches the Creature option they chose
			cout << "***  ERROR No Creature matches your input. Please enter a valid Creature!  ***\n";

		
	}
	cout << "\n\n     This is Team 2's Creature Lineup: ";
	team2.print();
	cout << "\n";

	int rounds = 1;//use integer to display the rounds
	bool done = false;//declare bool value to loop through first round of matchups

	//this is the first round matchup loop that will determine who is put into the loser and winner brackets
	while (done == false)
	{
		Creature *c1;//declare two Creature pointers
		Creature *c2;
		c1 = team1.top();//set them equal to the top of the
		c1->setTeam("team1");//set their member variable to team1. This will be used later.
		c2 = team2.top();//set c2 = to Creature at top of the list
		c2->setTeam("team2");//set member variable to team2. This will be used later
		cout
			<< "**********************************************\n"
			<< "**     Round " << rounds << "  " << c1->getType() << " vs  " << c2->getType() << "      **\n"
			<< "**********************************************\n";
		//while loop attacks until a Creature has been defeated.
		while (c1->getStatus() == "alive" && c2->getStatus() == "alive")
		{
			int attack1 = c1->attack();
			c2->defense(attack1);

			int attack2 = c2->attack();
			c1->defense(attack2);
		}
		if (c1->getStatus() == "alive")//team ones player won
		{
			team1.incrementScore();//add a point to the Creature for winning
			c1->incrementPoints();//increment the points for the creature object
			winner.add(c1);//add them to the winner bracket
			loser.add(c2);//add other Creature to loser bracket
			cout << c1->getType() << " has won! 1 Point for team 1!\n";
		}
		else//team twos player won
		{
			team2.incrementScore();//add a point to the Creature for winning
			c2->incrementPoints();//increment the points for the creature object
			winner.add(c2);//add winner to the winner bracket
			loser.add(c1);//add other Creature to loser bracket
			cout << c2->getType() << " has won! 1 Point for team 2!\n";
		}
		//heal both of the Creatures so they can fight again with full health
		c1->heal();
		c2->heal();
		//remove the Creatures from the list since they have been added to the winner / loser pile
		team1.remove();
		team2.remove();
		//display the Rounds and the current score
		cout << "\n+-----------------------------------------------------------------+\n\n";
		cout
			<< "************************************************\n"
			<< "*******		End of Round " << rounds << "		 *******\n"
			<< "************************************************\n\n";

		cout << "***************************************\n"
			<< "*	    | ScoreBoard |            *\n"
			<< "*  | Team 1 |            | Team 2 |   *\n"
			<< "*  |   " << team1.getScore() << "    |            |   " << team2.getScore() << "    |   *\n"
			<< "***************************************\n\n";

		if (team1.top() == NULL)//no more creatures to fight
		{
			done = true;
			break;
			cout << "\n****   End of the first round of the tournament. We will now start the winner and loser brackets!\n   ****";
		}

		string continueFighting;
		cout << "Hit 'N' to start the next round!\n";
		cin >> continueFighting;

		bool errors = false;//create flag for user validation while loop
		while (errors == false)//loop until user enters valid input
		{
			if (continueFighting == "N" || continueFighting == "n")
				errors = true; //end loop

			else
			{
				cout << "Please enter 'N' to see the next round action!\n";
				cin >> continueFighting;//enter N to continue
				errors = false;//continue the loop until the user enters N
			}
		}//end errors while loop
		rounds++; //increment rounds					
	}//end first round

	cout << "\n\nAfter the first round of play the winners bracket is: ";
	winner.print();
	cout << "\nAnd the losers bracket is: ";
	loser.print();
	cout << "\n";

	string winnersRound;//allow user to enter when they want the winner round to start
	cout << "Hit 'N' to start the WINNERS ROUND(S)!\n";
	cin >> winnersRound;
	bool error = false;//create flag for user validation while loop
	while (error == false)//loop until user enters valid input
	{
		if (winnersRound == "N" || winnersRound == "n")
			error = true; //end loop

		else
		{
			cout << "Please enter 'N' to start the WINNERS ROUND(S)!\n";
			cin >> winnersRound;//enter N to continue
			error = false;//continue the loop until the user enters N
		}
	}//end errors while loop

	int rounds2 = 1;//declare new integer variable for rounds
	bool game = false;//creater variable 
	while (game == false)
	{
		Creature *w1;//creater Creature pointer and set it to the top of th
		w1 = winner.top();//declare w1 equal to top
		winner.remove();//remove them from the winner bracket until it is decided if they won
		Creature *w2;
		w2 = winner.top();//set w2 to the new top Creature
		winner.remove();//remove them from the winner bracket until it is decided if they won

		cout
			<< "*******************************************************\n"
			<< "*  -Winner Bracket - Round " << rounds2 << " -  " << w1->getType() << " vs  " << w2->getType() << "  *\n"
			<< "*******************************************************\n";
		//while loop attacks until a Creature has been defeated.
		while (w1->getStatus() == "alive" && w2->getStatus() == "alive")
		{
			int attack1 = w1->attack();
			w2->defense(attack1);

			int attack2 = w2->attack();
			w1->defense(attack2);
		}
		if (w1->getStatus() == "alive")//team ones player won
		{
			w1->incrementPoints();//increment the points for the creature object
			loser.add(w2);//w2 lost so send them to the holding list
			winner.add(w1);//add w1 back to the winner bracket
			winner.moveToFront();//it is at the top of the list and can be sent to the back

			if (w1->getTeam() == "team1")//if the Creature is apart of team1
			{
				team1.incrementScore();//increment score of correct team
				cout << w1->getType() << " has won! 1 Point for team 1!\n";
			}
			else//creature is apart of team2
			{
				team2.incrementScore();//increment score of correct team
				cout << w1->getType() << " has won! 1 Point for team 2!\n";
			}	
		}
		else//team twos player won
		{
			w2->incrementPoints();//increment the points for the creature object
			loser.add(w1);//w1 lost so send them to the holding list
			winner.add(w2);//add w2 back to the winner bracket
			winner.moveToFront();//it is at the top of the list and can be sent to the back

			if (w2->getTeam() == "team1")
			{
				team1.incrementScore();//increment points for team 1
				cout << w2->getType() << " has won! 1 Point for team 1!\n";
			}
			else
			{
				team2.incrementScore();//increment points for team 2
				cout << w2->getType() << " has won! 1 Point for team 2!\n";
			}
		}
		//heal the Creatures for later rounds
		w1->heal();
		w2->heal();
		//display the Rounds and the current score
		cout << "\n+-----------------------------------------------------------------+\n\n";
		cout
			<< "************************************************\n"
			<< "*******		End of Round " << rounds2 << "		 *******\n"
			<< "************************************************\n\n";
		cout << "***************************************\n"
			<< "*	    | ScoreBoard |            *\n"
			<< "*  | Team 1 |            | Team 2 |   *\n"
			<< "*  |   " << team1.getScore() << "    |            |   " << team2.getScore() << "    |   *\n"
			<< "***************************************\n\n";

		if (winner.getNumCreatures() <= 1)//no more Creatures to fight
		{
			game = true;//escape the winners bracket
			break;
		}

		string continueFighting;//string to allow the user to enter Next round
		cout << "Hit 'N' to start the next round!\n";
		cin >> continueFighting;

		bool errors = false;//create flag for user validation while loop
		while (errors == false)//loop until user enters valid input
		{
			if (continueFighting == "N" || continueFighting == "n")
				errors = true; //end loop

			else//didnt hit N to continue
			{
				cout << "Please enter 'N' to see the next round action!\n";
				cin >> continueFighting;//enter N to continue
				errors = false;//continue the loop until the user enters N
			}
		}//end errors while loop
		rounds2++; //increment rounds					
	}

	//sort the loser list into ascending order
	loser.sort();

	Creature * second = loser.top();//second place will always be Creature on top of loser pile
	loser.remove();//take that value out of the loser pile so we can determine the third place finishers

	Creature *third = loser.top();//the first third place finisher is now on top of the loser list
	thirdPlace.add(third);//add them to the thirdPlace list
	loser.remove();//remove the value from the top

	//need to loop through the rest of the losers bracket to determine if the values are equal to the top
	//value and then add them to the third place finishers because there are ties
	bool getThirdPlace = false;//bool to loop until all the third place finishers are determined
	while (getThirdPlace == false)
	{
		if (loser.top() == NULL)//no more elements in the loser list
			getThirdPlace = true;//end loop because no other Creatures equal the third place finisher

		else
		{
			Creature *alsoThird = loser.top();//set also third to the top of loser list
			if (alsoThird->getPoints() == third->getPoints())//if the two Creature points equal eachother
			{
				thirdPlace.add(alsoThird);//add the value to the thirdPlace pile
				loser.remove();//remove it from the loser so we can check the next value
			}
			else
				getThirdPlace = true;//end loop because no other Creatures equal the third place finisher
		}
	}

	string seeCreature;//string to hold user input
	bool seeCreatureWin = false;//declare string for user input
	cout << "\nThat was the final round of play! We have determined our winners and losers!\n\n"
		<< "Hit 'N' to see which Creature is our WINNER\n";
	cin >> seeCreature; 
	int round = 0;//create round to use so we can display winner incrementally
	bool creatureWin = false; //set bool false for final loop to display winners and losers
	while (round <= 2)//loop until user enters valid input
	{
		if (seeCreature == "N" || seeCreature == "n")
		{
			if (round == 0)
			{
				cout << "\n***  Our THIRD PLACE finishers are: ";
				thirdPlace.print();//output the Creatures who are in third place
				cout << "\n";
				cout << "\nHit 'N' to see our SECOND PLACE finisher!\n";
				cin >> seeCreature;
				round++;
			}
			else if (round == 1)
			{
				cout << "\n***  Our RUNNER UP and second place finisher is " << second->getType() << "  ***\n";
				round++;//increment round
				cout << "\nHit 'N' to see our GRAND WINNER!\n";
				cin >> seeCreature; 
			}
			else if(round == 2)
			{
				Creature *win = winner.top();//set win Creature to element left in winner pool
				cout << "\n***************************************************************\n"
					<< "*   The Winner of the Creature Tournament is " << win->getType() << "!!  *\n"
					<< "***************************************************************\n";
				round++;//increment rounds. This will remove us from forloop
			}
		}
		else//didnt hit N to continue
		{
			cout << "\nPlease enter 'N' to the FINAL RESULTS OF THE WINNERS BRACKET!!\n";
			cin >> seeCreature;//enter N to continue
		}
	}

	string userInput;//declare string for user input
	cout << "\nNOW IT IS TIME TO SEE WHICH TEAM WON THE TOURNAMENT!\n\n"
		<< "Hit 'N' to FIND OUT!!!\n";
	cin >> userInput;

	bool seeScores = false; //set bool false for final loop to display winners and losers
	while (seeScores == false)//loop until user enters valid input
	{
		if (userInput == "N" || userInput == "n")
		{
			seeScores = true; //end loop
			cout << "***************************************\n"
				<< "*	    | ScoreBoard |            *\n"
				<< "*  | Team 1 |            | Team 2 |   *\n"
				<< "*  |   " << team1.getScore() << "    |            |   " << team2.getScore() << "    |   *\n"
				<< "***************************************\n\n";

			//display which team won (incase the user couldnt figure it out)
			if (team1.getScore() > team2.getScore())//team1 had more points
			{
				cout << "****************************\n"
					 << "**     TEAM 1 WINS!!!     **\n"
					 << "****************************\n\n";
			}
			else//team 2 had more points
			{
				cout << "****************************\n"
					 << "**     TEAM 2 WINS!!!     **\n"
					 << "****************************\n\n";
			}
		}
		else//didnt hit N to continue
		{
			cout << "Please enter 'N' to see which team won!!\n";
			cin >> userInput;//enter N to continue
			seeScores = false;//continue the loop until the user enters N
		}
	}
	return 0;
}

//this function is used to display the menu options to the user
void displayMenu()
{
	cout
		<< " - 1 -   ***   Barbarian - No special ability, but is a BRAWLER!   ***\n"
		<< " - 2 -   ***   Medusa - Glare ability that instantly DESTROYS the enemy!   ***\n"
		<< " - 3 -   ***   Vampire - Charm ability which cancels the enemy's attack!   ***\n"
		<< " - 4 -   ***   Blue Men - Are a group of little Blue Men that fight together to conquer the enemy!   ***\n"
		<< " - 5 -   ***   Harry Potter - Can he live FOREVER?!?!?   ***\n"
		<< " - Q -   ***   Quit - By hitting Q you will exit the game   ***\n\n";
}
	
	

