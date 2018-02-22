#include <stdio.h>

int a[100000], d[100000], s[100000];

int dfs(int now, int cnt, int step){
	if ( d[now] ) {
		if ( step != s[now] ) return 0;
		return cnt-d[now];
	}
	d[now]=cnt;
	s[now]=step;
	return dfs(a[now], cnt+1, step);
}

int main(){
	int T; scanf("%d", &T);

	while(T--){
		int n; scanf("%d", &n);
		for (int i=1; i<=n; i++){
			scanf("%d", &a[i]); d[i]=0, s[i]=0;
		}

		int ans=0;
		for (int i=1; i<=n; i++){
			if ( !d[i] ) ans += dfs(i, 1, i);
		}

		printf("%d\n", n-ans);
	}
}
