#include <stdio.h>
#include <string.h>

// Helper functions
int replace_character(char * string, const char findThisChar, const char replaceItWithThis);

int main(int argc, char* argv[]) {
    char* testString1 = NULL;
    char testString2[] = "Wish this newline\n wasn't here";
    char testString3[] = "This is what I goa";

    replace_character(testString1, 'a', 'b');
    replace_character(testString2, '\n', ' ');
    replace_character(testString3, 'a', 't');

    printf("TestString1: %s\n", testString1);
    printf("TestString2: %s\n", testString2);
    printf("TestString3: %s\n", testString3);
}

int replace_character(char * string, const char findThisChar, const char replaceItWithThis) {
    int charactersReplaced = 0;
    int index;

    if(string == NULL) {
        return -1;
    }

    for(index = 0; index < strlen(string); index++) {
        if(string[index] == findThisChar) {
            string[index] = replaceItWithThis;
            charactersReplaced++;
        }
    }

    return charactersReplaced;
}