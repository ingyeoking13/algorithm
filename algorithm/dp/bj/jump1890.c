#include <stdio.h>

long long int n, d[101][101], a[101][101];
int main(){
	scanf("%lld", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%lld", &a[i][j]);
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (j==0 && i==0) d[i][j]=1;
			for (int k=0; k<j; k++){
				if (k+a[i][k]==j) d[i][j]+=d[i][k];
			}
			for (int k=0; k<i; k++){
				if (k+a[k][j]==i) d[i][j]+=d[k][j];
			}
		}
	}

	printf("%lld\n", d[n-1][n-1]);
};
