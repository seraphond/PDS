#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/type.h>

static  int buffer=1024;

easyMtail(char* path,int ligne){
    
}

mtail(char * path, int lignes){
    FILE* file=NULL;

    int nb_ligne=0;
    char *contenu_ligne;
    file=open(path,O_RDONLY);
    lseek(file,-buffer,SEEK_END);
    while((contenu_ligne=fgets())!=NULL){
        nb_ligne++;
    }
    if(nb_ligne>lignes){
        lseek(file,-buffer,SEEK_END);


    }



}

int main(int argc,char* argv[]){


    return 0;
}

