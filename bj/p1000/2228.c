#include <stdio.h>

int d[101][60], c[101][60], a[101], s[101];
int max(int x, int y){ if (x>y) return x; return y; }
int dfs(int n, int m){
	if (m==0) return 0;
	if (n<0) return -(1<<27);
	if (c[n][m]) return d[n][m];
	c[n][m]=1;
	d[n][m]=dfs(n-1,m);
	for (int i=n;i>0;i--){
		d[n][m]= max(dfs(i-2,m-1)+s[n]-s[i-1], d[n][m]); 
	}	
	return d[n][m];
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	s[0]=a[0];
	for (int i=1; i<n; i++) s[i]=s[i-1]+a[i];
	printf("%d\n", dfs(n-1, m));
}
