#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

int main(int argc, char **argv){

DIR* d = opendir("..");
    if(d == NULL){
        perror("opendir");
    }

    //pro4ita i printi si4ki ne6ta v dir-a i tipa im
    struct dirent *p = readdir(d);
    while(p != NULL){    
        if(p->d_type == DT_DIR){
            printf("d ");
        }
        else{
            if(p->d_type == DT_REG){
                printf("f ");
            }
            else{
                printf("? ");
            }
        }
        printf("%s\n", p->d_name);
        p = readdir(d);    
    }
    closedir(d);
    //--------------------------------------------//

return 0;
}
