#include <stdio.h>

int main(){

	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	int ans=0;

	while(a!=b){
		a=a/2+a%2;
		b=b/2+b%2;
		ans++;
	}
	printf("%d\n", ans);
}
