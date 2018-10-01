#include <stdio.h>
#include <unistd.h>

int main(){
	printf("ls -l command running...\n");
	char *av[3]= {"ls", "-l", 0};

	execv("/bin/ls", av); 
	//execl("/bin/ls", "ls", "-l", 0);
	printf("ls command run with not display\n");
}
