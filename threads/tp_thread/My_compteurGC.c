//
// Created by seraphond on 02/12/16.
//

#include "compteur-gc.c"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <pthread.h>

typedef struct  {
    unsigned  long total;
    char * buf;
    int size;
}res_s;

void * my_compteur_gc(void * arg) {
    res_s *args= (res_s) *arg;
    args->total=0;
    for(int i=0;i<args->size;i++){
        if((args->buf[i]=='G')||(args->buf[i]=='C')){
            args->total++;
        }
    }
    return (void*) args;



}

int main(int argc,char *argv){
    struct stat st;
    int status;
    pthread_t *tab;
    res_s truc;
    char *tampon;
    int lus,i;
    int fd;
    unsigned long cptr = 0;
    off_t taille = 0;
    res_s *dataTab;


    /* Quelle taille ? */
    assert(stat(argv[1], &st) != -1);
    tampon = malloc(st.st_size);
    assert(tampon != NULL);

    /* Chargement en mémoire */
    fd = open(argv[1], O_RDONLY);
    assert(fd != -1);
    while ((lus = read(fd, tampon + taille, st.st_size - taille)) > 0)
        taille += lus;
    assert(lus != -1);
    assert(taille == st.st_size);
    close(fd);



    tab=malloc(argv[2]*sizeof(pthread_t)+1);
    dataTab=malloc(argv[2]*sizeof(res_s)+1);

    for (int j=0;j<argv[2];j++){
        dataTab[j]=truc;
    }

    /*Initialisation des thread*/
    for(i =0; i<argv[2];i++){
        status = pthread_create(tab+i,NULL,my_compteur_gc,(void*) dataTab+i);//Manque l'argument de my compteur
        if(!status){
            perror("Error init pthread");
            exit(EXIT_FAILURE);
        }
    }
    /*Calcul*/
    for(i =0; i<argv[2];i++){
        status = pthread_join(tab[i],(void*)dataTab+i);//Manque le truc de renvoie
        if(!status){
            perror("Error exec pthread");
            exit(EXIT_FAILURE);
        }
    }
}