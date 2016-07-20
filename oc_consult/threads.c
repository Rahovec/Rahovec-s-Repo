#include <pthread.h>
#include <stdio.h>

int a = 0;
pthread_mutex_t m;

int zlato = 100;
int zlato_v_igra4a = 0;


void work( void *arg){
    int i;
    while(zlato > 0){
        pthread_mutex_lock(&m);        
        printf("Zlato na mapa:%d\n", zlato);        
        zlato -= 10 ;
        pthread_mutex_unlock(&m);
    
        pthread_mutex_lock(&m);
        printf("Transporting gold n STDs\n");
        zlato_v_igra4a += 10;
        printf("Zlato v 4ekmedjeto:\n", zlato_v_igra4a);
        pthread_mutex_unlock(&m);

    }
    
    return NULL;
}

int main(){

    pthread_mutex_init(&m, NULL);    
    
    pthread_t t[2];
    pthread_create(&t[0], NULL, work, NULL);
    pthread_create(&t[1], NULL, work, NULL);

    pthread_join(t[0], NULL);
    pthread_join(t[1], NULL);

    printf("%d\n", a);
    return 0;
}
