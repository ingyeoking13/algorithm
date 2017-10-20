#include <stdio.h>

char str[8];

int main(){
	fgets(str, 8, stdin);
	printf("%s", str);
	printf("%c", str[5]);

}
