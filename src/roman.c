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
	int length;
	int i;
	int value = 0;
	
	if(input == NULL)
		return -1;
	
	length = strlen(input);
	if(length <= 0)
		return -1;
	
	for(i = length - 1; i >= 0; --i)
		value += single_character_value(input[i]);
	
	return value;
}
