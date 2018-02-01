#include <bits/stdc++.h>

using namespace std;
int d[32001], ans[32001], len;
vector<int> e[32001];
priority_queue<int, vector<int>,greater<int> > pq;

int main(){
	int n,m; scanf("%d %d", &n, &m);
	while(m--){
		int u, v; scanf("%d %d", &u, &v);
		e[u].push_back(v);
		d[v]++;
	}

	for (int i=1; i<=n; i++) if ( !d[i] ) pq.push(i);

	while(!pq.empty()){
		int now = pq.top(); pq.pop();
		if ( !d[now] ) ans[len++] = now;

		int sz = e[now].size();
		for (int i=0; i<sz; i++){
			d[e[now][i]]--;
			if ( !d[e[now][i]] ) pq.push(e[now][i]);
		}
	}

	for (int i=0; i<len; i++) printf("%d ", ans[i]);
	printf("\n");
}
