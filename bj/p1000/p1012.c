#include <stdio.h>

int arr[51][51];
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
int m, n, k, ans;
void dfs(int rc){
	int x=rc/n, y=rc%n;
	arr[x][y]=0;
	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if (nx>=0 && nx<m && ny>=0 && ny<n){
			if (arr[nx][ny]){ 
				dfs(nx*n+ny);
			}
		}
	}
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		ans=0;
		scanf("%d %d %d", &m, &n, &k);
		for (int i=0; i<k; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			arr[a][b]=1;
		}
		for (int i=0; i<m; i++){
			for (int j=0; j<n; j++){
				if (arr[i][j]) {dfs(i*n+j); ans++;}
			}
		}
		printf("%d\n", ans);
	}
}

