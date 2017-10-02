#include <stdio.h>
#include <pthread.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int thread_args[3]={0, 1, 2};

void* thread_function0(void *arg){
	int sum=0;
	for (int i=0; i<100; i++) sum+=i;

	printf("Thread[0]: 1+2+3...100 = %d \n", sum);
	sleep(3);
}

void* thread_function1(void *arg){
	int sum=0;
	for (int i=400; i<800; i++) sum+=i;

	printf("Thread[0]: 401+402+403...800 = %d \n", sum);
	sleep(3);
}

int main(){
	pthread_t mythread[2];
	int NUM=2, sum[2];

	if (pthread_create(&mythread[0], NULL, thread_function0, NULL)){
		printf("Main: don't make thread0");
		abort();
	}
	printf("Main: make thread0 \n");

	if (pthread_create(&mythread[0], NULL, thread_function1, NULL)){
		printf("Main: don't make thread1");
		abort();
	}
	printf("Main: make thread1 \n");

	printf("Main: waiting Thread[0] \n");
	pthread_join( mythread[0], (void **)&sum[0]);
	printf("Main: Thread[0] terminated \n");

	printf("Main: waiting Thread[1] \n");
	pthread_join( mythread[1], (void **)&sum[1]);
	printf("Main: Thread[1] terminated \n");

	sum[0] += sum[1];
	printf("Main: all Thread terminated...\n");
	printf("Main: Final sum : %d \n", sum[0]);
	exit(0);
}

