#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>


int main(){
	int sd[2], res;

	int n1, n2;
	char buf[BUFSIZ];
	char* data = "This is from sd[0]";

	res = socketpair(PF_LOCAL, SOCK_STREAM, 0, sd);

	write(sd[0], data, strlen(data));
	printf("[sed] %s\n", data);

	n2 = read(sd[1], buf, BUFSIZ);
	buf[n2] = 0;
	printf("[received] %s\n", buf);

	close(sd[0]);
	close(sd[1]);
}
