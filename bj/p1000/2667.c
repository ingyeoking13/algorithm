#include <stdio.h>
#include <stdlib.h>

int a[25][25], ans, n, b[625];
int dx[4]={-1, 1, 0, 0}, dy[4]= {0, 0, 1, -1};
int mycmp(const void* x, const void* y){return *(int *)x - *(int *)y;}
void dfs(int x, int y){
	a[x][y]=0, b[ans]++;
	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if (nx>=0 && ny >= 0 && nx<n && ny<n){
			if (a[nx][ny]==1) dfs(nx, ny); 
		}
	}
	return ;
}
int main(){
	scanf("%d", &n);

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			scanf("%1d", &a[i][j]);

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (a[i][j]) { dfs(i, j); ans++; }

	qsort(b, ans, sizeof(int), mycmp);
	printf("%d\n", ans);
	for (int i=0 ; i<ans; i++) printf("%d\n", b[i]);
}
