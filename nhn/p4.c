#include <stdio.h>
#include <stdlib.h>

int a[11][11], ans[10000], t=0, n; 
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};

int mycmp(const void* a, const void* b){
	return *(int *)a - *(int *)b;
}
void dfs(int x, int y){
	ans[t]+=1; a[x][y]=0;
	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if (nx>=0 && nx<n && ny>=0 && ny<n){
			if (a[nx][ny]){ dfs(nx,ny);
			}
		}
	}
}

int main(){

	scanf("%d", &n);

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			if (a[i][j]) { dfs(i, j); t++;}
		}
	}

	qsort( ans, t, sizeof(int), mycmp);

	printf("%d\n", t);
	for (int i=0; i<t; i++){
		printf(i==t-1?"%d\n":"%d ",ans[i]);
	}

}

