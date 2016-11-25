/* mshell - a job manager */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>


#include "jobs.h"
#include "common.h"
#include "sighandlers.h"

/*
 * wrapper for the sigaction function
 */
int sigaction_wrapper(int signum, handler_t * handler) {
    struct  sigaction act;
    act.sa_handler=handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags=/*SA_NODEFER ;*/SA_RESTART;
    if (sigaction(signum,&act,NULL)<0){
        unix_error("error sigaction wrapper");
    }
    return 0;

}

/*
 * sigchld_handler - The kernel sends a SIGCHLD to the shell whenever
 *     a child job terminates (becomes a zombie), or stops because it
 *     received a SIGSTOP or SIGTSTP signal. The handler reaps all
 *     available zombie children
 */
void sigchld_handler(int sig) {
    pid_t child_pid;
    int status;
    if (verbose)
        printf("sigchld_handler: entering\n");
    while ((child_pid=waitpid(-1,&status, WNOHANG|WUNTRACED))>0 ) {
        /*s'est stoppé avec un signal*/
        if (WIFSTOPPED(status)) {
            struct job_t *j = jobs_getjobpid(child_pid);
            if(!j){
                fprintf(stderr, "error recup job 1\n");
            }
            j->jb_state = ST;
            fprintf(stdout, "Job [%d] (%d) stopped by signal %d\n",j->jb_jid,j->jb_pid,WSTOPSIG(status));
        }
        /* s'est stoppé avec un signal inconnu*/
        else if (WIFSIGNALED(status)) {
            struct job_t *j = jobs_getjobpid(child_pid);
            if(!j){
                fprintf(stderr, "error recup job 2\n");
            }
            j->jb_state = ST;
            fprintf(stdout, "Job [%d] (%d) stopped by unknown signal %d\n",j->jb_jid,j->jb_pid,WTERMSIG(status));
            jobs_deletejob(child_pid);
        }
        /*  s'est stoppé naturellement */
        else if (WIFEXITED(status)) {
            struct job_t *j = jobs_getjobpid(child_pid);
            if(!j){
                fprintf(stderr, "error recup job 3\n");
            }
            fprintf(stdout, "Job [%d] (%d) stopped naturaly\n",j->jb_jid,j->jb_pid);
            jobs_deletejob(child_pid);
        }
        else{
            unix_error("waitpid error");
        }
    }

    if (verbose)
        printf("sigchld_handler: exiting\n");

    return;
}

/*
 * sigint_handler - The kernel sends a SIGINT to the shell whenver the
 *    user types ctrl-c at the keyboard.  Catch it and send it along
 *    to the foreground job.
 */
void sigint_handler(int sig) {
    pid_t pid;

    if (verbose)
        printf("sigint_handler: entering\n");

    /*fgpid => pid du job en avant plan*/
    if ((pid = jobs_fgpid()) > 0) {
        if(kill(pid,sig) < 0){
            unix_error("Kill error sigint");
        }
    }
    if (verbose)
        printf("sigint_handler: exiting\n");
}

/*
 * sigtstp_handler - The kernel sends a SIGTSTP to the shell whenever
 *     the user types ctrl-z at the keyboard. Catch it and suspend the
 *     foreground job by sending it a SIGTSTP.
 */
void sigtstp_handler(int sig) {
    pid_t pid;

    if (verbose)
        printf("sigtstp_handler: entering\n");
    /*fgpid => pid du job en avant plan*/
    if ((pid = jobs_fgpid()) > 0) {
        if(kill(pid,sig) < 0){
            unix_error("Kill error sigstp");
        }
    }

    if (verbose)
        printf("sigtstp_handler: exiting\n");

    return;
}
