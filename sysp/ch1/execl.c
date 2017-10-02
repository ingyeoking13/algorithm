#include <stdio.h>
#include <unistd.h>

int main(){
	printf("ls -l command running...\n");
	execl("/bin/ls", "ls", "-l", (char *) 0);
	printf("ls command run with not display\n");
}
