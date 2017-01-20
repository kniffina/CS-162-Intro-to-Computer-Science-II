/*************************************************************
* Filename: fibonacci.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 3/5/2016
* Description: This is the cpp file for the fibonacci functions.
* They will each be described in more detail below and their
* implemenation will also take place.
***************************************************************/
#include "fibonacci.hpp"
#include <iostream>

/************************************************************
 * recursive function takes an int parameter that is representative
 * of the sequence number in the fibonacci sequence that
 * is going to be returned. This function is derived from the link below.
 * http://stackoverflow.com/questions/1518726/recursive-fibonacci
 * I did not make this on my own, rather just changed a couple
 * of variable names. It finds the number in the fibonacci sequence
 * by making a function call to itself until the if / else 
 * statements are met and it cannot continue. 
 **********************************************************/
int recursive(int x)
{
	if (x == 0) //if the value of x = 0
		return 0; //return integer value 0

	else if (x == 1)
		return 1;

	//make a return call, calling the recursive function again
	//and subtracting its value by 1 and adding it to another 
	//recursive call, but with the x value subtracted by 2.
	return (recursive(x - 1) + recursive(x - 2));
}

/************************************************************
* iterative function takes an int parameter that is representative
* of the sequence number in the fibonacci sequence that
* is going to be returned. This function is derived from the link below.
* http://www.codeproject.com/Tips/109443/Fibonacci-Recursive-and-Non-Recursive-C
* I did not make this on my own, rather just changed a couple
* of variable names. It finds the number in the fibonacci sequence
* by walking through each number up until the sequence number
* equals the value sent into the program. The first and
* second value are added, and then returned to display the answer.
**********************************************************/
int iterative(int x)
{
	//create 3 variables that will represent the 
	//and second numbers in the fibonacci sequence
	int first = 0;
	int second = 1;

	//set counter to 2
	int counter = 2;

	//loop until the counter is equal to the x value
	while (counter < x) {
		int temp = second; //set a temp equal to second value
		second = first + second; //set second to first + second
		first = temp; //set first variable equal to temp
		counter++; //increment counter
	}

	if (x == 0) //if x int value is equal to 0
		return 0;

	else 
		return first + second;
}

