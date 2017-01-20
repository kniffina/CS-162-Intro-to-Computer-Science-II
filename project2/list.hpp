/*************************************************************
* Filename: List.hpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Date: 1/28/2016
* Description: This is the hpp file for class List.
* It contains constructors, member variables, and other useful
* functions that are being declared.
* Input: none
* Output: none
***************************************************************/
#include "item.hpp"
#ifndef LIST_HPP
#define LIST_HPP

class List
{
private:
	//Pointer to Item
	Item *array;

	//holds the number of items in the array
	int numOfItems;

	//need a maxSize int variable to keep track of
	//how large of an array it needs to be
	int maxSize;
public:
	//default constructor
	List();

	//other functions
	void addItem(); //returns void. Parameters Item by reference
	void removeItem();  //returns void. Parameters Item by reference
	void displayList();//no parameters, does not return anything

};

#endif