#include <bits/stdc++.h>

using namespace std;
vector<int> e[20001];
int c[20001];
bool dfs(int now, int chk){
	c[now]=chk;
	int sz = e[now].size();
	for (int i=0; i<sz; i++){
		if(!c[e[now][i]]){
		 	if(dfs(e[now][i], 3-chk)==0) return 0;
		}
		else if (c[now] == c[e[now][i]]) return 0;
	}
	return 1;
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n, m; scanf("%d %d", &n, &m);
		memset(e, 0, sizeof(e));
		memset(c, 0, sizeof(c));
		while(m--){
			int u, v; scanf("%d %d", &u, &v);
			e[u].push_back(v);
			e[v].push_back(u);
		}

		int ans=1;
		for (int i=1; i<=n; i++){
			if (!c[i]) {
				if(!dfs(i, 1)) ans=0;
			}
		}

		printf(ans?"YES\n":"NO\n");
	}
}
