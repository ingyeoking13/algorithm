#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

  pid_t ret;
	for (int i=0; i<3; i++){
		ret=fork();
		printf("[%d] PID(%d) PPID(%d)\n", i, getpid(), getppid());
#ifndef OMIT_SWITCH
		switch(ret){
			case 0: pause(); return 0;
			case -1: break;
			default: break;
		}
#endif
	}
	wait(NULL);
	return 0;
}

