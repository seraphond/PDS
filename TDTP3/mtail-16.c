#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

#define BUFFER_SIZE 4096


int compteur_carac(const char * pathname) {
    int file;
    int bytes_read;
    char actualChar;
    int nbChar = 0;

    file = open(pathname,O_RDONLY);
    bytes_read = read(file,&actualChar,1);

    while(bytes_read != 0){
        nbChar++;
        bytes_read = read(file,&actualChar,1);
    }

    close(file);
    return nbChar;
}


int compteur_ligne(const char * pathname) {
    int file;
    int nblines = 0;
    char buf[BUFFER_SIZE];
    int i = 0;
    int nbTotalChar = compteur_carac(pathname);

    file = open(pathname,O_RDONLY);
    read(file,&buf,BUFFER_SIZE);


    while (i < nbTotalChar ){
        if (buf[i] == '\n') {
            nblines++;
        }
        i++;
    }
    if (buf[nbTotalChar] == '\0' && buf[nbTotalChar-1] != '\n'){
        nblines++;
    }

    close(file);
    return nblines;
}


int easytail(const char * pathname, int nb_ligne_voulu ) {

    int file;
    int displayLines;
    int i = 0;
    int cpt = 0;

    int nbTotalLines = compteur_ligne(pathname);
    int nbTotalChar = compteur_carac(pathname);
    char buf[BUFFER_SIZE];

    file = open(pathname,O_RDONLY);

    displayLines = read(file,&buf,BUFFER_SIZE);

    while(i < nbTotalChar && displayLines != 0){
        if(buf[i] == '\n'){
            cpt++;
        }
        if (nb_ligne_voulu != 0) {
            if (cpt >= (nbTotalLines - nb_ligne_voulu )){
                printf("%c",buf[i]);
            }
        }
        else{
            printf("%c",buf[i]);
        }

        i++;
    }
    close(file);
    return 0;
}




int main(int argc, char *argv[]) {
    int c;
    char *pathname = argv[argc-1];

    int nb_ligne_voulu  = 0;



    while ( (c = getopt(argc,argv,"n:")) != -1 ) {
        switch(c) {
            case 'n' :
                nb_ligne_voulu  = atoi(optarg);
                break;

            default:
                printf("Mtail-16 [-n : number of line from the end] file_pathname\n");
                exit(EXIT_FAILURE);
                break;
        }
    }
    return easytail(pathname,nb_ligne_voulu );
}

    Contact GitHub API Training Shop Blog About

    © 2016 GitHub, Inc. Terms Privacy Security Status Help
