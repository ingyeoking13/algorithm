#include <stdio.h>

int main(){
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", b-a>c-b?b-a-1:c-b-1);
}
