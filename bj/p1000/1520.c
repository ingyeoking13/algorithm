#include <stdio.h>
#include <string.h>
int a[501][501], d[501][501], row, col;
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, 1, -1};
int dfs(int x, int y){
	if (x==0 && y==0) return d[0][0]=1;
	if (d[x][y]!=-1) return d[x][y];

	d[x][y]=0;
	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if (nx>=0 && ny>=0 && nx<row & ny<col){
			if (a[x][y]<a[nx][ny]) {
				d[x][y]+=dfs(nx, ny);
			}
		}
	}
	
	return d[x][y]; 
}
int main(){
	scanf("%d %d", &row, &col);

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			scanf("%d", &a[i][j]);
			d[i][j]=-1;
		}
	}
	printf("%d\n", dfs(row-1, col-1));
}
