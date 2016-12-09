/* mshell - a job manager */

#include <stdio.h>
#include <signal.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "jobs.h"

#define BOLD "\033[00;01m"
#define NORM "\033[00;00m"
#define MAXJOBS      16              /* max jobs at any point in time */


void do_help() {
    printf("available commands are:\n");
    printf(" exit - cause the shell to exit\n");
    printf(BOLD "\t exit\n" NORM);
    printf(" jobs - display status of jobs in the current session\n");
    printf(BOLD "\t jobs\n" NORM);
    printf(" fg   - run a job identified by its pid or job id in the foreground\n");
    printf(BOLD "\t fg " NORM "pid" BOLD "|" NORM "jobid \n");
    printf(" bg   - run a job identified by its pid or job id in the background\n");
    printf(BOLD "\t bg " NORM "pid" BOLD "|" NORM "jobid \n");
    printf(" stop - stop a job identified by its pid or job id\n");
    printf(BOLD "\t stop " NORM "pid" BOLD "|" NORM "jobid \n");
    printf(" kill - kill a job identified by its pid or job id\n");
    printf(BOLD "\t kill " NORM "pid" BOLD "|" NORM "jobid \n");
    printf(" help - print this message\n");
    printf(BOLD "\t help\n" NORM);
    printf("\n");
    printf("ctrl-z and ctrl-c can be used to send a SIGTSTP and a SIGINT, respectively\n\n");
}

/* treat_argv - Determine pid or jobid and return the associated job structure */
struct job_t *treat_argv(char **argv) {
    struct job_t *jobp = NULL;

    /* Ignore command if no argument */
    if (argv[1] == NULL) {
        printf("%s command requires PID or %%jobid argument\n", argv[0]);
        return NULL;
    }

    /* Parse the required PID or %JID arg */
    if (isdigit((int) argv[1][0])) {
        pid_t pid = atoi(argv[1]);
        if (!(jobp = jobs_getjobpid(pid))) {
            printf("(%d): No such process\n", (int) pid);
            return NULL;
        }
    } else if (argv[1][0] == '%') {
        int jid = atoi(&argv[1][1]);
        if (!(jobp = jobs_getjobjid(jid))) {
            printf("%s: No such job\n", argv[1]);
            return NULL;
        }
    } else {
        printf("%s: argument must be a PID or %%jobid\n", argv[0]);
        return NULL;
    }

    return jobp;
}


/* do_bg - Execute the builtin bg command */
void do_bg(char **argv) {
    //TODO:do_bg:a verifier , mais normalment c'est bon
    struct job_t *j;
    j=treat_argv(argv);

    if (j==NULL){
        fprintf(stderr,"aucun job a mettre en arrière plan");
        return;
    }

    j->jb_state=BG;
    kill(j->jb_pid,SIGSTOP);



}

/* waitfg - Block until process pid is no longer the foreground process */
void waitfg(pid_t pid) {


    struct job_t *j ;
    sigset_t mask;
    sigset_t masknormal;
    int test;
    j=jobs_getjobpid(pid);
    if(!j){
        return;
    }

    test=sigemptyset(&mask);
    if (test != 0){
        fprintf(stderr,"erreur dans le mask");
    }

    test = sigaddset(&mask,SIGCHLD);
    if (test !=0){
        fprintf(stderr,"erreur dans le mask");
    }
  //  j->job_getjobpid(pid);
    sigprocmask(SIG_BLOCK,&mask,&masknormal);

    while (j->jb_pid == pid && j->jb_state == FG) {
        /* Wait for a signal which isn't blocked in masknormal set, */
        /* ignoring mask previously sets by sigprocmask calls, */
        /* potentially catching some previous blocked signals */
        /* (i.e. blocked SIGCHLD) */
        sigsuspend(&masknormal);
    }

        /*sleep(1);problème le sleep peut être interrompu par n'importe quoi*/

    sigprocmask(SIG_SETMASK,&masknormal,NULL);

    return;
}

/* do_fg - Execute the builtin fg command */
void do_fg(char **argv) {
    struct job_t *j ;
    j=NULL;
    j=treat_argv(argv);
    if (j == NULL) {
      return;
    }
    kill(j->jb_pid,SIGCONT);
    j->jb_state = FG;
    waitfg(j->jb_pid);
    return;

}

/* do_stop - Execute the builtin stop command */
void do_stop(char **argv) {


    struct job_t *j;
    j=treat_argv(argv);

    if (j==NULL){
        fprintf(stderr,"aucun job à arreter");
        return;
    }

    j->jb_state=ST;
    kill(j->jb_pid,SIGTERM);

    return;
}

/* do_kill - Execute the builtin kill command */
void do_kill(char **argv) {


    struct job_t *j;
    j=treat_argv(argv);

    if (j==NULL){
        fprintf(stderr,"aucun job a mettre en killer plan");
        exit(EXIT_SUCCESS);
    }
    kill(j->jb_pid, SIGCONT);
    kill(j->jb_pid, SIGTERM);



}

/* do_exit - Execute the builtin exit command */
void do_exit() {


    kill(getpid(), 15);

    return;


}

/* do_jobs  */
void do_jobs() {

    jobs_listjobs();

    return;

}
