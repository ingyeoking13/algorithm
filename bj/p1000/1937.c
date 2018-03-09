#include <stdio.h>
#include <string.h>

int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};
int a[500][500], d[500][500], n;

int max(int x, int y){ return x<y?y:x; }
int dfs(int x, int y){
	if (d[x][y] >=0) return d[x][y];
	
	d[x][y]=1;
	for (int i=0; i<4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if (0<= nx && nx<n && 0 <= ny && ny < n){
			if ( a[x][y] > a[nx][ny] ){
				d[x][y] = max(d[x][y], dfs(nx, ny)+1);
			}	
		}
	}
	return d[x][y];
}

int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	memset(d, -1, sizeof(d));
	int ans=0;
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			int tmp= dfs(i,j);
			if ( ans < tmp ) ans= tmp;
		}
	}
	printf("%d\n", ans);
}
