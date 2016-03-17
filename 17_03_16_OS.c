/*
>5 choveka iskat da karat 3 koli lmao
>kolite sa ednomestni.f1
>izvejdame koi 4ovek koq kola kara
>40vecite sa ot 0-4
>kolite ot 0-2
>I suck at programing.jkek
>sled kato kara kola chovek iska da zeme nova sled kratka po4ivka
>Y did i got into this shit

*/

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#define NUM_OF_THREADS 5
#define PEOPLE_COUNT 5
#define CARS_COUNT 3


int koli[CARS_COUNT] = {0,0,0},hora[PEOPLE_COUNT] = {0,0,0,0,0};


void driving(int i){
    int j;
    for(j=0;j<CARS_COUNT;j++){

    }

}


int main(){

    pthread_t threads[NUM_OF_THREADS];
	int i;	
	for (i=0; i<NUM_OF_THREADS; i++){
        if(pthread_create(&threads[i], NULL, driving, (void*)i)){ 
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

