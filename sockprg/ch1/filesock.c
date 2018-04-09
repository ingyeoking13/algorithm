#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/socket.h>

int main(){

	int fd = open("/etc/services", O_RDONLY);
	int sd = socket(PF_INET, SOCK_STREAM, 0);

	printf("fd = [%d]\n", fd);
	printf("sd = [%d]\n", sd);

}
