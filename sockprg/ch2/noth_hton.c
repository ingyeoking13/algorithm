#include <stdio.h>
#include <arpa/inet.h>

int main(){
	short data = 0x1234;
	char *ch;

	ch = (char *) &data;

	printf("original data : 0x1234\n");

	if ( ch[0] == 0x12 && ch[1] == 0x34)
		printf("host data(big-endian): ");
	else if (ch[1] == 0x12 && ch[0] == 0x34)
		printf("host data(little-endian): ");
	printf("0x%x%x\n", ch[0], ch[1]);

	short ndata = htons(data);
	ch = (char *)& ndata;
	printf("network data(big-endian) : 0x%x%x\n", ch[0], ch[1]);
}
