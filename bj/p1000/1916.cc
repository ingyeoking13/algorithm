#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
typedef struct { int v, w; }node;
vector<node> e[1001];
priority_queue<pair<int, int> > pq;
int d[1001];


int main(){
	int n, m; scanf("%d %d", &n, &m);
	while(m--){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[u].push_back({v, w});
	}

	int s, E;
	scanf("%d %d", &s, &E);

	for (int i=0; i<=1000; i++) d[i]=1e3*1e5+1;
	d[s]=0;
	pq.push(make_pair(0, s));

	while (!pq.empty()){
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if ( d[now] < cost ) continue;

		for (int i=0; i<e[now].size(); i++){
			if ( d[e[now][i].v] > cost + e[now][i].w) {
				d[e[now][i].v] = cost + e[now][i].w;
				pq.push(make_pair(-cost-e[now][i].w, e[now][i].v));

			}

		}

	}

	printf("%d\n", d[E]);

}
