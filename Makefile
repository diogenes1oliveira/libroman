CC=g++

OBJ_DIR = obj
SRC = src
INCLUDE = include
LIB = lib
TEST_DIR = test

FLAGS = -g
LIBS = -lgtest -lpthread

# The names of the files to compile
BASENAMES = roman

# Final dynamic library
LIB_FINAL = roman

# The names of the tests to run
TESTS = testSimple testIncreasing

# Generating the final .so path
LIB_NAME=lib$(LIB_FINAL).so
LIB_FULLNAME = $(LIB)/$(LIB_NAME)

# Generating include/*.h dependencies
_HEADERS = $(addprefix $(INCLUDE)/, $(BASENAMES))
HEADERS = $(addsuffix .h, $(_HEADERS))

# Generating src/*.c dependencies
_SOURCES = $(addprefix $(SRC)/, $(BASENAMES))
SOURCES = $(addsuffix .c, $(_SOURCES))

_OBJS = $(addprefix $(OBJ_DIR)/, $(BASENAMES))
OBJS = $(addsuffix .o, $(_OBJS))

# Setting up gtest
GTEST_ROOT_DIR=../googletest-master
# GTEST_LIB_DIR must point to where is libgtest.a
GTEST_LIB_DIR=$(GTEST_ROOT_DIR)/build/googlemock/gtest
# GTEST_INCLUDE_DIR must point to where the include directory "gtest" is
GTEST_INCLUDE_DIR=$(GTEST_ROOT_DIR)/googletest/include

# Paths pointing to where the libraries are
LIBS_DIR = $(GTEST_LIB_DIR) $(LIB)
LIBS_FLAG = $(addprefix -L, $(LIBS_DIR)) $(LIBS)

# Paths to include to the .h path
_HEADERS_FLAG = $(INCLUDE) $(GTEST_INCLUDE_DIR)
HEADERS_FLAG = $(addprefix -I, $(_HEADERS_FLAG))

_TESTS_SOURCE=$(addprefix $(TEST_DIR)/, $(TESTS))
TESTS_SOURCE=$(addsuffix .c, $(_TESTS_SOURCE))
TESTS_BIN = $(addprefix $(TEST_DIR)/bin/, $(TESTS))

# The default target builds the .so library and all the tests
all: $(LIB_FULLNAME) build-tests

$(LIB_FULLNAME): $(OBJS)
	mkdir -p $(LIB)
	$(CC) $(FLAGS) -shared -fPIC -Wl,-soname,$(LIB_NAME) -o $(LIB_FULLNAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC)/%.c $(HEADERS)
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c -fPIC -o $@ $< $(HEADERS_FLAG)

run-tests: build-tests
	$(foreach var,$(TESTS_BIN),LD_LIBRARY_PATH=$(LIB) ./$(var);) 

build-tests: $(LIB_FULLNAME) $(TESTS_BIN)

$(TEST_DIR)/bin/%: $(TEST_DIR)/%.c $(HEADERS) $(SOURCES)
	mkdir -p $(TEST_DIR)/bin
	$(CC) $(FLAGS) -o $@ $< $(HEADERS_FLAG) $(LIBS_FLAG) -l$(LIB_FINAL)

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf $(TESTS_BIN)/*
	rm -rf $(LIB)/*

