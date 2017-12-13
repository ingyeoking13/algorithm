//FAIL
#include <stdio.h>

int d[1500];
int gcd(int a, int b){ return b?gcd(b, a%b):a; }
int main(){
	int a, b, c; scanf("%d %d %d", &a, &b, &c);
	int g= gcd(a, b);
	a/=g, b/=g;

}
