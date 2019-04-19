/*
Exercise: Basic Array Exercise 2

Instructions:
-Using the nul-terminated string below:
-Deterimine the length of this string


REQUIRMENTS:
-No hard coding values (unless it's zero or something) 
-NO strlen() (DO NOT INCLUDE ANYTHING ELSE OTHER THAN stdio.h)
*/


#include <stdio.h>


int main()
{
	char studentGrades[] = "Determine the length of this string.";
	int stringSize = 0;

	// Itterate through the array and determine it's length without strlen()
	while(studentGrades[stringSize] != '\0') 
	{
		stringSize++;
	}


	// Print out the size in a human readable format
	printf("String size: %d\n", stringSize);

	return 0;
}