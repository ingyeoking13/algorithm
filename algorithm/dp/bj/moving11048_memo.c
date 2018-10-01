#include <stdio.h>
#include <string.h>
int d[1001][1001], a[1001][1001];
int max(int a, int b){if (a>b) return a; return b;}
int dfs(int x, int y){
	if (x<1 || y<1) return 0;
	if (d[x][y]>=0) return d[x][y];
	d[x][y]=max(dfs(x-1, y), dfs(x,y-1))+a[x][y];
	return d[x][y];
}

int main(){
	int n,m;
	scanf("%d %d", &n, &m);

	for (int i=1; i<=n; i++){
		for (int j=1; j<=m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	memset(d, -1, sizeof(d));
	dfs(n,m);
	printf("%d\n", d[n][m]);
}
