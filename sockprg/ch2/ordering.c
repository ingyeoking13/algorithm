#include <stdio.h>

int main(){
	short data;
	char *ch;

	data = 0x1234;
	ch = (char *) &data;

	printf("original data : 0x1234\n");

	if ( ch[0] == 0x12 && ch[1] == 0x34)
		printf("host data(big-endian): ");
	else if (ch[1] == 0x12 && ch[0] == 0x34)
		printf("host data(little-endian): ");
	printf("0x%x%x\n", ch[0], ch[1]);
}
