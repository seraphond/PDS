/*
 Created by seraphond on 07/10/16.
*/

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

/*export MCAT_BUFSIZ=2*/

int compteur_carac(const char * path) {
    int file;
    int bytes_read;
    char actualChar;
    int nbChar = 0;

    file = open(path,O_RDONLY);
    bytes_read = read(file,&actualChar,1);

    while(bytes_read != 0){
        nbChar++;
        bytes_read = read(file,&actualChar,1);
    }

    close(file);
    return nbChar;
}


void  mcat_scd(char * path,int buf_size){
    int file;
    char * buf;
    int displayLines;
    file=open(path,O_RDONLY);
    buf=malloc(buf_size+1* sizeof(char));
    displayLines = read(file,buf,buf_size);
    while(displayLines !=0 ){

            write(STDOUT_FILENO,buf,displayLines);


        displayLines = read(file,buf,buf_size);
    }
    free(buf);



}

int main (int argc , char *argv[]){
    char * bufSize =getenv("MCAT_BUFSIZ");
    int  taille= atoi(bufSize);
    mcat_scd(argv[1],taille);

    return EXIT_SUCCESS;
}

