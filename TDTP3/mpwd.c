
#include <limits.h>
#include <dirent.h>
#include <stdio.h>



void print_name_in_parent(const char * node, const char * parent){

    struct stats st;
    struct dirent * dire;
    DIR dir;
    int status;

    status=stat(node,&st);
    //assert

    dirp=opendir(parent);
    while ((dire=read.dir(dir))!=NULL){
        if(dire->d_ino == st.st_ino){
            prinf("%s",dire->d_name);
            closedir(dir);
            return;
        }
    }

    closedir(dir);
    assert("YOU SHALL NOT PASS!\n");

}

int is_result(char  * pathname){
    static int read_init=1;
    static struct stat ratstat;
    struct  stat pathstat;
    int status;

    if('read_int'){
        read_init=0;
        status=stat("/",&ratstat);
    }


    //assrt

    status=(pathname,pathstat);

    return pathstat.st_dev==ratstat.st_dev && pathstat.st_ino == ratstat.st_ino;
}

int main(int argc, char * argv){
    char result[PATH_MAX+1];
    getcwd(result,PATH_MAX);
    printf("%s",result);


    return 0;
}

