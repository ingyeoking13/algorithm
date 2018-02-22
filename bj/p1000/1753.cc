#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;
typedef struct {int v, w; }vertex;
vector <vertex>e[20001];
priority_queue <pair<int, int> >pq;
int d[20001];
int main(){
	int n, m, s; scanf("%d %d %d", &n, &m, &s); 
	while(m--){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[u].push_back({v, w});
	}

	for (int i=0; i<=20000; i++) d[i] =2*1e5+1;
	d[s]=0; 
	pq.push(make_pair(0, s));

	while(!pq.empty()){
		int cost = -pq.top().first; 
		int now = pq.top().second;
		pq.pop();

		if ( d[now] < cost ) continue;

		for (int i=0; i<e[now].size(); i++){

			if ( d[e[now][i].v] > d[now] + e[now][i].w ){
				d[e[now][i].v] = d[now] + e[now][i].w;
				pq.push(make_pair(-d[e[now][i].v], e[now][i].v));
			}

		}
	}
	for (int i=1; i<=n; i++) {
		if ( d[i] == 2*1e5+1) printf("INF\n");
		else printf("%d\n", d[i]);
	}
}
