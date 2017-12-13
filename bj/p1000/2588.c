#include <stdio.h>

int main(){
	int a, b; scanf("%d", &a); scanf("%d", &b);
	int b1=b/100;
	int b2=b/10%10;
	int b3=b%10;
	printf("%d\n%d\n%d\n", a*b3, a*b2, a*b1);
	printf("%d\n", a*b1*100+a*b2*10+a*b3);
}
