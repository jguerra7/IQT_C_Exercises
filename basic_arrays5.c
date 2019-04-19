/*
Exercise: Basic Array Exercise 5

Instructions:
-Ask the user to input a string
-Ask the user to input a char to search in string
-Ask the user what to change the char to
-Print out the new string

ex:
"Hello World" - Original
"l" - char to change
"x" - what to change it to
"Hexxo Worxd" - Modified


REQUIRMENTS:
-No hard coding values (unless it's zero or something) 
-Nul-terminate string
-Catch errors!!! (Nothing entered, invalid, etc)
*/


#include <stdio.h>
#include <string.h>


int main()
{
	char userString[256] = {0};
	char needle = 0; // Char to search for
	char newNeedle = 0; // What to change it to
	char moddedString[256] = {0};

	const int MAXCHARS = sizeof(userString) / sizeof(userString[0]);
	int index;
	char *foundNeedle;
	char tmpChar;

	// Ask user for string, store input into userString
	printf("Please enter string\n");
	if(NULL == fgets(userString, sizeof(userString), stdin))
	{
		// Failed to gather input
		printf("Unable to gather input\n");
		return 1;
	}
	else if(0 != userString[MAXCHARS - 1])
	{
		// Not null terminated, string too long
		printf("String too long\n");
		return 1;

	} 
	else if('\n' == userString[0])
	{
		// Empty string
		printf("No characters to search\n");
		return 1;
	}

	printf("Please enter character to search for\n");
	needle = getchar();
	if('\n' == needle || EOF == needle) 
	{
		printf("Unable to gather search character\n");
		return 1;
	}

	while(EOF != (tmpChar = getchar()) && '\n' != tmpChar); // Loop for extra characters

	printf("Please enter character to replace with\n");
	newNeedle = getchar();
	if('\n' == newNeedle || EOF == newNeedle) 
	{
		printf("Unable to gather replacement character\n");
		return 1;
	}

	// Modify the string, save it to moddedString
	strcpy(moddedString, userString);
	while(NULL != (foundNeedle = strchr(moddedString, needle))) {
		*foundNeedle = newNeedle;
	}

	// Print the string (moddedString)
	printf("%s", moddedString);

	return 0;
}