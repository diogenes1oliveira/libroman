# libroman
A library to convert Roman numerals to their integer values.

Building the library
-----------------

To build the static library, you'll need the following commands available
in your system:

+ `g++` (C++ compiler)
+ `ar`  (static library creator)
+ `pthreads`
+ `cmake`

In addition, to run the tests you need to have the GTest framework
in your system. The easiest way is to clone the
[Google Test repository](https://github.com/google/googletest) to a
directory in your local path and then build it using `cmake`:

```bash
cd /home/foo/
git clone https://github.com/google/googletest
cd googletest
mkdir build && cd build
cmake .. && make
```

You can then `cd` to this project root folder `libroman` and pass the GTest
root directory as the variable `GTEST_ROOT_DIR` to the `make` command.
```bash
cd /home/foo/libroman
make GTEST_ROOT_DIR=/home/foo/googletest
```

If not, you'll need to provide the paths to GTest as variables
to the `make` command:

```bash
cd /home/foo/libroman
make GTEST_LIB_DIR=/home/foo/gtest-lib-path GTEST_INCLUDE_DIR=/home/foo/gtest-include-path
```

+ `GTEST_LIB_DIR` points to where the library .a file is. Defaults to
	`GTEST_ROOT_DIR/build/googlemock/gtest`.
+ `GTEST_INCLUDE_DIR` must point to where the include directory ```gtest``` is.
	`Defaults to GTEST_ROOT_DIR/googletest/include`.

To run the tests, simply run `make run-tests`.

Using the library
-----------------
To use the library, simply include the header roman.h and
call the function roman_to_int() with a string as its only parameter:

```c
#include <stdio.h>
#include "roman.h"

int main() {
	int value = roman_to_int("XII");
	printf("%d\n", value); // 12
}
```

And then you need to compile your program linking it against the `libroman.a`
static library in the `lib/` directory, including the header directory as well:

```bash
g++ -o bar bar.c -I /home/foo/libroman/include -L /home/foo/libroman/lib -lroman
```

Using the standalone binary
---------------------------
There's a standalone binary `roman-to-int` in the `bin/` directory that accepts
Roman numerical strings as its only command-line argument, and prints to stdout
its numerical integer value. For example, the code below outputs `12`:

```bash
cd /home/foo/libroman
./bin/roman-to-int XII
```

Roman numerical system
----------------------
The Roman numerical system is composed by assigning numerical values to
certain characters, as in the table below:

| Character | Value |
|-----------|-------|
|     I     |    1  |
|     V     |    5  |
|     X     |   10  |
|     L     |   50  |
|     C     |  100  |
|     D     |  500  |
|     M     | 1000  |

The numbers must normally be written in descending order, with repeating
characters having their value multiplied by the number of times they appear
(3, at most). As such, we'd have VI = 6, MMMLX = 3060, for instance. The
characters V, L and D cannot be repeated in any circunstance, rendering Roman
numbers such as VV or MDDI invalid.

If a character like I, X or C appears before another with a greater value, its
value is subtracted from this one: IV = 4, for instance. The rules for
subtracting characters are written in the table below: 

| Character | Can appear before |
|-----------|-------------------|
|     I     |    V, X           |
|     X     |    L, C           |
|     C     |    D, M           |
| V, L, D   |    None           |

When subtracting there can't be any repetition, thus IIX or CCMI are invalid
Roman numbers.
