#include <stdio.h>

int a[1000][1000];
int min(int x, int y) { if (x<y) return x; return y; }
int main(){
	int n, m; scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &a[i][j]);
			a[i][j]=!a[i][j];
		}
	}

	int ans=1;
	for (int i=1; i<n; i++){
		for (int j=1; j<m; j++){
			if (a[i][j]){
				a[i][j]=min(min(a[i-1][j],a[i][j-1]), a[i-1][j-1])+1;
			}
			if (a[i][j]>ans) ans=a[i][j];
		}
	}
	if (n==0 || m==0) ans=0;
	printf("%d\n", ans);
}
