#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(){
	int tcpsd;
	struct sockaddr_in s_addr;

	// tcp socket create
	if ((tcpsd = socket(PF_INET, SOCK_STREAM, 0))<0){ 
		perror("socket()");
		exit(-1);
	}

	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_family = AF_INET;
	inet_aton("203,249.39.3", &(s_addr.sin_addr.s_addr));
	s_addr.sin_port = htons(7);

	printf("ip(decimal) = %s\n", inet_ntoa(s_addr.sin_addr.s_addr));
	printf("ip(bin) = %s\n", ntohl(s_addr.sin_addr.s_addr));
	printf("port no = %d \n", ntohs(s_addr.sin_port));
	close(tcpsd);
}
