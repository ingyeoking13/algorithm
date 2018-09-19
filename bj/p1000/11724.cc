#include <bits/stdc++.h>

using namespace std;
vector<int> e[1001];
bool v[1001];

void dfs(int now){
	v[now]=1;

	int sz = e[now].size();
	for (int i=0; i<sz; i++){
		if(!v[e[now][i]]) dfs(e[now][i]);
	}
}

int main(){
	int n, m; scanf("%d %d", &n, &m);
	while(m--){
		int u, v; scanf("%d %d", &u, &v);
		e[u].push_back(v), e[v].push_back(u);
	}

	int ans=0;
	for (int i=1; i<=n; i++){
		if (!v[i]){
			ans++;
			dfs(i);
		}
	}

	printf("%d\n", ans);
}
