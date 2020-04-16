CC=gcc
CFLAGS=-Wall -g
BINS=librarytest libstaticcode.a static_librarytest libfunc.so run_librarytest
all: $(BINS)


#static
libstaticcode.a: libfunc.o
	ar rcs libstaticcode.a libfunc.o
static_librarytest: librarytest.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lstaticcode



#dynamic
libfunc.so: libfunc.c header.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ libfunc.c -lc
run_librarytest: librarytest.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lfunc

clean:
	rm *.o $(BINS)