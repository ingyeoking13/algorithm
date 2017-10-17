#include <stdio.h>

int a[1001][1001],q[1002002], h, t, ans, chk=1;
int dx[4]={-1, 1, 0, 0}, dy[4]={0, 0, -1, 1};

int main(){
	int row, col;
	scanf("%d %d",&col, &row);
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			scanf("%d", &a[i][j]);
			if (a[i][j]==1) q[t++]= i*col+j;
		}
	}

	while(h<t) {
		int now=q[h++];
		int x=now/col, y= now%col;
		for (int i=0; i<4; i++){
			int nx=x+dx[i], ny= y+dy[i];
			if (nx>=0 && ny>=0 && nx<row && ny<col){
				if (a[nx][ny]==0){
					a[nx][ny]=1;
					q[t++]=nx*col+ny;
					a[nx][ny]=a[x][y]+1;
				}
			}
		}
	}

	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if (a[i][j]>ans) ans=a[i][j];
			if (a[i][j]==0) chk=0; 
		}
	}
	if (chk) printf("%d\n", ans-1);
	else printf("-1\n");
}
