CC      = gcc
## Options pour la compilation
CFLAGS  = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

all: realclean mtail.beta

exe:
	./mtail.beta mtail.c 2

mtail.beta:
	${CC} ${CFLAGS} -o mtail.beta mtail.c

realclean:
	rm *.beta || true

## Liste des pseudo-cibles
.PHONY: all clean realclean
