#include <stdio.h>
#include <string.h>

char a[50][51];
int d[50][50], q[2500], h, t, ans;
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};

int main(){
	int row, col; scanf("%d %d", &row, &col);
	for (int i=0; i<row; i++) scanf("%s", a[i]);

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if ( a[i][j] == 'L'){
				memset(d, 0, sizeof(d));
				h=0, t=0; d[i][j]=1, q[t++]= i*col+j;
				while (h<t){
					int now = q[h++];
					int x = now/col, y = now%col;
					if ( ans < d[x][y] ) ans = d[x][y];

					for (int k=0; k<4; k++){
						int nx = x+dx[k], ny = y+dy[k];
						if ( 0<= nx && nx <row && 0<= ny && ny <col){
							if ( !d[nx][ny] && a[nx][ny]=='L'){
								d[nx][ny]= d[x][y]+1;
								q[t++] = nx*col+ny;
							}
						}
					}
				}
			}
		}
	}

	printf("%d\n", ans-1);
}
