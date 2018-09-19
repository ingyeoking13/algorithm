#include <stdio.h>

int a[51][51], ans, n, m;
int dx[8]={1, 1, 1, -1, -1, -1, 0, 0}, dy[8]={1, -1, 0, 1, -1, 0, 1, -1};
void dfs(int x, int y){
	if (a[x][y]) a[x][y]=0;
	for (int i=0; i<8; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx>=0 && nx<n && ny>=0 && ny<m){
			if(a[nx][ny]==1) dfs(nx, ny);
		}
	}
}

int main(){

	while(1){
		scanf("%d %d", &m, &n);
		if (n==0 || m==0) break;

		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				scanf("%d", &a[i][j]);
			}
		}

		for (int i=0; i<n; i++){
			for (int j=0; j<m; j++){
				if (a[i][j]) {ans++; dfs(i,j);}
			}
		}
		printf("%d\n", ans);
		ans=0;
	}

}
