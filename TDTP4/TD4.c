//
// Created by seraphond on 07/10/16.
//
#include "TD4.h"

#define  PDS_MAX_FDS 8
#define  PDS_BUF_SIZE 4096;

struct pds_file_s{
    long pds_bpos;
    long pds_fpos;
    long pds_bcnt;
    int pds_fmodif;
    int pds_fd;
    char * pds_buf;
    bool pds_busy;
    int pds_buf_size;
};

static  pds_file_t pds_fds[PDS_MAX_FDS]; // on réserve 8 places de file descriptor


pds_file_t  * pds_stdin=pds_fds;
pds_file_t  * pds_stdout=pds_fds+1;
pds_file_t  * pds_strr=pds_fds+2;

pds_file_t  *pds_fopen(const char *path){
    //on cherche  une cas de libre
    pds_file_t * tmp;
    int i=0;
    int nRead;
    for(i;i<PDS_MAX_FDS;i++){
        if(!(pds_fds[i]->pds_busy)){
            tmp=&pds_fds[i];
            break;
        }

    }
    if(i==PDS_MAX_FDS){
        //gestion d'erreur
    }

    tmp->pds_buf_size=PDS_BUF_SIZE;
    tmp->pds_busy=true;
    tmp->pds_buf=malloc(tmp.buf_size* sizeof(char));
    if(tmp->pds_buf == NULL){
        //erreur
    }
    //initialiser lse champs,ouvrir le fichier avec open

    if((tmp_pds->fd=open(path,O_RDWR|O_CREATE,S_IRUSR|S_IRWUSR|S_IRGRP|S_IRWGRP|S_IROTH|S_IRWOTH))==-1){
        //Erreur
    }

    tmp->pds_bpos=tmp->fpos=tmp->pds_bcnt=tmp->pds_fmodif=0;

    //remplir le buffer

    nRead=read(tmp->fd,tmp->pds_buf,tmp->pds_bufsize);
    if(nRead==1){
        return  EXIT_FAILLURE;
    }
    tmp->pds_cnt=nRead;

    if(nRead<tmp_>pds_buf_size){
        memset(tmp->buf+nRead,'0',(tmp->buf_size-nRead));
    }
    return tmp;

}

int pds_fflush(pds_file_t *stream){

    memset(stream,'0',);
    pds_file_t  * pds_stdin=stream[0];
    pds_file_t  * pds_stdout=stream[1];
    pds_file_t  * pds_strr=stream[2];

}

int pds_fclose(pds_file_t * stream){

}
/*

int pds_fseek(pds_file_t *stream){

}

int pds_fgetc(pds_file_t * stream){

}
*/


