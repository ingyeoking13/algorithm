#include <stdio.h>

long long d[35]={1};
int main(){
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++){
		for (int j=0; j<i; j++){
			d[i]+=d[j]*d[i-j-1];
		}
	}
	printf("%lld\n", d[n]);
}
