#include <stdio.h>

int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, -1, 1};
int a[101][101], chk[101][101], ans, n, T=1;

void dfs(int now, int cnt, int p){
	int x=now/n, y=now%n;
	if (cnt==4) { if (p>ans) ans=p; return; }
	p+= a[x][y]; chk[x][y]=1;
	for (int i=0; i<4; i++){
		int nx= x+dx[i], ny=y+dy[i];
		if (nx>=0 && ny>=0 && nx<n && ny<n && chk[nx][ny]==0){
		 	dfs(nx*n + ny, cnt+1, p);
	 	}
	}
	chk[x][y]=0;
}

void fu(int now){
	int x=now/n, y=now%n; int p=a[x][y];
	int min=1000001; int cnt=0;
	for (int i=0; i<4; i++){
		int nx=x+dx[i], ny=y+dy[i];
		if (nx>=0 && ny>=0 && nx<n && ny<n){
			p+=a[nx][ny]; cnt++;
			if (a[nx][ny]<min) min=a[nx][ny];
		}
	}
	if (cnt==4) {p-=min; cnt--;}
	if (cnt==3 && ans<p) ans=p;
}
int main(){
	scanf("%d", &n);
	while(n){
		ans=-4000001;
		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				scanf("%d", &a[i][j]);
			}
		}

		for (int i=0; i<n; i++){
			for (int j=0; j<n; j++){
				printf("%d %d :", i, j);
				dfs(i*n+j, 0, 0); 
				fu(i*n+j);
				printf(" %d \n",ans);
			}
		}
		printf("%d. %d\n", T++, ans);
		scanf("%d", &n);
	}
}
