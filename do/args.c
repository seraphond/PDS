#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "makeargv.h"

/* Démonstration de l’utilisation des fonctions makeargv et freeargv */

int main(int argc, char *argv[]) {
    int i, j;
    char **cmdargv;
    char **arg;

    for (i = 1; i < argc; i++) {
        /* création du argv de l'argument i */
        cmdargv = makeargv(argv[i]);
        assert(cmdargv != NULL);

        /* test: affichage */
        j = 0;
        arg = cmdargv;
        fprintf(stderr, "makeargv(\"%s\") retourne un tableau argv tel que :\n", argv[i]);
        do {
            if(*arg)
                fprintf(stderr, "  argv[%d] = %s\n", j, *arg);
            else
                fprintf(stderr, "  argv[%d] = %s\n", j, "NULL");
            j++;
        } while (*arg++);
        fprintf(stderr, "\n");

        /* libération mémoire */
        freeargv(cmdargv);
    }

    exit(EXIT_SUCCESS);
}
