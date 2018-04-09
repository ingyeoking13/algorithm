#include <stdio.h>
#include <string.h>
#define MOD 1000007

int d[201][201];
int dx[] ={1, 0}, dy[] = {0, 1};
int main(){
	int row, col; scanf("%d %d", &row, &col);
	int tx, ty;   scanf("%d %d", &tx, &ty);

	d[1][1]=1;
	for (int i=1; i<=tx; i++){
		for (int j=1; j<=ty; j++){
			int x=i, y=j;
			for (int k=0; k<2; k++){
				int nx = x+dx[k], ny = y+dy[k];
				if (nx<= row && ny <= col){
					d[nx][ny]+=d[x][y];
					d[nx][ny]%=MOD;
				}
			}
		}
	}

	long long tmp=d[tx][ty];
	memset(d,0, sizeof(d));
	d[tx][ty]=1;

	for (int i=tx; i<=row; i++){
		for (int j=ty; j<=col; j++){
			int x=i, y=j;
			for (int k=0; k<2; k++){
				int nx = x+dx[k], ny = y+dy[k];
				if (nx<= row && ny <= col){
					d[nx][ny]+=d[x][y];
					d[nx][ny]%=MOD;
				}
			}
		}
	}
	printf("%lld\n", (tmp%MOD*d[row][col]%MOD)%MOD);
}
