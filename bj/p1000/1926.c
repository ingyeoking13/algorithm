#include <stdio.h>

char a[500][500], chk[500][500];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int row, col;

int dfs(int x, int y){
	int ret=1;
	for(int i=0; i<4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		if ( 0<=nx && nx < row && 0<=ny && ny < col ){
			if (chk[nx][ny]) continue;
			if (a[nx][ny]==0) continue;
			chk[nx][ny]=1;
			ret+=dfs(nx, ny);
		}
	}
	return ret;
}

int main(){

	scanf("%d %d", &row, &col);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			scanf("%d", &a[i][j]);
		}
	}

	int cnt=0, mx=0;
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if ( a[i][j] && !chk[i][j] ){
				chk[i][j]=1;
				int tmp=dfs(i,j);
				if ( tmp > mx) mx= tmp;
				cnt++;
			}
		}
	}
	printf("%d\n%d\n", cnt, mx);

}
