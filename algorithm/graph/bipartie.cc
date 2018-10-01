//baekjoon 1707
#include <vector>
#include <stdio.h>

using namespace std;
vector<int> e[20001];
int c[20001];

int dfs(int now, int color){
	c[now]=color;
	for (int i=0; i<e[now].size(); i++){
		if (!c[e[now][i]]) {
			dfs(e[now][i], 3-color);
		}
	}
}

int main(){
	int T; scanf("%d", &T);
	while(T--){
		int n, m; scanf("%d %d", &n, &m);
		for (int i=1; i<=n; i++) { e[i].clear(); c[i]=0; }
		while(m--){
			int u, v; scanf("%d %d", &u, &v);
			e[u].push_back(v); e[v].push_back(u);
		}

		for (int i=1; i<=n; i++){
			if (!c[i]) dfs(i,1);
		}

		int chk=1;
		for (int i=1; i<=n; i++){
			for (int j=0; j<e[i].size(); j++){
				if ( c[e[i][j]] == c[i] ) chk=0;
			}
		}
		printf(chk?"YES\n":"NO\n");
	}
}
