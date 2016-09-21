#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

void usage(){
    printf("macces <MODE> <nFichier> (-v)\n");
}

int main(int argc,char*argv[]){
  int errnum_r,errnum_x,errnum_w;
  int status;
  char *nom_fic;

  int c;
  int rflag=0;
  int xflag=0;
  int wflag=0;
  int vflag=0;

  opterr=0;

  while((c=getopt(argc,argv,"rxwv"))!=-1){
    switch(c){
    case('r'):
      rflag=1;
      break;
    case('x'):
      xflag=1;
      break;
    case('w'):
      wflag=1;
      break;
    case('v'):
      vflag=1;
      break;
    case('?'):
      fprintf(stderr,"Option inconue:-%c\n",optopt);
      usage();
      exit(EXIT_FAILURE);
      break;
    default:
      abort();
    }
  }
  nom_fic=argv[optind];

  /*  printf("fichier: %s",nom_fic);*/

  if(rflag==1){
     status=access(nom_fic,R_OK);
      errnum_r = errno;
      errno=0;
      if(status ==0){
	printf("Lecture accordée\n");
      }else{
	printf("lecture refusée\n");
     }
  }

  if(xflag==1){
     status=access(nom_fic,X_OK);
     errnum_x = errno;
      errno=0;
     if(status ==0){
       printf("Execution accordée\n");
     }else{
       printf("Execution refusée\n");
     }
  }

  if(wflag==1){
    status=access(nom_fic,W_OK);
    errnum_w = errno;
     errno=0;
    if(status ==0){
      printf("Ecriture accordée\n");
    }else{
      printf("Ecriture refusée\n");
    }
  }

  if(vflag==1){
    if(errnum_r !=0){
      printf("Erreur de lecture:\n");
      fprintf(stderr, "%s\n",strerror(errnum_r));
    }
    if(errnum_x !=0){
       printf("Erreur d execution:\n");
      fprintf(stderr, "%s\n",strerror(errnum_x));
    }
    if(errnum_w !=0){
       printf("Erreur d ecriture:\n");
      fprintf(stderr, "%s\n",strerror(errnum_w));
    }
    if ((errnum_r != 0) || (errnum_x != 0)||(errnum_w != 0)){
      exit(EXIT_FAILURE);
    }
  }

  return EXIT_SUCCESS;
  
  
}
