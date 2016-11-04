//
// Created by seraphond on 04/11/16.
//


#define MAXJOB 16
#define MAXLINE 16
struct job_s{
    pid_t job_pid;
    int job_id;
    int job_state;
    char job_cmdline[MAXLINE];
};

static  struct job_s jobs[MAXJOB];

int sigaction_wrapper(int signum,handler_t *handler){
    struct  sigaction act;
    act.sa_handler=handler;
    sigemptyset(&act.sa_mask);
    act.sa_flays=SA_NODEFER ;
    if (sigaction(signum,&act,NULL)<0){
        unix_error("error sigaction wrapper");

    }

    return 0;

}

void sigint(int sig){
    pid_t pid;
    if((pid=jobsfpid())>0){
        if(kill(pid,sig)<0){
            unix_error("erreur");
        }
    }
}

