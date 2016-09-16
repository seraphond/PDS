cc=gcc
CFLAGS=-Wall -Werror -ansi 
CFLAGS+=-D_XOPEN8SOURCE=500
CFLAGS+=-g

prlimit:prlimit.o
	$(CC) -o prlimit 

prlimit.o:prlimit.c
	$(CC) -o prlimit.o -c prlimit.c $(CFLAGS)

clean:
	rm -rf *.o
 
