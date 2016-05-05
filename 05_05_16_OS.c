/*vzima statistika za fail*/


#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
int main(){
    struct stat st;
    struct passwd *pwd = getpwuid(st.st_uid);    

    stat("a.out", &st);
    printf("%d\n", st.st_size);

    /*get
    printf("%s\n", pwd->pw_name);*/ //tva trqq zima imeto na potrebitelq
return 0;
}
