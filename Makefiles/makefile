CC=gcc
CFLAGS=-Wall -g
BINS=librarytest libstaticcode.a static_librarytest libfunc.so run_librarytest
all: $(BINS)

libfunc.o: libfunc.c header.h
	$(CC) $(CFLAGS) -c libfunc.c

libfunc.so: libfunc.c header.h
	$(CC) $(CFLAGS) -fPIC -shared -o $@ libfunc.c -lc

libstaticcode.a: libfunc.o
	ar rcs libstaticcode.a libfunc.o

static_librarytest: librarytest.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lstaticcode

librarytest: librarytest.c libfunc.o
	$(CC) $(CFLAGS) -o $@ $^

run_librarytest: librarytest.c
	$(CC) $(CFLAGS) -o $@ $^ -L. -lfunc

clean:
	rm *.o $(BINS)