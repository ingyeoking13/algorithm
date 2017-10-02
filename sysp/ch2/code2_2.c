#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int main(){
	int fd;
	char buf_msg[64];
	printf("Low level file handle\n");
	if ((fd=open("fd_test.log", O_CREAT | O_WRONLY, 0644))==-1){
		fprintf(stderr, "Fail: open: %d(%s) \n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
	dprintf(fd, "PID[%d] Low level file handle\n", getpid());
	strcpy(buf_msg, "write: Test message\n");
	close(fd);
	return EXIT_SUCCESS;

}
