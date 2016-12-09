/* mshell - a job manager */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "pipe.h"
#include <sys/wait.h>
/*
void do_pipe(char *cmds[MAXCMDS][MAXARGS], int nbcmd, int bg) {

    int i,j;
    int pipes[MAXCMDS][2];

    //On a besoin de nbcmd - 1 pipe pour les comm
    for(i = 0; i < nbcmd-1; i++){
        pipe(pipes[i]);
    }

    //Premier fils où on ne connecte que la sortie au pipe
    switch(fork()){
        case -1:
            perror("Erreur fork debut");
            exit(EXIT_FAILURE);
        case 0:
            dup2(pipes[0][1],STDOUT_FILENO);
            close(pipes[0][1]);
            execvp(cmds[0][0],cmds[0]);
        default:
            close(pipes[0][1]);
            close(pipes[0][0]);
            break;
    }
    //Fils intermediaires où on connecte l'entrée et la sortie
    for (i = 1; i < nbcmd-1; i++) {
        switch (fork()){
            case -1:
                perror("Erreur fork milieu");
                exit(EXIT_FAILURE);
            case 0:
                dup2(pipes[i-1][0],STDIN_FILENO);
                dup2(pipes[i][1],STDOUT_FILENO);
                close(pipes[i-1][0]);
                close(pipes[i][1]);
                execvp(cmds[i][0],cmds[i]);
            default:
                close(pipes[i][0]);
                close(pipes[i][1]);
                break;
        }
    }
    //Dernier fils ou on ne connecte que l'entrée
    switch(fork()){
        case -1:
            perror("Erreur fork fin");
            exit(EXIT_FAILURE);
        case 0:
            dup2(pipes[i][0],STDIN_FILENO);//ou i-1 si erreur index
            close(pipes[i][0]);
            execvp(cmds[nbcmd-1][0],cmds[nbcmd-1]);
        default:
            close(pipes[i][0]);
            close(pipes[i][1]);
            break;
    }
    //On attends tout le monde
    for (j = 0; j < nbcmd; ++j) {
        wait(NULL);
    }
    return;
}
*/
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
            execvp(cmds[0][0],cmds[0]);
        default:
            break;
    }

    switch (fork()){
        case -1:
            perror("erreur fork");
            exit(EXIT_FAILURE);
        case 0:
            close(fd[1]);
            dup2(fd[0],STDIN_FILENO);
            close(fd[0]);
            execvp(cmds[1][0],cmds[1]);
        default:
            break;
    }

    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);

    return;


}
