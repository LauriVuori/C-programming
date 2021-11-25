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

# hae gitistä gframework


PROJ_EXECUTABLE = main_release
FILE_FOR_TESTING = modb_server
C_FILES = modb_init
# Compiler
CC = gcc

ifeq ($(CC), gcc)
FILETYPE = c
else
FILETYPE = cpp
endif


#Here we define include dir
# INCLUDE = ./include -I /usr/include/modbus/
INCLUDE = ./include -I./modbus_lib/include/modbus/
SRC= ./src

CFLAGS = -c -I$(INCLUDE)
DEBUG_FLAGS = -g $(CFLAGS)
OBJECTS := $(patsubst %.$(FILETYPE),%.o,$(wildcard $(SRC)/*.$(FILETYPE)))

# LINKS = -lmodbus
LIB_FOLDER = -L./modbus_lib/lib/
LINKS =  -lmodbus
LD_PATH = -Wl,-rpath=./modbus_lib/lib/

$(PROJ_EXECUTABLE) : $(OBJECTS)
		$(CC) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) $(OBJECTS) -o $@ $(LINKS) 


# debug: $(OBJECTS)
# 	gcc $(DEBUG_FLAGS) src/main.c -o src/main.o
# 	gcc $(DEBUG_FLAGS) -lmodbus src/$(C_FILES).c -o src/$(C_FILES).o 
# 	gcc $(DEBUG_FLAGS) -lmodbus src/modb_incoming.c -o src/modb_incoming.o 
# 	gcc $(DEBUG_FLAGS) -lmodbus src/modb_createdata.c -o src/modb_createdata.o 
# 	gcc -g  $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) ./src/main.o ./src/$(C_FILES).o src/modb_incoming.o src/modb_createdata.o  -o $@ $(LINKS)
debug: $(OBJECTS)
	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/main.c -o src/main.o $(LINKS)
	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/$(C_FILES).c -o src/$(C_FILES).o $(LINKS)
	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/modb_incoming.c -o src/modb_incoming.o $(LINKS)
	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/modb_createdata.c -o src/modb_createdata.o $(LINKS)
	gcc -g  $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) ./src/main.o ./src/$(C_FILES).o src/modb_incoming.o src/modb_createdata.o  -o $@ $(LINKS)

all: $(OBJECTS) $(PROJ_EXECUTABLE)

.$(FILETYPE).o: *.h
	$(CC) $(CFLAGS) $< -o $@ 



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
COV_OUTPUT=./cov_output

test: $(TEST_DIR)/Gtest_main.o $(TEST_DIR)/unit_test_case.o $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o $(GTEST_LIB)/libgtest.a 
	g++  $(COPTS_COV) -pthread $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o $(TEST_DIR)/unit_test_case.o $(TEST_DIR)/Gtest_main.o $(GTEST_LIB)/libgtest.a -o unit_tests

$(GTEST_LIB)/libgtest.a:
	g++ -isystem $(GTEST_DIR)/include -I $(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc -o $(GTEST_LIB)/gtest-all.o
	ar -rv  $(GTEST_LIB)/libgtest.a $(GTEST_LIB)/gtest-all.o

$(TEST_DIR)/Gtest_main.o: $(TEST_DIR)/Gtest_main.c
	g++ -c $(TEST_DIR)/Gtest_main.c $(GTEST_INCLUDE) -o $(TEST_DIR)/Gtest_main.o

$(TEST_DIR)/unit_test_case.o: $(TEST_DIR)/unit_test_case.$(FILETYPE)
	g++ -c $(TEST_DIR)/unit_test_case.$(FILETYPE) $(GTEST_INCLUDE) -o $(TEST_DIR)/unit_test_case.o

$(TEST_DIR)/$(FILE_FOR_TESTING)_test.o: $(SRC)/$(FILE_FOR_TESTING).$(FILETYPE)
	g++  -c $(COPTS_COV) $(SRC)/$(FILE_FOR_TESTING).$(FILETYPE) -o $(TEST_DIR)/$(FILE_FOR_TESTING)_test.o

report:
# -rm -f $(TEST_DIR)/Gtest_main.gcda $(TEST_DIR)/Gtest_main.gcno $(TEST_DIR)/unit_test_case.gcda $(TEST_DIR)/unit_test_case.gcno
	lcov -rc lcov_branch_coverage=1 -c -i -d . -o .coverage.base
	lcov -rc lcov_branch_coverage=1 -c -d . -o .coverage.run
	lcov -rc lcov_branch_coverage=1 -d . -a .coverage.base -a .coverage.run -o .coverage.total
	genhtml --branch-coverage -o $(COV_OUTPUT) .coverage.total
	rm -f .coverage.base .coverage.run .coverage.total

clean:
	-rm -f $(OBJECTS) $(PROJ_EXECUTABLE) $(TEST_DIR)/*.o $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno unit_tests
	-rm -f .coverage.base .coverage.run .coverage.total
	-rm -f $(SRC)/debug.exe debug

clean_units:
	-rm -f $(TEST_DIR)/*.gcda $(TEST_DIR)/*.gcno