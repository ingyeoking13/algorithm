#include <stdio.h>

int a[2001], d[2001][2001];
int dfs(int l, int r){
	if (l==r) return 1;
	if (l+1==r && a[l]==a[r]) return 1;
	if (d[l][r]>0) return d[l][r];
	if (a[l] != a[r]) return 0;
	d[l][r]=dfs(l+1, r-1);

}

int main(){
	int n;
	for (int i=0; i<n; i++) scanf("%d", &a[i]);

	dfs(0, n-1);
	int T;
	scanf("%d", &T);
	while(T--){
		int a, b;
		scanf("%d %d", &a, &b);
		if(d[a-1][b-1]) printf("1\n");
		else printf("0\n");
	}
}
