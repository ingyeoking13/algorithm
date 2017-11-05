#include <stdio.h>
#include <string.h>

int a[20][20], chk[101], n, ans;
int dx[4]= {-1, 1, 1, -1}, dy[4]= {1, 1, -1, -1};
int sx, sy;

void dfs(int x, int y, int cnt, int dir){
	if (dir==3 && cnt>ans && sx==x && sy==y ){ ans=cnt;  return;}
	for (int i=0; i<2; i++){
		if (dir+i<4){
			int nx=x+dx[dir+i], ny=y+dy[dir+i];
			if (nx>=0 && ny>=0 && nx<n && ny<n){
				if (!chk[a[nx][ny]]){
					chk[a[nx][ny]]=1;
					dfs(nx, ny, cnt+1, dir+i);
					chk[a[nx][ny]]=0;
				}
			}
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	for (int t_c = 1; t_c<=T; t_c++){
		ans=0;
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				scanf("%d", &a[i][j]);
			}
		}

		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				sx=i,sy=j;
				dfs(i, j, 0, 0);
			}
		}

		printf("#%d ", t_c);
		if (ans<=1) printf("-1\n");
		else printf("%d\n", ans);
	}
}
