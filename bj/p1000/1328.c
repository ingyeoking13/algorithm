#include <stdio.h>

long long d[101][101][101];int  n, l, r; 
int main(){
	scanf("%d %d %d", &n, &l, &r);

	d[1][1][1]=1;
	for (int i=2; i<=n; i++){
		for (int j=1; j<=l; j++){
			for (int k=1; k<=r; k++){
				d[i][j][k]= d[i-1][j-1][k]+d[i-1][j][k-1] 
					+d[i-1][j][k]*(i-2);
				d[i][j][k]%=10000000007;
			}
		}
	}
	printf("%lld\n", d[n][l][r]);
}
