/*******************************************************************
* Filename: queue.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 3/3/2016
* Description: This is the header file for Queue function. It takes 2
* integer values, and a int deque passe in b
**********************************************************************/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

/***********************************************************
 * Queue function declaration. Takes two ints as parameters. One
 * represents the percent that a value will be added to the queue
 * and the other represents the percent that the front value in 
 * the queue will be removed. A deque is passed in by reference
 * as well. 
 ***********************************************************/
void Queue(int addPercent, int removePercent, deque<int> &q);