
CC = gcc

INCLUDE = ./include
SRC=./src/

CFLAGS = -c -I$(INCLUDE)


OBJECTS := $(patsubst %.c,%.o,$(wildcard $(SRC)*.c))


EXECUTABLE = runcypher


all: $(OBJECTS) $(EXECUTABLE)


$(EXECUTABLE) : $(OBJECTS)
		$(CC) $(OBJECTS) -o $@ $(LIBS)
.c.o: *.h
	$(CC) $(CFLAGS) $< -o $@

clean :
	-rm -f $(OBJECTS) $(EXECUTABLE)



full: all clean