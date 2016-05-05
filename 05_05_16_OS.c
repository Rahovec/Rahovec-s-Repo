/*vzima statistika za fail*/


#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
    struct stat st;
    stat("a.out", &st);
    printf("%d\n", st.st_size);

return 0;
}
