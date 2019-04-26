/*
Haystack Needle Lab

Purpose:
Remove the needle from the haystack
AKA: Move the substring from the string using memory operators and functions

*/
#include <stdio.h>    // printf
#include <stdlib.h>   // malloc
#include <string.h>   // strstr, memmove


int haystack_needle(char *haystack, char *needle, char *buffer);

int main()
{
  char string[] = "This is my brand new sentence";
  char substring[] = " brand new";

  printf("Haystack: %s\n", string);
  printf("Needle: %s\n", substring);

  char* buffer =  malloc(sizeof(string));
  if(buffer == NULL) {
    printf("Unable to create buffer\n");
    return 1;
  }

  haystack_needle(string, substring, buffer);

  if(buffer !=  NULL) {
    free(buffer);
  }

  printf("New String: %s\n", string);

  return 0;
}

/*
Arguments:
-haystack --- pointer to string to search
-needle   --- pointer to substring to search inside of haystack
-buffer   --- pointer to a buffer

PURPOSE:
haystack_needle takes the arguments above and searches the haystack
for the needle. Once it finds the needle... it removes it from the haystack.

Return:
return 0 on success
return -1 on error .... only needed if userinput is enabled.
*/
int haystack_needle(char *haystack, char *needle, char *buffer)
{
    if(haystack == NULL || needle == NULL || buffer == NULL) {
      // Error: NULL values
      return -1;
    } else if(sizeof(needle) > sizeof(buffer)) {
      // Error: Buffer too small
      return -1;
    }

    strcpy(buffer, needle);

    char* mark_position = strstr(haystack, buffer);
    if(mark_position == NULL) {
        // Error: No needle 
        return -1;
    }

    // Memmove to remove needle from haystack
    int needle_length = strlen(buffer);
    //printf("Needle location: %s\n", mark_position);
    //printf("End of Needle: %s\n", mark_position + needle_length);
    memmove(mark_position, mark_position + needle_length, strlen(mark_position + needle_length) + 1);

    return 0;
}

