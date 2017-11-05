#include <stdio.h>

long long a[101][101], d[101][101];
long long dfs(int x, int y){
	if (x==0 && y==0) return 1;
	if (d[x][y]) return d[x][y];
	for (int i=y-1; i>=0; i--)
		if (a[x][i]+i==y) d[x][y]+=dfs(x, i);
	for (int i=x-1; i>=0; i--)
		if (a[i][y]+i==x) d[x][y]+=dfs(i, y);

	return d[x][y];
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	printf("%lld\n",	dfs(n-1,n-1));
}
