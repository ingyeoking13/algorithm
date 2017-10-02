#include <stdio.h>
#include <pthread.h>

int thread_args[3]={0, 1, 2};

void* thread(void *arg){
	for (int i=0;  i<3; i++)
		printf("thread[%d] : running %d thread \n", *(int *)arg, i);
	pthread_exit(0);
}

int main(){
	pthread_t threads[3];
	for (int i=0; i<3; i++){
		pthread_create(&threads[i], 
				NULL, 
				 thread, 
				 &thread_args[i]);
	}
	pthread_exit(0);
}
