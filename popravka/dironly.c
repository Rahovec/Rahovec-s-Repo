#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[]){

	DIR* d = opendir(".");
	if(d == NULL){
		perror(".");
		return 1;
	}

	while(1){
		errno = 0;	
		struct dirent* dir = readdir(d);
		if(dir == NULL){
			if(errno != 0){
				perror("read");
				break;
			}
			else{
				break;
			}
		}
		
		printf("%s\n", dir -> d_name);
	}

if (closedir(d) != 0){
	perror("close");
	return 1;
}
return 0;
}
