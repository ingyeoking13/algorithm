#include <stdio.h>
#include <string.h>

int d[501][501], w[501], s[501];
int min(int a, int b) { if (a< b) return a; return b;}
int dfs(int f, int t){
	if (d[f][t]>=0) return d[f][t];
	if (f==t) return d[f][t]=0;

	d[f][t]=1<<28;
	for (int i=0; i<t-f+1; i++){
		d[f][t]=min(dfs(f,f+i)+dfs(f+i+1,t)+s[t]-s[f-1],d[f][t]);
	}
	return d[f][t];
}
int main(){

	int T; scanf("%d", &T);
	while (T--){
		memset(d, -1, sizeof(d));
		memset(s, 0, sizeof(s));
		int n; scanf("%d", &n);
		for (int i=0; i<n; i++) scanf("%d", &w[i]);
		s[0]=w[0];
 		for (int i=1; i<n; i++) s[i]=s[i-1]+w[i];
		printf("%d\n", dfs(0, n-1));
	}
}
