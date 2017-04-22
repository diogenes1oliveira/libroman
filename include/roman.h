#ifndef ROMAN_H_
#define ROMAN_H_

/**
 * Returns the integer value of the roman characters string.
 * 
 * This function parses the input string, which must correspond to a valid
 * roman character string, which must satisfy the following conditions:
 * 
 * + It must be non-null and non-empty.
 * + The characters V, L or D cannot be repeated.
 * + The characters I, X, C or M can be repeated up to three times.
 * + If the characters are in non-decreasing order
*/
int roman_to_int(const char *input);

#endif // ROMAN_H_
