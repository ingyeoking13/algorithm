#include <stdio.h>
#include <math.h>

long long g(long long a, long long b){
	if (b==0) return a;
	else return g(b, a%b);
}
int main(){
	long long a, b; scanf("%lld %lld", &a, &b);

	long long parent = b-a;
	long long cnt=0;
	long long i=sqrt(a), to =sqrt(b);

	for (; i<=to; i++) if (i*i > a && i*i<=b) cnt++;
	
	if (cnt ==0) return !printf("0\n");
	long long k =g(cnt, parent);
	printf("%lld/%lld\n", cnt/k, parent/k);
}
