//
// Created by seraphond on 14/10/16.
//

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
            printf("bouh");
            for (i=0;i<100000000;i++){
                /*trololo */
            }
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
                    printf("bouh");
                    for (i=0;i<100000000;i++){
                        /*trololo */
                    }
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
                            printf("bouh");
                            for (i=0;i<100000000;i++){
                                /*trololo */
                            }
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
                                    printf("bouh");
                                    for (i=0;i<100000000;i++){
                                        /*trololo */
                                    }
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
                                            printf("bouh");
                                            for (i=0;i<100000000;i++){
                                                /*trololo */
                                            }
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
                                                    printf("bouh");
                                                    for (i=0;i<100000000;i++){
                                                        /*trololo */
                                                    }
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
                                                            printf("bouh");
                                                            for (i=0;i<100000000;i++){
                                                                /*trololo */
                                                            }
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
                                                                    printf("bouh");
                                                                    for (i=0;i<100000000;i++){
                                                                        /*trololo */
                                                                    }
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
                                                                            printf("bouh");
                                                                            for (i=0;i<100000000;i++){
                                                                                /*trololo */
                                                                            }
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
                                                                                    printf("bouh");
                                                                                    for (i=0;i<100000000;i++){
                                                                                        /*trololo */
                                                                                    }
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
            wait(null);
            break;

    }

}