CC      = gcc
## Options pour la compilation
CFLAGS  = -Wall -Werror 
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

all: realclean mtail-16.beta mtail-17-18.beta

test:
	./mtail-17-18.beta mtail-16.c 8

mtail-16.beta:
	${CC} ${CFLAGS} -o mtail-16.beta mtail-16.c

mtail-17-18.beta:
	${CC} ${CFLAGS} -o mtail-17-18.beta mtail-17-18.c

realclean:
	rm *.beta || true

## Liste des pseudo-cibles
.PHONY: all clean realclean
