#include <stdio.h>

int a[8][8], ans, n, k;
int dx[4]={1, -1, 0, 0}, dy[4] ={0, 0, -1, 1};
void dfs(int now, int prev, int cnt, int chk){
	if (cnt>ans) ans=cnt;
	int x=now/n, y =now%n;

	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if(nx>=0 && ny>=0 && nx<n && ny<n){
			if (a[nx][ny]<a[x][y]) dfs(nx*n+ny, now, cnt+1, chk);
			else{
				if (nx*n+ny!=prev &&chk==0 && a[x][y]>a[nx][ny]-k){
					int tmp= a[nx][ny];
					a[nx][ny]=a[x][y]-1;
					dfs(nx*n+ny, now,cnt+1, chk+1);
					a[nx][ny]=tmp;
				}
			}
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	for (int test_case=1; test_case<=T; test_case++){

		scanf("%d %d", &n, &k);

		int max=0;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				scanf("%d", &a[i][j]);
				if (max<a[i][j]) max=a[i][j];
			}
		}

		ans=0;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				if (a[i][j]==max)  dfs(i*n+j,0,1, 0);
			}
		}

		printf("#%d %d\n", test_case, ans);
	}
}
