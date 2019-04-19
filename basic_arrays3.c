/*
Exercise: Basic Array Exercise 3

Instructions:
-Using the nul-terminated string below:
-Ask the user to input how many characters they want to print out
ex: 5 characters... "Deter"
-Print out only those characters without creating a new string/buffer or using additional printf() formatting


REQUIRMENTS:
-No hard coding values (unless it's zero or something) 
-No using printf special formatting
-Catch errors!!! (Nothing entered, non-number, etc)
*/


#include <stdio.h>
#include <string.h>


int main()
{
	char testString[] = "Determine the length of this string.";
	int howManyToPrint = 0;
	int result;

	// Ask user for input
	printf("How many characters should I print?\n");
	result = scanf("%d", &howManyToPrint);
	printf("Characters: %d\n", howManyToPrint);

	// Catch errors
	if(howManyToPrint <= 0) 
	{
		printf("Number of characters must be non-negative\n");
		return 1;
	} 
	else if(howManyToPrint > strlen(testString)) 
	{
		printf("Too many characters\n");
		return 1;
	}

	// Itterate through the array, printing out only the number of characters the user asks for
	int index;
	for(index = 0; index < howManyToPrint; index++) 
	{
		printf("%c", testString[index]);
	}
	printf("\n");

	return 0;
}