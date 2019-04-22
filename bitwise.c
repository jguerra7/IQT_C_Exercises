#include <stdio.h>
#include <stdlib.h>

#define _32_BITS  32

int main(int argc, char* argv[]) {
    uint32_t input;
    uint32_t bitChecker = 0x01;

    fprintf(stdout, "Please enter a number to convert to bits:\n");
    fscanf(stdin, "%u", &input);

    fprintf(stdout, "Your number: %u\n", input);

    int count = _32_BITS;
    while(--count >= 0) {
        fprintf(stdout, "%d", input >> count  & bitChecker);
    }
    fprintf(stdout, "\n");

    return 0;
}