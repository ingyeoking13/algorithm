#include <bits/stdc++.h>

using namespace std;
vector<int> e[10001];
queue<int> q;
int v[10001], cnt[10001], ans;

int main(){
	int n, m; scanf("%d %d", &n, &m);
	while(m--){
		int u, v; scanf("%d %d", &u, &v);
		e[v].push_back(u);
	}

	for (int i=1; i<=n; i++){
		memset(v, 0, sizeof(v));
		q.push(i);
		v[i]=1;

		while(!q.empty()){
			int now = q.front(); q.pop();
			int sz = e[now].size();

			for (int j=0; j<sz; j++){
				if (!v[ e[now][j] ]){
					q.push(e[now][j]);
					v[ e[now][j] ]=1;
				}
			}
		}

		for (int j=1; j<=n; j++) if ( v[j] ) cnt[i]++;
		ans=max(ans, cnt[i]);
	}

	for (int i=1; i<=n; i++) 
		if ( cnt[i] == ans) printf("%d ", i);
	printf("\n");
}
