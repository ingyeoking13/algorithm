#include <stdio.h>

int main(){

	int n, a, b; scanf("%d %d %d", &n, &a, &b);
	int ans = 0;

	for (int bplate=n-1; bplate; bplate--){
		int aplate = n-bplate;
		int minb = b/bplate, mina = a/aplate;
		int max = minb>mina?mina:minb;
		if ( ans < max ) ans=max;
	}
	printf("%d\n", ans);
}
