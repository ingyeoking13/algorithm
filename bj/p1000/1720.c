#include <stdio.h>

long long a[31], d[31];
int main(){
	a[1]=1, a[2]=3;
	for (int i=3; i<=30; i++) a[i]=a[i-1]+a[i-2]*2LL;

	d[1]=1, d[2]=3;
	for (int i=3; i<=30; i++){
		long long b=0;
		if (i%2) b=a[(i-1)/2];
		else b=a[i/2]+2LL*a[(i-2)/2];
		d[i]=(a[i]+b)/2;
	}
	int n; scanf("%d", &n); 
	printf("%lld\n", d[n]);
}
