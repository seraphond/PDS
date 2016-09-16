CC=gcc
CFLAGS=-Wall -Werror -ansi 
CFLAGS+=-D_XOPEN_SOURCE=500
CFLAGS+=-g

prlimit.exe:prlimit.c Maccess.exe
	$(CC) prlimit.c -o prlimit.exe $(CFLAGS)
Maccess.exe:Maccess.c
	$(CC) Maccess.c -o Maccess.exe $(CFLAGS)

clean:
	rm -rf *.exe
 
