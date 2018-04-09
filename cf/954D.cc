#include <stdio.h>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;
vector<int> e[1001];
bool chk[1001][1001];
int d[2][1001];
int main(){
	int n, m, s, t;

	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int i=0; i<m; i++){
		int u, v; scanf("%d %d", &u, &v);
		chk[u][v]=1; chk[v][u]=1;
		e[u].push_back(v);
		e[v].push_back(u);
	}

	memset(d, 0x3f, sizeof(d));

	d[0][s]=0;
	d[1][t]=0;

	for (int k=0; k<2; k++){
		priority_queue<pair<int, int> > pq;
		if ( k == 0) pq.push({-d[0][s], s});
		else pq.push({-d[1][t], t});

		while(!pq.empty()){
			int dist = -pq.top().first;
			int now = pq.top().second;
			pq.pop();

			if ( d[k][now] < dist ) continue;

			for (int i=0; i<e[now].size(); i++){

				if ( d[k][e[now][i]] >  d[k][now] + 1){
					d[k][e[now][i]] = d[k][now]+1;
					pq.push({-d[k][e[now][i]], e[now][i]});
				}
			}
		}
	}

	int ans=0;
	int mn =d[0][t];
	for (int i=1; i<=n; i++){
		for (int j=i+1; j<=n; j++){
			if ( chk[i][j] ) continue;
			if (min(d[0][i] + d[1][j]+1, d[1][i] + d[0][j]+1)>=mn){
			 	ans++;
			}
		}
	}
	printf("%d\n", ans);

}
