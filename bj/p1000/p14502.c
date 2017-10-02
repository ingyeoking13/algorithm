//samsung SW 기출문제
#include <stdio.h>
#include <string.h>
int n, m, area=0, ans=-1;
int b[8][8], c[8][8];
int v[64];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int virus(int x, int y){
	c[x][y]=1; area++;
	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx>=0 && nx<n && ny>=0 && ny<m){
			if (b[nx][ny]==0 && c[nx][ny]==0){
				virus(nx, ny); 
			}
		}
	}
}
void dfs(int rc, int cnt){
	if (rc>=m*n){
		if (cnt==3){
			for (int i=0; i<n; i++){
				for (int j=0; j<m; j++){
					if (b[i][j]==2) virus(i, j);
				}
			}
			for (int i=0; i< n; i++){
				for (int j=0; j<m; j++){
					if (b[i][j]==1) area++;
				}
			}
			if (ans<m*n-area) ans=m*n-area;
			area=0;
			memset(c, 0, sizeof(c));
		}
		return;
	}

	int x=rc/m, y=rc%m;
	if (b[x][y]==0 && cnt<3){
		b[x][y]=1;
		dfs(x*m+y+1, cnt+1);
		b[x][y]=0;
	}
	dfs(x*m+y+1, cnt);
}
int main(){
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%d", &b[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", ans);
}
