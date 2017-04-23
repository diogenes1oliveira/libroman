# Simple tests
Starting with tests for simple inputs: test/testSimple.c

First test - sanity of the input
--------------------------------

The first test I did just checks if the function handles correctly non-valid
strings i.e., empty or NULL strings:

\snippet test/testSimple.c SimpleInput, InvalidInput


Second test - single characters
-------------------------------

The second test involves checking if the conversion for single characters
is working as expected:

\snippet test/testSimple.c SimpleInput, SingleCharacter

The resulting code after these tests can be seen in this [GitHub commit](https://github.com/diogenes1oliveira/libroman/commit/e9c1c6680af03fe397e5194c65434c857d4dd20d?diff=split#diff-3d6fc1bf772186c45fcd2c22d7ecd7b4). In a nutshell, I added a test for the validity of the string, making the function `roman_to_int()` pass the first test. Then I added the function `single_character_value()` to return the numerical value of a Roman character, satisfying the second test.
