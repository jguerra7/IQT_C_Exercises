#include "Case_Manipulation.h"

////////////////////////////////////////////////////////////////////
//////////////////////////// Stub Code /////////////////////////////
////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
////////////////////////// IMPORTANT NOTE //////////////////////////
////////////////////////////////////////////////////////////////////
// You may not utilize and C Standard libraries in this header.
////////////////////////////////////////////////////////////////////

////////////////////////////// FUNC 1 //////////////////////////////
// ARGUMENTS:
//		letter - numerical representation of a single character
// PURPOSE:
//		Change the case of letter if it is in fact an alphabet letter
// RETURN:
//		If letter is a lower-case alphabet letter, return its upper-case
//		If letter is an upper-case alphabet letter, return its lower-case
//		If letter is not an alphabet letter, return letter
unsigned int chg_alpha_case(unsigned int letter)
{
	const int UPPER_LOWER_DIFF = 32;

	if(letter >= 'a' && letter <= 'z') {
		// Convert lower case to upper case
		return letter - UPPER_LOWER_DIFF;
	} else if(letter >= 'A' && letter <= 'Z') {
		// Convert upper case to lower case
		return letter + UPPER_LOWER_DIFF;
	} else {
		// Not a letter
		return letter;
	}
}


////////////////////////////// FUNC 2 //////////////////////////////
// ARGUMENTS:
//		string_ptr - a pointer to a nul-terminated string
// PURPOSE:
//		Change the case of each alphabet letter in string using chg_alpha_case()
// RETURN:
//		If string_ptr is NULL, return NULL
//		Otherwise, return string_ptr
char * chg_string_case(char * string_ptr)
{
	if(string_ptr == NULL) {
		// NULL input
		return NULL;
	}

	int index;
	for(index = 0; string_ptr[index] != '\0'; index++) {
		// Change each character
		string_ptr[index] = chg_alpha_case(string_ptr[index]);
	}

	return string_ptr;
}

////////////////////////////// FUNC 3 //////////////////////////////
// ARGUMENTS:
//		string_ptr - a pointer to a nul-terminated string
//		start_here - the index of the nul-terminated string to begin at (see: string_ptr)
// PURPOSE:
//		Starting at index "start_here" utilize chg_string_case() to change the case of...
//			...each alphabet letter in string_ptr
// RETURN:
//		If string_ptr is NULL, return NULL
//		If start_here is outside of the string, return NULL
//		Otherwise, return a pointer to index "start_here"
char * chg_starting_here(char * string_ptr, int start_here)
{
	if(string_ptr == NULL || start_here < 0) {
		return NULL;
	}

	// No strlen, loop through string until null character to find length :-|
	int string_len = 0;
	char* tmp_ptr = string_ptr;
	while(*tmp_ptr++ != '\0') { 
		string_len++; 
	}
	if(start_here > string_len) {
		return NULL;
	}

	// Change string starting from pointer
	chg_string_case(string_ptr + start_here);

	return string_ptr + start_here;
}
