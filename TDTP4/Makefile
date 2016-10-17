CC      = gcc
## Options pour la compilation
CFLAGS  = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

#all: realclean mtail.beta

#exe: ./mtail-17-18 mtail-16.c 8

mcat_scd.beta: mcat-scd.c
	${CC} ${CFLAGS} -o mcat_scd.beta mcat-scd.c


realclean:
	rm *.beta || true

## Liste des pseudo-cibles
.PHONY: all clean realclean
