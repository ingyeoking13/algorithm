//삼성 sw기출 로봇청소기
#include <stdio.h>
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
int m, n, a[51][51], ans=0;
int dfs(int x, int y, int d){
	if (a[x][y]==0) {a[x][y]=2; ans++;} 
	int stuck=0;
	for(int i=d+3; i>d-1; i--){
		int ch=0;
		int nx=x+dx[i%4], ny=y+dy[i%4];
		if (nx >=0 && nx<m && ny>=0 && ny<n && a[nx][ny]==0)
		{ dfs(nx, ny, i%4); break; }
		else stuck++;
	}
	if (stuck==4){
		int nx=x-dx[d], ny=y-dy[d];
		if (nx>=0 && nx<m && ny>=0 && ny<n && a[nx][ny]!=1) 
			dfs(nx, ny, d);
	}
}

int main(){
	int sx, sy, d;
	scanf("%d %d", &m, &n);
	scanf("%d %d %d", &sx, &sy, &d);

	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	dfs(sx, sy, d);
	printf("%d\n", ans);
}
