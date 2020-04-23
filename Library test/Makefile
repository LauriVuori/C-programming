#all: library.cpp main.cpp
#$@ evaluates to all
#$< evaluates to library.cpp
#$^ evaluates to library.cpp main.cpp
#ar t (static lib insides)
#nm -D (dynamic..)




CC=gcc
CFLAGS=-Wall -fPIC
LD_FLAGS=-L.
RUN=normal createdyna linkversion rundynamic staticlib runstatic
all: $(RUN)

#normal linking----------
normal: main.o function.o function2.o 
	$(CC) $(CFLAGS) $^ -o $@
#-----------------------



#dynamic linking--------
createdyna: 
	$(CC) -shared -Wl,-soname,libdynamic.so.1.0 -o libdynamic.so.1.0 *.o

linkversion:
	ln -sf libdynamic.so.1.0 libdynamic.so

rundynamic: main.c
	$(CC) -Wall $^ -L. -ldynamic -o $@
#-----------------------

#static linking--------
staticlib: function.o function2.o
	ar rcs libstatic.a $^

runstatic: main.o
	$(CC) -o $@ $^ $(LD_FLAGS) -lstatic

#----------------------
clean:
	rm *.o *.so normal runstatic rundynamic libdynamic.so.1.0 *.a 