PROJ_EXECUTABLE = main_release
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



debug: $(OBJECTS)
	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/main.c -o src/main.o $(LINKS)
	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/$(C_FILES).c -o src/$(C_FILES).o $(LINKS)
	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/modb_incoming.c -o src/modb_incoming.o $(LINKS)
	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/modb_createdata.c -o src/modb_createdata.o $(LINKS)
	gcc -g  $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) ./src/main.o ./src/$(C_FILES).o src/modb_incoming.o src/modb_createdata.o  -o $@ $(LINKS)


.$(FILETYPE).o: *.h
	$(CC) $(CFLAGS) $< -o $@ 


clean:
	-rm -f $(OBJECTS) $(PROJ_EXECUTABLE) $(TEST_DIR)/*.o
	-rm -f $(SRC)/debug.exe debug

