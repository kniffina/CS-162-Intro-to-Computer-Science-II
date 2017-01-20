/*******************************************************************
* Filename: lab7.cpp
* Email: kniffina@oregonstate.edu
* Author: Adam Kniffin
* Email: kniffina@oregonstate.edu
* Date: 2/20/2016
* Description: This is the cpp file for lab7 of CS 162. It contains three function
* declarations, binarySearch, bubbleSort, linearSearch. Each of these functions take
* an integer array, int size, and int value, as its parameters. If the value
* is found, it is returned, if it is not -1 is returned. For bubbleSort,
* when the function is called and the parameters are filled, the array passed in
* is sorted in ascending order. The main program lets the user choose from 3 different text documents
* each with the number zero at the beginning, middle, or end of the document. It then
* lets the user choose which sort of search they would like to use.
**********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using namespace std;


//declare linearSearch function. 
int linearSearch(int arr[], int size, int value);

//declare binarySearch function.
int binarySearch(int arr[], int size, int value);

//declare bubbleSort function
void bubbleSort(int a[], int size);

//main function allows user to dictate what they want to do 
int main()
{
	int array[20];//declare an array of 20 integer values
	int i = 0;//declare integer value to count in while loop

	//declare our input file
	ifstream inputFile;
	
	string inputFileName;//declare variable to hold value that user enters

	cout << "Welcome to the sorting and searching program.\n"
		<< "In this program you will enter the text document you would like to search through.\n"
		<< "Each document contains the value of 0 either in the beginning, middle, or end\n"
		<< "Enter the option you would like to choose from below \n\n"
		<< " * 1 * - The zero is near the BEGINNING of the document to be sorteded\n"
		<< " * 2 * - The zero is near the MIDDLE of the document to be sorteded\n"
		<< " * 3 * - The zero is near the END of the document to be sorteded\n"
		<< "Enter number that corresponds to the file you want to use:\n";
	cin >> inputFileName;
	
	bool correctFile = false;//bool to run while loop
	while (correctFile == false)//while loop that will run until user enters 1, 2, or 3
	{
		if (inputFileName == "1")//open early.txt
		{
			inputFile.open("early.txt");
			correctFile = true;
		}
		
		else if (inputFileName == "2")//open middle.txt
		{
			inputFile.open("middle.txt");
			correctFile = true;
		}
		else if (inputFileName == "3")//open end.txt
		{
			inputFile.open("end.txt");
			correctFile = true;
		}
		else  //invalid input
		{
			cout << "Error. Invalid input. Enter 1, 2, or 3:\n";
			cin >> inputFileName;
		}
	}
	//add the values of the file to the array that was established
	while (!inputFile.eof())//loop until the file ends
	{
		inputFile >> array[i];
		i++;//increment the i value
	}

	int ableBinary = 0;//create variable so the binary search can only be used after the Bubble Sort
	bool done = false;//set flag to run program until user enters Q
	while (done == false)
	{		
		string option;
		cout
			<< "\nOption 1 - Linear Search. Enter '1' to use a linear search to find the value of 0 in a file\n"
			<< "Option 2 -  Bubble Sort.  Enter '2' to sort all of the values in the text file you choose in ascending order\n"
			<< "Option 3 - Binary Search. Enter '3' to use a binary search to find teh value of 0 in your file.\n"
			<< "      ***  In order to use the Binary Search you must first use the Bubble Sort Function to sort the values  ***\n"
			<< "Option 4 - Print the Array. Enter '4' to see contents in the array!\n"			
			<< "\n - Quit - . Enter 'Q' to quit the program\n";
		cin >> option;
	

		if (option == "1")//linearSearch function
		{
			cout << "\nWe will search the text document that you opened to find the location of 0\n";
			cout << "0 was found in  position " << linearSearch(array, 20, 0) << " of the array!\n\n";	
			done = false;
		}


		else if (option == "2")//BubbleSort Function
		{
			cout << "\nYou have chosen the Bubble Sort. The array will now be in \n"
				<< "ascending order. The binarySearch function is now available!\n\n";
			bubbleSort(array, 20);
			ableBinary = 1;//set variable to 1 
			done = false;
			
		}
		else if (option == "3")
		{
			if(ableBinary == 0)
			{
				cout << "\nYou must first use the Bubble Sort in order to use the Binary Search.\n"
					<< "This is because in order to use the Binary Search, the orders must be sorted first! (Bubble Sort is Option '2')\n\n";
					
			}
			else		
			{
				int choice; //declare variable that user wants to search for
				cout << "\nEnter the value that you would like to searh for. The value must be positive and between 0 - 9!\n";
				cin >> choice;

				int answer = binarySearch(array, 20, choice);//set answer variable to position returned from binarySearch

				cout << "\nThe value that you are searching for was found in position " << answer << " of the array (or " 
					<< answer + 1 << ")\n\n";
			}
		}
		else if (option == "4")
		{
			cout << "\nThe array contains the values: ";
			for (int i = 0; i < 20; i++)
				cout << array[i] << "|";
			cout << "\n\n";
		}
		else if (option == "Q" || option == "q")//quit the program
		{
			cout << "\nThank you, have a great day!\n";
			done = true;//set bool to true to exit program
		}
		else //user entered invalid data
			cout << "\n***   Error. Not a valid input!   ***\n\n";
		
	}
	return 0;
}

/*************************************************************************
* linearSearch function takes an array, int, and int as parameters and searches
* through the array starting at the beginning until the end, designated by the size
* integer. If the value is found then it is returned, if it is not, then -1 is returned.
* This function is not from any source, just something that I came up with. 
*************************************************************************/
int linearSearch(int arr[], int size, int value)
{
	for (int i = 0; i < size; i++)//loop through the array
	{
		if (arr[i] == value)//if we find the value return its value
			return i;//return its position in the array
	}

	return -1;
}

/*************************************************************************
* binarySearch function takes an array, int, and int as parameters and searches
* through the array starting at the beginning until the end. It finds the
* location of the value being passed in by cutting the array in half and
* if th
*************************************************************************/
int binarySearch(int array[], int size, int value)
{
	int first = 0, // First array element
		last = size - 1, // Last array element
		middle, // Midpoint of search
		position = -1; // Position of search value
	bool found = false; // Flag
	
		while (found == false && first <= last)
		{
			middle = (first + last) / 2; // Calculate midpoint
			if (array[middle] == value) // If value is found at mid
			{
				found = true;
				position = middle;
			}
			else if (array[middle] > value) // If value is in lower half
				last = middle - 1;
			else
				first = middle + 1; // If value is in upper half
		}
		return position;
}


/**************************************************************
 * bubbleSort takes an integer array and a integer as its parameters
 * it then sorts each value of the array into ascending order. It does
 * this with two for-loops that first go through the size of the array
 * and looks at each value and the one below it. If it is lower then the previous
 * value, then they are swapped. This was taken from the bubble sort lecture
 * done by professor Rooker on slide number 5.
 **************************************************************/
void bubbleSort(int a[], int size)
{
	for (int i = (size - 1); i >= 0; i--)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[j - 1] > a[j])
			{
				//swap elements at j-1 and j
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}
}


