#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper functions
int remove_newlines(char * sentenceString);

int main(int argc, char* argv[]) {
    // Construct test strings
    char testString1[] = "This\n is a \ntest\n str\ning";
    char testString2[] = "\nTest this\n";
    char testString3[] = {0};
    char* testString4 = NULL;
    char testString5[] = "\n";

    // Test strings
    printf("----------Test 1----------\n");
    remove_newlines(testString1);
    printf("----------Test 2----------\n");
    remove_newlines(testString2);
    printf("----------Test 3----------\n");
    remove_newlines(testString3);
    printf("----------Test 4----------\n");
    remove_newlines(testString4);
    printf("----------Test 5----------\n");
    remove_newlines(testString5);

    return 0;
}

int remove_newlines(char * sentenceString) {
    int numReplaced = 0;

    // Null string
    if(sentenceString == NULL) {
        printf("NULL String\n");
        numReplaced = -1;
    }
    // Empty string
    else if(sentenceString[0] == 0) {
        printf("Empty String\n");
        numReplaced = -2;
    } else {
        int index;
        for(index = 0; index < strlen(sentenceString); index++) {
            if(sentenceString[index] == '\n') {
                if(index + 1 < strlen(sentenceString)) { // Verify memmove will not go out of bounds
                    memmove(&sentenceString[index], &sentenceString[index + 1], strlen(sentenceString) - index);
                } else {
                    sentenceString[index] = '\0'; // Replace new line with NULL terminator if out of bounds
                }
                numReplaced++;
            }
        }
    }

    if(numReplaced == 0) {
        printf("No characters replaced\n");
        numReplaced = -1;
    } else if(numReplaced > 0) {
        printf("Characters Replaced: %d\n", numReplaced);
        printf("New String: %s\n", sentenceString);
    }

    return numReplaced;
}