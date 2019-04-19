#include <stdio.h>
#include <string.h>
#include "Case_Manipulation.h"


int main() {

	// test strings
	char string1[] = "This is a Test";
	char string2[] = "TEST$ $THIS #IS a test!!!";
	char *string3 = NULL;

	char str4[] = "Another test";
	char str5[] = "ANOTHER % test";
	char *str6 = NULL;

	// output strings
	char output1[] = "tHIS IS A tEST";
	char output2[] = "test$ $this #is A TEST!!!";
	char output3[] = "aNOTHER TEST";
	char output4[] = "aNOTHER test";
	char output5[] = "ANOTHER % TEST";

	int start1 = 0;
	int start2 = 7;
	int start3 = 400;
	int start4 = -5;




	printf("########## TEST 1 ##########\n\n");

	
	if (chg_alpha_case('A') == 'a') {
		printf("Test 1a: PASS\n");
	}else {
		printf("Test 1a: FAIL\n");
		printf("OUTPUT: %c\n", chg_alpha_case('A'));
	}
	if (chg_alpha_case('y') == 'Y') {
		printf("Test 1b: PASS\n");
	}else {
		printf("Test 1b: FAIL\n");
		printf("OUTPUT: %c\n", chg_alpha_case('y'));
	}
	if (chg_alpha_case(47) == 47) {
		printf("Test 1c: PASS\n");
	}
	else {
		printf("Test 1c: FAIL\n");
		printf("OUTPUT: %c\n", chg_alpha_case('47'));
	}

	printf("\n\n########## TEST 2 ##########\n\n");

	chg_string_case(string1);
	chg_string_case(string2);
	if (strcmp(string1, output1) == 0) {
		printf("Test 2a: PASS\n");
	}
	else {
		printf("Test 2a: FAIL\n");
		printf("OUTPUT: %s\n", string1);
	}
	if (strcmp(string2, output2) == 0) {
		printf("Test 2b: PASS\n");
	}
	else {
		printf("Test 2b: FAIL\n");
		printf("OUTPUT: %s\n", string2);
	}
	if (chg_string_case(string3) == NULL) {
		printf("Test 2c: PASS\n");
	}
	else {
		printf("Test 2c: FAIL\n");
		printf("OUTPUT: N/A\n");
	}



	printf("\n\n########## TEST 3 ##########\n\n");

	chg_starting_here(str4, start1);
	if (strcmp(str4, output3) == 0) {
		printf("Test 3a: PASS\n");
	}
	else {
		printf("Test 3a: FAIL\n");
		printf("OUTPUT: %s\n", str4);
	}
	chg_starting_here(str4, start2);
	if (strcmp(str4, output4) == 0) {
		printf("Test 3b: PASS\n");
	}
	else {
		printf("Test 3b: FAIL\n");
		printf("OUTPUT: %s\n", str4);
	}
	chg_starting_here(str5, start2);
	if (strcmp(str5, output5) == 0) {
		printf("Test 3c: PASS\n");
	}
	else {
		printf("Test 3c: FAIL\n");
		printf("OUTPUT: %s\n", str5);
	}
	if (chg_starting_here(str5, start3) == NULL) {
		printf("Test 3d: PASS\n");
	}
	else {
		printf("Test 3d: FAIL\n");
		printf("OUTPUT: N/A\n");
	}
	if (chg_starting_here(str5, start4) == NULL) {
		printf("Test 3e: PASS\n");
	}
	else {
		printf("Test 3e: FAIL\n");
		printf("OUTPUT: N/A\n");
	}

	getchar();
	getchar();

	return 0;
}