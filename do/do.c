#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define AND 1
#define OR 0

int main(int argc, char const *argv[]) {
    int i,res,opt;
    int mode = AND;
    pid_t pid;
    /*Détermination du nombre d'option --XX en comptant le nom de la commande ./XX*/
    opt = 1;
    for (i = 0; i < argc; i++) {
        if (memcmp(argv[i],"--",2) == 0) {
            opt++;
        }
    }
    printf("Il y a %d options.\n",opt);
    /*ASSERTIONS :
    forcement --and ou --or pour que ca marche
    et un argv
    */
    /*Tableau des pids*/
    pid_t *tab = malloc(sizeof(pid_t)*(argc-opt));
    int *tabStatus = malloc(sizeof(int)*(argc-opt));
    /*Changement de mode*/
    if(strcmp(argv[1],"--or") == 0){
        mode = OR;
    }
    /*Lancement des process*/
    for (i = 2; i < argc; i++) {
        pid = fork();
        /*Lancement d'un process*/
        switch (pid) {
            /*Si erreur*/
            case -1:
                fprintf(stderr, "FORK ERROR\n");
                break;
            /*Lance le exec donc n'execute plus la suite : pas de probleme avec le fork et la boucle for*/
            case 0:
                execvp(argv[i],NULL);
                exit(EXIT_FAILURE);
        }
        /*Stockage du pid*/
        tab[i-opt] = pid;
    }
    /*Attente des processus*/
    for (i = opt; i < argc; i++) {
        wait(tabStatus+i-opt);
    }
    /*Valeur de retour :*/
    res = 0;
    for (i = 0; i < argc-opt; i++) {
        if (mode == AND) {
            res = res && WEXITSTATUS(tabStatus[i]);
        }
        else{
            res = res || WEXITSTATUS(tabStatus[i]);
        }
    }
    printf("RESULTAT : %d\n",res );
    return res;
}
