#include <stdio.h>
#include <algorithm>

using namespace std;
int a[101][101];
int dx[]={-1, 1, 0, 0}, dy[] ={0, 0, -1, 1};


int dfs(int x, int y, int n, int m){
	a[x][y] = 0;

	int ret=1;

	for (int i=0; i<4; i++){

		int nx = x +dx[i], ny = y+dy[i];
		if (1<= x && x<=n && 1<=y && y<=m){
			if ( a[nx][ny] ) {
			 	ret+=dfs(nx, ny, n, m);
			}
		}
	}

	return ret;
}

int main(){
	int n, m, k; scanf("%d %d %d", &n, &m, &k);

	while(k--){

		int x, y; scanf("%d %d", &x, &y);
		a[x][y] =1;
	}

	int ans=0;
	for (int i=1; i<=100; i++){
		for (int j=1; j<=100; j++){

			if (a[i][j]){
				int tmp = dfs(i, j, n, m);
				ans = max(tmp, ans);
			}
		}
	}
	printf("%d\n", ans);

}
