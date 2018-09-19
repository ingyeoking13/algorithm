#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
struct Maximumflow{
	struct Edge{
		int v, capa, cost;
		Edge* rev;
		Edge(int v, int ca, int co) :
			v(v), capa(ca), cost(co){ }
	};

	int n, s, t;
	vector<vector<Edge*> >e;
	vector<int> chk, dist;
	vector<pair<int, int> > p;

	Maximumflow(int n, int s, int t) :
	 	s(s), t(t){
		e.resize(n), dist.resize(n);
		chk.resize(n), p.resize(n);
	};

	void add_edge(int u, int v, int capa, int cost){
		Edge* edge = new Edge(v, capa, cost);
		Edge* res = new Edge(u, 0, -cost);
		edge->rev = res; 
		res->rev = edge;
		e[u].push_back(edge); 
		e[v].push_back(res);
	}

	int spfa(int& flow, int& cost){
		fill(chk.begin(), chk.end(),0);
		fill(dist.begin(), dist.end(),0x3f3f3f3f);
		fill(p.begin(), p.end(), make_pair(-1, -1));

		dist[s]=0;
		queue<int> q;
		q.push(s);

		while(!q.empty()){
			int now = q.front(); q.pop();
			chk[now]=0;

			for (int i=0; i<e[now].size(); i++){
				if ( e[now][i]->capa <= 0) continue;

				int v = e[now][i]->v;
				if ( dist[v] > e[now][i]->cost + dist[now] ){
					dist[v] = e[now][i]->cost + dist[now];
					p[v] = make_pair(now, i);
					if (!chk[v]) q.push(v), chk[v]=1;
				}
			}
		}

		if ( dist[t] == 0x3f3f3f3f) return 0; 

		int now = t;
		int mn =e[p[now].first][p[now].second]->capa;
		while (p[now].first != -1){
			mn = min(mn, e[p[now].first][p[now].second]->capa);
			now = p[now].first;
		}

		now = t;
		while(p[now].first != -1){
			Edge* ne = e[p[now].first][p[now].second];
			ne->capa -= mn;
			ne->rev->capa += mn;
			now = p[now].first;
		}

		flow += mn;
		cost += mn*dist[t];
		return 1;

	};

	pair<int, int> flow(){
		int flow =0, cost=0;
		while(spfa(flow, cost));
		return make_pair(flow, cost);
	}
};

int main(){
	while(1){
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		if (!n ) break;
		Maximumflow mf(n+4, 0, n+3);
		mf.add_edge(0, 1, a, 0);
		mf.add_edge(0, 2, b, 0);

		for (int i=1; i<=n; i++){
			int capa;
			scanf("%d %d %d", &capa, &a, &b);
			mf.add_edge(2+i,n+3, capa, 0);
			mf.add_edge(1,2+i, 20000, a);
			mf.add_edge(2,2+i, 20000, b);
		}


		pair<int, int> ans= mf.flow();
		printf("%d\n", ans.second);
	}
}
