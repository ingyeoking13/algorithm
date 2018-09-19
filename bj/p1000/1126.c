#include <stdio.h>
#include <string.h>

int a[51], d[51][250001], n;
int inf = 1<<20;
int max(int x, int y) { return x<y?y:x; }
int dfs(int k, int diff){
	if ( diff>250000 ) return -inf;
	if ( k==n ){
		if (diff==0)  return 0;
		else return -inf;
	}
	if ( d[k][diff]!=-1 ) return d[k][diff];
	d[k][diff] = dfs(k+1, diff);

	d[k][diff] =  max(d[k][diff], dfs(k+1,diff+a[k]));
	if ( a[k]>diff ){
		d[k][diff] = max(d[k][diff], diff+dfs(k+1, a[k]-diff));
	}
	else{
		d[k][diff] = max(d[k][diff], a[k]+dfs(k+1, diff-a[k]));
	}
	return d[k][diff];
}
int main(){
	scanf("%d", &n);
	for (int i=0; i<n; i++) scanf("%d", &a[i]);
	memset(d,-1, sizeof(d));
	int ans=dfs(0, 0);
	printf("%d\n", ans?ans:-1);
}
