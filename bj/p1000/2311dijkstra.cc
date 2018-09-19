#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
	int v, d;
	Edge* rev;
	Edge(int v, int d) : v(v), d(d) {}
};

int main(){
	int n, m; scanf("%d %d", &n, &m);
	vector<int> d(n+1);
	vector<pair<int, int> > pred(n+1); 
	vector<vector<Edge*> > e(n+1);

	while(m--){
		int u, v, d; scanf("%d %d %d", &u, &v, &d);
		Edge* edge = new Edge(v, d);
		Edge* revedge = new Edge(u, d);
		edge->rev = revedge;
		revedge->rev = edge;
		e[u].push_back(edge);
		e[v].push_back(revedge);
	}

	priority_queue<pair<int, int> > pq;

	fill(d.begin(), d.end(), 0x3f3f3f3f);
	fill(pred.begin(), pred.end(), make_pair(-1, -1));
	pq.push(make_pair(0, 1));
	d[1]=0;

	while(!pq.empty()){
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if ( d[now] <cost ) continue;

		for (int i=0; i<e[now].size(); i++){
			int v = e[now][i]->v, dist = e[now][i]->d;

			if (d[v] > d[now] + dist){
				d[v] = d[now]+dist;
				pred[v] = make_pair(now, i);
				pq.push(make_pair(-d[v], v));
			}
		}
	}

	int now = n;
	int ans = d[n];
	printf("delete path \n");
	while(pred[now].first!=-1){
		e[pred[now].first][pred[now].second]->d=-1;
		e[pred[now].first][pred[now].second]->rev->d=-1;
		printf("%d %d\n", pred[now].first, pred[now].second);
		now = pred[now].first;
	}

	fill(d.begin(), d.end(), 0x3f3f3f3f);
	pq.push(make_pair(0, 1));

	d[1]=0;
	while(!pq.empty()){
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if ( d[now] <cost ) continue;

		printf("now %d\n", now);
		for (int i=0; i<e[now].size(); i++){
			int v = e[now][i]->v, dist = e[now][i]->d;
			if (dist<0) continue;
			printf("%d %d\n", v, dist);

			if (d[v] > d[now] + dist){
				d[v] = d[now]+dist;
				pq.push(make_pair(-d[v], v));
			}
		}
	}

	printf("%d\n", ans +d[n]);
}
