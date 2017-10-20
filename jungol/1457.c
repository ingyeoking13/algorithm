#include <stdio.h>
#include <stdlib.h>

int a[101][101], ans[101], cnt;
int dx[4]={-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int row, col, T;

void dfs(int y, int x){
	ans[cnt]++; a[y][x]=1;

	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if (nx>=0 && ny>=0 && ny<row && nx<col){
			if(a[ny][nx]==0) dfs(ny, nx);
		}
	}
}
int mycmp(const void* a, const void* b){ return *(int *)a- *(int *)b;}

int main(){

	scanf("%d %d %d", &row, &col, &T);

	int xa, ya, xb, yb;
	while(T--){
		scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
		for(int i=ya; i<yb; i++){
			for (int j=xa; j<xb; j++){
				a[i][j]=1;
			}
		}
	}

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if (a[i][j]==0) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	qsort(ans, cnt, sizeof(int), mycmp);

	printf("%d\n", cnt);
	for(int i=0; i<cnt; i++) printf("%d ", ans[i]);
	printf("\n");
}
