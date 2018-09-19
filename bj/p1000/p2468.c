#include <stdio.h>

int a[101][101], b[101][101], n;
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, -1, 1};

int dfs(int x, int y){
	b[x][y]=0;
	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if (nx>=0 && nx<n && ny>=0 && ny<n){
			if(b[nx][ny]) dfs(nx, ny); 
		}
	}
}

int main(){

	scanf("%d", &n);
	for (int i=0; i<n; i++) 
		for (int j=0; j<n; j++)
			scanf("%d", &a[i][j]); 

	int ans=1; 
	for (int i=1; i<=100; i++){
		int tmp=0;
		for (int j=0; j<n; j++){
			for (int k=0; k<n; k++){
				if (a[j][k]>i) b[j][k]=a[j][k];
				else b[j][k]=0;
			}
		}

		for (int j=0; j<n; j++){
			for (int k=0; k<n; k++){
				if (b[j][k]) {
					dfs(j, k);
					tmp++;
				}
			}
		}
		ans=ans>tmp?ans:tmp;
	}

	printf("%d\n", ans);
}
