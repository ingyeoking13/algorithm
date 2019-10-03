#include <bits/stdc++.h>

using namespace std;
typedef struct{int v, w; }node;
int d[501], pred[501];
vector<node> e[501];

int main(){
	int n, m; scanf("%d %d", &n, &m);
	while(m--){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[u].push_back({v, w});
	}

	for (int i=1; i<=500; i++) d[i]=5e6+1;
	d[1]=0;

	for (int i=1; i<=n-1; i++){

		for (int j=1; j<=n; j++){
			for (int k=0; k<e[j].size(); k++){
				if (d[j] != 5e6+1 && d[e[j][k].v] > d[j] + e[j][k].w){
					d[e[j][k].v] = d[j] + e[j][k].w;
				}
			}
		}

	}
	int cycle=0;
	for (int i=1; i<=n; i++){
		for (int j=0; j<e[i].size(); j++){
			if (d[i] != 5e6+1 && d[e[i][j].v] > d[i] + e[i][j].w) {
				cycle=1;
			}
		}
	}

	if (cycle) printf("-1\n");
	else{
		for (int i=2; i<=n; i++) printf("%d\n", (d[i]==5e6+1)?-1:d[i]);
	}

}
