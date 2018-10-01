#include <stdio.h>

int gcd(int a, int b){
	return a?gcd( b%a, a):b;
}

int main(){
	int a, b; scanf("%d %d", &a, &b);
	printf("%d\n", gcd(a, b));
}

