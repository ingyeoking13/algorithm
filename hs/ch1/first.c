#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char* argv[]){
	char buf[80];

	if (argc<2) { printf("argument error\n"); exit(-1);}

	strcpy(buf,argv[1]);
	printf("your input is %s\n", buf);
}
