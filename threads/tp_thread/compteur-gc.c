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
    char * buf;
    int size;
}res_s;

void * my_compteur_gc(void * arg) {
    int total;
    total=0;
    res_s *args= (res_s) *arg;
    for(int i=0;i<args->size;i++){
        if((args->buf[i]=='G')||(args->buf[i]=='C')){
            total++;
        }
    }
    return  (void*)total;



}

unsigned long compteur_gc(char *bloc, unsigned long taille) {
    unsigned long i, cptr = 0;

    for (i = 0; i < taille; i++)
        if (bloc[i] == 'G' || bloc[i] == 'C')
            cptr++;

    return cptr;
}

int main(int argc, char *argv[]) {
    struct stat st;
    int argv2;
    int fd;
    int status;
    int *resu;
    char *tampon;
    int lus;
    unsigned long cptr = 0;
    res_s *dataTab;
    pthread_t *tab;
    res_s truc;
    off_t taille = 0;
    struct timespec debut, fin;

    argv2=atoi(argv[2]);

    assert(argv[1] != NULL);

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


    assert(clock_gettime(CLOCK_MONOTONIC, &debut) != -1);
    /*découpage */
    tab=malloc(argv2*sizeof(pthread_t)+1);
    dataTab=malloc(argv2*sizeof(res_s)+1);
    resu=malloc(argv2*sizeof(int)+1);

    for (int j=0;j<argv2;j++){ /*  */
        dataTab[j]=truc;
    }
/*Initialisation des thread*/
    for(int i =0; i<argv2;i++){
        status = pthread_create(tab+i,NULL,my_compteur_gc,(void*) dataTab+i);//Manque l'argument de my compteur
        if(!status){
            perror("Error init pthread");
            exit(EXIT_FAILURE);
        }
    }
    /* Calcul proprement dit */

    /*Calcul*/
    for(int i =0; i<argv2;i++){
        status = pthread_join(tab[i],(void*)resu+i);//Manque le truc de renvoie
        if(!status){
            perror("Error exec pthread");
            exit(EXIT_FAILURE);
        }
    }

    for(int k=0;k<argv2;k++){
        cptr+=(int)resu[k];
    }
    /*cptr = compteur_gc(tampon, taille);*/
    assert(clock_gettime(CLOCK_MONOTONIC, &fin) != -1);

    /* Affichage des résultats */
    printf("Nombres de GC:   %ld\n", cptr);
    printf("Taux de GC:      %lf\n", ((double) cptr) / ((double) taille));

    fin.tv_sec  -= debut.tv_sec;
    fin.tv_nsec -= debut.tv_nsec;
    if (fin.tv_nsec < 0) {
        fin.tv_sec--;
        fin.tv_nsec += 1000000000;
    }
    printf("Durée de calcul: %ld.%09ld\n", fin.tv_sec, fin.tv_nsec);
    printf("(Attention: très peu de chiffres après la virgule sont réellement significatifs !)\n");

    return 0;
}
