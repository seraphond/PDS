CC      = gcc
## Options pour la compilation
CFLAGS  = -Wall -Werror -ansi -pedantic
CFLAGS += -D_XOPEN_SOURCE=500
CFLAGS += -g

all: realclean Course_pid.beta TpZombis.beta

exe:
./Course_pid.beta

Course_pid.beta:
${CC} ${CFLAGS} -o Course_pid.beta Course_pid.c

TpZombis.beta:
${CC} ${CFLAGS} -o TpZombis.beta TpZombis.c

realclean:
rm *.beta || true

## Liste des pseudo-cibles
.PHONY: all clean realclean