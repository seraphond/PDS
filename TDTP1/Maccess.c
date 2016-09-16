#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>


int main(int argc,char*argv[]){
  int errnum;
  int status;
  if(argc>4){
    perror("Errreur de syntaxe , trop d'arguments");
    exit(1);
  }else if(strcmp(argv[3],"-v")==0){
    

  }else{
    char * nom_fic =argv[2];
    

    if(strcmp(argv[1],"-x")==0){
      status=access(nom_fic,X_OK);
    
    }else if(strcmp(argv[1],"-r")==0){
      status=access(nom_fic,R_OK);
    }else if(strcmp(argv[1],"-w")==0){
      status=access(nom_fic,W_OK);
    }else{
      perror("J\'ai pas capté le mode désolé bro\n");
      exit(2);
    }
  if(status){
    printf("tu n'a pas le droit\n");
    
  }else{
    printf("tu as le droit\n");
  }
  return 0;
}
