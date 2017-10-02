#include <stdio.h>

long long f[91]={0, 1};

int main(){

	int n;
	for (int i=2; i<91; i++) f[i]=f[i-1]+f[i-2];
	scanf("%d", &n);
	printf("%lld\n", f[n]);
}
