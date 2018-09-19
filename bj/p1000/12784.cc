#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct Edge{
	int v, w;
	Edge(int v, int w) : v(v), w(w) {}
};

vector<Edge> e[1001];
char chk[1001];

int dfs(int now, int dist)
{
	int ret=dist;
	int child=0;
	int tmp=0;
	chk[now]=1;
	for (int i=0; i<e[now].size(); i++)
	{
		if (!chk[e[now][i].v])
		{
			child += dfs(e[now][i].v, e[now][i].w);
			tmp=1;
		};
	}
	if (!tmp) return ret;
	return ret=min(ret, child);
};

int main()
{
	int T; scanf("%d", &T);

	while(T--){
		int n, m; scanf("%d %d", &n, &m);
		memset(chk, 0, sizeof(chk));
		while(m--){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			e[u].push_back({v, w});
			e[v].push_back({u, w});
		}
		int tmp=dfs(1,1e9);
		printf("%d\n", tmp==1e9?0:tmp);
		for (int i=1; i<=n; i++) e[i].clear();
	}
}
