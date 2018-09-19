#include <stdio.h>

int d[1001]={0, 1, 3};
int main(){

	int n;
	scanf("%d", &n);
	for (int i=3; i<=n; i++){
		d[i]=d[i-1]+2*d[i-2];
		d[i]%=10007;
	}

	printf("%d\n", d[n]);
}
