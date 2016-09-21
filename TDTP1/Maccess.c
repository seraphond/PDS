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
  int errnum;
  int status;
  char *nom_fic;

/*Gestion des erreurs d'utilisations*/
  if(argc > 4){
    perror("Errreur de syntaxe , trop d'arguments");
    usage();
    exit(EXIT_FAILURE);
    }else if(argc < 3){
        perror("Argument(s) manquant");
        usage();
        exit(EXIT_FAILURE);
    }else if(strcmp(argv[2],"-v") == 0){
        perror("Nom du ficher ou mode manquant");
        usage();
        exit(EXIT_FAILURE);
    }else if((argc == 4) && (strcmp(argv[3],"-v") != 0)){
        perror("Options utilisés invalides");
        usage();
        exit(EXIT_FAILURE);
    }
  /*Début du traitement et vérification de l'utilisation des modes*/
  else{
    nom_fic = argv[2];

    if(strcmp(argv[1],"-x")==0){
      status=access(nom_fic,X_OK);
      errnum = errno;
    }else if(strcmp(argv[1],"-r")==0){
      status=access(nom_fic,R_OK);
      errnum = errno;
    }else if(strcmp(argv[1],"-w")==0){
      status=access(nom_fic,W_OK);
      errnum = errno;
    }else{
      perror("Erreur dans l'utilisation des modes\n");
      exit(EXIT_FAILURE);
    }

    /*Résultat pour l'utilisateur*/
    if(status != 0){
        /*Gestion d'une erreur potentielle d'access()*/
        if ((errnum != 0) && ((argc == 4) && (strcmp(argv[3],"-v") == 0))) {
            fprintf(stderr, "%s\n",strerror(errnum));
            exit(EXIT_FAILURE);
        }else{
        printf("Tu n'a pas le droit\n");
        }
    }else{
        printf("Tu as le droit\n");
    }
    return EXIT_SUCCESS;
}
}
