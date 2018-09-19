#include <stdio.h>

int d[1001][1001];
int main(){
	int n, k; scanf("%d %d", &n, &k);

	for (int i=1; i<=n; i++){
		for (int j=0; j<=i; j++){
			if ( !j ) d[i][j]=1;
			else if ( j == i) d[i][j]=1;
			else{
				d[i][j] = d[i-1][j]+d[i-1][j-1];
				d[i][j]%=10007;
			}
		}
	}
	printf("%d\n", d[n][k]);
}
