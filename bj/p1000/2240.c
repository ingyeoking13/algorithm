#include <stdio.h>
#include <string.h>

int a[1001], d[1001][31], T, jump;
int max(int x, int y) { if (x<y) return y; return x; }
int dfs(int n, int m){
	if (n == T && m <= jump) return 0;
	if (m>jump) return 0;
	if (d[n][m]!=-1) return d[n][m];

	int where =  m%2+1;
	d[n][m]=max(dfs(n+1,m), dfs(n+1, m+1))+ (where==a[n]?1:0);
	return d[n][m];
}
int main(){
	scanf("%d %d", &T, &jump);
	for (int i=0; i<T; i++) scanf("%d", &a[i]);
	memset(d, -1, sizeof(d));
	printf("%d\n", max(dfs(0, 0), dfs(0, 1)));
}
