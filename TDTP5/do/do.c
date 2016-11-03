//
// Created by seraphond on 03/11/16.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main (int argc,char** argv){
    int  i,j,res;

    i=2;
    res=0;
    int pfid,status,temp;
    temp=pfid=status=0;

    if(strcmp(argv[1],"--cc")==0){
        i++;
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
            if(WIFEXITED(pfid)){
                return WEXITSTATUS(pfid); // dans le AND si ca marche pas  on arrète et on retourne la valeur
            }
            temp = WEXITSTATUS(pfid);
            for (j = 4; j < i; j++) {
                wait(&pfid);
                res = temp & WEXITSTATUS(pfid);
                if(WIFEXITED(pfid)){
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
            if(WIFEXITED(pfid)){
                return temp; // dans le OR si ca marche on arrète et on retourne la valeur
            }

            res=temp;
            for (j = 4; j < i; j++) {
                wait(&pfid);
                res = temp | WEXITSTATUS(pfid);
                if(WIFEXITED(pfid)){
                    return WEXITSTATUS(pfid); // dans le OR si ca marche on arrète et on retourne la valeur
                }

            }

            return res;


        } else {
            //ni or ni and
            printf("wrong !\n");
            exit(EXIT_FAILURE);

        }


    }else {


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