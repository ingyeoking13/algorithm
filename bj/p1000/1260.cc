#include <bits/stdc++.h>

using namespace std;
vector<int> e[1001];
bool v[1001];

void dfs(int now){
	v[now]=1;
	printf("%d ", now);
	int sz = e[now].size();

	for (int i=0; i<sz; i++){
		if (!v[e[now][i]]) {
			dfs(e[now][i]);
		}
	}
}

int main(){
	int n, m, s; scanf("%d %d %d", &n, &m, &s);
	while(m--){
		int u, v; scanf("%d %d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for (int i=1; i<=1000; i++) 
		sort(e[i].begin(), e[i].end());

	dfs(s);
	printf("\n");

	memset(v, 0, sizeof(v));
	queue<int> q;
	q.push(s);
	v[s]=1;

	while(!q.empty()){
		int now = q.front(); q.pop();
		int sz = e[now].size();
		printf("%d ", now);

		for (int i=0; i<sz; i++){
			if(!v[e[now][i]]){
				v[e[now][i]]=1;
				q.push(e[now][i]);
			}
		}
	}
	printf("\n");
}
