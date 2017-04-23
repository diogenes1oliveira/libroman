# Subtracting
Tests for subtracting characters: test/testSubtracting.c

First test - wrong order
------------------------

This test checks if the function is failing for subtracting characters in
the wrong order, i.e.: V, L or D before a higher value algarism.

\snippet test/testSubtracting.c SubtractingInput, WrongOrder

Second test - negative characters
---------------------------------

This one confirms if the function is working correctly for characters
with negative value, i.e.: I appearing V or X, C appearing before D or M, etc.

\snippet test/testSubtracting.c SubtractingInput, SingleSubtractingChar

Both tests were satisfied when I created a helper function to check if the
algarism can come before another. [GitHub commit](https://github.com/diogenes1oliveira/libroman/commit/4311b18560b1ccf7ad2c0f3b5fa90c4d505dd7c0#diff-3d6fc1bf772186c45fcd2c22d7ecd7b4)

Third test - multiple negative characters
-----------------------------------------

This snippet checks if the function fails (as expected) for strings where
a negative-valued algarism appears more than once.

\snippet test/testSubtracting.c SubtractingInput, MultipleSubtractingChar

I made the function satisfy this test by checking if there are repetitions
when the function is already in the subtracting mode: [GitHub commit](https://github.com/diogenes1oliveira/libroman/commit/0d80a8dac9f89ff4a4953b23d7aa7936137b7092#diff-3d6fc1bf772186c45fcd2c22d7ecd7b4)
