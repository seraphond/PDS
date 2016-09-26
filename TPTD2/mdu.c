#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <getopt.h>
#include <limits.h>
#include <ctype.h>

static int opt_follow_link=1;
static int opt_apparent_size=0;

/* regarder les tables de hachage -> hcreate , hsearch hdestroy*/

int valid_name(char * dname){
    if((strcmp(dname,".") == 0)||(strcmp(dname,"..")==0)){
        return 0;
    }else{
        return 1;
    }

}

int du_file(const char *pathname) {
    /* Fichier Regulier */


    struct stat st;
    int status;
    DIR *dir;
    char path_entry[PATH_MAX+1];
    struct dirent *dire;
    int size;

    if(opt_follow_link){
        status=stat(pathname,&st);
    }else{
        status=lstat(pathname,&st);
    }
    /* printf("la valeur de status vaux:%d \n",status); */

    if(status!=0){
        fprintf(stderr,"Une erreur a été rencontrée \n");
    }

    /* faire  un assert pour gérer les cas d'arreurs avc status*/

    /* fichier + lien */
    if (S_ISREG(st.st_mode)) {
        if (opt_apparent_size) {
            return st.st_size;
        } else {
            return st.st_blocks;
        }
    }



    /* Dossier */
    if (S_ISDIR(st.st_mode)){

        if(opt_apparent_size){
            size=st.st_size;
        }else{
            size=st.st_blocks;
        }
    }

        dir=opendir(pathname);
        /* faire  un assert*/
        while((dire=readdir(dir))!=NULL){
            if(!valid_name(dire->d_name)) { /* à définir au dessus*/
                continue;
            }
            snprintf(path_entry,PATH_MAX,"%s/%s",pathname,dire->d_name);

            size+=du_file(path_entry);
            closedir(dir);

            return size;
        }
        fprintf(stdout,"type du fichier non pris en compte %s",pathname);
    return 0;
    }



int main(int argc,char* argv[]){
    char * pathname;
    int c;
    int bflag,Lflag=0;

    opterr=0;
    while((c=getopt(argc,argv,"bLB:"))!=-1) {
        switch (c) {
            case 'b':
                bflag = 1;
                break;
            case 'L':
                Lflag = 1;
                break;
            case '?':
                 if (isprint(optopt)) {
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                    return EXIT_FAILURE;
                } else {
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                    return EXIT_FAILURE;
                }
            default:
                opt_apparent_size=512;

        }
    }

    pathname=argv[optind];

    if (bflag==1){
        opt_apparent_size=1;
    }


    if(Lflag==1){
        opt_follow_link=0;
    }




   /* printf("test : %d \n test2:%d\n test3:%d\n",valid_name("."),valid_name(".."),valid_name("truc"));*/

    printf("%d\n",du_file(pathname));

    return EXIT_SUCCESS;
}

