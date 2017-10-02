//미로탐색 BFS find the shortest distance
#include <stdio.h>

int a[101][101];
int c[101][101];
int q[10200], t=0, h=0;
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			scanf("%1d", &a[i][j]);
		}
	}

	a[0][0]=1;
	q[t++]=0;
	while (h<t){
		int now=q[h++];
		int x= now/m, y=now%m;
		for(int i=0; i<4; i++){
			int nx=x+dx[i], ny= y+dy[i];
			if (nx>=0 && nx<n && ny>=0 && ny<m){
				if (a[nx][ny] && c[nx][ny]==0){
					q[t++]=nx*m+ny;
					c[nx][ny]=1;
					a[nx][ny]=a[x][y]+1;
				}
			}
		}
	}
	printf("%d\n", a[n-1][m-1]);
}
