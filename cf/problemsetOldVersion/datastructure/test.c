#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char tmp[100];
	char *test = (char *)malloc(11);
	scanf("%s", tmp);
	strcpy(test, tmp);
	printf("%s\n", test);
	free(test);
}
