//
// Created by seraphond on 14/10/16.
//


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int i=0;


    switch (fork()){
        case -1:
            perror("erreur fork");
            exit (EXIT_FAILURE);
        case 0:
            for (i=0;i<100000000;i++){
                /*trololo */
            }
            printf("bouh\n");
            for (i=0;i<100000000;i++){
                /*trololo */
            }
            printf("proccessus %d est arrivé.\n",getpid());
            break;
        default:
            switch (fork()){
                case -1:
                    perror("erreur fork");
                    exit (EXIT_FAILURE);
                case 0:
                    for (i=0;i<100000000;i++){
                        /*trololo */
                    }
                    printf("bouh\n");
                    for (i=0;i<100000000;i++){
                        /*trololo */
                    }
                    printf("proccessus %d est arrivé.\n",getpid());
                    break;
                default:
                    switch (fork()){
                        case -1:
                            perror("erreur fork");
                            exit (EXIT_FAILURE);
                        case 0:
                            for (i=0;i<100000000;i++){
                                /*trololo */
                            }
                            printf("bouh\n");
                            for (i=0;i<100000000;i++){
                                /*trololo */
                            }
                            printf("proccessus %d est arrivé.\n",getpid());
                            break;
                        default:
                            switch (fork()){
                                case -1:
                                    perror("erreur fork");
                                    exit (EXIT_FAILURE);
                                case 0:
                                    for (i=0;i<100000000;i++){
                                        /*trololo */
                                    }
                                    printf("bouh\n");
                                    for (i=0;i<100000000;i++){
                                        /*trololo */
                                    }
                                    printf("proccessus %d est arrivé.\n",getpid());
                                    break;
                                default:
                                    switch (fork()){
                                        case -1:
                                            perror("erreur fork");
                                            exit (EXIT_FAILURE);
                                        case 0:
                                            for (i=0;i<100000000;i++){
                                                /*trololo */
                                            }
                                            printf("bouh\n");
                                            for (i=0;i<100000000;i++){
                                                /*trololo */
                                            }
                                            printf("proccessus %d est arrivé.\n",getpid());
                                            break;
                                        default:
                                            switch (fork()){
                                                case -1:
                                                    perror("erreur fork");
                                                    exit (EXIT_FAILURE);
                                                case 0:
                                                    for (i=0;i<100000000;i++){
                                                        /*trololo */
                                                    }
                                                    printf("bouh\n");
                                                    for (i=0;i<100000000;i++){
                                                        /*trololo */
                                                    }
                                                    printf("proccessus %d est arrivé.\n",getpid());
                                                    break;
                                                default:
                                                    switch (fork()){
                                                        case -1:
                                                            perror("erreur fork");
                                                            exit (EXIT_FAILURE);
                                                        case 0:
                                                            for (i=0;i<100000000;i++){
                                                                /*trololo */
                                                            }
                                                            printf("bouh\n");
                                                            for (i=0;i<100000000;i++){
                                                                /*trololo */
                                                            }
                                                            printf("proccessus %d est arrivé.\n",getpid());
                                                            break;
                                                        default:
                                                            switch (fork()){
                                                                case -1:
                                                                    perror("erreur fork");
                                                                    exit (EXIT_FAILURE);
                                                                case 0:
                                                                    for (i=0;i<100000000;i++){
                                                                        /*trololo */
                                                                    }
                                                                    printf("bouh\n");
                                                                    for (i=0;i<100000000;i++){
                                                                        /*trololo */
                                                                    }
                                                                    printf("proccessus %d est arrivé.\n",getpid());
                                                                    break;
                                                                default:
                                                                    switch (fork()){
                                                                        case -1:
                                                                            perror("erreur fork");
                                                                            exit (EXIT_FAILURE);
                                                                        case 0:
                                                                            for (i=0;i<100000000;i++){
                                                                                /*trololo */
                                                                            }
                                                                            printf("bouh\n");
                                                                            for (i=0;i<100000000;i++){
                                                                                /*trololo */
                                                                            }
                                                                            printf("proccessus %d est arrivé.\n",getpid());
                                                                            break;
                                                                        default:
                                                                            switch (fork()){
                                                                                case -1:
                                                                                    perror("erreur fork");
                                                                                    exit (EXIT_FAILURE);
                                                                                case 0:
                                                                                    for (i=0;i<100000000;i++){
                                                                                        /*trololo */
                                                                                    }
                                                                                    printf("bouh\n");
                                                                                    for (i=0;i<100000000;i++){
                                                                                        /*trololo */
                                                                                    }
                                                                                    printf("proccessus %d est arrivé.\n",getpid());
                                                                                    break;
                                                                                default:
                                                                                    break;
                                                                                }
                                                                            break;
                                                                        }
                                                                    break;
                                                            }
                                                            break;
                                                    }
                                                    break;
                                            }
                                            break;
                                    }
                                    break;
                            }
                            break;
                    }


                    break;
            }
            /* afficher ls pid*/

            wait(NULL);
            wait(NULL);
            wait(NULL);
            wait(NULL);
            wait(NULL);
            wait(NULL);
            wait(NULL);
            wait(NULL);
            wait(NULL);
            wait(NULL);
            break;

    }


}