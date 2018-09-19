#include <stdio.h>

int a[101];long long d[101][21];
int main(){
	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	d[0][a[0]]=1;
	for (int i=1; i<n-1; i++){
		for (int j=0; j<=20; j++){
			if (d[i-1][j]){
				if (j+a[i]<=20) d[i][j+a[i]]+=d[i-1][j];
				if (j-a[i]>=0) d[i][j-a[i]]+=d[i-1][j];
			}
		}
	}
	printf("%lld\n", d[n-2][a[n-1]]);
}
