#include <stdio.h>

short a[501][501], v[501], n, cnt;

void dfs(int now, int depth){
	if (depth==0) return ;

	for (int i=1; i<=n; i++){
		if ( a[now][i]){
			if( !v[i]) v[i]=1,cnt++;
		 	dfs(i, depth-1); 
		}
	}
}

int main(){
	int m; scanf("%d %d", &n, &m);
	while(m--){
		int u, v; scanf("%d %d", &u, &v);
		a[u][v]=a[v][u]=1;
	}

	v[1]=1;
	dfs(1, 2); 
	printf("%d\n", cnt);
}
