#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
typedef struct{int v, w; }node;
vector<node> e[500];
priority_queue< pair<int, int> > pq;
vector<int> pred[500];
int d[500], n, m, st, en;

void dfsdel(int now, int next){
	if ( now == -1) return;
	for (int i=0; i<e[now].size(); i++){
		if ( e[now][i].v == next ) {
			e[now][i].v=-1;
		}
	}
	for (int i=0; i<pred[now].size(); i++)
	 	dfsdel(pred[now][i] ,now);
}

void dijkstra(){
	for (int i=0; i<n; i++) d[i]=500*1000+1;
	for (int i=0; i<n; i++) pred[i].clear();

	d[st]=0;
	pq.push(make_pair(0, st));

	while(!pq.empty()){
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if ( d[now] < cost ) continue;

		for (int i=0; i< e[now].size(); i++){
			if (d[e[now][i].v] >= d[now] + e[now][i].w){
				if (d[e[now][i].v] > d[now] + e[now][i].w){
					pred[e[now][i].v].clear();
				}
				d[e[now][i].v] = d[now] + e[now][i].w;
				pred[e[now][i].v].push_back(now);
				pq.push({-d[e[now][i].v], e[now][i].v});
			}
		}
	}
}

int main(){
  while(1){
    scanf("%d %d", &n, &m);
    if ( n*m == 0) break;
    scanf("%d %d", &st, &en);

    for (int i=0; i<n; i++) e[i].clear();

    while(m--){
      int u, v, w; scanf("%d %d %d", &u, &v, &w);
      e[u].push_back({v, w});
    }


		dijkstra();
		for (int i=0; i<pred[en].size(); i++)
			dfsdel(pred[en][i],en);
		dijkstra();

		printf("%d\n", d[en]>=500*1000+1?-1:d[en]);
  }
}
