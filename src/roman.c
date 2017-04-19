#include "roman.h"

#include <string.h>

static int single_character_value(char c) {
	int value;
	
	switch(c) {
		case 'I':
			value = 1;
			break;
		case 'V':
			value = 5;
			break;
		case 'X':
			value = 10;
			break;
		case 'L':
			value = 50;
			break;
		case 'C':
			value = 100;
			break;
		case 'D':
			value = 500;
			break;
		case 'M':
			value = 1000;
			break;
		default:
			value = -1;
	}
	
	return value;
}

int roman_to_int(const char *input) {
	if(input == NULL || strlen(input) == 0)
		return -1;
	
	return single_character_value(input[0]);
}
