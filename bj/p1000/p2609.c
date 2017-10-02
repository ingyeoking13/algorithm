#include <stdio.h>

int gcd(int a, int b){
	int ret;
	if (b) ret=gcd(b, a%b);
	else ret=a;
	return ret;
}

int main(){

	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", gcd(a,b));
	printf("%d\n", a*b/gcd(a,b));
}
