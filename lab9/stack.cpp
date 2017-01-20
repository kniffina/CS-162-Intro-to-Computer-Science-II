/*******************************************************************
* Filename: stack.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 3/4/2016
* Description: This file contains the implementation of the stack function.
* it will be described in more detail below.
**********************************************************************/
#include "stack.hpp"
#include <iostream>
#include <string>
#include <algorithm>
using std::string;

/***********************************************************************
 * stack function takes a string reference as its parameter. The function
 * creates a copy of the string value passed in. It then reverses the
 * string and adds it to the end of the value passed in. The reference
 * value then adds the reversed string to it, to make a palindrome
 * and that value is returned.
 ***********************************************************************/
string stack(string &first)
{
	//create second string from reference value
	string second = first;
	
	//reverse the string created
	std::reverse(second.begin(), second.end());

	//add it to the end of the value passed in.
	//This creates a palindrome
	first = first + second;

	//return the value
	return first;

}