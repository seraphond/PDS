/* mshell - a job manager */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include "pipe.h"

void do_pipe(char *cmds[MAXCMDS][MAXARGS], int nbcmd, int bg) {


    int pid;
    int fd[2];

     pipe(fd);


    switch (fork()){
        case -1:
            perror("erreur fork");
            exit(EXIT_FAILURE);
     case 0:
            close(fd[0]);
            dup2(fd[1],STDOUT_FILENO);
            close(fd[1]);
            printf("je passe ici");
            execvp(cmds[0][0],cmds[0]);

        default:

            break;
    }

    switch (pid=fork()){
        case -1:
            perror("erreur fork");
            exit(EXIT_FAILURE);
        case 0:
            close(fd[1]);
            dup2(fd[0],STDIN_FILENO);
            close(fd[0]);
            execvp(cmds[1][0],cmds[1]);
        default:
            ;
    }

    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);



    return;
}
