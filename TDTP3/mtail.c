#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/*write(stdout_fileno,buffer+i+1,bufsize-i-1)*/

int compteur_de_ligne(char* buf,int buffer_size){
    int i=0;
    int nb_ligne=0;
    while (i<buffer_size) {
        if (buf[i] == '\n') {
            nb_ligne++;
        }
        i++;
    }
    return i;
}

void easyMtail(char* path,int ligne){
    int file;
    int nb_ligne=0;
    char *contenu=NULL;
    int buf_size_real;
    file = open(path,O_RDONLY);
    printf("file = %d\n",file);
    buf_size_real = read(file,contenu,BUFFER_SIZE);
    printf("Real buf size = %d",buf_size_real);
    nb_ligne=compteur_de_ligne(contenu, buf_size_real);
    printf("%d\n",nb_ligne);
}

/*void mtail(char * path, int lignes){
    FILE* file=NULL;

    int nb_ligne=0;
    char *contenu_ligne;
    file=open(path,O_RDONLY);
    lseek(file,-buffer,SEEK_END);
    while((fgets(contenu_ligne,buffer,file))!=NULL){
        nb_ligne++;
    }
    if(nb_ligne>lignes){
        lseek(file,-buffer,SEEK_END);


    }
}*/

int main(int argc,char* argv[]){
    char * nom_fic=argv[1];
    int nb_lignes=(int)argv[2];

    easyMtail(nom_fic,nb_lignes);

    return 0;
}

