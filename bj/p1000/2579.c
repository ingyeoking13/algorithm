#include <stdio.h>

int a[301], d[301];
int max(int x, int y) { if (x>y) return x; return y;}
int dfs(int n){
	if(n<=0) return 0;
	if (d[n]) return d[n];
	return d[n]=max(dfs(n-2)+a[n],dfs(n-3)+a[n-1]+a[n]);
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);
	printf("%d\n", dfs(n));
}
