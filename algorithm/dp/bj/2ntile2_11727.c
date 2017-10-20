#include <stdio.h>
int d[1000];
int main(){
	int n;
	scanf("%d", &n);
	d[0]=1;
	d[1]=1;
	for (int i=2; i<=n; i++)
		d[i]=(d[i-1]%10007+(2*d[i-2])%10007)%10007;

	printf("%d\n", d[n]);
}
