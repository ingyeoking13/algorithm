#include <stdio.h>

int main(){
	long long n, m; long long k; scanf("%lld %lld %lld", &n, &m, &k);
	if ( k>=n){
		long long tmp = k-n;
		long long x = n-tmp/(m-1);
		long long y;
		if ( (tmp/(m-1))%2 )  y= m-tmp%(m-1);
		else y= 2+tmp%(m-1);

		printf("%lld %lld\n", x, y);
	}
	else printf("%lld %d\n", k+1, 1);
}
