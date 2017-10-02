#include <stdio.h>

int main(){

	char str[100000];

	while(fgets(str, sizeof(str), stdin))
		printf("%s", str);

	return 0;
}
