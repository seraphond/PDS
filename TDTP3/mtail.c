#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/type.h>



mtail(char * path, int n){
    FILE* file=NULL;
    int buffer=n;
    int nb_ligne=0;
    char *contenu_ligne;
    file=open(path,O_RDONLY);
    lseek(file,-buffer,SEEK_END);



}

int main(int argc,char* argv[]){


    return 0;
}

