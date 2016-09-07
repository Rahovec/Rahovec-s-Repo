#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char buf[100];

int main(){

	int comma_count = 0;
	int point_count = 0;
	int total_written = 0;
	int count = 0;

	int fd = open("danailov.c", O_RDONLY);
	if(fd == -1){
		perror("danailov.c");
		return 1;
	}
 	
	while(1){
		ssize_t bytes_read = read (fd, &buf, 100);
		if (bytes_read == -1) {
			perror ("read");
			return 1;
		}

		for(count = 0; count <= bytes_read; count++){
			if(buf[count] == ','){
				comma_count ++;
			}	
		}

		for(count = 0; count <= bytes_read; count++){
			if(buf[count] == '.'){
				point_count ++;
			}	
		}

		if(bytes_read == 0){
			break;
		}else{
			total_written = 0;
			ssize_t bytes_written = write (1, &buf + total_written, bytes_read - total_written);
			if (bytes_written == -1){
				perror ("write");
				return 1;
			}
			total_written += bytes_written; 
		}
	}

if(close(fd) != 0){
	perror ("close");
	return 1;
}

printf("Number of commas: %d \n", comma_count);
printf("Number of points: %d \n", point_count);

	return 0;
}
