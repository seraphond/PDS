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
    j=treat_argv(**argv);

    if (j==NULL){
        fprintf(stderr,"aucun job a mettre en arrière plan");
        exit(EXIT_SUCCESS);
    }

    j->jb_state=BG;
    kill(j->jb_pid,SIGSTOP);



}

/* waitfg - Block until process pid is no longer the foreground process */
void waitfg(pid_t pid) {
<<<<<<< HEAD
    sigsuspend(); //TODO : add a mask
    return;
=======

    struct job_t *j ;
    int mask;
    j=jobs_getjobpid(pid);

    sigemptyset(&mask);
    if (mask = 0){
        fprintf(stderr,"erreur dans le mask");
    }

    sigaddset(mask,SIGCHLD);
    if (mask = 0){
        fprintf(stderr,"erreur dans le mask");
    }
    //j->job_getjobpid(pid);
    sigprocmask(SIG_BLOCK,&masknormal,&mask);

    while  (j->jb_state ==FG){

        sigsuspend(&mask);
        /*sleep(1);problème le sleep peut être interrompu par n'importe quoi*/
    }
    sigprocmask(SIG_BLOCK,&masknormal,NULL);
>>>>>>> b3fb99848272a2204c0648f44ead4bbce1956e48
}

/* do_fg - Execute the builtin fg command */
void do_fg(char **argv) {
<<<<<<< HEAD
    struct job_t *j = treat_argv(argv);
    if (j == NULL) {
        fprintf(stderr, "Erreur de pointeur\n");
        exit(EXIT_FAILURE);
    }
    kill(j->jb_pid,SIGCONT);
    j->jb_state = FG;
    waitfg(j->jb_pid);
    return;
=======
    //TODO:do_fg:a verifier , mais normalment c'est bon
    struct job_t *j;
    j=treat_argv(**argv);

    if (j==NULL){
        fprintf(stderr,"aucun job a mettre en premier plan");
        exit(EXIT_SUCCESS);
    }

    j->jb_state=FG;
    kill(j->jb_pid,SIGCONT);
    waitfg(j->jb_pid);



>>>>>>> b3fb99848272a2204c0648f44ead4bbce1956e48
}

/* do_stop - Execute the builtin stop command */
void do_stop(char **argv) {

    //TODO:do_stop:a verifier , mais normalment c'est bon
    struct job_t *j;
    j=treat_argv(**argv);

    if (j==NULL){
        fprintf(stderr,"aucun job a mettre en premier plan");
        exit(EXIT_SUCCESS);
    }

    j->jb_state=ST;
    kill(j->jb_pid,SIGTERM);
    jobs_deletejob(j->jb_pid);
}

/* do_kill - Execute the builtin kill command */
void do_kill(char **argv) {

    //TODO: do_kill:a verifier , mais normalment c'est bon
    struct job_t *j;
    j=treat_argv(**argv);

    if (j==NULL){
        fprintf(stderr,"aucun job a mettre en killer plan");
        exit(EXIT_SUCCESS);
    }


    kill(j->jb_pid,SIGKILL);
    jobs_deletejob(j->jb_pid);


}

/* do_exit - Execute the builtin exit command */
void do_exit() {

    //TODO:do_exit
    int i;
    char** cmd;
    char*  jid;
    cmd[0]="stop";
    cmd[1]="%";

    for (i = 0; i < MAXJOBS; i++) {
        if (jobs[i].jb_pid != 0) {
            jid=job[i].jb_jid;
            strcat(cmd[1],jid);
            do_stop(cmd);
            printf("[%d] (%d) exited", jobs[i].jb_jid, (int) jobs[i].jb_pid);
        }
    }

    // une foit que tout est fermé  , fermer le terminal

    exit(EXIT_SUCCESS);



}

/* do_jobs - Execute the builtin fg command */
void do_jobs() {
    //TODO:do_job
    printf("do_jobs : To be implemented\n");

    return;
}
