CC=gcc
CFLAGS=-Wall -g
LD_FLAGS=-L. 
BINS=libfunc.o librarytest.o header.h libstaticcode.a static_librarytest libfunc1.so run_librarytest
all: $(BINS)

#static
libstaticcode.a: libfunc.o
	ar rcs libstaticcode.a libfunc.o
static_librarytest: librarytest.c
	$(CC) -o $@ $^ $(LD_FLAGS) -lstaticcode



#dynamic
libfunc1.so: libfunc.c header.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ libfunc.c
run_librarytest: libfunc.c
	$(CC) -o $@ $^ $(LD_FLAGS) -lfunc1

clean:
	rm *.o *.so *.a *.exe