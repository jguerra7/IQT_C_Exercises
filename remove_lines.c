#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper functions
int remove_newlines(char * sentenceString);

int main(int argc, char* argv[]) {
    char testString1[] = "This\n is a \n test \n str\ning";
    char testString2[] = "\nTest this\n";
    char testString3[] = {0};
    char* testString4 = NULL;

    remove_newlines(testString1);
    printf("TestString1: %s\n", testString1);
    remove_newlines(testString2);
    printf("TestString2: %s\n", testString2);
    remove_newlines(testString3);
    printf("TestString3: %s\n", testString3);
    remove_newlines(testString4);
    printf("TestString4: %s\n", testString4);

    return 0;
}

int remove_newlines(char * sentenceString) {
    if(sentenceString == NULL || sentenceString[0] == 0) {
        return 0;
    }

    int index;
    for(index = 0; index < strlen(sentenceString); index++) {
        if(*(sentenceString + index) == '\n') {
            memmove(&sentenceString[index], &sentenceString[index + 1], strlen(sentenceString) - index);
        }
    }


    return 0;
}