#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t m;
pthread_mutex_t trans;
int money = 1000;
int transactions = 0;

void* deposit(void* arg){
	int taskid;
	taskid = (int) arg;	
	pthread_mutex_lock(&m);
		money -= 100;
		printf("100 withdrawn from %d banker\n", taskid);
		
	pthread_mutex_unlock(&m);
	pthread_mutex_lock(&trans);
		transactions ++;
		
	pthread_mutex_unlock(&trans);
	//sleep(1);
	return NULL;
}


void* withdraw(void* arg){
	int taskid = (int) arg;
	pthread_mutex_lock(&m);
		money += 100;
		printf("100 deposited from %d banker\n", taskid);
	pthread_mutex_unlock(&m);

	pthread_mutex_lock(&trans);
		transactions ++;
	pthread_mutex_unlock(&trans);
	//sleep(1);
	return NULL;
}

/*void* work(void* arg){
    pthread_mutex_lock(&m);
        while(transactions <20){
            pthread_mutex_unlock(&m);
            pthread_mutex_lock(&m);
               	money+=50;
            printf("Money deposited: %d\n",money);
            pthread_mutex_unlock(&m);
            pthread_mutex_lock(&trans);
            	money -= 50;
            printf("Money Withdrawn: %d\n", money);
            pthread_mutex_unlock(&trans);
            pthread_mutex_lock(&m);
        }
		transactions ++;
        pthread_mutex_unlock(&m);
        return NULL;
        }
*/
int main(){

	if ( pthread_mutex_init (&m, NULL) != 0) {
		perror("pthread_mutex_init");
		return 1;
	}
	
	
	if ( pthread_mutex_init (&trans, NULL) != 0) {
		perror("pthread_mutex_init");
		return 1;
	}

	pthread_t banker[2];

	/*if(pthread_create(&banker[0], NULL, work, NULL) != 0 ){
		perror("pthread_create");	
		return 1;
	}*/

	while(transactions < 20){
		if(pthread_create(&banker[0], NULL, deposit, 0) != 0){
	
			printf("Error while processing pthread");
			return 1;
		}	
	
		if(pthread_create(&banker[1], NULL, withdraw, 1) != 0){
			perror("pthread_create");
			return 1;	
		}
	}

	if(pthread_join(banker[0], NULL) != 0){
		perror("pthread_join");
		return 1;
	}
	if(pthread_join(banker[1], NULL) != 0){
		perror("pthread_join");
		return 1;
	}
	printf("current money is %d\n", money);
	pthread_mutex_destroy(&m);
	pthread_mutex_destroy(&trans);

return 0;
}
