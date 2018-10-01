#include <stdio.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	struct sched_param param;
	int policy;
	char *policy_name;

	pid_t current_pid =getpid();
	param.sched_priority = 5;
	sched_setscheduler(current_pid, SCHED_OTHER, &param);
	sched_getparam(current_pid, &param);
	policy = sched_getscheduler(current_pid);

	if (policy==0) 			policy_name="SCHED_NORMAL";
	else if (policy==1) policy_name="SCHED_FIFO" ;
	else if (policy==2) policy_name="SCHED_PR" ;
	else 								policy_name="Unknown" ;
	printf("Current PID: %d\n", (int)current_pid);
	printf("Scheduling Policy: %d, %s\n", policy, policy_name); 
	printf("RT Sched Priory: %d\n", param.sched_priority);

}
