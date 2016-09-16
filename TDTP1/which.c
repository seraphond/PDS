#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

#define PATHMAX 1000

static char** dir;

void filldirs(){
 char* path;
 int i,taille=0;
 

 path= getenv("PATH");

 if (path ==NULL){
   printf("La commande n\'a pas été trouvée.\n");
   exit(1);
 }
 while(path[i]!='\0'){
   if(path[i]==':'){
     taille++;
     path[i]='\0';
   }
   i++;
   
 }
 dir=malloc((taille+1)*sizeof(char*));

 if (dir==NULL){
   printf("A Plus mémoire !");
   exit(1);
 }
 for(i=0;i<=taille;i++){
   dir[i]=path; //je met le mot dans le tableau
   path=path+strlen(path)+1;// j'avance le path d'un mot
 }
 dir[taille+1]=NULL;
 
}

int which(const char* cmd){
  char* dirname;
  char* tmp[PATHMAX+1];
  int status;
  for(dirname=dir;dirname!=NULL;dirname++){
    snprinft(tmp,PATHMAX,"%s/%s",dirname,cmd);
   status= access(tmp,X_OK);
    if(status){
      printf("commande trouvée,%s",dirname);
      return 0;
    }
  }
}
int main(int argc,char* argv[]){
  char* commande=argv[1];
  int i,val=0;

  if(argc>2){
    printf("Erreur de syntaxe , usage : which <commande>");
    exit(1);
  }
  filldirs();
  for(i=0;i<(argc+1);i++){
    nval=which(argv[i]);
  }
  
  
  return nval;
}
