#include <stdio.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	printf("I'm the original process: pid= %d, ppid= %d\n", 
			getpid(), getppid());
	pid_t pid = fork();
	if (pid!=0){
		printf("I'm parent process: pid= %d, ppid= %d\n", 
				getpid(), getppid());
		printf("I'm child process: pid= %d\n", pid);
		while(1) sleep(1000);
	}
	else {
		sleep(5);
		printf("I'm child process: pid= %d, ppid= %d\n", getpid(), getppid());
	}
	printf("pid %d terminated...\n", getpid());
}
