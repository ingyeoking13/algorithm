#include <stdio.h>

int f[13]={1, 1};
int main(){

	for (int i=2; i<13; i++) f[i]=f[i-1]*i;

	int n;
	scanf("%d", &n);
	printf("%d\n", f[n]);
}

