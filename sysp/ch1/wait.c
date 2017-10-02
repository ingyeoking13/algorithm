#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <sys/wait.h>

int main(){
	int status;
	pid_t pid= fork();
	if (pid<0){
		fprintf(stderr, "fork error\n");
		exit(-1);
	}
	else if (pid==0){
		printf("[child] I'm a child... sleep 5 second. \n");
		system("sleep 5");
		return -1;
	}
	else{
		printf("[parent] wait terminated child PID(%d). \n", pid);
		int child_pid = wait(&status);
		printf("[parent] child (pid:%d) terminated \n", child_pid);
		if (WIFEXITED(status)){
			printf("[parent] return from child code = %d\n", WEXITSTATUS(status));
		}
		printf("[parent] I'm terminated\n");
		exit(0);
	}
}
