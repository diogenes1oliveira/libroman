#include "roman.h"

#include <stdbool.h>
#include <string.h>

static int string_length(const char *str) {
	return (
		str == NULL ?
		-1 :
		strlen(str)
	);
}

static int alg_value(char alg) {
	int value;
	
	switch(alg) {
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

static bool alg_can_repeat(char alg) {
	return !(alg == 'V' || alg == 'L' || alg == 'D');
}

static bool alg_can_come_before(char now, char before) {
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
			return false;
	}
}

int roman_to_int(const char *input) {
	int length;
	int i;
	int finalValue = 0;
	int valueNow = -1;
	int valueBefore = -1;
	char algNow = '\0';
	char algBefore = '\0';
	int repetitions = 0;
	bool isSubtracting = false;
	
	/* This checks if the string is valid */
	length = string_length(input);
	if(length <= 0)
		return -1;
	
	/* Loop through the string, starting from the end */
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
		
		/* A smaller algarism coming before a greater one (IX, for instance)
		 * can't be repeated.
		 */
		if(isSubtracting && repetitions >= 2)
			return -1;
		
		valueNow = alg_value(algNow);
		if(valueNow == -1)
			return -1;
		
		/* If TRUE, I am in the subtracting mode: a smaller algarism coming
		 * before a greater one.
		 */
		if(valueNow < valueBefore) {
			if(!alg_can_come_before(algNow, algBefore))
				return -1;
			
			finalValue -= valueNow;
			isSubtracting = true;
		}
		else {
			finalValue += valueNow;
			isSubtracting = false;
		}
		
		algBefore = algNow;
		valueBefore = valueNow;
	}
	
	return finalValue;
}
