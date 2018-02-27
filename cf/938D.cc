#include <bits/stdc++.h>

using namespace std;
typedef struct{ int v; long long w; }node;
vector<node> e[200001];
vector<int> ans;
int a[200001], v[200001];

int main(){
	int n, m; scanf("%d %d", &n, &m);
	while(m--){
		int u, v; scanf("%d %d %lld", &u, &v, &w);
		e[u].push_back({v, w}); e[v].push_back({u, w});
	}
	for (int i=1; i<=n; i++) scanf("%d", &a[i]);

	for (int i=1; i<=n; i++){



	}


}
