#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int pid= fork();
	if (pid<0){
		fprintf(stderr, "fork error\n");
		exit(-1);
	}
	else if (pid==0){
		printf("[child] I'm a child... sleep 5 second. \n");
		execl("/bin/sleep", "sleep", "5", NULL);
	}
	else{
		printf("[parent] wait terminated child PID(%d). \n", pid);
		wait(NULL);
		printf("[parent] child terminated \n");
		exit(0);
	}
}
