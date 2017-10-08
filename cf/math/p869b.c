#include <stdio.h>

int main(){

	long long a, b;
	scanf("%lld %lld", &a, &b);

	long long ans=1;
	if (b-a<10){
		for (long long i=a+1; i<=b; i++){
			ans*=(i%10);
			ans%=10;
		}
	}
	else ans=0;

	printf("%lld\n", ans);
}
