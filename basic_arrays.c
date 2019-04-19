/*
Exercise: Basic Array Exercise 1

Instructions:
Using the array below defined in main... calculate the sum and averages. Print out the results.

REQUIRMENTS:
-No hard coding values (unless it's zero or something) 
*/


#include <stdio.h>


int main()
{
	float studentGrades[6] = {88.9, 91.6, 63.5, 99.0, 92.5};
	float sum = 0.0;
	float average = 0.0;

	// Calculate the sum and averages. Be sure to store the sum and averages in sum,average variables
	int numGrades = sizeof(studentGrades)/sizeof(studentGrades[0]); 
	for(int index = 0; index < numGrades; index++) 
	{
		sum += studentGrades[index];
	}

	average = sum / numGrades;

	// Print out the variables in a human readable format
	printf("Sum: %.2f\n", sum);
	printf("Average: %.2f\n", average);

	return 0;
}