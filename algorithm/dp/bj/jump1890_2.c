#include <stdio.h>

int n, a[101][101];
long long int d[101][101];
int main(){
	scanf("%d", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	d[0][0]=1;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (a[i][j]==0) continue;
      d[i][j+a[i][j]] += d[i][j];
			d[i+a[i][j]][j] += d[i][j];
		}
	}
	printf("%lld\n", d[n-1][n-1]);
}
