long long facto(long long num){
	if (num<=1) return 1;
	else return num* facto(num-1);
}
#include <stdio.h>

long long facto(long long num){
	if (num<=1) return 1;
	else return num* facto(num-1);
}
int main(){
	long long m, n, ans;
	scanf("%lld %lld", &m, &n);

	if (m>n) ans=facto(n);
	else ans=facto(m);

	printf("%lld\n", ans);
}

