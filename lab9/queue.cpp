/*******************************************************************
* Filename: queue.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 3/3/2016
* Description: This file holds the implementation of the queue
* function. It will be described in more detail below. 
**********************************************************************/
#include "queue.hpp"
#include <iostream>
#include <algorithm>
#include <deque>

/***********************************************************
* Queue function declaration. Takes two ints as parameters. One
* represents the percent that a value will be added to the queue
* and the other represents the percent that the front value in
* the queue will be removed. A deque is passed in by reference
* as well. A random number is generated and is determined if
* it can be added to the deque by the percent chance. If it can
* then it is added. The same is done for the remove percent.
***********************************************************/
void Queue(int addPercent, int removePercent, deque<int> &q)
{
	//randomly generate a value that will be added
	//if it falls within the addPercent
	int randomAdd = rand() % 101;
	
	//create two random numbers and if they fall within
	//the percent chance, the random number is added / removed
	int addIntPercent = rand() % 101;
	int removeIntPercent = rand() % 101;
		
	//if the value is in the percetage chance
	if (addIntPercent > 0 && addIntPercent <= addPercent)
		q.push_back(randomAdd); //add the random value to the back	
	
	if (removeIntPercent > 0 && removeIntPercent <= removePercent)
		q.pop_front();//remove the front value
	
}