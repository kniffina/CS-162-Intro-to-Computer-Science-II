/*************************************************************
* Filename: lab4.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 1/28/2016
* Description: This is the hpp file for lab4.cpp. It contains guards,
* and function declarations.
* detail below.
* Input: none
* Output: none
***************************************************************/
#include <iostream>
using std::string;

#ifndef LAB4_HPP
#define LAB4_HPP

//reverString takes an int param and returns a string
string reverseString(string);

//arraySum takes an int, and an int array as parameters and returns an int
int arraySum(int, int []);

//triangleCalc takes an int as params and returns and int value
int triangularCalc(int);

#endif
