#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>

int thread_args[3]={0, 1, 2};

void* thread(void *arg){
	nice(19);
	for (int i=0;  i<100; i++)
		printf("thread[%d] : running %d thread \n", *(int *)arg, i);
	pthread_exit(0);
}

int main(){
	int i;
	pthread_t threads[3];
	pthread_attr_t thread_attrs;
	struct sched_param param;

	for (int i=0; i<3; i++){
		pthread_attr_init(&thread_attrs);
		pthread_attr_setschedpolicy(&thread_attrs, SCHED_RR);
		param.sched_priority=20;
		pthread_attr_setschedparam(&thread_attrs,&param);
		pthread_create(&threads[i], 
				NULL, 
				 thread, 
				 &thread_args[i]);
	}

	printf("End Main Thread\n");
	pthread_exit(0);
}
