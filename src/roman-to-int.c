#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "roman.h"

int main(int argc, char *argv[]) {
	
	if(argc < 2) {
		fprintf(stderr, "No Roman string was passed as an argument.\n");
		return 1;
	}
	
	if(argc > 2) {
		fprintf(stderr, "Too many command-line arguments.\n");
		return 1;
	}
	
	int arg_len = strlen(argv[1]);
	char * arg_str = (char *) malloc(arg_len + 1);
	
	if(arg_str == NULL) {
		fprintf(stderr, "Couldn't allocate memory.\n");
		return 1;
	}
	memset(arg_str, 0, (arg_len + 1) * sizeof(char));
	
	for(int i = 0; i < arg_len; ++i)
		arg_str[i] = toupper(argv[1][i]);
	
	int value = roman_to_int(arg_str);
	
	if(value == -1) {
		fprintf(stderr, "Invalid roman numeral.\n");
		return -1;
	}
	
	printf("%d\n", value);
	return 0;
}
