#include <stdio.h>
#include <arpa/inet.h>

int main(){

	struct in_addr inp;
	const char *ipAddr = "203.249.39.3";
	char *addr;

	inet_aton(ipAddr, &inp);
	printf("ip(decimal)[%s] -> ip(bin)[0x%x]\n",
			   ipAddr, ntohl(inp.s_addr));

	addr = inet_ntoa(inp);
	printf("ip(bin)[0x%x] -> ip(decimal)[%s]\n", ntohl(inp.s_addr), addr);

}
