#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct Maximumflow{

	struct Edge{
		int v, capa, cost;
		Edge* rev;
		Edge(int v, int c, int cost) : v(v), capa(c), cost(cost){}
	};

	int s, t;
	vector<vector<Edge *> > e;
	vector<int> chk, dist;
	vector<pair<int, int> > p;

	Maximumflow(int n, int m) : s(0), t(n+m+1){ 
		e.resize(n+m+2); chk.resize(n+m+2);
		p.resize(n+m+2, make_pair(-1, -1));
		dist.resize(n+m+2);
	}

	void add_edge(int u, int v, int c, int cost){
		Edge* edge = new Edge(v, c, cost);
		Edge* res = new Edge(u, 0, -cost);
		edge->rev = res;
		res->rev = edge;
		e[u].push_back(edge);
		e[v].push_back(res);
	}

	bool spfa(int &flow, int &cost){
		fill(chk.begin(), chk.end(), 0);
		fill(dist.begin(), dist.end(), 0x3f3f3f3f);
		fill(p.begin(), p.end(), make_pair(-1,-1));
		dist[s] = 0;
		queue<int> q;
		q.push(s);

		while(!q.empty()){
			int now= q.front(); q.pop();
			chk[now] = 0;
			for (int i=0; i<e[now].size(); i++){
				if ( e[now][i]->capa <= 0) continue;

				int v = e[now][i]->v;
				if(dist[v] > dist[now] + e[now][i]->cost){
					dist[v] = dist[now] + e[now][i]->cost;
					p[v] = make_pair(now, i);
					if( !chk[v] ) chk[v]=1, q.push(v);

				}
			}
		}
		if (dist[t] == 0x3f3f3f3f) return 0;

		int now = t;
		int mn = e[p[now].first][p[now].second]->capa;
		while(p[now].first != -1){
			mn = min(e[p[now].first][p[now].second]->capa,mn);
			now = p[now].first;
		}

		now = t;
		while(p[now].first !=-1){
			e[p[now].first][p[now].second]->capa -= mn;
			e[p[now].first][p[now].second]->rev->capa += mn;
			now = p[now].first;
		}

		flow += mn;
		cost += mn*dist[t];
		return 1;
	}

	pair<int,int> flow(){
		int flow=0, cost=0;
		while(spfa(flow, cost));
		return {flow, cost};
	}
};

int main(){
	int n, m; scanf("%d %d", &n, &m);
	int a;

	Maximumflow mf(n, m);
	for (int i=1; i<=n; i++) {
		scanf("%d", &a);
		mf.add_edge(0, i, a, 0);
	}

	for (int i=1; i<=m; i++) {
		scanf("%d", &a);
		mf.add_edge(n+i, n+m+1, a, 0);
	}

	for (int i=1; i<=m; i++){
		for (int j=1; j<=n; j++){
			scanf("%d", &a);
			mf.add_edge(j,n+i, 100,a);
		}
	}

	printf("%d\n", mf.flow().second);
}
