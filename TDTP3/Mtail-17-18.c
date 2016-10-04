//
// Created by seraphond on 04/10/16.
//
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

#define BUFFER_SIZE 64


int compteur_carac_buffer(char * buf) {
    int nbChar = 0;
    int i = 0;

    while (buf[i] != '\0'){
        nbChar++;
        i++;
    }

    return nbChar;
}



int compteur_ligne_buffer(char * buf) {
    int nblines = 0;
    int nbTotalChar = compteur_carac_buffer(buf);
    int i = 0;

    while (i<nbTotalChar){
        if (buf[i] == '\n') {
            nblines++;
        }
        i++;
    }

    if (buf[nbTotalChar] == '\0' && buf[nbTotalChar-1] != '\n'){
        nblines++;
    }

    return nblines;
}


int index_tail_buffer(const char * buffer, int bufsize, int ntail, int *nlines){

    int nlines_read = 0;
    int i = bufsize;

    while (i>=0 && nlines_read < ntail){
        if(buffer[i] == '\n'){
            nlines_read++;
        }
        i--;
    }

    *nlines = nlines_read;

    if (!(nlines_read<ntail)){
        i=i+2;
        return i;
    }
    return -1;
}


void display_buffer(char * buf, int from, int at){
    for(int i = from;i < at; i++){
        printf("%c",buf[i]);
    }
}



void tail_before_pos(int fd, unsigned int pos, int ntail){

    char * buffer;
    int read_bytes, index, nb_lines_read, lastByte;

    buffer = malloc(BUFFER_SIZE+1);


    if (buffer == NULL){
        printf("Le buffer est vide.");
        exit(EXIT_FAILURE);
    }

    if (lseek(fd,-(int)pos,SEEK_CUR) == -1){

        lseek(fd,0,SEEK_SET);
        lastByte = lseek(fd,0,SEEK_END);
        read_bytes = read(fd,buffer,lastByte);
    }
    else{
        lastByte = lseek(fd,0,SEEK_CUR);
        read_bytes = read(fd,buffer,BUFFER_SIZE);
    }

    index = index_tail_buffer(buffer,read_bytes,ntail,&nb_lines_read);

    if (index == -1) {
        tail_before_pos(fd,BUFFER_SIZE+read_bytes,ntail-nb_lines_read);
        display_buffer(buffer,0,read_bytes);
    }
    else {
        display_buffer(buffer,index,read_bytes-index);
    }

    free(buffer);
}

void tail(const char * pathname, int ntail){

    int fd = open(pathname,O_RDONLY);
    if (fd == -1) {
        printf("Problème lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    tail_before_pos(fd,BUFFER_SIZE,ntail);
    close(fd);
}


int main(int argc, char *argv[]) {
    char *pathname = argv[argc-1];
    int ntail = 0;
    int c;

    while ( (c = getopt(argc,argv,"n:")) != -1 ) {
        switch(c) {
            case 'n' :
                ntail = atoi(optarg);
                break;

            default:
                printf("mtail [-n : number of line from the end] file_pathname\n");
                exit(EXIT_FAILURE);
                break;
        }
    }
    tail(pathname,ntail);
    return 0;
}

