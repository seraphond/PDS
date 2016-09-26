CC=gcc
CFLAGS=-Wall -Werror -ansi
CFLAGS+=-D_XOPEN_SOURCE=500
CFLAGS+=-g

all: mdu.beta test

mdu.beta: mdu.c
	gcc -Wall -Werror -ansi -D_XOPEN_SOURCE=500 -g -o mdu.beta mdu.c

test:
	chmod +x test.sh
	./test.sh

clean:
	rm -rf *.beta
