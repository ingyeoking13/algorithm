#include <stdio.h>

int a[501][501], d[501][501];
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
int dfs(int x, int y){
	if (x==0 && y==0) return d[0][0]=1;
	if (d[x][y]) return d[x][y];

}
int main(){
	int row, col;
	scanf("%d %d", &row, &col);

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			scanf("%d", &a[i][j]);
		}
	}
	dfs(row-1, col-1);
	printf("%d\n", d[row-1][col-1]);
}
