#include <bits/stdc++.h>

using namespace std;
int t[1001], sumt[1001], d[1001];
vector<int> e[1001];
queue<int> q;
int main(){
	int T; scanf("%d", &T);
	while(T--){
		memset(sumt, 0, sizeof(sumt));
		for (int i=0; i<=1000; i++) e[i].clear();

		int n, k; 
		scanf("%d %d", &n, &k);
		for (int i=1; i<=n; i++){
		 	scanf("%d", &t[i]);
			sumt[i] = t[i];
		}

		while(k--){
			int u, v; scanf("%d %d", &u, &v);
			e[u].push_back(v);
			d[v]++;
		}
		int w; scanf("%d", &w);

		for (int i=1; i<=n; i++) if (!d[i]) q.push(i);

		while(!q.empty()){
			int now= q.front(); q.pop();
			
			int sz = e[now].size();
			for (int i=0; i<sz; i++){
				d[ e[now][i] ]--;
				sumt[ e[now][i] ] = max(sumt[ e[now][i] ], sumt[now] + t[ e[now][i]]);

				if (! d[ e[now][i] ]) q.push( e[now][i] );
			}
		}

		printf("%d\n", sumt[w]);
	}
}
