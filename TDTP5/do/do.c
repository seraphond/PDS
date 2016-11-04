//
// Created by seraphond on 03/11/16.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main (int argc,char** argv) {
    int i, j, res,cpt,cpt2;
    int * truc;

    i = 2;
    res = 0;
    int pfid, status, temp;
    cpt2=cpt=temp = pfid = status = 0;


    if (strcmp(argv[1], "--cc") == 0) {


        i++;
        if(strcmp(argv[2],"--kill")==0){
            i++; // variable gérant les commandes , on increment pour lui dire que --XXX n'est pas une commande

            if (strcmp(argv[3], "--and") == 0) {
                // conjontion
                if (argc > 4) {
                    while (i < argc) {
                        switch (truc[cpt]=fork()) { // on stocke les pid dans un tableau
                            case -1 :
                                perror("erreur fork");
                                return EXIT_FAILURE;
                            case 0:

                                system(argv[i]);
                                exit(EXIT_SUCCESS);
                            default:
                                // papa il glande

                                break;
                        }
                        cpt++;
                        i++;
                    }
                } else {
                    perror("WRONG!!!!!!!!!!  Number of param incorect");
                    exit(EXIT_FAILURE);
                }

                wait(&pfid);
                temp = WEXITSTATUS(pfid);
                cpt2++;
                if (WIFEXITED(pfid)) {
                    while(cpt2<cpt){
                        kill(truc[cpt2],SIGKILL);
                        cpt2++;
                    } // si ca loupe du 1er coup il faut tuer les autres process
                    return temp; // dans le AND si ca marche pas  on arrète et on retourne la valeur
                }

                temp = WEXITSTATUS(pfid);
                for (j = 5; j < i; j++) {
                    wait(&pfid);
                    res = temp & WEXITSTATUS(pfid);
                    if (WIFEXITED(pfid)) {
                        while(cpt2<cpt){
                            kill(truc[cpt2],SIGKILL); // on tue les process après celui qui loupe
                            cpt2++;
                        }
                        return res; // dans le AND si ca marche pas  on arrète et on retourne la valeur
                    }
                    cpt2++;
                }

                return res;

            } else if (strcmp(argv[3], "--or") == 0) {
                //disjonction
                if (argc > 4) {
                    while (i < argc) {
                        switch (truc[cpt]=fork()) {
                            case -1 :
                                perror("erreur fork");
                                return EXIT_FAILURE;
                            case 0:

                                system(argv[i]);
                                exit(EXIT_SUCCESS);
                            default:
                                // papa il glande

                                break;
                        }
                        cpt++;
                        i++;
                    }
                } else {

                    perror("WRONG!!!!!!! check your number of param");
                    exit(EXIT_FAILURE);
                }

                wait(&pfid);
                temp = WEXITSTATUS(pfid);
                cpt2++;
                if (WIFEXITED(pfid)) {
                    while(cpt2<cpt){
                        kill(truc[cpt2],SIGKILL); // on tue les process après celui qui réussi
                        cpt2++;
                    }
                    return temp; // dans le OR si ca marche on arrète et on retourne la valeur
                }

                res = temp;
                for (j = 5; j < i; j++) {
                    wait(&pfid);
                    res = temp | WEXITSTATUS(pfid);
                    if (WIFEXITED(pfid)) {
                        while(cpt2<cpt){
                            kill(truc[cpt2],SIGKILL); // on tue les process après celui qui réussi
                            cpt2++;
                        }
                        return res; // dans le OR si ca marche on arrète et on retourne la valeur
                    }
                    cpt2++;
                }

                return res;


            } else {
                //ni or ni and
                printf("wrong !\n");
                exit(EXIT_FAILURE);

            }

        } else {
            if (strcmp(argv[2], "--and") == 0) {
                // conjontion
                if (argc > 3) {
                    while (i < argc) {
                        switch (fork()) {
                            case -1 :
                                perror("erreur fork");
                                return EXIT_FAILURE;
                            case 0:

                                system(argv[i]);
                                exit(EXIT_SUCCESS);
                            default:
                                // papa il glande

                                break;
                        }
                        i++;
                    }
                } else {
                    perror("WRONG!!!!!!!!!!  Number of param incorect");
                    exit(EXIT_FAILURE);
                }

                wait(&pfid);
                temp = WEXITSTATUS(pfid);
                if (WIFEXITED(pfid)) {
                    return WEXITSTATUS(pfid); // dans le AND si ca marche pas  on arrète et on retourne la valeur
                }
                temp = WEXITSTATUS(pfid);
                for (j = 4; j < i; j++) {
                    wait(&pfid);
                    res = temp & WEXITSTATUS(pfid);
                    if (WIFEXITED(pfid)) {
                        return res; // dans le AND si ca marche pas  on arrète et on retourne la valeur
                    }

                }

                return res;

            } else if (strcmp(argv[2], "--or") == 0) {
                //disjonction
                if (argc > 3) {
                    while (i < argc) {
                        switch (fork()) {
                            case -1 :
                                perror("erreur fork");
                                return EXIT_FAILURE;
                            case 0:

                                system(argv[i]);
                                exit(EXIT_SUCCESS);
                            default:
                                // papa il glande

                                break;
                        }
                        i++;
                    }
                } else {

                    perror("WRONG!!!!!!! check your number of param");
                    exit(EXIT_FAILURE);
                }

                wait(&pfid);
                temp = WEXITSTATUS(pfid);
                if (WIFEXITED(pfid)) {
                    return temp; // dans le OR si ca marche on arrète et on retourne la valeur
                }

                res = temp;
                for (j = 4; j < i; j++) {
                    wait(&pfid);
                    res = temp | WEXITSTATUS(pfid);
                    if (WIFEXITED(pfid)) {
                        return WEXITSTATUS(pfid); // dans le OR si ca marche on arrète et on retourne la valeur
                    }

                }

                return res;


            } else {
                //ni or ni and
                printf("wrong !\n");
                exit(EXIT_FAILURE);

            }
        }

    } else {


        if (strcmp(argv[1], "--and") == 0) {
            // conjontion
            if (argc > 2) {
                while (i < argc) {
                    switch (fork()) {
                        case -1 :
                            perror("erreur fork");
                            return EXIT_FAILURE;
                        case 0:

                            system(argv[i]);
                            exit(EXIT_SUCCESS);
                        default:
                            // papa il glande

                            break;
                    }
                    i++;
                }
            } else {
                perror("WRONG!!!!!!!!!!  Number of param incorect");
                exit(EXIT_FAILURE);
            }

            wait(&pfid);
            temp = WEXITSTATUS(pfid);
            for (j = 3; j < i; j++) {
                wait(&pfid);
                res = temp & WEXITSTATUS(pfid);

            }

            return res;

        } else if (strcmp(argv[1], "--or") == 0) {
            //disjonction
            if (argc > 2) {
                while (i < argc) {
                    switch (fork()) {
                        case -1 :
                            perror("erreur fork");
                            return EXIT_FAILURE;
                        case 0:

                            system(argv[i]);
                            exit(EXIT_SUCCESS);
                        default:
                            // papa il glande

                            break;
                    }
                    i++;
                }
            } else {

                perror("WRONG!!!!!!! check your number of param");
                exit(EXIT_FAILURE);
            }

            wait(&pfid);
            temp = WEXITSTATUS(pfid);
            for (j = 3; j < i; j++) {
                wait(&pfid);
                res = temp | WEXITSTATUS(pfid);

            }

            return res;


        } else {
            //ni or ni and
            printf("wrong !\n");
            exit(EXIT_FAILURE);

        }

    }


}