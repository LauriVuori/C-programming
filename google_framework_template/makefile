# git clone https://github.com/google/googletest.git
# export GTEST_DIR=~/googletest/googletest ,,,, echo $GTEST_DIR
# make new folder for testing
# g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc ar -rv libgtest.a gtest-all.o
# Unit test g++ -isystem ${GTEST_DIR}/include -pthread unit_test_case.c code_to_be_tested.c Gtest_main.c libgtest.a -o my_test

PROJ = testing
# Compiler
CC = gcc
# Include folder
INCLUDE = ./include/

# Source folder
SRC=./src/
# Debugging
#CFLAGS = -g -c -Wall -I$(INCLUDE)
# Release
#CFLAGS = -O -c -Wall -I$(INCLUDE)

# Compilation flags
#-c is to create the .o file(s)
#-I is to include the header directory 
CFLAGS = -c -I$(INCLUDE) -lpthread

#We could have also mentioned the list of source files 
#SOURCES =  profession.cpp employee.cpp main.cpp

#$(patsubst pattern,replacement,text)
#Below we assume that the .cpp source files are under $(SRC) directory

ifeq ($(CC), gcc)
OBJECTS := $(patsubst %.c,%.o,$(wildcard $(SRC)*.c))
else
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard $(SRC)*.cpp))
endif

# Name of executable
EXECUTABLE = $(PROJ)

#Here we define all rule and its dependencies
all: $(OBJECTS) $(EXECUTABLE)

# The $@ refers to the left side of : 
$(EXECUTABLE) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $@ $(LIBS) -lpthread

#The $< refers to the first item in the dependency list
#The $@ refers the target file, file.o.
#This is a suffix rule telling how to turn .cpp into .o file
.c.o: *.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)

clean_release:
	-rm -f $(OBJECTS)


# Make release
release: all clean_release

# ifdef LOCAL
# else
# endif

################### Google Test framework #######################
# ifdef LOCAL
# GTEST_DIR=~/googletest/googletest
GTEST_INCLUDE=-I $(GTEST_DIR)/include
# GTEST_LIB=libgtest.a
# else
# GTEST_DIR=
# GTEST_INCLUDE=
# GTEST_LIB=-lgtest
# endif


COPTS=-Wall -fpermissive
COPTS_COV=$(COPTS) -fprofile-arcs -ftest-coverage
LDFLAGS=-fprofile-arcs -ftest-coverage
COV_OUTPUT=./cov_output

TEST_DIR = ./test

test: $(TEST_DIR)/Gtest_main.o $(TEST_DIR)/unit_test_case.o $(SRC)code_to_be_tested.o $(GTEST_LIB) libgtest.a 
	g++  $(LDFLAGS) $(GTEST_INCLUDE) -pthread   $(TEST_DIR)/unit_test_case.o $(SRC)code_to_be_tested.o $(TEST_DIR)/Gtest_main.o  -o test_file
# $(TEST_DIR)_test.o
libgtest.a:
	g++ -isystem $(GTEST_DIR)/include -I $(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv  libgtest.a gtest-all.o

Gtest_main.o: $(TEST_DIR)/Gtest_main.c
	g++ -c $(TEST_DIR)/Gtest_main.c $(GTEST_INCLUDE) -o $(TEST_DIR)/Gtest_main.o

unit_test_case.o: $(TEST_DIR)/unit_test_case.c
	g++ -c $(COPTS) $(TEST_DIR)/unit_test_case.c $(GTEST_INCLUDE) -o $(TEST_DIR)/unit_test_case.o

code_to_be_tested.o: $(SRC)code_to_be_tested.c $(GTEST_INCLUDE) libgtest.a
	g++ -c $(SRC)code_to_be_tested.c $(GTEST_INCLUDE) -o $(SRC)code_to_be_tested.o 


################### Google Test framework #######################
