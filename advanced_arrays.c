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
#include <stdlib.h>
#include <string.h>

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
	char userString[256] = {0};
	char searchChar;
	const int MAXCHARS = sizeof(userString) / sizeof(userString[0]);
	char outputString[MAXCHARS] = {0};

	// Ask the user a string... store it in a variable
	printf("Please enter string\n");
	if(fgets(userString, sizeof(userString), stdin) == NULL)
	{
		// Failed to gather input
		printf("Unable to gather input\n");
		return 1;
	}
	else if(userString[MAXCHARS - 1] != 0)
	{
		// Not null terminated, string too long
		printf("String too long\n");
		return 1;

	} 
	else if(userString[0] == '\n')
	{
		// Empty string
		printf("No characters to search\n");
		return 1;
	}

	// Ask user for a char to search... store it in a variable
	printf("Please enter character to search for\n");
	searchChar = getchar();
	if(searchChar == '\n' || searchChar == EOF) 
	{
		printf("Unable to gather search character\n");
		return 1;
	}

	// Call create_substring passing the appropiate variables
	if(create_substring(userString, searchChar, outputString) != 0) {
		printf("Unable create substring");
		return 1;
	}
	// Print out the original string and the new string
	else {
		printf("Original: %s", userString);
		printf("Substring: %s", outputString);
	}
	
	return 0;
}

int create_substring(char * inputStr_ptr, char searchChar, char * outputStr_ptr)
{
	if(inputStr_ptr == NULL) {
		return -1;
	}
	else if(outputStr_ptr == NULL) {
		return -1;
	} 
	else if(sizeof(inputStr_ptr) !=  sizeof(outputStr_ptr)) {
		return -1;
	}

	int continueSubstring = 0;
	int inIndex;
	int outIndex = 0;
	for(inIndex = 0; inIndex < strlen(inputStr_ptr); inIndex++) {
		if(continueSubstring == 0 && inputStr_ptr[inIndex] == searchChar) {
			continueSubstring = 1;
		}

		if(continueSubstring == 1) {
			outputStr_ptr[outIndex++] = inputStr_ptr[inIndex];
		}
	}

	return 0;
}