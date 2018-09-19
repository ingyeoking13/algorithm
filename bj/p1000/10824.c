#include <stdio.h>

int main(){
	long long a, b, c, d; scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
	for (int i=b; i; i/=10) a*=10;
	for (int i=d; i; i/=10) c*=10;
	
	printf("%lld\n", a+b+c+d);
}
