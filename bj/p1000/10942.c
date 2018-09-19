#include <stdio.h>

int a[2001], d[2001][2001];
int dfs(int f, int t){
	if (f==t) return d[f][t]=1;
	if (d[f][t]>=0) return d[f][t];
	if (a[f]!=a[t]) return d[f][t]=0;
	if (a[f]==a[t]) {
		if (f+1==t) return d[f][t]=1;
		return d[f][t]=dfs(f+1,t-1);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) d[i][j]=-1;

	for (int i=1; i<2001; i++){
		for (int j=2000; j>=i; j--){
			dfs(i,j);
		}
	}

	int T;
	scanf("%d", &T);
	while(T--){
		int f, t;
		scanf("%d %d", &f, &t);
		printf("%d\n", d[f][t]);
	}
}
