#include <stdio.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(){


	pid_t current_pid = getpid();
	int priority = getpriority(PRIO_PROCESS, current_pid);
	printf("\n[now Nice value.]\n");
	printf("Process ID: %d, Nice: %d\n", current_pid, priority);
	system("ps -l -p $(pgrep prio)");

	printf("\n[Nice value change + 10]\n");
	setpriority(PRIO_PROCESS, current_pid, 10);
	priority=getpriority(PRIO_PROCESS, current_pid);
	printf("Process ID: %d, Nice: %d\n", current_pid, priority);
	system("ps -l -p $(pgrep prio)");

	printf("\n[Nice value change - 10]\n");
	setpriority(PRIO_PROCESS, current_pid, -10); // virtual에서는 음수먹음
	priority=getpriority(PRIO_PROCESS, current_pid);
	printf("Process ID: %d, Nice: %d\n", current_pid, priority);
	system("ps -l -p $(pgrep prio)");
}
