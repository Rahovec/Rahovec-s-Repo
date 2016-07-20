#include <stdio.h>
#include <sys/stat.h>

int main(){
//---------size na argumenta
    struct stat s;
    int e = stat(".", &s);
    if (e !=0 ){
                
        
        perror("stat");
    }
    printf("%ld\n", s.st_size);
//---------------------------
}
