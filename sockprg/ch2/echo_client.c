#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 9000
#define ADDR "127.0.0.1"

int main(){
	int csck;
	struct sockaddr_in s_addr;
	
	char rcvbuf[BUFSIZ];
	char sndbuf[BUFSIZ];

	csck = socket(PF_INET, SOCK_STREAM, 0);
	memset(&s_addr, 0, sizeof(s_addr));

	s_addr.sin_addr.s_addr = inet_addr(ADDR);
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);

	
	if ( connect(csck, (struct sockaddr *) &s_addr, sizeof(s_addr))==-1){
		printf("Can not Bind\n");
		close(csck);
		return -1;
	}

	while(1){
		int n;
		printf("input: ");
		scanf("%s", sndbuf); getchar();

		if (!strcmp(sndbuf, "quit")) break;
	
		printf("original Data : %s\n", sndbuf);
		if((n=write(csck, sndbuf, strlen(sndbuf)))<0){
			return -1;
		}

		int r = n, l=0;
		while(r >0){
			if ((n=read(csck, &rcvbuf[l], r))<0){
				return -1;
			}
			r = l-n;
			l += n;
		}
		rcvbuf[l] =0;
		printf("echoed Data: %s\n", rcvbuf);

	}
	close(csck);
}
