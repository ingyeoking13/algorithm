#include <stdio.h>
#include <vector>
using namespace std;

vector<int> e[200001];
bool chk[200001];

int dfs(int now){
	chk[now]=1;

	bool ret = (e[now].size()==2);
	for (int i=0; i<e[now].size(); i++){
		if (chk[e[now][i]]) continue;
		if (!dfs(e[now][i])) ret=0;
	}
	return ret;
}
int main(){
	int n, m; scanf("%d %d", &n, &m);
	for (int i=0; i<m; i++){
		int u, v; scanf("%d %d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	int ans=0;
	for (int i=1; i<=n; i++){
		if (chk[i]) continue;
		if(dfs(i)) ans++;
	}

	printf("%d\n", ans );

}
