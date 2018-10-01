#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(){
	struct in_addr addr;
	struct hostent *host;
	const char *hostName = "www.yahoo.com";

	if (!(host = gethostbyname(hostName))){
		printf("gethostbyname() error -chk network\n");
		exit(-1);
	}

	printf("official name = %s\n", host->h_name);

	int i=0;
	while(host->h_aliases[i]) printf("aliases =%s\n", host->h_aliases[i++]);

	printf("address type =%d\n", host->h_addrtype);
	printf("address lentgh =%d\n", host->h_length);

	i=0;
	while(host->h_addr_list[i]){
		memcpy(&addr.s_addr, host->h_addr_list[i], 4);
		printf("address = %s(0x%x)\n",
				inet_ntoa(addr),
				ntohl(*(long *)host->h_addr_list[i]));
		i++;
	}



}
