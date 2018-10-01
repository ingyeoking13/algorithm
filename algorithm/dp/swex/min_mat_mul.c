#include <stdio.h>

typedef struct array{ int r, c; }array;
array a[501];
int d[501][501];

int min(int n, int m) { if (n<m) return n; return m;}

int dfs(int l, int r){
	if (l==r) return 0;
	if (d[l][r]) return d[l][r];
	d[l][r]=1<<25;
	for (int i=l; i<r; i++)
		d[l][r]=min(dfs(l,i)+dfs(i+1,r)+a[l].r*a[i].c*a[r].c,d[l][r]);
	
	return d[l][r];
}

int main(){

	int n;
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d %d", &a[i].r, &a[i].c);

	printf("%d\n", dfs(1,n));
}
