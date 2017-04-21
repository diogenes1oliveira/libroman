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

static int alg_can_repeat(char alg) {
	return !(alg == 'V' || alg == 'L' || alg == 'D');
}

static int alg_can_come_before(char now, char before) {
	switch(now) {
		case 'I':
			return (before == 'X' || before == 'V');
			break;
		case 'X':
			return (before == 'C' || before == 'L');
			break;
		case 'C':
			return (before == 'D' || before == 'M');
			break;
		default:
			return 0;
	}
}

int roman_to_int(const char *input) {
	int length;
	int i;
	int value = 0;
	int valueNow = -1;
	int valueBefore = -1;
	char algNow = '\0';
	char algBefore = '\0';
	int repetitions = 0;
	
	if(input == NULL)
		return -1;
	
	length = strlen(input);
	if(length <= 0)
		return -1;
	
	for(i = length - 1; i >= 0; --i) {
		algNow = input[i];
		
		if(repetitions > 3)
			return -1;
		
		if(algBefore != algNow) {
			repetitions = 1;
		}
		else {
			if(!alg_can_repeat(algNow))
				return -1;
			
			++repetitions;
		}
		
		valueNow = single_character_value(algNow);
		
		if(valueNow == -1)
			return -1;
		
		if(valueNow < valueBefore) {
			if(!alg_can_come_before(algNow, algBefore))
				return -1;
			
			value -= valueNow;
		}
		else {
			value += valueNow;
		}
		
		algBefore = algNow;
		valueBefore = valueNow;
	}
	
	return value;
}
