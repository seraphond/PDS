CC=gcc
CFLAGS=-Wall -Werror -ansi 
CFLAGS+=-D_XOPEN_SOURCE=500
CFLAGS+=-g

all: prlimit.exe Maccess.exe Maccess+.exe test

prlimit.exe:prlimit.c Maccess.exe
	$(CC) prlimit.c -o prlimit.exe $(CFLAGS)
Maccess.exe:Maccess.c Maccess+.exe
	$(CC) Maccess.c -o Maccess.exe $(CFLAGS)
Maccess+.exe:Maccess+.c
	$(CC) Maccess+.c -o Maccess+.exe $(CFLAGS)

clean:
	rm -rf *.exe
test:
	chmod +x test.sh	
	./test.sh
