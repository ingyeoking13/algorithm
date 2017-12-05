#include <stdio.h>
#include <stdlib.h>

int a[100][100], b[10000], ans;
int row, col, T;
int dx[4]={1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int mycmp(const void* x, const void* y){ return *(int *)x - *(int *)y; }
void dfs(int x, int y){
	a[x][y]=1; b[ans]++;
	for (int i=0; i<4; i++){
		int nx= x+dx[i], ny=y+dy[i];
		if (nx>=0 && ny>=0 && nx<row && ny<col ){
			if (!a[nx][ny]){
				dfs(nx, ny);
			}
		}
	}
}
int main(){
	scanf("%d %d %d", &row, &col, &T);
	while(T--){
		int ly, lx, ry, rx;
		scanf("%d %d %d %d", &ly, &lx, &ry, &rx);
		for (int i=lx; i<rx; i++)
			for (int j=ly; j<ry; j++)
				a[i][j]=1;
	}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if (!a[i][j]){
				dfs(i, j);
				ans++;
			}
		}
	}

	qsort(b, ans, sizeof(int), mycmp);
	printf("%d\n", ans);
	for (int i=0; i<ans; i++) printf("%d ", b[i]);
	printf("\n");
}
