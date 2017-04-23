# Increasing characters
Tests for more complex inputs: test/testIncreasing.c

First test - multiple single characters
---------------------------------------

The first test I did checks if the function is returning the right values
for strings with repeatable characters (I, X, C and M).

\snippet test/testIncreasing.c ComplexInput, MultipleSingleCharacters

This test was satisfied by creating a loop through the string to add all
the values in it, as can be seen in this [GitHub commit](https://github.com/diogenes1oliveira/libroman/commit/637a23468d94b2257037522e7fdd3f34160322ab#diff-3d6fc1bf772186c45fcd2c22d7ecd7b4).

Second test - increasing characters
-----------------------------------

The first test I did just checks if the function handles correctly inputs
with multiple, but strictly increasing values for its algarisms.

\snippet test/testIncreasing.c ComplexInput, IncreasingCharacters

Third test - non-repeatable characters
--------------------------------------

This snippet checks if the function fails (as expected) for strings where
one of the non-repeatable characters (V, L or D) appear more than once.

\snippet test/testIncreasing.c ComplexInput, NonRepeatableCharacters

Fourth test - too many repetitions
----------------------------------

This snippet checks if the function fails when the repeatable characters
(I, X, C or D) repeat more than 3 times.

\snippet test/testIncreasing.c ComplexInput, TooManyRepetitions

To satisfy the 2nd, 3rd and 4th tests, the function was altered as in this [Github commit](https://github.com/diogenes1oliveira/libroman/commit/2da558c048fbe2a989ed9bceddb52fc4b1b615b7#diff-3d6fc1bf772186c45fcd2c22d7ecd7b4).
I added a check function to see if the character is repeatable and then, 
in the main `roman_to_int()` function, I checked if the repeatable ones weren't
repeating too much (more than 3 times).

Fifth test - invalid characters
--------------------------------

This test checks if the function behaves correctly when a string
with invalid characters is passed as the input:

\snippet test/testIncreasing.c ComplexInput, InvalidCharacter

In this [Github commit](https://github.com/diogenes1oliveira/libroman/commit/818abdde2a85e1c1924458c4f25cfff65835bc95#diff-3d6fc1bf772186c45fcd2c22d7ecd7b4), 
I made the function comply to this test by making it return `-1` when
encountering an invalid character.

Sixth test - subtracting before repeating characters
----------------------------------------------------

This test was made way after the other tests, when I checked that strings like
IXX weren't being recognized as invalid. So this one checks if the function
is behaving properly when a subtracting character is put before an already
repeating character.

\snippet test/testIncreasing.c ComplexInput, SubtractingBeforeRepetition

In this [Github commit](https://github.com/diogenes1oliveira/libroman/commit/2cd1eaf9f7230c4bff2776c36d46a7cce91239d0#diff-3d6fc1bf772186c45fcd2c22d7ecd7b4), 
I commited the needed correction to the function.

