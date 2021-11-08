# git clone https://github.com/google/googletest.git
# export GTEST_DIR=~/googletest/googletest ,,,, echo $GTEST_DIR
# make new folder for testing
# g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} -pthread -c ${GTEST_DIR}/src/gtest-all.cc ar -rv libgtest.a gtest-all.o
# Unit test g++ -isystem ${GTEST_DIR}/include -pthread unit_test_case.c code_to_be_tested.c Gtest_main.c libgtest.a -o my_test

# when running test_file, unnecesary in test folder, should be fixed

# commands
# make
# make release
# make test
# make report

PROJ = run_ring
FILE_FOR_TESTING = ring_buffer
# Compiler
CC = gcc
ifeq ($(CC), gcc)
FILETYPE = c
else
FILETYPE = cpp
endif

# Include folder
INCLUDE = ./include/
TEST_FILE = test_file
# Source folder
SRC=./src
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


OBJECTS := $(patsubst %.$(FILETYPE),%.o,$(wildcard $(SRC)/*.$(FILETYPE)))


# Name of executable
EXECUTABLE = $(PROJ)

# The $@ refers to the left side of : 
$(EXECUTABLE) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $@ $(LIBS) -lpthread

#The $< refers to the first item in the dependency list
#The $@ refers the target file, file.o.
#This is a suffix rule telling how to turn .cpp into .o file
.c.o: *.h
	$(CC) $(CFLAGS) $< -o $@

# ifdef LOCAL
# else
# endif

################### Google Test framework #######################
# ifdef LOCAL
# GTEST_DIR=~/googletest/googletest
GTEST_INCLUDE=-I $(GTEST_DIR)/include
GTEST_LIB = ./g_lib
# else
# GTEST_DIR=
# GTEST_INCLUDE=
# GTEST_LIB=-lgtest
# endif

FLAGS = -Wall
# COPTS= -Wall -fpermissive
COPTS= -Wall
COPTS_COV= $(COPTS) -fprofile-arcs -ftest-coverage
LDFLAGS=-fprofile-arcs -ftest-coverage
COV_OUTPUT=./cov_output

TEST_DIR = ./test
# change location of lib
test: Gtest_main.o unit_test_case.o $(FILE_FOR_TESTING)_test.o $(GTEST_LIB)/libgtest.a  
	g++  $(LDFLAGS) -pthread $(TEST_DIR)/Gtest_main.o $(TEST_DIR)/unit_test_case.o $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o $(GTEST_LIB)/libgtest.a -o $(TEST_FILE)

$(GTEST_LIB)/libgtest.a:
	g++ -isystem $(GTEST_DIR)/include -I $(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc -o $(GTEST_LIB)/gtest-all.o
	ar -rv  $(GTEST_LIB)/libgtest.a $(GTEST_LIB)/gtest-all.o

Gtest_main.o: $(TEST_DIR)/Gtest_main.c
	g++ -c $(TEST_DIR)/Gtest_main.c $(GTEST_INCLUDE) -o $(TEST_DIR)/Gtest_main.o

unit_test_case.o: $(TEST_DIR)/unit_test_case.$(FILETYPE)
	g++ -c $(COPTS) $(TEST_DIR)/unit_test_case.$(FILETYPE) $(GTEST_INCLUDE) -I $(SRC)/$(FILE_FOR_TESTING)/ -o $(TEST_DIR)/unit_test_case.o

$(FILE_FOR_TESTING)_test.o: $(SRC)/$(FILE_FOR_TESTING).c 
	$(CC) -c $(COPTS_COV) $(FLAGS) $(SRC)/$(FILE_FOR_TESTING).c -o $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o


# $(FILE_FOR_TESTING)_test.gcno:
# 	./test_file

################### Coverage analysis #######################

report:
	gcc $(COPTS_COV) -isystem ${GTEST_DIR}/include -pthread -I$(SRC)/ $(GTEST_LIB)/libgtest.a $(SRC)/main.c $(SRC)/$(FILE_FOR_TESTING).$(FILETYPE) -o branch
	./branch
	lcov -rc lcov_branch_coverage=1 -c -i -d . -o .coverage.base
	lcov -rc lcov_branch_coverage=1 -c -d . -o .coverage.run
	lcov -rc lcov_branch_coverage=1 -d . -a .coverage.base -a .coverage.run -o .coverage.total
	genhtml --branch-coverage -o $(COV_OUTPUT) .coverage.total
	rm -f .coverage.base .coverage.run .coverage.total branch  $(FILE_FOR_TESTING).gcno $(FILE_FOR_TESTING).gcda
	rm -f main.gcda main.gcno branch 
	rm -f ring_buffer.gcno  unit_test_case.gcno
	

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)  $(TEST_DIR)/Gtest_main.o $(TEST_DIR)/unit_test_case.o 
	-rm -f $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o

clean_release:
	-rm -f $(OBJECTS)

clean_all: 
	-rm -f $(OBJECTS) $(EXECUTABLE)  $(TEST_DIR)/Gtest_main.o $(TEST_DIR)/unit_test_case.o 
	-rm -f $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o
	-rm -f -r $(COV_OUTPUT)/* $(GTEST_LIB)/* test_file