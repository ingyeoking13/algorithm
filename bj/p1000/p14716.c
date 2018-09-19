#include <stdio.h>

int a[300][300];
int dx[8]={1, 1, 1, -1, -1, -1, 0, 0}, dy[8]={0, 1, -1, 0, 1, -1, 1, -1};
int m, n, ans=0;

int dfs(int x, int y){
	a[x][y]=0;
	for (int i=0; i<8; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if (nx>=0 && nx<m && ny>=0 && ny<n){
			if (a[nx][ny]) dfs(nx,ny);
		}
	}
}
int main(){
	scanf("%d %d", &m, &n);
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			if (a[i][j]) {
				dfs(i, j);
				ans++;
			}
		}
	}
	printf("%d\n", ans);
}
