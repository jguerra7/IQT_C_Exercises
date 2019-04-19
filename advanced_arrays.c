/*
Exercise: Advanced Array Exercise 1

Instructions:
-Using the provided function below
-Search through a passed string for a character. Once that character is found, create a string starting at that character and store it in the appropiate buffer

example:
inputStr_ptr = "Hello World"
searchChar = 'W'
outputStr_ptr will then equal: "World"


REQUIRMENTS:
-No hard coding values (unless it's zero or something) 
-Catch errors!!! (Nothing entered, non-number, etc)
*/


#include <stdio.h>

// Creates a substring of a string based on the searchChar
/*
Arguments:
-inputStr_ptr: A pointer to a inputted string (the string to be searched through)
-searchChar: The char to find in the string
-outputStr_ptr: The buffer in which to store the substring

Return:
Errors:
-1 for any errors (check for null strings/buffers, unreasonable substring, etc)
0 for success
*/
int create_substring(char * inputStr_ptr, char searchChar, char * outputStr_ptr);


int main()
{

	// Ask the user a string... store it in a variable

	// Ask user for a char to search... store it in a variable

	// Call create_substring passing the appropiate variables

	// Print out the original string and the new string


	return 0;
}

int create_substring(char * inputStr_ptr, char searchChar, char * outputStr_ptr)
{
	// Insert code here
}