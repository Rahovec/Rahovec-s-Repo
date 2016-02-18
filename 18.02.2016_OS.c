#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#define NUM_OF_THREADS 5


void* test(void *p)
{

	int id = (int)p;
	printf("Zdr ot nishka %d\n", id);

	return id*id;


}

int main(){

	pthread_t threads[NUM_OF_THREADS];
	int i;	
	for (i=0; i<NUM_OF_THREADS; i++){
		if (pthread_create(&threads[i], NULL, test, (void*)i)){ 
			perror("Error inpthread create");
		}
	}

	
	for(i=0; i<NUM_OF_THREADS; i++){

		void* result;
		pthread_join(threads[i], (void*)result);
		printf("thread %d returned %d/n", i, (int)result);
	}


	return 0;
}
