#include <bits/stdc++.h>

using namespace std;
typedef struct{int v, w;}node;
vector<node> e[501];
int d[501];
int main(){
	int T; scanf("%d", &T);

	while(T--){
		int n, m, h; scanf("%d %d %d", &n, &m, &h);
		for (int i=1; i<=n; i++) e[i].clear();

		for (int i=0; i<m; i++){
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			e[u].push_back({v, w});
			e[v].push_back({u, w});
		}

		for (int i=0; i<h; i++){
			int u, v, w; scanf("%d %d %d", &u, &v, &w);
			e[u].push_back({v, -w});
		}

		for (int i=1; i<=n; i++) d[i]=1<<20;
		d[1]=0;

		for (int i=0; i<n-1; i++){

			for (int j=1; j<=n; j++){
				for (int k=0; k<e[j].size(); k++){
					if (d[e[j][k].v] > d[j]+e[j][k].w){
						d[e[j][k].v] = d[j]+e[j][k].w;
					}
				}
			}

		}

		int ans=0;
		for (int i=0; i<n; i++){
			for (int j=0; j<e[i].size(); j++){
				if (d[e[i][j].v] > d[i]+e[i][j].w){
					ans=1;
				}
			}
		}
		if (ans) printf("YES\n");
		else printf("NO\n");
	}
}
