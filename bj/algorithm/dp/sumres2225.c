#include <stdio.h>
#define mod 1000000000

long long d[201][201];
int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	d[0][0]=1;
	for (int i=1; i<=k; i++){
		for (int j=0; j<=n; j++){
			for (int l=j; l>=0; l--){
					d[i][j]+=d[i-1][j-l];
					d[i][j]%=mod;
			}
		}
	}
	printf("%lld\n", d[k][n]);

}
