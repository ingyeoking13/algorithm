#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 9000
#define IPADDR "127.0.0.1"

int main(){
	int c_sock;
	struct sockaddr_in c_addr;
	int len, n;

	char rcvbuf[BUFSIZ];

	c_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&c_addr, 0, sizeof(c_addr));
	c_addr.sin_addr.s_addr = inet_addr(IPADDR);
	c_addr.sin_family = AF_INET;
	c_addr.sin_port = htons(PORT);

	if ( connect(c_sock, (struct sockaddr *) &c_addr, sizeof(c_addr))==-1){
		printf("Can not Connect\n");
		close(c_sock);
		return -1;
	}

	// 기능 추가
	char buf[7000];
	scanf("%s", buf);
	write(c_sock, buf, strlen(buf)+1);

	char tmp= 'x';
	while ((n=read(c_sock, &tmp, 1))>0) tmp++;

	tmp=0;
	printf("received data : %s\n", rcvbuf);
	close(c_sock);
}


