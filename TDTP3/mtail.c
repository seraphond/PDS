#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/*write(stdout_fileno,buffer+i+1,bufsize-i-1)*/

int compteur_de_ligne(unsigned  char* buf,int buffer_size){
    int i=0;
    int nb_ligne=0;
    while (i<buffer_size) {
        if (buf[i] == '\n') {
            nb_ligne++;
        }
        i++;
    }
    return nb_ligne;
}

off_t find_offset(int fd,int ligne_obj) {
    int nb_ligne = 0;
    char *c[1];
    off_t obj=0;

    while (read(fd, c, 1) != 0) {
        printf("%s",c[0]);
        if (nb_ligne == ligne_obj) {
            return  lseek(fd, obj, SEEK_CUR);

        }
        if (c[0] == '\n') {
            nb_ligne++;
        }
    }
    return 0;
}
void easyMtail(char* path,int ligne){

}

/*void mtail(char * path, int lignes){

}*/

int main(int argc,char* argv[]){
    char * nom_fic;
    int lignes;
    lignes=0;
    nom_fic=argv[1];
    int debut;
    debut=atoi(argv[2]);
    int file;
    unsigned char contenu[BUFFER_SIZE];
    int octet_lu=0;
    off_t offset;


    file = open(nom_fic,O_RDONLY);


    octet_lu = read(file,contenu,BUFFER_SIZE+1);
    lignes=compteur_de_ligne(contenu, BUFFER_SIZE+1);
    offset=find_offset(file,(lignes-debut));
    //lseek(file,offset,SEEK_SET);
    write(STDOUT_FILENO,contenu,BUFFER_SIZE);
    //easyMtail(nom_fic,nb_lignes);

    return 0;
}

