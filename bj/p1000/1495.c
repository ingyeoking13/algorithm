#include <stdio.h>
int a[101], d[101][1001];
int main(){
	int n,s,m; scanf("%d %d %d", &n, &s, &m);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);

	d[0][s]=1;
	for (int i=1; i<=n; i++){
		for (int j=0; j<=m; j++){
			if (d[i-1][j]){
				if (j+a[i]<=m) d[i][j+a[i]]=1;
				if (j-a[i]>=0) d[i][j-a[i]]=1;
			}
		}
	}
	int ans=-1;
	for (int i=0; i<=m; i++) if (d[n][i]) ans=i;
	printf("%d\n", ans);
}
