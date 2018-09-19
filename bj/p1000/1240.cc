#include <bits/stdc++.h>

using namespace std;
typedef struct{int v,d; }node;
vector<node> e[1001];
int chk[1001];

int dfs(int now, int end, int len){
	if (now==end) return len;
	else {
		int sz= e[now].size();
		for (int i=0; i<sz; i++){
			if (!chk[e[now][i].v]){
				chk[e[now][i].v]=1;
				int ret=dfs(e[now][i].v, end, len+e[now][i].d);
				chk[e[now][i].v]=0;
				if(ret) return ret;
			}
		}
		return 0;
	}
}
int main(){
	int n, m; scanf("%d %d",&n, &m);
	for (int i=0; i<n-1; i++){
		int u, v, d; scanf("%d %d %d", &u, &v, &d);
		e[u].push_back({v, d});
		e[v].push_back({u, d});
	}
	while(m--){
		int s, e; scanf("%d %d", &s, &e);
		chk[s]=1;
		printf("%d\n", dfs(s, e, 0));
		chk[s]=0;
	}
}
