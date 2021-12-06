# src kansioon ja include kansioon voidaan vapaasti lisätä tiedostoja.

# executable
PROJ_EXECUTABLE = main_release
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
#flagit
CFLAGS = -c -I$(INCLUDE)
DEBUG_FLAGS = -g $(CFLAGS)
OBJECTS := $(patsubst %.$(FILETYPE),%.o,$(wildcard $(SRC)/*.$(FILETYPE)))

# Tiedot modbus kirjastosta
LIB_FOLDER = -L./modbus_lib/lib/
LINKS =  -lmodbus
LD_PATH = -Wl,-rpath=./modbus_lib/lib/
#luodaan executable
$(PROJ_EXECUTABLE) : $(OBJECTS)
		$(CC) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) $(OBJECTS) -o $@ $(LINKS) 


# debug filen luonti. Debug asetuksissa täytyy ajaa pelkästään debug.out tiedostoa
# debug ei jostain syystä löydä luotua kirjastoa
# debug.out: $(OBJECTS)
# 	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/main.c -o src/main.o $(LINKS)
# 	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/modb_init.c -o src/modb_init.o $(LINKS)
# 	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/modb_incoming.c -o src/modb_incoming.o $(LINKS)
# 	gcc $(DEBUG_FLAGS) $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) src/modb_createdata.c -o src/modb_createdata.o $(LINKS)
# 	gcc -g  $(LIB_FOLDER) $(LD_PATH) -I$(INCLUDE) ./src/main.o ./src/modb_init.o src/modb_incoming.o src/modb_createdata.o  -o $@ $(LINKS)

#objekti tiedostojen luonti
.$(FILETYPE).o: *.h
	$(CC) $(CFLAGS) $< -o $@ 


clean:
	-rm -f $(OBJECTS) $(PROJ_EXECUTABLE)