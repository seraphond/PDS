//
// Created by seraphond on 14/10/16.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

typedef void (*func_t) (void*);

void fork_fork(func_t f,void *arg){
    int pidpf =-1;
    int pfid=0 ;
    printf("coucou , je suis le pere et mon pid c'est: %d\n",getpid());
    switch (fork()){
        /*fils */
        case 0:
            printf("coucou , je suis le fils et mon pid c'est: %d\n",getpid());
            pidpf = fork();
            switch (pidpf){
                case -1:
                    perror("erreur fork");
                    exit (EXIT_FAILURE);
                    /*petit-fils*/
                case 0:
                    printf("coucou , je suis le petit fils et mon pid c'est: %d et mon pere c'est : %d\n",getpid(),getppid());
                    f(arg);
                    printf("coucou , je suis le petit fils et mon pid c'est: %d et mon pere c'est : %d\n",getpid(),getppid());
                    exit(EXIT_SUCCESS);
                default:
                    exit(pidpf);
            }

        case -1:
                perror("erreur fork");
                exit(EXIT_FAILURE);
        default:

            wait(&pfid);

            printf("le pid de petit fils est %d\n",WEXITSTATUS(pfid)); /* on peut pas faire mieux  et ca coute  3fois
 plus en mémoire*/

    }

}

int main(){

    void p(){
        sleep(10);
    }
    void * truc=NULL;
    fork_fork(p,truc);
    return 0;

}