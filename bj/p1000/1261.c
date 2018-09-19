#include <stdio.h>

int a[101][101],chk[101][101],d[101][101],q1[10000], q2[10000];
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};
int main(){
	int row, col;
	scanf("%d %d", &col, &row);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			scanf("%1d", &a[i][j]);
		}
	}

	int h1=0, h2=0, t1=0, t2=0;
	q1[t1++]=0;
	chk[0][0]=1;
	while(h1<t1){
		int now=q1[h1++];
		int x=now/col, y=now%col;
		for(int i=0; i<4; i++){
			int nx=x+dx[i], ny=y+dy[i];
			if(nx>=0 && ny>=0 && nx<row && ny<col){
				if (!chk[nx][ny]){
					if (a[nx][ny]==0) {
						chk[nx][ny]=1;
						d[nx][ny]=d[x][y];
						q1[t1++]=nx*col+ny;
					}
					else {
						chk[nx][ny]=1;
						d[nx][ny]=d[x][y]+1;
						q2[t2++]=nx*col+ny;
					}
				}
			}
		}
		if (h1==t1) {
			while(h2<t2) {
				q1[t1]=q2[h2];
				t1++; h2++;
			}
		}
	}
	printf("%d\n", d[row-1][col-1]);
}
