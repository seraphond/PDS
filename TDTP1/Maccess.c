#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char*argv[]){
  char * nom_fic =argv[2];
  int status;
  if(argc>3){
    printf("Erreur de syntaxe. Usage :maccess <mode> <fichier>\n");
    exit(1);
  }
  if(strcmp(argv[1],"-x")==0){
    status=access(nom_fic,X_OK);
    
  }else if(strcmp(argv[1],"-r")==0){
    status=access(nom_fic,R_OK);
    }else if(strcmp(argv[1],"-w")==0){
    status=access(nom_fic,W_OK);
  }else{
    printf("J\'ai pas capte le mode désolé\n");
    exit(1);
  }

  if(status){
    printf("tu n'a pas le droit\n");
    
  }else{
    printf("tu as le droit\n");
  }
  return 0;
}
