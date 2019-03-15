#include <stdio.h>

int main(){

	int n, m, a;
	scanf("%d %d %d", &m, &n, &a);

	long long ans;
	ans=m%a==0?m/a:m/a+1;
	m=n%a==0?n/a:n/a+1;
	ans*=m;
	printf("%I64d\n", ans);
}
