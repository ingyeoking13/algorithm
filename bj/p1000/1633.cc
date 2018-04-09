#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;
struct Maximumflow{
	struct Edge{
		int v, capa, cost;
		Edge* rev;
		Edge(int v, int ca, int co) : v(v), capa(ca), cost(co){}
	};

	int s, t;
	vector<vector<Edge* > > e;
	vector<int> chk, d;
	vector<pair<int, int> > p;

	Maximumflow(int n, int s, int t) : s(s), t(t) {
		e.resize(n), chk.resize(n);
		d.resize(n), p.resize(n);
	}
	void add_edge(int u, int v, int capa, int cost){
		Edge *edge = new Edge(v, capa, cost);
		Edge *res = new Edge(u, 0, -cost);
		edge->rev = res;
		res->rev = edge;
		e[u].push_back(edge);
		e[v].push_back(res);
	}

	bool spfa(int &flow, int &cost){
		fill(chk.begin(), chk.end(), 0);
		fill(d.begin(), d.end(), 0x3f3f3f3f);
		fill(p.begin(), p.end(), make_pair(-1, -1));

		queue<int> q;
		d[s] = 0;
		q.push(s);

		while(!q.empty()){
			int now = q.front(); q.pop();
			chk[now]=0;

			for (int i=0; i<e[now].size(); i++){
				if ( e[now][i]->capa <=0) continue;
				int v = e[now][i]->v;

				if ( d[v] > e[now][i]->cost + d[now] ){
					d[v] = e[now][i]->cost + d[now];
					p[v] = make_pair(now, i);
					if (!chk[v]) q.push(v), chk[v]=1;
				}
			}
		}

		if ( d[t] == 0x3f3f3f3f) return 0;

		int now = t;
		int mn = 0x3f3f3f3f;

		while( p[now].first != -1){
			mn = min(e[p[now].first][p[now].second]->capa, mn);
			now = p[now].first;
		}

		now = t;
		while(p[now].first != -1){
			e[p[now].first][p[now].second]->capa -= mn;
			e[p[now].first][p[now].second]->rev->capa += mn;
			now = p[now].first;
		}
		cost += mn*d[t];
		flow += mn;
		return 1;
	}

	pair<int, int> flow(){
		int flow=0, cost=0;
		while(spfa(flow, cost));
		return make_pair(flow, cost);
	}
};

int main(){

	vector<pair<int, int> > v;
	int w, b;
	while(~scanf("%d %d", &w, &b)){
		v.push_back(make_pair(w, b));
	}

	Maximumflow mf(v.size()+4, 0,v.size()+3);

	for (int i=0; i<v.size(); i++){
		mf.add_edge(0, i+1, 1, 0);
		mf.add_edge(i+1, v.size()+1, 1, -v[i].first);
		mf.add_edge(i+1, v.size()+2, 1, -v[i].second); 
	}
	mf.add_edge(v.size()+1, v.size()+3, 15, 0);
	mf.add_edge(v.size()+2, v.size()+3, 15, 0);
	printf("%d\n", -mf.flow().second);
}
