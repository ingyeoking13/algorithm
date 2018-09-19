#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
typedef struct{ int v, w; }node;
vector<node> e[801];
int d[3][801], pred[801];
priority_queue< pair<int, int> > pq;

int main(){
	int n, m; scanf("%d %d", &n, &m);
	while (m--){
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		e[u].push_back({v, w}); e[v].push_back({u, w});
	}

	int p1, p2; scanf("%d %d", &p1, &p2);

	for (int i=0; i< 3; i++) 
		for (int j=1; j<=800; j++)
			d[i][j] = 3*800*1000+1;

	int a[3] = {1, p1, p2};

	for (int k=0; k<3; k++){
		pq.push( make_pair( 0, a[k]) );
		d[k][a[k]]=0;

		while(!pq.empty()){

			int cost = -pq.top().first;
			int now = pq.top().second;
			pq.pop();

			if ( d[k][now] < cost) continue;

			for (int i=0; i<e[now].size(); i++){

				if ( d[k][e[now][i].v] >  d[k][now] + e[now][i].w ){
					d[k][e[now][i].v] = d[k][now] + e[now][i].w;
					pq.push(make_pair(-d[k][e[now][i].v], e[now][i].v));
				}
			}
		}
	}
	int ans=min(d[0][p1]+d[1][p2]+d[2][n] , d[0][p2]+d[2][p1]+d[1][n]);
	printf("%d\n", (ans>=3*800*1000+1)?-1:ans); 
}
