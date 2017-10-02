#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 30
#define DIE(x) perror(x),exit(1)

int main(int argc, char **argv){

	char mesg[]="Hi! good afternoon? ^__^";
	char buf[BUFSIZE];
	ssize_t rcount, wcount;
	int pipefd[2];
	size_t len;
	pid_t pid=getpid();
	if (pipe(pipefd)<0)	DIE("pipe");
	printf("\nPID=%d, Read end=fd%d, write end=fd%d\n", 
			pid, pipefd[0], pipefd[1]);

	printf("----------file descripter --------\n");
	system("ls -l /proc/$$/fd");
	printf("-------------- ---------- --------\n");

	len=strlen(mesg);
	printf("Writing message by pipe: <%s>\n", mesg);
	if ((wcount=wrte(pipefd[1],mesg,len) != len)) {
		fprintf(stderr, "%s: write failed: %s \n", argv[0], streror[errno]);
		exit(1);
	}
	if ((rcount=wrte(pipefd[0],buf,BUFSIZE) != wcount)) {
		fprintf(stderr, "%s: read failed: %s \n", argv[0], streror[errno]);
		exit(1);
	}
	buf[rcount]=0;
	printf("read pipe with message : <%s>\n", buf);

	close(pipefd[0]);
	close(pipefd[1]);

}
