/*
Exercise: Basic Array Exercise 4

Instructions:
-Ask the user to input a string
-Store that string into an array... ensure the array is nul-terminated
-Print out the string
-BONUS: Print out the string all capitalized


REQUIRMENTS:
-No hard coding values (unless it's zero or something) 
-Catch errors!!! (Nothing entered, invalid, etc)
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>


int main()
{
	char userString[256] = {0};
	
	const int MAXCHARS = sizeof(userString)/sizeof(userString[0]);
	int index;

	// Ask user for input, store input into userString
	printf("Please provide a string\n");
	if(NULL == fgets(userString, sizeof(userString), stdin))
	{
		printf("Unable to gather input\n");
		return 1;
	}

	// Catch errors
	// Check last element for NULL
	if(userString[MAXCHARS - 1] != 0) 
	{
		printf("String too long\n");
		return 1;
	}
	// Check for valid length
	else if(strlen(userString) <= 0) 
	{
		printf("No characters to print\n");
		return 1;
	}

	// Print the string
	for(index = 0; index < strlen(userString); index++)
	{
		// Print each character upper case
		printf("%c", toupper(userString[index]));
	}

	return 0;
}