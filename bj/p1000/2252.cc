#include <bits/stdc++.h>

using namespace std;

vector<int> e[32001];
int d[32001], ans[32001], len;
queue<int> q;

int main(){
	int n, m; scanf("%d %d", &n, &m);
	while(m--){
		int u, v; scanf("%d %d", &u, &v);
		e[u].push_back(v);
		d[v]++;
	}

	for (int i=n; i>=1; i--) if ( !d[i] )  q.push(i);

	while(!q.empty()){
		int now = q.front(); q.pop();
		if ( !d[now] ) ans[len++] = now;

		int sz = e[now].size();
		for (int i=0; i<sz; i++){
			d[ e[now][i] ]--;
			if ( ! d[ e[now][i] ] )  q.push(e[now][i]);
		}
	}

	for (int i=0; i<len; i++) printf("%d ", ans[i]);
	printf("\n");

}
