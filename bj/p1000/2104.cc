#include <bits/stdc++.h>

using namespace std;
long long a[100001];
long long s[100001];int mn[200002], len;

int dfs(int f, int t, int now){
	if ( f== t) return mn[now] = a[f];
	len =max(len, now);
	return mn[now] = min(dfs(f, (f+t)/2, now*2), dfs((f+t)/2+1, t, now*2+1));
}

int main(){
	int n; scanf("%d", &n);
	for (int i=1; i<=n; i++){
		scanf("%lld", &a[i]);
		s[i]=s[i-1]+a[i];
	}
	dfs(1, n, 1);

	for (int i=


}
