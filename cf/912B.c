#include <stdio.h>

long long calc(long long a){

	if (a%4==0) return a;
	if (a%4==1) return 1;
	if (a%4==2) return a+1;
	return 0;

}
int main(){
	long long n, k; scanf("%lld %lld", &n, &k);
	k=n-k;
	printf("%lld\n", calc(n));
}
