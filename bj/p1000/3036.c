#include <stdio.h>

int gcd(int a, int b){ return b?gcd(b,a%b):a; }
int main(){
	int T; scanf("%d", &T);
	int a, b; scanf("%d\n", &a);

	while(--T>0){
		scanf("%d", &b);
		int tmp = gcd(a, b);
		printf("%d/%d\n", a/tmp, b/tmp);
	}
}
