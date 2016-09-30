#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <dirent.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/stat.h>

/*Exercice 8*/
void pwd1(void){
    char result[PATH_MAX];
    getcwd(result, PATH_MAX);
    printf("%s\n",result);
}


/*Exercice 9*/
int is_root(char *pathname){

    static int root_init = 1;
    static struct stat rootstat;
    struct stat pathstat;
    int status;

    if(root_init){
    root_init = 0;
    status = stat("/", &rootstat);
    /*assert*/
    }
    status = stat(pathname, &pathstat);
    /*assert*/
    return pathstat.st_dev == rootstat.st_dev && pathstat.st_ino == rootstat.st_ino;
}


/*Exercice 10*/
void print_name_in_parent(const char *node, const char *parent){

    struct stat st;
    struct dirent *dire;
    DIR *dirp;
    int status;

    status = stat(node,&st);
    /*assert*/
    dirp = opendir(parent);
    /*assert*/
    while ((dire = readdir(dirp)) != NULL){
        if(dire->d_ino == st.st_ino){
            printf("%s\n", dire->d_name);
            closedir(dirp);
            return;
        }
    }
    closedir(dirp);
    assert("Vous ne passerez pas !\n");
}


/*Exercice 11*/
void print_node_dirname(const char *node){
    char parent[PATH_MAX+1];

    if (is_root(node)) {
        return;
    }
    else{
        /*PATH_MAX est de type long alors que snprinft veut du size_t*/
        snprintf(parent,PATH_MAX,"%s/..",node);
        print_node_dirname(parent);
        printf("/");
        print_name_in_parent(node,parent);
    }
}


/*exercie 12*/
void pwd2(){
    print_node_dirname(".");
}


int main(int argc, char const *argv[]) {
    return 0;
}
