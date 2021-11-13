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

PROJ_EXECUTABLE = main_release
FILE_FOR_TESTING = ring_buffer

# Compiler
CC = gcc

ifeq ($(CC), gcc)
FILETYPE = c
else
FILETYPE = cpp
endif


#Here we define include dir
INCLUDE = ./include
SRC= ./src

CFLAGS = -c -I$(INCLUDE) -lpthread

OBJECTS := $(patsubst %.$(FILETYPE),%.o,$(wildcard $(SRC)/*.$(FILETYPE)))



$(PROJ_EXECUTABLE) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $@ $(LIBS) -lpthread

all: $(OBJECTS) $(PROJ_EXECUTABLE)

.$(FILETYPE).o: *.h
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(PROJ_EXECUTABLE) $(TEST_DIR)/*.o $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno
	# -rm -f $(OBJECTS) $(PROJ_EXECUTABLE)  $(TEST_DIR)/Gtest_main.o $(TEST_DIR)/unit_test_case.o 
	# -rm -f $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o
	# -rm -f $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno test_file

# ################### Google Test framework #######################
# # ifdef LOCAL
# # GTEST_DIR=~/googletest/googletest
GTEST_INCLUDE=-I $(GTEST_DIR)/include
GTEST_LIB = ./g_lib
TEST_DIR=./test
# # else
# GTEST_DIR=
# # GTEST_INCLUDE=
# # GTEST_LIB=-lgtest
# # endif

# FLAGS = -Wall
# # COPTS= -Wall -fpermissive
COPTS= -Wall -fpermissive
COPTS_COV= $(COPTS) -fprofile-arcs -ftest-coverage
# LDFLAGS=-fprofile-arcs -ftest-coverage
# COV_OUTPUT=./cov_output

# TEST_DIR = ./test
# # change location of lib
# test: Gtest_main.o unit_test_case.o $(FILE_FOR_TESTING)_test.o $(GTEST_LIB)/libgtest.a  
# 	g++  $(COPTS) -pthread $(TEST_DIR)/Gtest_main.o $(TEST_DIR)/unit_test_case.o $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o $(GTEST_LIB)/libgtest.a -o $(TEST_FILE)

# $(GTEST_LIB)/libgtest.a:
# 	g++ -isystem $(GTEST_INCLUDE) -pthread -c $(GTEST_DIR)/src/gtest-all.cc -o $(GTEST_LIB)/gtest-all.o

test: $(TEST_DIR)/Gtest_main.o $(TEST_DIR)/unit_test_case.o $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o $(GTEST_LIB)/libgtest.a
	g++  $(COPTS_COV) -pthread $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o $(TEST_DIR)/unit_test_case.o $(TEST_DIR)/Gtest_main.o $(GTEST_LIB)/libgtest.a -o unit_tests

$(GTEST_LIB)/libgtest.a:
	g++ -isystem $(GTEST_DIR)/include -I $(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc -o $(GTEST_LIB)/gtest-all.o
	ar -rv  $(GTEST_LIB)/libgtest.a $(GTEST_LIB)/gtest-all.o

$(TEST_DIR)/Gtest_main.o: $(TEST_DIR)/Gtest_main.c
	g++ -c $(COPTS_COV) $(TEST_DIR)/Gtest_main.c $(GTEST_INCLUDE) -o $(TEST_DIR)/Gtest_main.o

$(TEST_DIR)/unit_test_case.o: $(TEST_DIR)/unit_test_case.$(FILETYPE)
	g++ -c $(COPTS_COV) $(TEST_DIR)/unit_test_case.$(FILETYPE) $(GTEST_INCLUDE) -o $(TEST_DIR)/unit_test_case.o

$(TEST_DIR)/$(FILE_FOR_TESTING)_test.o: $(SRC)/$(FILE_FOR_TESTING).$(FILETYPE)
	g++  -c $(COPTS_COV) $(SRC)/$(FILE_FOR_TESTING).$(FILETYPE) -o $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o

report: rm_gmain
	lcov -rc lcov_branch_coverage=1 -c -i -d . -o .coverage.base
	lcov -rc lcov_branch_coverage=1 -c -d . -o .coverage.run
	lcov -rc lcov_branch_coverage=1 -d . -a .coverage.base -a .coverage.run -o .coverage.total
	genhtml --branch-coverage -o $(COV_OUTPUT) .coverage.total
	# rm -f .coverage.base .coverage.run .coverage.total
	# rm -f ringbuffer_test.gcda ringbuffer_test.gcno
