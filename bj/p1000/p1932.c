#include <stdio.h>

int d[500][500];
int a[500][500];
int max(int a, int b){
	if (a>b) return a;
	return b;
}

int main(){

	int n;
	scanf("%d", &n);

	for (int i=0; i<n;i++){
		for (int j=0; j<=i; j++){
			scanf("%d", &a[i][j]);
		}
	}

	d[0][0]=a[0][0];

	for (int i=1; i<n;i++){
		for (int j=0; j<=i; j++){
			if (j==0) d[i][j]=d[i-1][j]+a[i][j];
			else if (j==i)  d[i][j]=d[i-1][j-1]+a[i][j];
			else{
				d[i][j]=max(d[i-1][j]+a[i][j], d[i-1][j-1]+a[i][j]);
			}
		}
	}

	int ans=d[n-1][0];
	for (int i=1; i<n; i++){
		ans=max(ans,d[n-1][i]);
	}

	printf("%d\n", ans);
}
