#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 9000

int main(){
	int csck, ssck;
	struct sockaddr_in s_addr, c_addr;
	
	char rcvbuf[BUFSIZ];

	ssck = socket(PF_INET, SOCK_STREAM, 0);
	memset(&s_addr, 0, sizeof(s_addr));
	s_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	s_addr.sin_family = AF_INET;
	s_addr.sin_port = htons(PORT);

	if (bind(ssck, (struct sockaddr *) &s_addr, sizeof(s_addr)) == -1){
		printf("Can not Bind\n");
		return -1;
	}

	if ( listen(ssck,5) ==-1 ){
		printf("list Fail\n");
		return -1;
	}

	while(1){
		int len = sizeof(c_addr);
		int n;
		csck = accept(ssck, (struct sockaddr *) &c_addr, &len);
		printf("ssck: %d csck: %d\n",ssck, csck);
		while((n=read(csck, rcvbuf, sizeof(rcvbuf)))!=0){
			rcvbuf[n+1]=0;
			printf("%s\n", rcvbuf);
			write(csck, rcvbuf, n);
		}
		close(csck);
	}
	close(ssck);
}
