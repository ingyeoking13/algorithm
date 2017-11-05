#include <stdio.h>

int d[2001][2001], a[2001], b[2001];
int max(int x, int y) { if(x<y) return y; return x;}
int dfs(int n, int m){
	if (n <0 || m<0 ) return 0;
	if (d[n][m]) return d[n][m];
	d[n][m]=max(dfs(n-1, m-1),dfs(n-1, m));
	if (a[n] > b[y]) d[n][m]=max(d[n][m], dfs(n-1:w
	}
	return d[m][n];
};
int main(){

	int n; scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	for (int i=0; i<n; i++) scanf("%d", &b[i]);

	printf("%d\n", dfs(n-1, n-1));
}
