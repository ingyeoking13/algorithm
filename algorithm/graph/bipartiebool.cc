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
			if ( dfs(e[now][i], 3-color)) return 1;
		}
		else if( c[e[now][i]]==color) return 1;
	}
	return 0;
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

		int chk=1;
		for (int i=1; i<=n; i++){
			if ( !c[i]){
				if ( dfs(i,1) ) chk=0;
			}
		}
		printf(chk?"YES\n":"NO\n");
	}
}
