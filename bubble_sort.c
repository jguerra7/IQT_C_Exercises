#include <errno.h>      // errno
#include <math.h>       // HUGE_VAL
#include <stdio.h>      // printf
#include <stdlib.h>     // strtod
#include <string.h>     // strerror

#define MINARGS 2

// Helper functions
int convert_argument(const char* arg, double* convertedArg);
int swap(double* numbers, int length);

int main(int argc, char* argv[]) {
    int result;

    if(argc < MINARGS) {
        printf("Must include numbers to sort\n");
        result = 1;
    } else if(argc == MINARGS) {
        // Verify input is valid number
        double convertedArg;
        if(convert_argument(argv[1], &convertedArg) == 0) {
            // If valid, print
            printf("%.2f\n", convertedArg);
            result = 0;
        } else {
            result = 1;
        } 
    } else {
        int sortedLength = argc - 1; // Ignore first element, typically executable path
        double sortedArguments[sortedLength]; 

        // Convert string arguments to double array
        int argIndex;
        int sortedIndex = 0; 
        for(argIndex = 1; argIndex < argc; argIndex++) { 
            if(convert_argument(argv[argIndex], &sortedArguments[sortedIndex++]) == 1) {
                printf("Argument %d %s invalid, aborting\n", argIndex + 1, argv[argIndex]);
                return 1;
            }
        }

        // Keep swapping until sorted
        while(swap(sortedArguments, sortedLength) != 0) {}

        // Print results
        for(sortedIndex = 0; sortedIndex < sortedLength; sortedIndex++) {
            printf("%.2f ", sortedArguments[sortedIndex]);
        }
        printf("\n");

        result = 0;
    }

    return result;
}

int convert_argument(const char* arg, double* convertedArg) {
    int result;
    char* endPtr;

    // Error check
    if(arg == NULL || convertedArg == NULL) {
        return 1;
    }

    errno = 0; // Set to 0 to determine if strtod converted to 0 or there was an error
    *convertedArg = strtod(arg, &endPtr);
    // Check for errors
    if((*convertedArg  == 0.0  || *convertedArg  == HUGE_VAL) && errno != 0) { 
        printf("Error converting number: %s\n", strerror(errno));
        result = 1;
    }
    // All characters not converted
    else if(endPtr != arg + strlen(arg)) { // End pointer does not point to end of string
        printf("Unable to convert full string to number\n");
        result = 1;
    }
    // Conversion success
    else { 
        result = 0;
    }

    return result;
}

int swap(double* numbers, int length) {
    int numSwapped = 0;
    int index;
    double tmp;

    // Error check
    if(numbers == NULL || length <= 0) {
        return -1;
    }

    // Loop through array and swap as necessary
    for(index = 0; index < length - 1; index++) {
        // Compare current number to the next one
        if(numbers[index] > numbers[index + 1]) {
            // Swap
            tmp = numbers[index];
            numbers[index] = numbers[index + 1];
            numbers[index + 1] = tmp;

            // Update counter
            numSwapped++;
        }
    }

    return numSwapped;
}