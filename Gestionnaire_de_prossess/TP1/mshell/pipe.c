/* mshell - a job manager */

#include <stdio.h>
#include "pipe.h"

void do_pipe(char *cmds[MAXCMDS][MAXARGS], int nbcmd, int bg) {
    //TODO:début de la fonction
    /*
     * passer les arguments
     *
     * tableau de descripteurs de fichiers
     */
    int ld[2];
     pipe[fd];

    /*
     * on creer un fils
     */
    switch (fork()){
        case -1:
            perror(stderr,"erreur fork");
            exit(EXIT_FAILURE);
            /*
   * rediriger la sortie standard vers l'entrée de la 2eme cmd
   */
        case 0:
            close(fd[0]);
            dup2(fd[1],STDOUT_FILENO);
            close(fd[1]); // close file descriptor as soon as possible
            /* execute
     *
     */
            execvp(cmd1,argv[0]);

        default:

            break;
    }

    switch (pid=fork()){
        case -1:
            perror(stderr,"erreur fork");
            exit(EXIT_FAILURE);
        case 0:
            close(fd[1]);
            dup2(fd[0],STDIN_FILENO);
            close(fd[0]);
            execvp(cmd2,argv[1]);
        default:
            ;
    }
    close(fd[0]);
    close(fd[1]);
    wait(NULL);
    wait(NULL);



    return;
}
